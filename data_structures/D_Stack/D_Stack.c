
#include"D_Stack.h"




Status_t D_Stack_Init(D_Stack_t *Stack ,uint16_t GetSize)
{
    Status_t ret=NOK;

    if (NULL==Stack)
    {

        ret=NOK;
    }
    else
    {
       Stack->Array=(void**) calloc(GetSize,sizeof(void*));
       Stack->Top=-1;
       Stack->Counter=0;
       Stack->MaxSize=GetSize;
       ret=OK;

       if (!Stack->Array)   //check if memory allocated successfully or not
       {
         ret=NOK;
       }
       else
        {
           ret=OK;
        }
    }

return ret;
}

Status_t D_Stack_Push(D_Stack_t *Stack ,uint16_t Value){

  Status_t ret=NOK;
     if ((NULL==Stack)||(Stack->Counter==Stack->MaxSize))
    {

        ret=NOK;
    }
    else
    {
        (Stack->Top)++;
        (Stack->Counter)++;
        Stack->Array[Stack->Top]=Value;

    ret=OK;
    }


    return ret;
}
Status_t D_Stack_Pop(D_Stack_t* Stack ,uint16_t *Value){
     Status_t ret=NOK;
     if ((NULL==Stack)||(Stack->Top==-1))
    {

        ret=NOK;
    }
    else
    {
       (Stack->Counter)--;
       *Value= Stack->Array[Stack->Top];
       (Stack->Top)--;

    ret=OK;
    }


    return ret;

}
Status_t D_Stack_Count(D_Stack_t* Stack){
    Status_t ret=NOK;

    if (NULL==Stack)
    {

        ret=NOK;
    }
    else{
    printf("number of element is (%i)\n",Stack->Counter);
    ret=OK;
    }
    return ret;
}
Status_t D_Stack_Display(D_Stack_t* Stack){
   Status_t ret=NOK;
   uint16_t counter=0;

    if (NULL==Stack)
    {

        ret=NOK;
    }
    else{
            for (counter=Stack->Top;counter>=ZERO;counter--){
    printf("element (%i) equals (%i) \t",counter,Stack->Array[counter]);
            }
            printf("\n------------------------------------\n");

    ret=OK;
    }

    return ret;

}







