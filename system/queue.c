/* queue.c - enqueue, dequeue, isempty, nonempty, et al. */

#include <xinu.h>
#include <stdlib.h>

/**
 * Prints out contents of a queue
 * @param q	pointer to a queue
 */
void printqueue(struct queue *q)
{
	struct qentry *current = q->head;
	printf("[");
	while (current->next != NULL) {
		if (current == q->tail) {
			printf("(%d)", current->pid);
		}
		else {
			printf("(%d), ", current->pid);
			current = current->next;
		}
	}
	printf("]");
	// TODO - print all contents from head to tail
	// TODO - format should be [(pid), (pid), ...]
}

/**
 * Checks whether queue is empty
 * @param q	Pointer to a queue
 * @return TRUE if true, FALSE otherwise
 */
bool8 isempty(struct queue *q)
{
	if(q->size == EMPTY) {
		return TRUE;
	}
	else {
		return FALSE;
	}
	// TODO
}

/**
 * Checks whether queue is nonempty
 * @param q	Pointer to a queue
 * @return TRUE if true, FALSE otherwise
 */
bool8 nonempty(struct queue *q)
{
	if(q->head != NULL) {
		return FALSE;
	}
	else {
		return TRUE;
	}
	// TODO - don't just check q's size because q could be NULL
}

/**
 * Checks whether queue is full
 * @param q	Pointer to a queue
 * @return TRUE if true, FALSE otherwise
 */
bool8 isfull(struct queue *q)
{
	if(q->size >= NPROC) {
		return TRUE;
	}
	else {
		return FALSE;
	}
	// TODO - check if there are at least NPROC processes in the queue
}

/**
 * Insert a process at the tail of a queue
 * @param pid	ID process to insert
 * @param q	Pointer to the queue to use
 *
 * @return pid on success, SYSERR otherwise
 */
pid32 enqueue(pid32 pid, struct queue *q)
{
	// TODO - check if queue is full and if pid is illegal, and return SYSERR if either is true
	if(isfull(q) == TRUE || isbadpid(pid)) {
		return SYSERR;
	}
	else {
		struct qentry *new = (struct qentry*) malloc(uint32 nbytes);
		new = {.pid = pid, .next = NULL, .prev = q->tail};
		q->tail = new;
		return pid;
	}
	// TODO - allocate space on heap for a new QEntry

	// TODO - initialize the new QEntry

	// TODO - insert into tail of queue

	// TODO - return the pid on success
}

/**
 * Remove and return the first process on a list
 * @param q	Pointer to the queue to use
 * @return pid of the process removed, or EMPTY if queue is empty
 */
pid32 dequeue(struct queue *q)
{
	if(isempty(q) == EMPTY) {
		return EMPTY;
	}
	else {
		struct qentry *head = q->head;
		q->head = head->next;
		//free memory
		return head.pid;
	}
	// TODO - return EMPTY if queue is empty

	// TODO - get the head entry of the queue

	// TODO - unlink the head entry from the rest

	// TODO - free up the space on the heap

	// TODO - return the pid on success
}

/**
 * Finds a queue entry given pid
 * @param pid	a process ID
 * @param q	a pointer to a queue
 * @return pointer to the entry if found, NULL otherwise
 */
struct qentry *getbypid(pid32 pid, struct queue *q)
{
	// TODO - return NULL if queue is empty or if an illegal pid is given
	if(isEmpty(q) || isbadpid(pid))
		return NULL;
	// TODO - find the qentry with the given pid
	bool8 found = FALSE;
	struct qentry *temp = q->head;
	while(!found)
	{
		if(temp->pid == pid)
		{
			found = TRUE;
			break;
		}
		else temp = temp->next;
	}
	// TODO - return a pointer to it
	return temp;
}


/**
 * Remove a process from the front of a queue (pid assumed valid with no check)
 * @param q	pointer to a queue
 * @return pid on success, EMPTY if queue is empty
 */
pid32 getfirst(struct queue *q)
{
	// TODO - return EMPTY if queue is empty
	if(isEmpty(q))
		return EMPTY;
	// TODO - remove process from head of queue and return its pid
	pid32 removed = q->head->pid;
	struct qentry *next = q->head->next;
	free(q->head);
	q->head = next;
	return removed;
}

/**
 * Remove a process from the end of a queue (pid assumed valid with no check)
 * @param q	Pointer to the queue
 * @return pid on success, EMPTY otherwise
 */
pid32 getlast(struct queue *q)
{
	// TODO - return EMPTY if queue is empty
	if(isEmpty(q))
		return EMPTY;
	// TODO - remove process from tail of queue and return its pid
	pid32 removed = q->tail->pid;
	struct qentry *last = q->tail->prev;
	free(q->tail);
	q->tail = last;
	return removed;
}

/**
 * Remove a process from an arbitrary point in a queue
 * @param pid	ID of process to remove
 * @param q	Pointer to the queue
 * @return pid on success, SYSERR if pid is not found
 */
pid32 remove(pid32 pid, struct queue *q)
{
	// TODO - return EMPTY if queue is empty
	if(isEmpty(q))
		return EMPTY;
	// TODO - return SYSERR if pid is illegal
	if(isbadpid(pid))
		return SYSERR;
	// TODO - remove process identified by pid parameter from the queue and return its pid
	struct qentry *removed = getbypid(pid, q);
	if(removed != NULL)
	{
		
	}
	else // TODO - if pid does not exist in the queue, return SYSERR
		return SYSERR;
	
}