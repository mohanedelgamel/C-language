#ifndef _DOUBLE_LIST_H
#define _DOUBLE_LIST_H

#include<stdio.h>
#include<stdlib.h>

#include"Types.h"

typedef struct Node{
    uint32_t Data;
    struct Node *NextNode;
    struct Node *PreviousNode;
}Node_t;

void Insert_At_Beginning(Node_t **ListHead,uint32_t UserData);
void Insert_At_End(Node_t *ListHead,uint32_t UserData);
void Insert_After(Node_t **ListHead,uint32_t NodePosition,uint32_t UserData);
void Insert_Before(Node_t **ListHead,uint32_t NodePosition,uint32_t UserData);
void Delete_At_Beginning(Node_t **ListHead);
void Delete_AnyNode(Node_t *ListHead,uint32_t NodePosition);
void Display_forward(Node_t *ListHead);
void Display_Backward(Node_t *ListHead);
uint16_t List_Size(Node_t *ListHead);

#endif // _DOUBLE_LIST_H
