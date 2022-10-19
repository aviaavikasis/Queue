/*****************************************************   
 * Author : Avia Avikasis                            *
 * Reviewer: Ahron                                   *
 * 12/06/2022                                        *
 * Description : imlementation of queue              *
 *                                                   *
 *****************************************************/
 
#include <stdlib.h>   /* malloc */
#include <assert.h>
#include "queue.h"  
#include "slist.h"


struct queue
{
	struct slist *slist;
};

queue_ty *QueueCreate()
{
	queue_ty *queue = (queue_ty*)malloc(sizeof(queue_ty));
	if (NULL == queue)
	{
		return NULL;
	}
	queue -> slist = SlistCreate();
	return queue;
}

void QueueDestroy(queue_ty *queue)
{
	assert(NULL != queue);
	SlistDestroy(queue -> slist);
	free(queue);
	queue = NULL;
}

int QueueEnqueue(queue_ty *queue, void  *data)
{
	assert(NULL != queue);
	return (SlistInsertBefore(SlistBegin(queue -> slist) , data) == NULL);
}


void QueueDequeue(queue_ty *queue)
{	
	slist_iterator_ty iterator = NULL;
	assert(NULL != queue);
	iterator = SlistBegin(queue -> slist);
	
	if( SlistIterIsEqual( iterator , SlistEnd(queue -> slist)))
	{
		return;
	}
	
	while(SlistNext(iterator) != SlistEnd(queue -> slist))
	{
		iterator = SlistNext(iterator);
	}
	
	SlistRemove(iterator);
}


void *QueuePeek(const queue_ty *queue)
{
	slist_iterator_ty iterator = NULL;
	assert(NULL != queue);
	iterator = SlistBegin(queue -> slist);
	
	if( SlistIterIsEqual( iterator , SlistEnd(queue -> slist)))
	{
		return NULL;
	}
	while(!SlistIterIsEqual(SlistNext(iterator) , SlistEnd(queue -> slist)))
	{
		iterator = SlistNext(iterator);
	}
	return SlistGetData(iterator);
}


size_t QueueSize(const queue_ty *queue)
{
	assert(NULL != queue);
	return SlistSize(queue -> slist);
}

int QueueIsEmpty(const queue_ty *queue)
{
	assert(NULL != queue);
	return SlistIsEmpty(queue -> slist);
}

void QueueAppend(queue_ty *dest, queue_ty *src)
{
	assert(NULL != dest);
	assert(NULL != src);
	SlistAppend(dest -> slist , src -> slist);
}


















