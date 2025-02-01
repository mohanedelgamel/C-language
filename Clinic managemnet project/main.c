#include <stdio.h>
#include <unistd.h>
#include "user.h"
#include "admin.h"

Patient *Head_OF_Patient = NULL;
int main()
{
    while (1)
    {
        system("cls");
        int mode;
        int PassRes = 0;
        int Admin_choice;
        int user_choice;

        printf("                                              ***********************************************************\n");
        printf("                                              *********** WELCOME TO Clinic Management System ***********\n");
        printf("                                              ***********************************************************\n");
        sleep(2);
        printf("\n");
        printf("\n");
        printf("\n");
        printf("                                                                ____________________\n");
        printf("                                                               |     1-Admin mode   |\n");
        printf("                                                               |____________________|\n");
        printf("                                                               |     2-User mode    | \n");
        printf("                                                               |____________________| \n");
        printf("                                                               | 3-Exit the program |  \n");
        printf("                                                               |____________________|   \n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("        Enter the mode from the above list : ");
        scanf("%d", &mode);

        switch (mode)
        {
        default:
            printf("                          invalid number please enter 1 or 2 or 3 !!\n");
            sleep(3);
            break;
        case 1:
        {
            PassRes = Check_pass();
            if (PassRes == ValiPass)
            {
                system("cls");
                printf("                                              ***********************************************************\n");
                printf("                                              ************************ ADMIN MODE************************\n");
                printf("                                              ***********************************************************\n");
                sleep(2);
                printf("\n");
                printf("\n");
                printf("\n");
                printf("                                                                ______________________________ \n");
                printf("                                                               |      1-Add new patient       |\n");
                printf("                                                               | _____________________________|\n");
                printf("                                                               |     2-Edit patient info      |\n");
                printf("                                                               | _____________________________|\n");
                printf("                                                               | 3-Reserve a slot with doctor |\n");
                printf("                                                               | _____________________________|\n");
                printf("                                                               |     4-Cancel Reservation     |\n");
                printf("                                                               | _____________________________|\n");
                printf("                                                               |     5-Exit the program       |\n");
                printf("                                                               |______________________________|\n");
                printf("\n");
                printf("\n");
                printf("\n");

                printf("                                      Select From above list :");
                scanf("%d", &Admin_choice);

                switch (Admin_choice)
                {
                case 1:
                {
                    int resofadd = Add_Patient();
                    if (ADDED == resofadd)
                    {
                        printf("                                                               Patient added succeffly\n");
                        sleep(2);
                    }
                    else if (TOOMANYTrails == resofadd)
                    {
                        printf("                                                               Sorry too many trails !!\n");
                        sleep(2);
                    }
                    else
                    {
                        printf("                                                               Sorry ID exist :(\n");
                        sleep(2);
                    }
                    // system("cls");
                }
                break;
                case 2:
                {
                    int resofedit = Edit_Patient(Head_OF_Patient);
                    if (EDITTED == resofedit)
                    {
                        printf("                                                               Info Updated successfully\n");
                        sleep(2);
                    }
                    else if (E_TOOMANYTrails == resofedit)
                    {
                        printf("                                                               Too many trails !!\n");
                        sleep(2);
                    }
                    else
                    {
                        printf("                                                               ID not existed :( \n");
                        sleep(2);
                    }
                    // system("cls");
                }
                break;
                case 3:
                {
                    if (RESERVED == Reserve_Slot())
                    {
                        printf("                                                               Reserved  successfully\n");
                        sleep(2);
                    }
                    else
                    {
                        printf("                                                               failed to reserve \n");
                        sleep(2);
                    }
                    // system("cls");Cancel_Reservation()
                }
                break;
                case 4:
                {
                    if (CANCELLED == Cancel_Reservation())
                    {
                        printf("                                                               Cancelled succeffly\n");
                        sleep(2);
                    }
                    else
                    {
                        printf("                                                               failed to cancel \n");
                        sleep(2);
                    }
                    // system("cls");Cancel_Reservation()
                }
                break;
                case 5:
                    return 0;

                default:
                    printf("                                                               Invalid Number !!\n");
                    sleep(2);
                    break;
                }
            }
            else
            {
                printf("                                                               You entered 3 wrong trials !!\n");
                sleep(2);
            }
        }
        break;

        case 2:
        {
            system("cls");
            printf("                                              ***********************************************************\n");
            printf("                                              ************************ USER  MODE************************\n");
            printf("                                              ***********************************************************\n");
            sleep(2);
            printf("\n");
            printf("\n");
            printf("\n");
            printf("                                                                ___________________________ \n");
            printf("                                                               |      1-view my info       |\n");
            printf("                                                               |___________________________|\n");
            printf("                                                               |     2-view reservation    |\n");
            printf("                                                               |___________________________|\n");
            printf("                                                               |      3-Exit program       |\n");
            printf("                                                               |___________________________|\n");

            printf("\n");
            printf("\n");
            printf("\n");

            printf("                                                               Select From above list  :");
            scanf("%d", &user_choice);
            printf("\n");
            printf("\n");
            printf("\n");
            switch (user_choice)
            {
            case 1:
            {
                if (IDExistU == ViewPateint())
                {
                    sleep(1);
                    int exit;
                    printf("                                                               enter 1 to exit ");
                    scanf("%d", &exit);
                    while (exit != 1)
                    {
                        printf("                                                               enter 1 to exit ");
                        scanf("%d", &exit);
                    }
                }
                else
                {
                    printf("                                                               sorry ID not existed :( \n");
                    sleep(2);
                }
            }
            break;
            case 2:
            {
                View_Reservation();
                sleep(2);
                int exit;
                printf("                                                               enter 1 to exit ");
                scanf("%d", &exit);
                while (exit != 1)
                {
                    printf("                                                               enter 1 to exit ");
                    scanf("%d", &exit);
                }
            }
            break;
            case 3:
                return 0;
            default:
                printf("                                                               Invalid number \n");
                sleep(2);
            }
        }
        break;
        case 3:
            return 0;
        }
    }
    return 0;
}