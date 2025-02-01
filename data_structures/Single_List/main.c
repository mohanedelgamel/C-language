#include <stdio.h>
#include <stdlib.h>


#include"List.h"

uint16_t UserChoice;
uint16_t SizeOfLiSt;
S_List_t *Head=NULL;
List_status Ret;
int main()
{
   while (1)
   {

   printf("1- insert at the Beginning \n");
   printf("2- insert at the Middle \n");
   printf("3- insert at the End \n");
   printf("4- Delete at the Beginning \n");
   printf("5- Delete at the Middle \n");
   printf("6- show the size of list  \n");
   printf("7- Display list elements \n");
   printf("8- exist the Application \n");
    printf(" enter the number of operation :");
   scanf("%i",&UserChoice);
   printf("--------------------\n");

   switch(UserChoice){
   case 1 : {Ret=Insert_At_Beginning(&Head); break;}
   case 2 : {Insert_Node_After(Head);break;}
   case 3 : {Ret=Insert_At_End(&Head);break;}
   case 4 : {Ret=Delete_At_Beginning(&Head);break;}
   case 5 : {Ret=Delete_Middle(Head);break;}
   case 6 : {SizeOfLiSt=List_Size(Head);
             printf("list size is %i\n",SizeOfLiSt);
             break;}
   case 7 : {Ret=List_Display(Head);
             printf("NULL\n");
             break;}
   case 8 : {exit(1);break;}
   }
printf("--------------------\n");
   }
    return 0;
}
