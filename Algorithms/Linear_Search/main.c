#include <stdio.h>
#include <stdlib.h>

#include"Linear_Search.h"

uint32_t Array[10]={1,2,3,4,5,6,7,8,9,10};
uint32_t Ret;
int main()
{


    Ret=Linear_Search1(Array,10,6);
    printf("return index is %i\n",Ret);
    Ret=Linear_Search1(Array,10,15);
    printf("return index is %i\n",Ret);


    printf("-------------------------------\n");
     Ret=Linear_Search2(Array,10,6);
    printf("return index is %i\n",Ret);
    Ret=Linear_Search2(Array,10,15);
    printf("return index is %i\n",Ret);

    return 0;
}
