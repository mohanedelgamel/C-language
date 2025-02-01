
#include "Queue.h"

Queue_t *Queue_init(uint16_t Get_Max_Size,Queue_status_t *ReturnStat)
{
    Queue_t *Queue;
    Queue=(Queue_t*)malloc(sizeof(Queue_t));
    if (Queue==NULL)
    {
        *ReturnStat=NULL_POINTER;
        Queue=NULL;
    }
    else
        {
      Queue->Queue_Array=(void **)calloc(Get_Max_Size,sizeof(void*));
      if (Queue->Queue_Array==NULL)
    {
       *ReturnStat=NULL_POINTER;
         Queue=NULL;
    }
    else {
         Queue->QueueElement=0;
         Queue->Queue_Back=-1;
         Queue->Queue_Front=-1;
         Queue->MaxSize=Get_Max_Size;
        *ReturnStat=OK;
        }

        }
return Queue;
}

Queue_status_t Enqueue(Queue_t *Queue,void *GetValue){
   Queue_status_t Ret;

   if ((Queue==NULL)|| (GetValue==NULL))
   {
       Ret=NULL_POINTER;
   }
   else
   {
       if (Queue->QueueElement==Queue->MaxSize)
       {
           Ret=QUEUE_FULL;
       }
       else
       {
           (Queue->Queue_Back)++;
           if (Queue->QueueElement==ZERO)
           {
            (Queue->Queue_Front)++;
             Queue->Queue_Array[Queue->Queue_Back]= GetValue;
               Ret=OK;

           }
           else if (Queue->Queue_Back==Queue->MaxSize)
           {
               Queue->Queue_Back==0;
            Queue->Queue_Array[Queue->Queue_Back]= GetValue;
            Ret=OK;

           }
           else
            {
             Queue->Queue_Array[Queue->Queue_Back]= GetValue;
             Ret=OK;

            }
           (Queue->QueueElement)++;
       }
   }
   return Ret;
}
Queue_status_t Dequeue(Queue_t *Queue,void *GetValue)
{
  Queue_status_t Ret;
     if ((Queue==NULL)|| (GetValue==NULL))
   {
       Ret=NULL_POINTER;
   }
   else
   {
       if (Queue->QueueElement==ZERO)
       {
           Ret=QUEUE_EMPTY;
       }
       else
        {
            GetValue=Queue->Queue_Array[Queue->Queue_Front];

            if (Queue->QueueElement==1)
            {

              Queue->Queue_Back=-1;
              Queue->Queue_Front=-1;
              Queue->QueueElement=0;
              Ret=OK;
            }
            else if (Queue->Queue_Front==Queue->MaxSize-1)
            {

                Queue->Queue_Front=0;
                (Queue->QueueElement)--;
                Ret=OK;
            }
            else{
                (Queue->QueueElement)--;
                (Queue->Queue_Front)++;
                 Ret=OK;
            }
        }

   }
      printf("%i\n" ,GetValue);
return Ret;
}

Queue_status_t Queue_Size(Queue_t *Queue)
{

Queue_status_t Ret;
     if (Queue==NULL)
   {
       Ret=NULL_POINTER;
   }
   else
   {
   printf("number of existing element is (%i)\n",Queue->QueueElement);
   Ret=OK;
   }
   return Ret;
}
Queue_status_t Queue_Front(Queue_t *Queue,void *GetValue)
{
Queue_status_t Ret;
     if ((Queue==NULL)|| (GetValue==NULL))
   {
       Ret=NULL_POINTER;
   }
   else
   {
       if (Queue->QueueElement==ZERO)
       {
           Ret=QUEUE_EMPTY;
       }
       else
        {
            GetValue=Queue->Queue_Array[Queue->Queue_Front];
            Ret=OK;
        }
   return Ret;
}
}
Queue_status_t Queue_Back(Queue_t *Queue,void *GetValue)
{

 Queue_status_t Ret;

   if ((Queue==NULL)|| (GetValue==NULL))
   {
       Ret=NULL_POINTER;
   }
   else
   {
       if (Queue->QueueElement==ZERO)
       {
           Ret=QUEUE_EMPTY;
       }
       else
        {
        GetValue=Queue->Queue_Array[Queue->Queue_Back];
        Ret=OK;
        }
       }
       return Ret;
}
