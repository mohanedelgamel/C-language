#include "Double_List.h"

Node_t *ListHead1=NULL;
uint16_t TotalNumber=0;
int main()
{

    Insert_At_Beginning(&ListHead1,33);
    Insert_At_Beginning(&ListHead1,22);
    Insert_At_Beginning(&ListHead1,11);
    Insert_At_End(ListHead1,44);
    Insert_At_End(ListHead1,55);
    Display_forward(ListHead1);
    Display_Backward(ListHead1);
    Delete_At_Beginning(&ListHead1);
    Display_forward(ListHead1);
    Insert_After(&ListHead1,17,33);
    Display_forward(ListHead1);

    return 0;
}
