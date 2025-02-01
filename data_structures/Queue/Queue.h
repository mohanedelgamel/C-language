
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdlib.h>

#include "Types.h"

typedef struct Queue{
    void **Queue_Array;
    uint16_t MaxSize;
    uint16_t QueueElement;
    sint16_t Queue_Front;
    sint16_t Queue_Back;
}Queue_t;

typedef enum {
    NULL_POINTER,
    OK,
    QUEUE_EMPTY,
    QUEUE_FULL
}Queue_status_t;

Queue_t *Queue_init(uint16_t Get_Max_Size,Queue_status_t *ReturnStat);
Queue_status_t Enqueue(Queue_t *Queue,void *GetValue);
Queue_status_t Dequeue(Queue_t *Queue,void *GetValue);

Queue_status_t Queue_Size(Queue_t *Queue);
Queue_status_t Queue_Front(Queue_t *Queue,void *GetValue);
Queue_status_t Queue_Back(Queue_t *Queue,void *GetValue);















#endif
