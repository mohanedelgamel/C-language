#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint32_t;

uint32_t Array[10]={6,4,8,11,77,99,44,9,2,1};




void Swap_Numbers(uint32_t *pNUmber1,uint32_t *pNUmber2);
void Bubble_Sort(uint32_t Array[],uint32_t ArrayLength);
void DisplayArray(uint32_t Array[],uint32_t ArrayLength);


int main()
{

    Bubble_Sort(Array,10);
    DisplayArray(Array,10);


    return 0;
}
void Swap_Numbers(uint32_t *pNUmber1,uint32_t *pNUmber2)
{
    uint32_t Temp=*pNUmber1;
    *pNUmber1=*pNUmber2;
    *pNUmber2=Temp;
}
void Bubble_Sort(uint32_t Array[],uint32_t ArrayLength)
{
    uint32_t Iteration_Counter;
    uint32_t Comparision_Counter;
    uint32_t Flag=0;

    for (Iteration_Counter=0;Iteration_Counter<ArrayLength-1;Iteration_Counter++)
    {

        for (Comparision_Counter=0;Comparision_Counter<ArrayLength-1-Iteration_Counter;Comparision_Counter++)
            {
               if (Array[Comparision_Counter]>Array[Comparision_Counter+1])
               {
                   Swap_Numbers(&Array[Comparision_Counter],&Array[Comparision_Counter+1]);
                   Flag=1;


               }

            }

            if (Flag==0)
            {
              // break;
            }
    }

}
void DisplayArray(uint32_t Array[],uint32_t ArrayLength)
{
    uint32_t Counter=0;
    for (Counter=0;Counter<ArrayLength;Counter++)
    {
        printf("%i\t",Array[Counter]);
    }
    printf("\n");

}
