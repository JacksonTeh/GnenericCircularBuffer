#include "unity.h"
#include "stdio.h"
#include "CircularBuffer.h"
#include "CException.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_circularBufferNew_given_6_should_allocate_CircularBuffer_object_with_a_buffer_of_6(void)
{
	CircularBuffer *cb = circularBufferNew(6);
	
	TEST_ASSERT_NOT_NULL(cb);
	TEST_ASSERT_NOT_NULL(cb->buffer);
	TEST_ASSERT_EQUAL(6, cb->length);
	TEST_ASSERT_EQUAL(0, cb->size);
	TEST_ASSERT_EQUAL_PTR(cb->buffer, cb->head);
	TEST_ASSERT_EQUAL_PTR(cb->buffer, cb->tail);
	
	circularBufferDel(cb);
}

void test_circularBufferAdd_given_length_of_2_fill_with_value_should_raise_an_exception_if_add_more_than_2_value(void)
{
	CircularBuffer *cb = circularBufferNew(2);
	
	CEXCEPTION_T err;
	
	Try
	{
		circularBufferAdd(cb, 2);
		circularBufferAdd(cb, 5);
		circularBufferAdd(cb, 6);
	}Catch(err)
	{
		TEST_ASSERT_EQUAL(ERR_BUFFER_IS_FULL, err);
		printf("Success: Exception generated. Error code: %d.\n", err);
		circularBufferDel(cb);
	}
}

void test_circularBufferAdd_given_2_5_and_6_added_in_cb_where_6_should_be_head_and_2_should_be_tail(void)
{
	CircularBuffer *cb = circularBufferNew(3);

	circularBufferAdd(cb, 2);
	circularBufferAdd(cb, 5);
	circularBufferAdd(cb, 6);

	TEST_ASSERT_EQUAL(3, cb->size);
	TEST_ASSERT_EQUAL(6, *cb->head);
	TEST_ASSERT_EQUAL(2, *cb->tail);
	
	circularBufferDel(cb);
}

void test_circularBufferRemove_given_length_of_0_should_raise_an_exception(void)
{
	CircularBuffer *cb = circularBufferNew(0);
	
	CEXCEPTION_T err;
	
	Try
	{
		circularBufferRemove(cb);
	}Catch(err)
	{
		TEST_ASSERT_EQUAL(ERR_BUFFER_IS_EMPTY, err);
		printf("Success: Exception generated. Error code: %d.\n", err);
		circularBufferDel(cb);
	}
}

void test_circularBufferRemove_given_2_5_and_6_added_in_cb_where_2_remove_5_should_be_the_tail(void)
{
	int dataRemove;
	CircularBuffer *cb = circularBufferNew(3);

	circularBufferAdd(cb, 2);
	circularBufferAdd(cb, 5);
	circularBufferAdd(cb, 6);
	
	dataRemove = circularBufferRemove(cb);
	TEST_ASSERT_EQUAL(2, dataRemove);
	
	TEST_ASSERT_EQUAL(2, cb->size);
	TEST_ASSERT_EQUAL(6, *cb->head);
	TEST_ASSERT_EQUAL(5, *cb->tail);
	
	circularBufferDel(cb);
}

void test_circularBufferRemove_given_2_5_and_6_added_in_cb_where_2_and_5_remove_6_should_be_the_tail_and_head(void)
{
	int dataRemove;
	CircularBuffer *cb = circularBufferNew(3);

	circularBufferAdd(cb, 2);
	circularBufferAdd(cb, 5);
	circularBufferAdd(cb, 6);
	
	dataRemove = circularBufferRemove(cb);
	TEST_ASSERT_EQUAL(2, dataRemove);
	dataRemove = circularBufferRemove(cb);
	TEST_ASSERT_EQUAL(5, dataRemove);

	TEST_ASSERT_EQUAL(1, cb->size);
	TEST_ASSERT_EQUAL(6, *cb->head);
	TEST_ASSERT_EQUAL(6, *cb->tail);
	
	circularBufferDel(cb);
}

void test_circularBufferRemove_given_2_5_and_6_added_in_cb_where_2_remove_6_should_be_the_tail_and_add_4_where_4_should_be_head(void)
{
	int dataRemove;
	CircularBuffer *cb = circularBufferNew(3);

	circularBufferAdd(cb, 2);
	circularBufferAdd(cb, 5);
	circularBufferAdd(cb, 6);
	
	dataRemove = circularBufferRemove(cb);
	TEST_ASSERT_EQUAL(2, dataRemove);
	
	circularBufferAdd(cb, 4);

	TEST_ASSERT_EQUAL(3, cb->size);
	TEST_ASSERT_EQUAL(4, *cb->head);
	TEST_ASSERT_EQUAL(5, *cb->tail);
	
	circularBufferDel(cb);
}
