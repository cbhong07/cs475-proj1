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
	struct queue *godHasForaskenUs = malloc(sizeof(struct queue)); //this will probably break :)
	
	// TODO - initialize the structure
	*godHasForaskenUs = (struct queue) {.head = NULL, .tail = NULL, .size = EMPTY};
	// TODO - return pointer to the structure
	return godHasForaskenUs;
}
