#include "Linear_Search.h"

uint32_t Linear_Search1(uint32_t Array[],uint32_t ArrayLength,uint32_t Req_data){
    uint32_t Index =0;
    for (Index=0;Index<ArrayLength;Index++)
    {
        if (Array[Index]==Req_data)
        {
            return Index;
        }
    }
   return -1 ;
}
uint32_t Linear_Search2(uint32_t Array[],uint32_t ArrayLength,uint32_t Req_data){
     uint32_t Left_Index =0;
     uint32_t Right_Index=ArrayLength-1;
    for (Left_Index=0;Left_Index<=Right_Index;)
    {
        if (Array[Left_Index]==Req_data)
        {
            return Left_Index;
        }else{
            /*  nothing*/
            };
          if (Array[Right_Index]==Req_data)
        {
            return Right_Index;
        }else
        {
            /*  nothing*/
        };

        Left_Index++;
        Right_Index--;
    }
   return -1 ;
}

