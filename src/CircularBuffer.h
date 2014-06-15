#ifndef CircularBuffer_H
#define CircularBuffer_H

typedef enum {ERR_NO_ERROR, ERR_BUFFER_IS_FULL, ERR_BUFFER_IS_EMPTY} ErrorCode;

typedef struct
{
	int *head;
	int *tail;
	int size;
	int length;
	int *buffer;
}CircularBuffer;

CircularBuffer *circularBufferNew(int length);
void circularBufferDel(CircularBuffer *circularBuffer);
void circularBufferAdd(CircularBuffer *cb, int value2Add);
int circularBufferRemove(CircularBuffer *cb);

#endif // CircularBuffer_H