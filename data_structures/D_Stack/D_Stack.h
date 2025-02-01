#ifndef _D_STACK_H
#define _D_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include"Types.h"

typedef struct d_stack{
   void ** Array;
   sint16_t Counter;
   sint16_t MaxSize;
   uint32_t Top;

}D_Stack_t;

typedef enum status{
    NOK,
    OK,
    STACK_FULL,
    STACK_EMPTY


}Status_t;

Status_t D_Stack_Init(D_Stack_t* Stack ,uint16_t GetSize);
Status_t D_Stack_Push(D_Stack_t* Stack ,uint16_t Value);
Status_t D_Stack_Pop(D_Stack_t* Stack ,uint16_t *Value);
Status_t D_Stack_Count(D_Stack_t* Stack);
Status_t D_Stack_Display(D_Stack_t* Stack);



#endif D_STACK_H // _D_STACK_H



