#include "queue.h"
#include <assert.h>
#include <stdio.h>

void QueueCreateTest();
void QueueEnqueueTest();
void QueueDequeueTest();
void QueuePeekTest();
void QueueSizeTest();
void QueueIsEmptyTest();
void QueueAppendTest();


int main(void)
{
	QueueCreateTest();
	QueueEnqueueTest();
	QueueDequeueTest();
	QueuePeekTest();
	QueueSizeTest();
	QueueIsEmptyTest();
	QueueAppendTest();
	printf("\n\n->->->->->->->->-> success!!! <-<-<-<-<-<-<-<-<-<\n\n\n");
	
	return 0;
}

void QueueCreateTest()
{

	queue_ty *queue = QueueCreate();
	assert(NULL != queue);
	QueueDestroy(queue);

}

void QueueEnqueueTest()
{

	int i = 0;
	queue_ty *queue = QueueCreate();
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	
	for ( ; i < 10 ; ++i)
	{
		QueueEnqueue(queue , (void*)(arr + i));
	}

	assert(*((int*)QueuePeek(queue)) == 1);	
	QueueDestroy(queue);
	
}


void QueueDequeueTest()
{

	int i = 0;
	queue_ty *queue = QueueCreate();
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	QueueDequeue(queue);

	for ( ; i < 10 ; ++i)
	{
		QueueEnqueue(queue , (void*)(arr + i));
	}

	for (i = 0 ; i < 3 ; ++i)
	{
		QueueDequeue(queue);
	}	
	assert(*((int*)QueuePeek(queue)) == 4);
	QueueDestroy(queue);
}


void QueuePeekTest()
{
	double d = 3.587;
	char c = 36;
	queue_ty *queue = QueueCreate();
	QueueEnqueue(queue , (void*)&d);
	QueueEnqueue(queue , (void*)&c);
	assert(*((double*)QueuePeek(queue)) == 3.587);	
	QueueDestroy(queue);	
}

void QueueSizeTest()
{

	int i = 0;
	queue_ty *queue = QueueCreate();
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	assert(QueueSize(queue) == 0);	
	
	for ( ; i < 10 ; ++i)
	{
		QueueEnqueue(queue , (void*)(arr + i));
	}
	assert(QueueSize(queue) == 10);	
	QueueDestroy(queue);
	
}

void QueueIsEmptyTest()
{

	int i = 0;
	queue_ty *queue = QueueCreate();
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	assert(QueueIsEmpty(queue) == 1);	
	
	for ( ; i < 10 ; ++i)
	{
		QueueEnqueue(queue , (void*)(arr + i));
	}
	assert(QueueIsEmpty(queue) == 0);	
	QueueDestroy(queue);

}

void QueueAppendTest()
{
	int i = 0;
	queue_ty *queue1 = QueueCreate();
	queue_ty *queue2 = QueueCreate();
	
	int arr1[10] = {10,9,8,7,6,5,4,3,2,1};
	int arr2[10] = {20,19,18,17,16,15,14,13,12,11};
	
	for ( ; i < 10 ; ++i)
	{
		QueueEnqueue(queue1 , (void*)(arr1 + i));
	}

	for (i = 0 ; i < 10 ; ++i)
	{
		QueueEnqueue(queue2 , (void*)(arr2 + i));
	}	
	
	QueueAppend(queue1 , queue2);
	assert(*((int*)QueuePeek(queue1)) == 20);	
	QueueDestroy(queue1);
}


