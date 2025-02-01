#include <stdio.h>
#include <stdlib.h>
#include"D_Stack.h"

D_Stack_t Stack1;
uint16_t Size;
Status_t ret;
uint16_t return_value;



int main()
{
    printf("enter the size of array :");
    scanf("%i",&Size);
    ret=D_Stack_Init(&Stack1,Size);


    printf("return state of init  is (%i)\n",ret);
    ret=D_Stack_Push(&Stack1,11);
      printf("return state of push  is (%i)\n",ret);
    ret=D_Stack_Push(&Stack1,13);
    printf("return state of push is (%i)\n",ret);
    ret=D_Stack_Push(&Stack1,15);
      printf("return state of push  is (%i)\n",ret);
    ret=D_Stack_Count(&Stack1);
      printf("return state of count is (%i)\n",ret);

      ret=D_Stack_Push(&Stack1,11);
      printf("return state of push  is (%i)\n",ret);
    ret=D_Stack_Push(&Stack1,13);
    printf("return state of push is (%i)\n",ret);
    ret=D_Stack_Push(&Stack1,15);
      printf("return state of push  is (%i)\n",ret);
    ret=D_Stack_Count(&Stack1);
      printf("return state of count is (%i)\n",ret);
    //ret=D_Stack_Display(&Stack1);
    // printf("return state is of display (%i)\n",ret);
      printf("-------------------------\n");

    ret=D_Stack_Pop(&Stack1,&return_value);
    printf("return state is (%i)\n",ret);

    ret=D_Stack_Pop(&Stack1,&return_value);
    printf("return state is (%i)\n",ret);
    ret=D_Stack_Pop(&Stack1,&return_value);
    printf("return state is (%i)\n",ret);

    ret=D_Stack_Count(&Stack1);
      printf("return state is (%i)\n",ret);
    //ret=D_Stack_Display(&Stack1);
    // printf("return state is (%i)\n",ret);



    return 0;
}
