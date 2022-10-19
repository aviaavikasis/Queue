#ifndef __ILRD_OL127_128_QUEUE_H__
#define __ILRD_OL127_128_QUEUE_H__

#include <stddef.h> /* size_t */

typedef struct queue queue_ty;

queue_ty *QueueCreate(void);

void QueueDestroy(queue_ty *queue); 

int QueueEnqueue(queue_ty *queue, void  *data);

void QueueDequeue(queue_ty *queue);

void *QueuePeek(const queue_ty *queue);

size_t QueueSize(const queue_ty *queue);

int QueueIsEmpty(const queue_ty *queue);

void QueueAppend(queue_ty *dest, queue_ty *src);

#endif /* __ILRD_OL127_128_QUEUE_H__ */
