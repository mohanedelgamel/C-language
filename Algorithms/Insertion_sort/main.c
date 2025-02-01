#include <stdio.h>
#include <stdlib.h>
typedef unsigned int uint32_t;

uint32_t Array[10]={6,4,8,11,77,99,44,9,2,1};





void Insertion_Sort(uint32_t Array[],uint32_t ArrayLength);
void DisplayArray(uint32_t Array[],uint32_t ArrayLength);


int main()
{
    DisplayArray(Array,10);
    Insertion_Sort(Array,10);
    DisplayArray(Array,10);


    return 0;
}

void Insertion_Sort(uint32_t Array[],uint32_t ArrayLength)
{
    uint32_t Iteration_Counter=0;
    uint32_t ComparedValue=0;
    signed int  IndexOfFirstCompare=0;

    for (Iteration_Counter=1;Iteration_Counter<ArrayLength;Iteration_Counter++)
    {
        ComparedValue=Array[Iteration_Counter];
        IndexOfFirstCompare=Iteration_Counter-1;
        while ((ComparedValue<Array[IndexOfFirstCompare])&&(IndexOfFirstCompare>=0))
        {
            Array[IndexOfFirstCompare+1]=Array[IndexOfFirstCompare];
            IndexOfFirstCompare--;
        }

        Array[IndexOfFirstCompare+1]=ComparedValue; //as index always less than by 1 we need to add 1
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
