#include <stdio.h>
#include <stdlib.h>
typedef unsigned int uint32_t;

uint32_t Array[10]= {6,4,8,11,77,99,44,9,2,1};


void Swap_Numbers(uint32_t *pNUmber1,uint32_t *pNUmber2);
void Selection_Sort(uint32_t Array[],uint32_t ArrayLength);
void DisplayArray(uint32_t Array[],uint32_t ArrayLength);


int main()
{
    DisplayArray(Array,10);
    Selection_Sort(Array,10);
    DisplayArray(Array,10);


    return 0;
}

void Selection_Sort(uint32_t Array[],uint32_t ArrayLength)
{
    uint32_t Iterator=0;
    uint32_t Comparetor=0;
    uint32_t Minimum_Index=0;

    for (Iterator=0; Iterator<ArrayLength-1; Iterator++)
    {
        Minimum_Index=Iterator;

        for(Comparetor=Iterator+1; Comparetor<ArrayLength; Comparetor++)
        {
            if (Array[Comparetor]<Array[Minimum_Index])
            {
                Minimum_Index=Comparetor;
            }
        }
        Swap_Numbers(&Array[Iterator],&Array[Minimum_Index]);
    }

}
void DisplayArray(uint32_t Array[],uint32_t ArrayLength)
{
    uint32_t Counter=0;
    for (Counter=0; Counter<ArrayLength; Counter++)
    {
        printf("%i\t",Array[Counter]);
    }
    printf("\n");

}
void Swap_Numbers(uint32_t *pNUmber1,uint32_t *pNUmber2)
{
    uint32_t Temp=*pNUmber1;
    *pNUmber1=*pNUmber2;
    *pNUmber2=Temp;
}
