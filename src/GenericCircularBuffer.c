#include "GenericCircularBuffer.h"
#include "malloc.h"
#include "stdio.h"
#include "CException.h"

/*
 * circularBufferNew
 *
 * Input
 *		length		length of the circularBuffer
 *		sizeOfType	
 
 * Function
 *		to set the memory allocated with given length and sizeOfType
 */
CircularBuffer *circularBufferNew(int length, int sizeOfType)
{
	CircularBuffer *cb;
	
	cb = malloc(sizeof(CircularBuffer));
	cb->buffer = malloc(sizeOfType * length);
	cb->length = length;
	cb->size = 0;
	cb->sizeOfType = sizeOfType;
	cb->head = cb->buffer;
	cb->tail = cb->buffer;
	
	return cb;
}

/*
 * circularBufferDel
 *
 * Input
 *		cb		is a pointer to CircularBuffer
 *
 * Function
 *		to free the memory allocated
 */
 void circularBufferDel(CircularBuffer *cb)
 {
	free(cb);
 }
 
void circularBufferAdd(CircularBuffer *cb, void *obj, void (*copy)(void *, void *))
{
	copy(obj, cb->buffer);
	
	if(cb->size != 0)
	{
		cb->head++;
		copy(obj, cb->head);
	}
	else
	{
		copy(obj, cb->tail);
		copy(obj, cb->head);
	}
	
	cb->buffer++;
	cb->size++;
}

void circularBufferRemove(CircularBuffer *cb, void *obj, void (*copy)(void *, void *))
{

}

int circularBufferIsFull(CircularBuffer *cb)
{

}

int circularBufferIsEmpty(CircularBuffer *cb)
{

}