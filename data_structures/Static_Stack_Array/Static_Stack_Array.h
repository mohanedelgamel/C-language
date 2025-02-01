#ifndef  _STATIC_STACK_ARRAY_H
#define _STATIC_STACK_ARRAY_H

#include <stdio.h>
#include <stdlib.h>

#include"Types.h"

#define STACK_MAX_SIZE 5

// struct to contain element and the pointer indicates

typedef struct Static_Stack_Array{
sint32_t Stack_pointer;
sint32_t Stack_Elements[STACK_MAX_SIZE];

}Static_Stack_Array_t;

//enum to contain stack status

typedef enum Static_Stack_Array_Status{
STACK_EMPTY,
STACK_FULL,
STACK_NOTFULL
}Static_Stack_Array_Status_t;

// enum to check return status

typedef enum Ret_Status{
R_OK,
R_NOK
}Ret_Status_t;

/*
 * @brief : stack initialize
 * @param : stack_name
 * @retval : Status

*/
Ret_Status_t Static_Stack_Array_Init(Static_Stack_Array_t *Array);

/*
 * @brief  : stack initialize
 * @param  : stack_name
 * @param  : pushed_value
 * @retval : Status

*/
Ret_Status_t Static_Stack_Array_Push(Static_Stack_Array_t *Array,sint32_t Value);
/*
 * @brief  : pop new element from the stack
 * @param  : stack_name
 * @param  :  get popped value
 * @retval : Status
*/
Ret_Status_t Static_Stack_Array_POP(Static_Stack_Array_t *Array,sint32_t *Value);
/*
 * @brief  : check whether stack is full
 * @param  : stack_name
 * @retval : Status
*/
static Static_Stack_Array_Status_t Static_Stack_Array_Full(Static_Stack_Array_t *Array);
/*
 * @brief  : check whether stack is empty
 * @param  : stack_name
 * @retval : Status
*/
static Static_Stack_Array_Status_t Static_Stack_Array_Empty(Static_Stack_Array_t *Array);
/*
 * @brief  : get the top element
 * @param  : stack_name
 * @param  : get top value
 * @retval : Status
*/
Ret_Status_t Static_Stack_Array_Top(Static_Stack_Array_t *Array,sint32_t *Value);
/*
 * @brief  : get the size of stack
 * @param  : stack_name
 * @retval : Status
*/
Ret_Status_t Static_Stack_Array_Size(Static_Stack_Array_t *Array);
/*
 * @brief  : Display stack elements
 * @param  : stack_name
 * @retval : Status
*/
Ret_Status_t Static_Stack_Array_Display(Static_Stack_Array_t *Array);




#endif
