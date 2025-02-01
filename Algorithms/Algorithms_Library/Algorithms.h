#ifndef _LINEAR_SEARCH_H
#define _LINEAR_SEARCH_H

#include "Types.h"

/*
* @brief  : Swap two numbers by referances
* @param  : (pNUmber1) get adress of first number
* @param  : (pNUmber2) get  adress of second number
* @retval :  void
*/

void Swap_Numbers(uint32_t *pNUmber1,uint32_t *pNUmber2);

/*
* @brief  : display array element
* @param  : (Array) get array name
* @param  : (ArrayLength) get array size
* @retval :  void

*/
void DisplayArray(uint32_t Array[],uint32_t ArrayLength);

/*
* @brief  : Search for element in array using Linear search algorithm in one direction
* @param  : (Array) get array name
* @param  : (ArrayLength) get array size
* @param  : (Req_data) get needed number to be searched
* @retval :  index of returned number
*/

sint32_t Linear_Search1(uint32_t Array[],uint32_t ArrayLength,uint32_t Req_data);
/*
* @brief  : Search for element in array using Linear search algorithm in Two direction
* @param  : (Array) get array name
* @param  : (ArrayLength) get array size
* @param  : (Req_data) get needed number to be searched
* @retval :  index of returned number
*/

sint32_t Linear_Search2(uint32_t Array[],uint32_t ArrayLength,uint32_t Req_data);
/*
* @brief  : Search for element in array using Binary search algorithm Not recursive
* @param  : (Array) get array name
* @param  : (Req_data) get needed number to be searched
* @param  : (S_Index) first index of array
* @param  : (E_Index) last index in the array
* @retval :  index of returned number
*/

sint16_t Binary_Search1(uint16_t Array[],uint16_t Req_data,uint16_t S_Index,uint16_t E_Index);

/*
* @brief  : Search for element in array using Binary search algorithm  recursively
* @param  : (Array) get array name
* @param  : (Req_data) get needed number to be searched
* @param  : (S_Index) first index of array
* @param  : (E_Index) last index in the array
* @retval :  index of returned number
*/

sint16_t Binary_Search2(uint16_t Array[],uint16_t Req_data,uint16_t S_Index,uint16_t E_Index);

/*
* @brief  : sorting array using Bubble sort algorithm
* @param  : (Array) get array name
* @param  : (ArrayLength) get array size
* @retval :  void
*/

void Bubble_Sort(uint32_t Array[],uint32_t ArrayLength);

/*
* @brief  : sorting array using Insertion sort algorithm
* @param  : (Array) get array name
* @param  : (ArrayLength) get array size
* @retval :  void
*/

void Insertion_Sort(uint32_t Array[],uint32_t ArrayLength);

/*
* @brief  : sorting array using Selection sort algorithm
* @param  : (Array) get array name
* @param  : (ArrayLength) get array size
* @retval :  void
*/

void Selection_Sort(uint32_t Array[],uint32_t ArrayLength);


#endif // _LINEAR_SEARCH_H
