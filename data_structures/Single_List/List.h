#ifndef _LIST_H_
#define _LIST_H_

#include<stdio.h>
#include<stdlib.h>
#include"Types.h"

typedef struct S_List{
    sint32_t Data;
    struct S_List *Link;
}S_List_t;



typedef enum {
    NOK,
    OK,
}List_status;


List_status Insert_At_Beginning(S_List_t **ListHead);  //Double pointer because i may change what the head point to
List_status Insert_At_End(S_List_t **ListHead);  //Double pointer because i may change what the head point to
List_status Insert_At_Middle(S_List_t *ListHead);// single pointer because i don't need to change the head
uint16_t List_Size(S_List_t *ListHead);
List_status List_Display(S_List_t *ListHead);
List_status Delete_At_Beginning(S_List_t **ListHead);
List_status Delete_Middle(S_List_t *ListHead);
void Insert_Node_After(S_List_t *List);



#endif // _LIST_H_




