#include"List.h"

uint16_t List_Size(S_List_t *ListHead)
{

    S_List_t *ListCount=ListHead;
    uint16_t Counter=0;

    if (ListHead==NULL)
    {
        Counter=0;

    }
    else
       {

       while (ListCount!=NULL)
       {
           Counter++;
           ListCount=ListCount->Link;
       }

        }
    return Counter;
}

List_status Insert_At_Beginning(S_List_t **ListHead)
{
    S_List_t *TempNode=NULL;
    List_status Ret;

    TempNode=(S_List_t *)malloc(sizeof(S_List_t));
    if (TempNode==NULL)
    {
        Ret=NOK;
    }
    else
    {
        printf("enter the data :");
        scanf("%i",&TempNode->Data);
        if (*ListHead==NULL)
        {
            *ListHead=TempNode;
            TempNode->Link=NULL;
        }
        else
        {
            TempNode->Link=*ListHead;
            *ListHead=TempNode;
        }
        Ret=OK;
    }
    return Ret;
}
List_status Insert_At_End(S_List_t **ListHead)
{
    S_List_t *TempNode=NULL;
    S_List_t *ListCount=*ListHead;
    List_status Ret;

    TempNode=(S_List_t *)malloc(sizeof(S_List_t));
    if (TempNode==NULL)
    {
        Ret=NOK;
    }
    else
    {
        printf("enter the data :");
        scanf("%i",&TempNode->Data);
        if (*ListHead==NULL)
        {
            *ListHead=TempNode;
            TempNode->Link=NULL;
        }
        else
        {
            while (ListCount->Link!=NULL)
            {
                ListCount=ListCount->Link;
            }
            ListCount->Link=TempNode;
            TempNode->Link=NULL;

        }
        Ret=OK;
    }
    return Ret;
}

List_status Insert_At_Middle(S_List_t *ListHead)
{
    List_status Ret;
    S_List_t *TempNode=NULL;
    S_List_t *ListCount=NULL;
    uint16_t ElementPlace=0;
    uint16_t Counter=1;


    TempNode=(S_List_t *)malloc(sizeof(S_List_t));
    if (TempNode==NULL)
    {
        Ret=NOK;
    }
    else
    {

        printf("please enter the place:");
            scanf("%i",&ElementPlace);


        if (ElementPlace>List_Size(ListHead))
        {
            printf("Error ! OUT OF RANGE \n");
        }
        else
        {
            ListCount=ListHead;
             printf("enter the data :");
        scanf("%i",&TempNode->Data);

            while (Counter<ElementPlace)
            {
                Counter++;
                ListCount=ListCount->Link;

            }
            TempNode->Link=ListCount->Link;
            ListCount->Link=TempNode;

        }
      Ret=OK;
    }

    return Ret;
}


List_status List_Display(S_List_t *ListHead)
{
    List_status Ret;
   S_List_t *ListCount=ListHead;

    if (ListHead==NULL)
    {
        printf("Empty list\n");
       Ret=NOK;
    }
    else
       {

       while (ListCount!=NULL)
       {
           printf(" %i => ",ListCount->Data);
           ListCount=ListCount->Link;
       }

        Ret=NOK;
        }
    return Ret;
}

List_status Delete_At_Beginning(S_List_t **ListHead)
{
   List_status Ret;
   S_List_t *ListFirstElement=*ListHead;

    if (*ListHead==NULL)
    {
        printf("Empty list\n");
       Ret=NOK;
    }
    else
    {
         *ListHead=ListFirstElement->Link;
          free(ListFirstElement);
        Ret=OK;
    }

return Ret;
}
List_status Delete_Middle(S_List_t *ListHead)
{
    List_status Ret;
    S_List_t *ListCount=ListHead;
    S_List_t *NextNode=NULL;

    uint16_t ElementPlace=0;
    uint16_t GetSize=0;
    uint16_t Counter=1;
    GetSize = List_Size(ListHead);

    if (ListHead==NULL)
    {
        printf("Empty list\n");
        Ret=NOK;
    }
    else if (GetSize==1 )
    {
        printf("please use delete at the begging func. \n");
        Ret=NOK;
    }

    else
    {
        printf("please enter the place:");
        scanf("%i",&ElementPlace);

        if (ElementPlace>GetSize)
        {
            printf("Error ! OUT OF RANGE \n");
            Ret=NOK;
        }
        else
        {

            while (Counter<ElementPlace-1) //stop before the element wanted to be deleted
            {
                Counter++;
                ListCount=ListCount->Link;
            }
            NextNode=ListCount->Link;
            ListCount->Link=NextNode->Link;
            free(NextNode);
        }
        Ret=OK;

    }
}
void Insert_Node_After(S_List_t *List){
    S_List_t *TempNode = NULL;
    S_List_t *NodeListCounter = NULL;
    uint32_t NodePosition = 0;    /*  */
    uint32_t ListLength = 0;      /*  */
    uint32_t NodeCounter = 1;     /* Points to the first node */

    printf("Enter Node Position (First node is position = 1): ");
    scanf("%i", &NodePosition);


    if(NodePosition > List_Size(List)){
        printf("Invalid Node Position -> List has ( %i ) Nodes \n", ListLength);
    }
    else{
        NodeListCounter = List;
        while(NodeCounter < NodePosition){
            NodeCounter++;
            NodeListCounter = NodeListCounter->Link;
        } /* TempNode points to the node where we have to insert after it */
        TempNode = (S_List_t *)malloc(sizeof(S_List_t));
        if(NULL != TempNode){
            printf("Enter Node Data : ");
            scanf("%i", &TempNode->Data);
            /* Connect the right side connection */
            TempNode->Link = NodeListCounter->Link;
            /* Connect the Left side connection */
            NodeListCounter->Link = TempNode;
        }
        else{
            /* Nothing */
        }
    }
}

