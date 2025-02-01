#include"Static_Stack_Array.h"

uint16_t ret=ZERO_INIT;
uint16_t Popped_val=ZERO_INIT;
Static_Stack_Array_t Stack1;
Static_Stack_Array_t Stack2;

int main()
{
    ret= Static_Stack_Array_Init(&Stack1);
    ret= Static_Stack_Array_Size(&Stack1);
    ret=Static_Stack_Array_Push(&Stack1,1);
    ret= Static_Stack_Array_Size(&Stack1);
    ret= Static_Stack_Array_Display(&Stack1);
     ret=Static_Stack_Array_Push(&Stack1,2);
    ret= Static_Stack_Array_Size(&Stack1);
    ret= Static_Stack_Array_Display(&Stack1);
     ret=Static_Stack_Array_Push(&Stack1,3);
    ret= Static_Stack_Array_Size(&Stack1);
    ret= Static_Stack_Array_Display(&Stack1);










    return 0;
}
