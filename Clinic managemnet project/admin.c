#include "admin.h"

#define NumberOFSolts 5
#define Stored_pass 1234
#define number_of_trails 3
extern Patient *Head_OF_Patient;
int Entered_pass = 0;
int Slots[NumberOFSolts][1] = {{0},
                               {0},
                               {0},
                               {0},
                               {0}

};

PASS Check_pass()
{
    for (int i = 0; i < number_of_trails; i++)
    {
        printf("                                                      Please Enter the Password:");
        scanf("%d", &Entered_pass);
        if (Entered_pass == Stored_pass)
        {
            printf("\n");
            printf("                                                         welcome admin to the system :) \n");
            sleep(2);
            return ValiPass;
        }
        else if (i != number_of_trails - 1)
        {
            printf("\n");
            sleep(1);
            printf("                                                         sorry wrong passowrd ): \n");
            printf("\n");
        }
    }
    return InvalidPAss;
}
ID ID_CHECK(int ID)
{
    Patient *Current = Head_OF_Patient;
    while (Current != NULL)
    {
        if (Current->ID == ID)
        {

            return IDExist;
        }
        Current = Current->Next;
    }
    return IDNotExist;
}
ADD Add_Patient()
{
    int count = 0;
    Patient *NewPatient = (Patient *)malloc(sizeof(Patient));
    NewPatient->Next = NULL;
    Patient *Current = Head_OF_Patient;
    if (Head_OF_Patient == NULL)
    {
        Head_OF_Patient = NewPatient;
        NewPatient->Prev = NULL;
        printf("                                                               Enter the ID of Patient Started from (1) : ");
        scanf("%d", &NewPatient->ID);
        fflush(stdin);
        if (NewPatient->ID <= 0)
        {
            free(NewPatient);
            return NOTADDED;
        }

        printf("                                                               Enter the Name of Patient : ");
        scanf("%s", &NewPatient->Name);
        fflush(stdin);

        printf("                                                               Enter the age of Patient : ");
        scanf("%d", &NewPatient->Age);
        fflush(stdin);

        while (count < 3)
        {

            printf("                                                               Enter the Gender of Patient ('M' or 'F') : ");
            scanf("%c", &NewPatient->Gender);
            fflush(stdin);
            if ((NewPatient->Gender == 'f') || NewPatient->Gender == 'F' || (NewPatient->Gender == 'm') || (NewPatient->Gender == 'M'))
            {
                break;
            }
            else
            {
                printf("                                                               Invalid gender !!\n");
            }
            count++;
        }
        if (count >= 3)
        {
            free(NewPatient);
            return TOOMANYTrails;
        }
    }
    else
    {
        printf("                                                               Enter the ID of Patient Started from (1) : ");
        scanf("%d", &NewPatient->ID);
        fflush(stdin);
        if (IDExist == ID_CHECK(NewPatient->ID))
        {

            return NOTADDED;
        }
        if (NewPatient->ID <= 0) // Check if id greater than 0
        {
            free(NewPatient);
            return NOTADDED;
        }

        printf("                                                               Enter the Name of Patient : ");
        scanf("%s", &NewPatient->Name);
        fflush(stdin);

        printf("                                                               Enter the age of Patient : ");
        scanf("%d", &NewPatient->Age);
        fflush(stdin);

        while (count < 3)
        {

            printf("                                                               Enter the Gender of Patient ('M' or 'F') : ");
            scanf("%c", &NewPatient->Gender);
            fflush(stdin);
            if ((NewPatient->Gender == 'f') || NewPatient->Gender == 'F' || (NewPatient->Gender == 'm') || (NewPatient->Gender == 'M'))
            {
                break;
            }
            else
            {
                printf("                                                               Invalid gender !!\n");
            }

            count++;
        }
        if (count >= 3)
        {
            free(NewPatient);
            return TOOMANYTrails;
        }

        while (Current->Next != NULL)
        {
            Current = Current->Next;
        }
        Current->Next = NewPatient;
        NewPatient->Prev = Current;
    }
    return ADDED;
}
EDIT Edit_Patient(Patient *Head_OF_Patient)
{
    int count = 0;
    Patient *Current = Head_OF_Patient;
    int compared_ID;
    printf("                                                               Enter ID of Patient to be eddited : ");
    scanf("%d", &compared_ID);
    while (Current != NULL)
    {
        if (Current->ID == compared_ID)
        {

            printf("                                                               Enter the Name of Patient : ");
            scanf("%s", &Current->Name);
            fflush(stdin);

            printf("                                                               Enter the age of Patient : ");
            scanf("%d", &Current->Age);
            fflush(stdin);

            return EDITTED;
        }
        Current = Current->Next;
    }

    return NOTEDITTED;
}

ISRESERVED Reserve_Slot()
{
    int EnteredID = 0;
    printf("                                                               Enter the ID of patient to reserve : ");
    scanf("%d", &EnteredID);

    if (ID_CHECK(EnteredID) == IDNotExist)
    {
        printf("                                                               Invalid ID :(\n");
        return NOTRESERVED;
    }
    else
    {
        int Choice;

        printf("                                                               Avalable slot :\n");
        if (Slots[0][0] == 0)
        {
            printf("                                                               ______________________\n");
            printf("                                                              | 1-From 2pm to 2:30pm | \n");
        }
        if (Slots[1][0] == 0)
        {
            printf("                                                               ______________________\n");
            printf("                                                              | 2-From 2:30pm to 3pm | \n");
        }
        if (Slots[2][0] == 0)
        {
            printf("                                                               ______________________\n");
            printf("                                                              | 3-From 3pm to 3:30pm | \n");
        }
        if (Slots[3][0] == 0)
        {
            printf("                                                               ______________________\n");
            printf("                                                              | 4-From 4pm to 4:30pm | \n");
        }
        if (Slots[4][0] == 0)
        {
            printf("                                                               ______________________\n");
            printf("                                                              | 5-From 4:30pm to 5pm | \n");
        }
        printf("                                                               ______________________ \n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("                                                               Enter desired slot : ");
        scanf("%d", &Choice);

        switch (Choice)
        {
        case 1:
        {
            if (Slots[0][0] == 0)
            {
                Slots[0][0] = EnteredID;
                return RESERVED;
            }
            else
            {
                printf("                                                               Unavailble slot !! \n");
                return NOTRESERVED;
            }
        }

        break;

        case 2:
        {
            if (Slots[1][0] == 0)
            {
                Slots[1][0] = EnteredID;
                return RESERVED;
            }
            else
            {
                printf("                                                               Unavailble slot !! \n");
                return NOTRESERVED;
            }
        }

        break;
        case 3:
        {
            if (Slots[2][0] == 0)
            {
                Slots[2][0] = EnteredID;
                return RESERVED;
            }
            else
            {
                printf("                                                               Unavailble slot !! \n");
                return NOTRESERVED;
            }
        }

        break;
        case 4:
        {
            if (Slots[3][0] == 0)
            {
                Slots[3][0] = EnteredID;
                return RESERVED;
            }
            else
            {
                printf("                                                               Unavailble slot !! \n");
                return NOTRESERVED;
            }
        }

        break;
        case 5:
        {
            if (Slots[4][0] == 0)
            {
                Slots[4][0] = EnteredID;
                return RESERVED;
            }
            else
            {
                printf("                                                               slot Reserved !! \n");
                return NOTRESERVED;
            }
        }

        break;

        default:
            printf("                                                               Invalid slot !!\n");
            return NOTRESERVED;
            break;
        }
    }
}

ISCANCELLED Cancel_Reservation()
{
    int EnteredID = 0;
    printf("                                                               Enter the ID : ");
    scanf("%d", &EnteredID);

    if (ID_CHECK(EnteredID) == IDNotExist)
    {
        printf("                                                               Invalid ID :(\n");
        return NOTCANCELLED;
    }
    else
    {
        for (int i = 0; i < NumberOFSolts; i++)
        {
            if (Slots[i][0] == EnteredID)
            {
                Slots[i][0] = 0;
                return CANCELLED;
            }
        }
        printf("                                                               No Reservation For This Patient \n");
        return NOTCANCELLED;
    }
}