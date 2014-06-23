#ifndef GenericCircularBuffer_H
#define GenericCircularBuffer_H

typedef enum {ERR_NO_ERROR, ERR_BUFFER_IS_FULL, ERR_BUFFER_IS_EMPTY} ErrorCode;

typedef struct
{
	void *head;
	void *tail;
	int size;
	int sizeOfType;
	int length;
	void *buffer;
}CircularBuffer;

CircularBuffer *circularBufferNew(int length, int sizeOfType);
void circularBufferDel(CircularBuffer *cb);
void circularBufferAdd(CircularBuffer *cb, void *obj, void (*copy)(void *, void *));
void circularBufferRemove(CircularBuffer *cb, void *obj, void (*copy)(void *, void *));
int circularBufferIsFull(CircularBuffer *cb);
int circularBufferIsEmpty(CircularBuffer *cb);

#endif // GenericCircularBuffer_H
