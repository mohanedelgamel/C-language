#include "Algorithms.h"
/*
* @brief  : display array element
* @param  : (Array) get array name
* @param  : (ArrayLength) get array size
* @retval :  void
*/

void DisplayArray(uint32_t Array[],uint32_t ArrayLength)
{
    uint32_t Counter=0;
    for (Counter=0; Counter<ArrayLength; Counter++)
    {
        printf("%i\t",Array[Counter]);
    }
    printf("\n");

}

/*
* @brief  : Swap two numbers by referances
* @param  : (pNUmber1) get adress of first number
* @param  : (pNUmber2) get  adress of second number
* @retval :  void
*/

void Swap_Numbers(uint32_t *pNUmber1,uint32_t *pNUmber2)
{
    uint32_t Temp=*pNUmber1;
    *pNUmber1=*pNUmber2;
    *pNUmber2=Temp;
}

/*
* @brief  : Search for element in array using Linear search algorithm in one direction
* @param  : (Array) get array name
* @param  : (ArrayLength) get array size
* @param  : (Req_data) get needed number to be searched
* @retval :  index of returned number
*/

sint32_t Linear_Search1(uint32_t Array[],uint32_t ArrayLength,uint32_t Req_data)
{
    uint32_t Index =0;
    for (Index=0; Index<ArrayLength; Index++)
    {
        if (Array[Index]==Req_data)
        {
            return Index;
        }
    }
    return -1 ;
}

/*
* @brief  : Search for element in array using Linear search algorithm in Two direction
* @param  : (Array) get array name
* @param  : (ArrayLength) get array size
* @param  : (Req_data) get needed number to be searched
* @retval :  index of returned number
*/

sint32_t Linear_Search2(uint32_t Array[],uint32_t ArrayLength,uint32_t Req_data)
{
    uint32_t Left_Index =0;
    uint32_t Right_Index=ArrayLength-1;
    for (Left_Index=0; Left_Index<=Right_Index;)
    {
        if (Array[Left_Index]==Req_data)
        {
            return Left_Index;
        }
        else
        {
            /*  nothing*/
        };
        if (Array[Right_Index]==Req_data)
        {
            return Right_Index;
        }
        else
        {
            /*  nothing*/
        };

        Left_Index++;
        Right_Index--;
    }
    return -1 ;
}

/*
* @brief  : Search for element in array using Binary search algorithm Not recursive
* @param  : (Array) get array name
* @param  : (Req_data) get needed number to be searched
* @param  : (S_Index) first index of array
* @param  : (E_Index) last index in the array
* @retval :  index of returned number
*/

sint16_t Binary_Search1(uint16_t Array[],uint16_t Req_data,uint16_t S_Index,uint16_t E_Index)
{
    uint16_t M_Index=0;

    while (S_Index<=E_Index)
    {
        M_Index=(S_Index+E_Index)/2;
        if (Array[M_Index]==Req_data)
        {
            return M_Index;
        }
        else if (Req_data<Array[M_Index])
        {
            E_Index=M_Index-1;
        }
        else
        {
            S_Index=M_Index+1;
        }

    }

    return -1;
}

/*
* @brief  : Search for element in array using Binary search algorithm  recursively
* @param  : (Array) get array name
* @param  : (Req_data) get needed number to be searched
* @param  : (S_Index) first index of array
* @param  : (E_Index) last index in the array
* @retval :  index of returned number
*/

sint16_t Binary_Search2(uint16_t Array[],uint16_t Req_data,uint16_t S_Index,uint16_t E_Index)
{
    uint16_t M_Index=0;

    while (S_Index<=E_Index)
    {
        M_Index=(S_Index+E_Index)/2;
        if (Array[M_Index]==Req_data)
        {
            return M_Index;
        }
        else if (Req_data<Array[M_Index])
        {

            return Binary_Search2(Array,Req_data,S_Index,M_Index-1);
        }
        else
        {
            return Binary_Search2(Array,Req_data,M_Index+1,E_Index);

        }

    }

    return -1;
}

/*
* @brief  : sorting array using Bubble sort algorithm
* @param  : (Array) get array name
* @param  : (ArrayLength) get array size
* @retval :  void
*/

void Bubble_Sort(uint32_t Array[],uint32_t ArrayLength)
{
    uint32_t Iteration_Counter;
    uint32_t Comparision_Counter;
    uint32_t Flag=0;

    for (Iteration_Counter=0; Iteration_Counter<ArrayLength-1; Iteration_Counter++)
    {

        for (Comparision_Counter=0; Comparision_Counter<ArrayLength-1-Iteration_Counter; Comparision_Counter++)
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

/*
* @brief  : sorting array using Insertion sort algorithm
* @param  : (Array) get array name
* @param  : (ArrayLength) get array size
* @retval :  void
*/

void Insertion_Sort(uint32_t Array[],uint32_t ArrayLength)
{
    uint32_t Iteration_Counter=0;
    uint32_t ComparedValue=0;
    signed int  IndexOfFirstCompare=0;

    for (Iteration_Counter=1; Iteration_Counter<ArrayLength; Iteration_Counter++)
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

/*
* @brief  : sorting array using Selection sort algorithm
* @param  : (Array) get array name
* @param  : (ArrayLength) get array size
* @retval :  void
*/

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
