#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint16_t;
typedef signed int sint16_t;


sint16_t Binary_Search1(uint16_t Array[],uint16_t Req_data,uint16_t S_Index,uint16_t E_Index);
sint16_t Binary_Search2(uint16_t Array[],uint16_t Req_data,uint16_t S_Index,uint16_t E_Index);

uint16_t Array[10]={0,1,2,3,4,5,6,7,8,9};
uint16_t Ret;
int main()
{
   Ret=Binary_Search1(Array,6,0,9);
   printf("ret is %i\n",Ret);
   Ret=Binary_Search1(Array,15,0,9);
   printf("ret is %i\n",Ret);

    Ret=Binary_Search2(Array,6,0,9);
   printf("ret is %i\n",Ret);
   Ret=Binary_Search2(Array,15,0,9);
   printf("ret is %i\n",Ret);
    return 0;
}
sint16_t Binary_Search1(uint16_t Array[],uint16_t Req_data,uint16_t S_Index,uint16_t E_Index){
    uint16_t M_Index=0;

    while (S_Index<=E_Index)
        {
        M_Index=(S_Index+E_Index)/2;
    if (Array[M_Index]==Req_data)
    {
        return M_Index;
    }
    else if (Req_data<Array[M_Index])
    {
        E_Index=M_Index-1;
    }
    else
    {
        S_Index=M_Index+1;
    }



        }


return -1;
}
sint16_t Binary_Search2(uint16_t Array[],uint16_t Req_data,uint16_t S_Index,uint16_t E_Index){
uint16_t M_Index=0;

    while (S_Index<=E_Index)
        {
        M_Index=(S_Index+E_Index)/2;
    if (Array[M_Index]==Req_data)
    {
        return M_Index;
    }
    else if (Req_data<Array[M_Index])
    {

        return Binary_Search2(Array,Req_data,S_Index,M_Index-1);
    }
    else
    {
         return Binary_Search2(Array,Req_data,M_Index+1,E_Index);

    }



        }


return -1;
}
