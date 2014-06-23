#include "unity.h"
#include "GenericCircularBuffer.h"
#include "malloc.h"
#include "stdio.h"
#include "CException.h"
#include "CicularBufferInt.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_circularBufferNew_should_create_new_CircularBuffer_object_of_integer_type(void)
{
	CircularBuffer *cb = circularBufferNew(5, sizeof(int));
	
	TEST_ASSERT_NOT_NULL(cb);
	TEST_ASSERT_NOT_NULL(cb->buffer);
	TEST_ASSERT_EQUAL(5, cb->length);
	TEST_ASSERT_EQUAL(0, cb->size);
	TEST_ASSERT_EQUAL(sizeof(int), cb->sizeOfType);
	TEST_ASSERT_EQUAL_PTR(cb->buffer, cb->head);
	TEST_ASSERT_EQUAL_PTR(cb->buffer, cb->tail);
	
	circularBufferDel(cb);
}

void test_circularBufferNew_should_create_new_CircularBuffer_object_of_double_type(void)
{
	CircularBuffer *cb = circularBufferNew(5, sizeof(double));
	
	TEST_ASSERT_NOT_NULL(cb);
	TEST_ASSERT_NOT_NULL(cb->buffer);
	TEST_ASSERT_EQUAL(5, cb->length);
	TEST_ASSERT_EQUAL(0, cb->size);
	TEST_ASSERT_EQUAL(sizeof(double), cb->sizeOfType);
	TEST_ASSERT_EQUAL_PTR(cb->buffer, cb->head);
	TEST_ASSERT_EQUAL_PTR(cb->buffer, cb->tail);
	
	circularBufferDel(cb);
}

void test_circularBufferAdd_should_add_1_integer(void)
{
	CircularBuffer *cb = circularBufferNew(5, sizeof(int));
	int integer = 4;
	
	circularBufferAdd(cb, &integer, copyInt);
	
	TEST_ASSERT_NOT_NULL(cb);
	TEST_ASSERT_NOT_NULL(cb->buffer);
	TEST_ASSERT_EQUAL(5, cb->length);
	TEST_ASSERT_EQUAL(sizeof(int), cb->sizeOfType);
	TEST_ASSERT_EQUAL(1, cb->size);
	//printf("cb->buffer[0]: %d\n", *cb->buffer);
	// TEST_ASSERT_EQUAL(4, ((int *)cb->buffer)[0]);
	// TEST_ASSERT_EQUAL(5, ((int *)cb->buffer)[1]);
	TEST_ASSERT_EQUAL(4, *((int *)cb->head));
	TEST_ASSERT_EQUAL(4, *((int *)cb->tail));
	
	circularBufferDel(cb);
}

void test_circularBufferAdd_should_add_2_integer(void)
{
	CircularBuffer *cb = circularBufferNew(5, sizeof(int));
	int arrayInt[] = {5, 7};
	
	circularBufferAdd(cb, &arrayInt[0], copyInt);
	circularBufferAdd(cb, &arrayInt[1], copyInt);
	
	TEST_ASSERT_NOT_NULL(cb);
	TEST_ASSERT_NOT_NULL(cb->buffer);
	TEST_ASSERT_EQUAL(5, cb->length);
	TEST_ASSERT_EQUAL(sizeof(int), cb->sizeOfType);
	TEST_ASSERT_EQUAL(2, cb->size);
	TEST_ASSERT_EQUAL(7, *((int *)cb->head));
	TEST_ASSERT_EQUAL(5, *((int *)cb->tail));
	
	circularBufferDel(cb);
}