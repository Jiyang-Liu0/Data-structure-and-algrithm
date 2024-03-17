#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList()
{
  itemCount = 0;
  headPtr = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  while (headPtr != nullptr)
  {
    Node<T>* temp=headPtr;
    headPtr=headPtr->getNext();
    delete temp;
    temp=nullptr;
  }
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{  
  itemCount = x.getLength();
  headPtr = x.headPtr;
  Node<T>* lastNodePtr = nullptr;

  for (int i=0;i<itemCount;i++)
  {
    Node<T>* newNodePtr = new Node<T>();
    newNodePtr->setItem(x.getEntry(i));
    if (i==0)
    {
      headPtr = newNodePtr;
    }

    if (lastNodePtr!=nullptr)
    {
      lastNodePtr->setNext(newNodePtr);
    }
    
    lastNodePtr = newNodePtr;
  }
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> x)
{
  swap(x);
  return *this;
}

template <typename T>
void LinkedList<T>::swap(LinkedList& x) 
{
  std::swap(itemCount,x.itemCount);
  std::swap(headPtr,x.headPtr);
}

template <typename T>
bool LinkedList<T>::isEmpty() const noexcept
{
  return (itemCount==0);
}

template <typename T>
std::size_t LinkedList<T>::getLength() const noexcept
{
  return itemCount;
}

template <typename T>
Node<T>* LinkedList<T>::find(std::size_t position) const
{
  Node<T>* ptr = headPtr;
  if (position>=itemCount || position<0)
  {
    return nullptr;
  }

  for (int i=0;i<position;i++)
  {
    ptr = ptr->getNext();
  }

  return ptr;
}

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  if(position<0 || position>itemCount){
    return false;
  }
  if (position == 0){
    Node<T>* temp = new Node<T>(item);
    temp->setNext(headPtr);
    headPtr = temp;
    itemCount++;
  } else {
    Node<T>* loc = find(position-1);
    Node<T>* temp = new Node<T>(item);
    temp->setNext(loc->getNext());
    loc->setNext(temp);
    itemCount++;
  }
  return true;
}

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  if(position<0 || position>=itemCount){
    return false;
  }

  if (position==0)
  {
    Node<T>* loc = headPtr;
    headPtr = headPtr->getNext();
    delete loc;
    loc = nullptr;
    itemCount--;
    return true;
  }

  Node<T>* prev=find(position-1);
  Node<T>* current= prev->getNext();
  prev->setNext(current->getNext());
  delete current;
  current = nullptr;
  itemCount--;

  return true;
}

template <typename T>
void LinkedList<T>::clear()
{
  while(headPtr!=nullptr)
  {
    Node<T>* temp = headPtr;
    headPtr = headPtr->getNext();
    delete temp;
    temp = nullptr;
  }
  itemCount = 0;
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  if(position<0 || position>=itemCount){
    return T();
  }
  
  Node<T>* loc = find(position);
  return loc->getItem();
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  if(position<0 || position>=itemCount){
    return;
  }
  
  Node<T>* loc = find(position);
  loc->setItem(newValue);
  return;
}
