#include "user.h"
#include "admin.h"
#define NumberOFSolts 5

extern Patient *Head_OF_Patient;
extern int Slots[NumberOFSolts][1];

IDu ViewPateint()
{
    Patient *Current = Head_OF_Patient;
    int compared_ID;
    printf("                                                               Enter ID of Patient to be viewed:");
    scanf("%d", &compared_ID);
    printf("\n");
    printf("\n");
    if (ID_CHECK(compared_ID) == IDExist)
    {
        while (Current != NULL)
        {
            if (Current->ID == compared_ID)
            {
                printf("                                                               ID of Patient : %d\n", Current->ID);
                printf("\n");
                printf("                                                               Name of Patient : %s\n", Current->Name);
                printf("\n");
                printf("                                                               Age of Patient : %d\n", Current->Age);
                printf("\n");
                printf("                                                               Gender of Patient : %c\n", Current->Gender);
                printf("\n");

                return IDExistU;
            }
            Current = Current->Next;
        }
    }
    else
    {
        return IDNotExistU;
    }
}

void View_Reservation()
{

    printf("                                                  ----------------------  Slots of the day ----------------------  \n");
    printf("\n");
    printf("\n");
    if (Slots[0][0] == 0)
    {
        printf("                                                               1-From 2pm to 2:30pm ---> Not reserved \n");
        printf("\n");
    }
    else
    {
        printf("                                                               1-From 2pm to 2:30pm ---> Patient ID: %d \n", Slots[0][0]);
        printf("\n");
    }
    if (Slots[1][0] == 0)
    {
        printf("                                                               2-From 2:30pm to 3pm ---> Not reserved \n");
        printf("\n");
    }
    else
    {
        printf("                                                               2-From 2:30pm to 3pm ---> Patient ID: %d \n", Slots[1][0]);
        printf("\n");
    }

    if (Slots[2][0] == 0)
    {
        printf("                                                               3-From 3pm to 3:30pm ---> Not reserved \n");
        printf("\n");
    }
    else
    {
        printf("                                                               3-From 3pm to 3:30pm ---> Patient ID: %d \n", Slots[2][0]);
        printf("\n");
    }
    if (Slots[3][0] == 0)
    {
        printf("                                                               4-From 4pm to 4:30pm ---> Not reserved \n");
        printf("\n");
    }
    else
    {
        printf("                                                               4-From 4pm to 4:30pm ---> Patient ID: %d \n", Slots[3][0]);
        printf("\n");
    }
    if (Slots[4][0] == 0)
    {
        printf("                                                               5-From 4:30pm to 5pm ---> Not reserved \n");
        printf("\n");
    }
    else
    {
        printf("                                                               5-From 4:30pm to 5pm ---> Patient ID: %d \n", Slots[4][0]);
        printf("\n");
    }
}