#include "sorted_linked_list.hpp"
#include <stdexcept>

template <typename T>
SortedLinkedList<T>::SortedLinkedList(): LinkedList<T>()
{
}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(LinkedList<T> unsorted_list):LinkedList<T>(sort(unsorted_list))
{
  // LinkedList<T> sorted_list = sort(unsorted_list);
  // LinkedList<T>::LinkedList(sorted_list);
}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList<T> & x):
  LinkedList<T>(x)
{
}

template <typename T>
SortedLinkedList<T>& SortedLinkedList<T>::operator=(SortedLinkedList<T> x)
{
  LinkedList<T>::operator=(x);
  return *this;
}

template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
  //LinkedList<T>::~LinkedList<T>();
}

template <typename T>
bool SortedLinkedList<T>::isEmpty() const noexcept
{
  return LinkedList<T>::isEmpty();
}

template <typename T>
std::size_t SortedLinkedList<T>::getLength() const noexcept
{
  return LinkedList<T>::getLength();
}

template <typename T>
void SortedLinkedList<T>::insert(const T& item)
{
  int i=0;
  for(i=0;i<LinkedList<T>::getLength();i++)
  {
    if (LinkedList<T>::getEntry(i)>item)
    {
      LinkedList<T>::insert(i,item);
      return;
    }
  }
  LinkedList<T>::insert(i,item);
}

template <typename T>
void SortedLinkedList<T>::remove(const T& item)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  int pos=getPosition(item);
  if(pos==-1)
  {
    throw std::logic_error("Item not found");
  }
  LinkedList<T>::remove(pos);
}

template <typename T>
void SortedLinkedList<T>::removeAt(std::size_t position)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  
  if(position>=LinkedList<T>::getLength())
  {
    throw std::range_error("empty list in remove");
  }

  LinkedList<T>::remove(position);
}

template <typename T>
void SortedLinkedList<T>::clear()
{
  LinkedList<T>::clear();
}

template <typename T>
T SortedLinkedList<T>::getEntry(std::size_t position) const
{
  return LinkedList<T>::getEntry(position);
}

template <typename T>
long int SortedLinkedList<T>::getPosition(const T& item)
{
  int i=0;
  for(i=0;i<LinkedList<T>::getLength();i++)
  {
    if (LinkedList<T>::getEntry(i)==item)
    {
      return i;
    }
  }
  return -1;
}

template<typename T>
LinkedList<T> SortedLinkedList<T>::sort(LinkedList<T> list)
{
	// Bubble sort
	int swaps; //Swap times
	int last; //The last position of unsorted list 

	do
	{
		swaps = 0; 
		last = list.getLength()-1;

		//Loop from the first to the last unsorted position
		for(int j=0;j<last;j++)
		{
			// If prev>next,then swap the values
			if (list.getEntry(j)>list.getEntry(j+1))
			{
				T temp = list.getEntry(j+1);
				list.setEntry(j+1,list.getEntry(j));
				list.setEntry(j,temp);
				swaps++; // Count swap times +1
			}
		}
		last--; //Shift one position to the left

		//If no swaps, then the list is sorted, break the loop
	} while (swaps>0);

	return list;
}