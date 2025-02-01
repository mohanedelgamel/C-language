#include "Double_List.h"

void Insert_At_Beginning(Node_t **ListHead,uint32_t UserData){
    Node_t *TempNode=NULL;
    TempNode=(Node_t *)malloc(sizeof(Node_t));
    if (TempNode!=NULL)
    {
        TempNode->Data=UserData;
        if (*ListHead==NULL) // if the list is empty
        {
            TempNode->PreviousNode=NULL;
            *ListHead=TempNode;
            TempNode->NextNode=NULL;

        }
        else //if the list contain one node or more
        {
              TempNode->PreviousNode=NULL;
              TempNode->NextNode=*ListHead;
              (*ListHead)->PreviousNode=TempNode;
              (*ListHead)=TempNode;
        }

    }
    else
    {
        printf("Error can't store in the heap\n");
    }

}
void Insert_At_End(Node_t *ListHead,uint32_t UserData){
   Node_t *TempNode=NULL;
   Node_t *NodeCounter=ListHead;
    TempNode=(Node_t *)malloc(sizeof(Node_t));
    if (TempNode!=NULL)
    {

    if (ListHead==NULL) // if the list is empty
        {
          printf("please use Insert at the begging \n");

        }
        else //if the list contain one node or more
        {
            while(NodeCounter->NextNode!=NULL)
            {
                NodeCounter=NodeCounter->NextNode;
            }
            NodeCounter->NextNode=TempNode;
            TempNode->PreviousNode=NodeCounter;
            TempNode->NextNode=NULL;
            TempNode->Data=UserData;

        }
    }
    else
    {
        printf("Error can't store in the heap\n");
    }

}
void Insert_After(Node_t **ListHead,uint32_t NodePosition,uint32_t UserData){
    Node_t *TempNode=NULL;
    Node_t *NodeCounterPrev=*ListHead;
    Node_t *NodeCounterNext=NULL;
    uint16_t CounterPosition=1;
    TempNode=(Node_t *)malloc(sizeof(Node_t));
    if (TempNode!=NULL)
    {

    if (*ListHead==NULL) // if the list is empty
        {
        printf("Item inserted but use insert at the beginning function next time \n");
        Insert_At_Beginning(ListHead,UserData);
        }
         else if (NodePosition>List_Size(ListHead))
        {
        printf("Error Out OF Range!!  \n");

        }

        else //if the list contain one node or more
        {
            while (CounterPosition<NodePosition)
            {
                NodeCounterPrev=NodeCounterPrev->NextNode;
                CounterPosition++;
            }
            NodeCounterNext=NodeCounterPrev->NextNode;

            if (NodeCounterPrev->NextNode==NULL)
            {
                printf("Item inserted but use insert at end function next time \n");
                Insert_At_End(*ListHead,UserData);
            }
            else
            {
                NodeCounterPrev->NextNode=TempNode;
                NodeCounterNext->PreviousNode=TempNode;
                TempNode->PreviousNode=NodeCounterPrev;
                TempNode->NextNode=NodeCounterNext;
                TempNode->Data=UserData;
            }
         }
    }
    else
    {
        printf("Error can't store in the heap\n");
    }

}
void Insert_Before(Node_t **ListHead,uint32_t NodePosition,uint32_t UserData){
    Node_t *TempNode=NULL;
    Node_t *NodeCounterPrev=NULL;
    Node_t *NodeCounterNext=*ListHead;
    uint16_t CounterPosition=1;
    TempNode=(Node_t *)malloc(sizeof(Node_t));
    if (TempNode!=NULL)
    {

    if (*ListHead==NULL) // if the list is empty
        {
           printf("Item inserted but use insert at the beginning function next time \n");
           Insert_At_Beginning(ListHead,UserData);

        }
        else if (NodePosition>List_Size(ListHead))
        {
        printf("Error Out OF Range!!  \n");

        }
        else //if the list contain one node or more
        {
            while (CounterPosition<NodePosition)
            {
                NodeCounterNext=NodeCounterNext->NextNode;
                CounterPosition++;
            }
            NodeCounterPrev=NodeCounterNext->PreviousNode;

            if (NodePosition==1)
            {
                printf("Item inserted but use insert at the beginning function next time \n");
                Insert_At_Beginning(ListHead,UserData);
            }
            else
            {
                NodeCounterPrev->NextNode=TempNode;
                NodeCounterNext->PreviousNode=TempNode;
                TempNode->PreviousNode=NodeCounterPrev;
                TempNode->NextNode=NodeCounterNext;
                TempNode->Data=UserData;
            }
    }
    }
    else
    {
        printf("Error can't store in the heap\n");
    }
}
void Delete_At_Beginning(Node_t **ListHead){
    /* Without using Pointer    */
    *ListHead=(*ListHead)->NextNode;
    free((*ListHead)->PreviousNode);
    (*ListHead)->PreviousNode=NULL;

}
void Delete_AnyNode(Node_t *ListHead,uint32_t NodePosition){
    Node_t *NodeCounter=ListHead;
    Node_t *NodeCounterPrev=NULL;
    uint16_t PositionCounter=NodePosition;
    if (ListHead==NULL)
    {
        printf("empty list \n");
    }
    else{

    if (NodePosition==1)
    {
        printf("use delete at beginning\n");
    }
    else if (NodePosition>List_Size(ListHead))
        {
        printf("Error Out OF Range!!  \n");

        }
    else
    {



        while (PositionCounter>1)
        {
            NodeCounter=NodeCounter->NextNode;
            PositionCounter--;
        }

        if (NodeCounter->NextNode==NULL)
        {
            NodeCounter->PreviousNode->NextNode=NULL;
            free(NodeCounter);

        }
        else
            {
        NodeCounterPrev=NodeCounter->PreviousNode;
        NodeCounterPrev->NextNode=NodeCounter->NextNode;
        NodeCounter->NextNode->PreviousNode= NodeCounterPrev;
        free(NodeCounter);
        NodeCounter=NULL;
            }

    }

    }


}
void Display_forward(Node_t *ListHead){
    Node_t *NodeCounter=ListHead;
    printf("-------------------------------\n");
    printf("Data Forward : ");
    printf(" %i => ",NodeCounter->Data);
    while(NodeCounter->NextNode!=NULL)
    {
        NodeCounter=NodeCounter->NextNode;
        printf(" %i => ",NodeCounter->Data);
    }
    printf(" NULL\n");
    printf("-------------------------------\n");

}
void Display_Backward(Node_t *ListHead){

Node_t *NodeCounter=ListHead;
 while(NodeCounter->NextNode!=NULL)
    {
        NodeCounter=NodeCounter->NextNode;
    }
    printf("-------------------------------\n");
    printf("Data Backward : ");
     printf(" NULL");
    printf(" =< %i ",NodeCounter->Data);
    while(NodeCounter->PreviousNode!=NULL)
    {
        NodeCounter=NodeCounter->PreviousNode;
        printf(" <= %i  ",NodeCounter->Data);
    }
    printf("\n");
    printf("-------------------------------\n");

}
uint16_t List_Size(Node_t *ListHead){
    uint16_t NodeCounter1=1;
    Node_t *NodeCounter=ListHead;

    while(NodeCounter->NextNode!=NULL)
    {
        NodeCounter=NodeCounter->NextNode;
        NodeCounter1++;
    }
    printf("number of nodes is %i \n",NodeCounter1);
return NodeCounter1;
}
