/* resched.c - resched */

#include <xinu.h>

/**
 * Reschedule processor to next ready process
 *
 */
void	resched(void)		// assumes interrupts are disabled
{
	struct procent *ptold;	// ptr to table entry for old process
	struct procent *ptnew;	// ptr to table entry for new process

	// If rescheduling is deferred, record attempt and return
	if (Defer.ndefers > 0) {
		Defer.attempt = TRUE;
		return;
	}

	// Point to process table entry for the current (old) process
	ptold = &proctab[currpid];
	kprintf("Resched: Ptold is [%d]\n", ptold);


	// TODO - check ptold's state. If it's running, put it on the ready queue and change state to ready
	if(ptold->prstate == PR_CURR)
	{
		kprintf("Ptold is ready, jumping into ready()\n");
		ready(currpid, RESCHED_NO);
		ptold->prstate = PR_READY;
	}

	// TODO - dequeue next process off the ready queue and point ptnew to it
	int tempPID = dequeue(readyqueue);
	ptnew = &proctab[tempPID];
	kprintf("Resched ptnew [%d] successul\n", ptnew);

	if(isbadpid(tempPID))
		kprintf("ptnew is valid\n");
	else
		kprintf("ptnew is not valid\n");

	// TODO - change its state to "current" (i.e., running)
	ptnew->prstate = PR_CURR;
	kprintf("Resched ptnew change state successfully\n");

	// TODO - set currpid to reflect new running process' PID
	currpid = ptnew;
	kprintf("Resched currpid [%d] reassigned successfully \n", currpid);

	// Context switch to next ready process
	ctxsw(&ptold->prstkptr, &ptnew->prstkptr);
	kprintf("Process [%d] resumed\n", currpid);

	// Old process returns here when resumed
	return;
}