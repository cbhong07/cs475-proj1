/* newqueue.c - newqueue */

#include <xinu.h>
#include <stdlib.h>

/**
 * Allocate and initialize a queue
 * @return pointer to queue structure
 */
struct queue *newqueue(void)
{
	
	// TODO - allocate memory for a new Queue structure (required to be on heap)
	struct queue *godHasForsakenUs = malloc(sizeof(struct queue)); //this will probably break :)
	
	// TODO - initialize the structure
	godHasForsakenUs->head = NULL;
	godHasForsakenUs->tail = NULL;
	godHasForsakenUs->size = 0;
	// TODO - return pointer to the structure
	return godHasForsakenUs;
}
