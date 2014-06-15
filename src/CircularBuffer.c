#include "malloc.h"
#include "stdio.h"
#include "CircularBuffer.h"
#include "CException.h"

// void dummy()
// {
	// CircularBuffer cb;		//statically allocated
	// CircularBuffer *ptr2cb	//dynamically allocated
	
	// ptr2cb = malloc(sizeof(CircularBuffer));
	// free(ptr2cb);
// }

/*
 * circularBufferDel
 *
 * Input
 *		length		length of the circularBuffer
 *
 * Function
 *		to set the memory allocated with given length
 */
CircularBuffer *circularBufferNew(int length)
{
	CircularBuffer *circularBuffer;
	
	circularBuffer = malloc(sizeof(CircularBuffer));
	circularBuffer->buffer = malloc(sizeof(int) * length);
	circularBuffer->length = length;
	circularBuffer->size = 0;
	circularBuffer->head = circularBuffer->buffer;
	circularBuffer->tail = circularBuffer->buffer;
	
	return circularBuffer;
}

/*
 * circularBufferDel
 *
 * Input
 *		circularBuffer		is a pointer to CircularBuffer
 *
 * Function
 *		to free the memory allocated
 */
void circularBufferDel(CircularBuffer *circularBuffer)
{
	free(circularBuffer);
}

/*
 * circularBufferAdd
 *
 * Input
 *		cb			is a pointer to CircularBuffer
 *		value2Add	value to be added to the Circular Buffer
 *
 * Function
 *		to add value to Circular Buffer and set the cb->head to be
 *		the last added value and cb->tail to be the first added value
 *		and raise an exception if Circular Buffer is full
 */
void circularBufferAdd(CircularBuffer *cb, int value2Add)
{
	if(cb->length == cb->size)
		Throw(ERR_BUFFER_IS_FULL);
	
	
	*cb->buffer = value2Add;
	
	if(cb->size == 0)
		*cb->tail = value2Add;
	
	if((cb->length - 1) != cb->size)
		cb->head++;
	else
		*cb->head = value2Add;

	cb->buffer++;
	cb->size++;
}

/*
 * circularBufferRemove
 *
 * Input
 *		cb				is a pointer to CircularBuffer
 *
 * Return
 *		dataRemove		data that had remove
 *
 * Function
 *		to remove the value added in Circular Buffer and move the cb->tail
 *		forward and raise an exception if Circular Buffer is empty
 */
int circularBufferRemove(CircularBuffer *cb)
{
	int dataRemove;
	if(cb->size == 0)
		Throw(ERR_BUFFER_IS_EMPTY);
	
	dataRemove = *cb->tail;
	cb->tail++;
	cb->size--;
	
	return dataRemove;
}