#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

Queue_t *Queue1;
Queue_status_t RetStatus;
uint16_t Queue_SizeUSer;
void *DeqValue=NULL;
uint16_t number1=5, number2=6,number3=7,number4=8;


int main()
{
    printf("Enter the Queue size :");
    scanf("%d",&Queue_SizeUSer);


    Queue1=Queue_init(Queue_Size,&RetStatus);
    printf("RetStatus of init  is (%i)\n",RetStatus);



    RetStatus=Enqueue(Queue1,number1);
    printf("RetStatus of enqueue  is (%i)\n",RetStatus);

    RetStatus= Queue_Size(Queue1);
    printf("RetStatus of count  is (%i)\n",RetStatus);

    RetStatus=Enqueue(Queue1,number2);
    printf("RetStatus of enqueue  is (%i)\n",RetStatus);

    RetStatus=Queue_Front(Queue1,&DeqValue);
    printf("RetStatus of front  is (%i)\n",RetStatus);
    //printf("%i\n",*((uint16_t*)DeqValue));



    RetStatus= Queue_Size(Queue1);
    printf("RetStatus of count  is (%i)\n",RetStatus);
RetStatus=Enqueue(Queue1,number3);
    printf("RetStatus of enqueue  is (%i)\n",RetStatus);

    RetStatus= Queue_Size(Queue1);
    printf("RetStatus of count  is (%i)\n",RetStatus);



    RetStatus=Dequeue(Queue1,&DeqValue);
    printf("RetStatus of dequeue is (%i)\n",RetStatus);


    RetStatus=Dequeue(Queue1,&DeqValue);
    printf("RetStatus of dequeue is (%i)\n",RetStatus);



    return 0;
}
