#include"Static_Stack_Array.h"
/*
 * @brief  : check whether stack is empty
 * @param  : stack_name
 * @retval : Status
*/

static Static_Stack_Array_Status_t Static_Stack_Array_Empty(Static_Stack_Array_t *Array)
{
uint16_t ret=STACK_EMPTY;
    if  ((Array==NULL) || (Array->Stack_pointer== -1) )
    {
        ret=STACK_EMPTY;

    }
    else
        {
            ret=STACK_NOTFULL;
        }


    return ret;

}
/*
 * @brief  : check whether stack is full
 * @param  : stack_name
 * @retval : Status
*/
static Static_Stack_Array_Status_t Static_Stack_Array_Full(Static_Stack_Array_t *Array){


 uint16_t ret=STACK_FULL;
    if  ((Array==NULL) || (Array->Stack_pointer==STACK_MAX_SIZE-1) )
    {
        ret=STACK_FULL;


    }
    else
        {
            ret=STACK_NOTFULL;

        }

    return ret;

}


/*
 * @brief : stack initialize
 * @param : stack_name
 * @retval : Status
*/
Ret_Status_t Static_Stack_Array_Init(Static_Stack_Array_t *Array)
{
    uint16_t ret=R_NOK;
    if  (Array==NULL)
    {
        ret=R_NOK;
        #ifdef STACK_DEBUG
        printf("Error !! can't init \n");
        #endif // STACK_DEBUG

    }
    else
        {
            Array->Stack_pointer=-1;
            ret=R_OK;
              #ifdef STACK_DEBUG
        printf(" init success \n");
        #endif // STACK_DEBUG
        }


    return ret;
}

/*
 * @brief  : push new element to the stack
 * @param  : stack_name
 * @param  : pushed_value
 * @retval : Status
*/
Ret_Status_t Static_Stack_Array_Push(Static_Stack_Array_t *Array,sint32_t Value)
{
    uint16_t ret=R_NOK;
    if   ((Array==NULL) || (Value==NULL)|| (Static_Stack_Array_Full(Array)==STACK_FULL) )
    {
        ret=R_NOK;
        #ifdef STACK_DEBUG
        printf("Error !! can't push full stack \n ");
        #endif // STACK_DEBUG

    }
    else
        {
            Array->Stack_pointer++;
            Array->Stack_Elements[Array->Stack_pointer]=Value;

              #ifdef STACK_DEBUG
        printf(" element (%i) pushed  \n",Value);
        #endif // STACK_DEBUG
        }


    return ret;

}
/*
 * @brief  : pop new element from the stack
 * @param  : stack_name
 * @param  :  get popped value
 * @retval : Status
*/
Ret_Status_t Static_Stack_Array_POP(Static_Stack_Array_t *Array,sint32_t *Value)
{
    uint16_t ret=R_NOK;
    if ((Array==NULL)||(Static_Stack_Array_Empty(Array)==STACK_EMPTY))
    {
        ret=R_NOK;
        #ifdef STACK_DEBUG
        printf("Error !! empty stack \n");
        #endif
    }
    else
        {
            *Value=Array->Stack_Elements[Array->Stack_pointer];
            Array->Stack_pointer--;
            #ifdef STACK_DEBUG
        printf("element (%i) is popped \n",*Value);
        #endif
        }

    return ret;
}

/*
 * @brief  : get the top elemnt
 * @param  : stack_name
 * @param  : get top value
 * @retval : Status
*/
Ret_Status_t Static_Stack_Array_Top(Static_Stack_Array_t *Array,sint32_t *Value)
{
    uint16_t ret=R_NOK;
    if ((Array==NULL)||(Static_Stack_Array_Empty(Array)==STACK_EMPTY))
    {
        ret=R_NOK;
        #ifdef STACK_DEBUG
        printf("Error !! empty stack \n");
        #endif
    }
    else
        {
            *Value=Array->Stack_Elements[Array->Stack_pointer];
            #ifdef STACK_DEBUG
        printf("element (%i) is on the top \n",*Value);
        #endif
        }

    return ret;
}

/*
 * @brief  : get the size of stack
 * @param  : stack_name
 * @retval : Status
*/
Ret_Status_t Static_Stack_Array_Size(Static_Stack_Array_t *Array)
{

uint16_t ret=R_NOK;
    if (Array==NULL)
    {
        ret=R_NOK;
        #ifdef STACK_DEBUG
        printf("Error !! wrong name \n");
        #endif
    }
    else
        {

        #ifdef STACK_DEBUG
        printf("stack size is (%i)  \n",Array->Stack_pointer+1);
        #endif
        }

    return ret;
}

/*
 * @brief  : Display stack elements
 * @param  : stack_name
 * @retval : Status
*/
Ret_Status_t Static_Stack_Array_Display(Static_Stack_Array_t *Array)
{
 uint16_t ret=R_NOK;
 sint16_t Counter=ZERO;
    if ((Array==NULL)||(Static_Stack_Array_Empty(Array)==STACK_EMPTY))
    {
        ret=R_NOK;
        #ifdef STACK_DEBUG
        printf("Error !! empty stack \n");
        #endif
    }
    else
        {
         for (Counter=Array->Stack_pointer;Counter>=ZERO;Counter--)
         {
             printf("element (%i) value is (%i) \t",Counter,
                                                    Array->Stack_Elements[Counter]);

         }
printf("\n-------------------------------\n");
        }

    return ret;
}
