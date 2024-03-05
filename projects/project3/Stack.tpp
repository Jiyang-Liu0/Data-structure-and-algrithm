//  Adapated from Frank M. Carrano and Timothy M. Henry.

/** ADT Stack implementation.
    @file Stack.cpp */

#include <iostream>
#include <cstddef>
#include "Stack.hpp"
#include "Node.hpp"

template<class ItemType>
Stack<ItemType>::Stack() : headPtr(nullptr), currentSize(0)
{
}  // end default constructor


template<class ItemType>
Stack<ItemType>::~Stack()
{
	clear();
}  // end destructor

template<class ItemType>
bool Stack<ItemType>::isEmpty() const
{
	return (currentSize==0);
}  // end isEmpty

template<class ItemType>
int Stack<ItemType>::size() const
{
	return currentSize;
}  // end size

template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newItem)
{
	Node<ItemType>* temp = new Node<ItemType>(newItem);
	temp->setNext(headPtr);
    headPtr = temp;
    currentSize++;
	return true;
}  // end push

template<class ItemType>
ItemType Stack<ItemType>::peek() const
{
	if (currentSize==0)
	{
		throw std::logic_error("The stack is empty!");
	}

	return headPtr->getItem();
}  // end peek

template<class ItemType>
bool Stack<ItemType>::pop() 
{
	if (currentSize==0)
	{
		return false;
	}

	Node<ItemType>* loc = headPtr;
    headPtr = headPtr->getNext();
    delete loc;
    loc = nullptr;
    currentSize--;
    return true;
}  // end pop

// TODO: Implement the clear method here
template<class ItemType>
void Stack<ItemType>::clear()
{
  while(headPtr!=nullptr)
  {
    Node<ItemType>* temp = headPtr;
    headPtr = headPtr->getNext();
    delete temp;
    temp = nullptr;
  }
  currentSize = 0;
}  // end clear

