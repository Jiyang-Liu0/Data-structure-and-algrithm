#ifndef _SORT_HPP
#define _SORT_HPP

#include "linked_list.hpp"

// template<typename T> LinkedList<T> sort(LinkedList<T> list)
// {
// 	// Bubble sort
// 	int swaps; //Swap times
// 	int last; //The last position of unsorted list 

// 	do
// 	{
// 		swaps = 0; 
// 		last = list.getLength()-1;

// 		//Loop from the first to the last unsorted position
// 		for(int j=0;j<last;j++)
// 		{
// 			// If prev>next,then swap the values
// 			if (list.getEntry(j)>list.getEntry(j+1))
// 			{
// 				T temp = list.getEntry(j+1);
// 				list.setEntry(j+1,list.getEntry(j));
// 				list.setEntry(j,temp);
// 				swaps++; // Count swap times +1
// 			}
// 		}
// 		last--; //Shift one position to the left

// 		//If no swaps, then the list is sorted, break the loop
// 	} while (swaps>0);

// 	return list;
// }


template<typename T> void mergeSort(LinkedList<T>& list,std::size_t first,std::size_t last)
{
	if(first<last)
	{
		std::size_t mid = std::floor((first+last)/2);
		mergeSort(list,first,mid);
		mergeSort(list,mid+1,last);
		merge(list,first,mid,last);
	}
}

template<typename T> LinkedList<T> merge(LinkedList<T> list,std::size_t first,std::size_t mid,std::size_t last)
{
	LinkedList<T> sortedList;
	std::size_t left=first;
	std::size_t right=mid+1;
	std::size_t listPosition = 0;

	while (left<=mid &&right<=last)
	{
		if(list.getEntry(left)>list.getEntry(right))
		{
			sortedList.insert(listPosition,list.getEntry(left));
			listPosition++;
			left++;
		}
		else
		{
			sortedList.insert(listPosition,list.getEntry(right));
			listPosition++;
			right++;			
		}
	}
	
	return sortedList;
}

#endif


