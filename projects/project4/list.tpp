#include "list.hpp"

template <typename T>
List<T>::List()
{
  itemCount = 0;
  headPtr = nullptr;
}

template <typename T>
List<T>::~List()
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
List<T>::List(const List<T>& x)
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
List<T>& List<T>::operator=(List<T> x)
{
  swap(x);
  return *this;
}

template <typename T>
void List<T>::swap(List<T>& x) 
{
  std::swap(itemCount,x.itemCount);
  std::swap(headPtr,x.headPtr);
}

template <typename T>
bool List<T>::isEmpty() const noexcept
{
  return (itemCount==0);
}

template <typename T>
std::size_t List<T>::getLength() const noexcept
{
  return itemCount;
}

template <typename T>
Node<T>* List<T>::find(std::size_t position) const
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
void List<T>::insert(std::size_t position, const T& item)
{
  if(position<0 || position>itemCount){
    throw std::range_error("Position is out of range");
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
}

template <typename T>
void List<T>::remove(std::size_t position)
{
  if(position<0 || position>=itemCount){
    throw std::range_error("Position is out of range");
  }

  if (position==0)
  {
    Node<T>* loc = headPtr;
    headPtr = headPtr->getNext();
    delete loc;
    loc = nullptr;
    itemCount--;
    return;
  }

  Node<T>* prev=find(position-1);
  Node<T>* current= prev->getNext();
  prev->setNext(current->getNext());
  delete current;
  current = nullptr;
  itemCount--;
}

template <typename T>
void List<T>::clear()
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
T List<T>::getEntry(std::size_t position) const
{
  if(position<0 || position>=itemCount){
    throw std::range_error("Position is out of range");
    // return T();
  }
  
  Node<T>* loc = find(position);
  return loc->getItem();
}

template <typename T>
void List<T>::setEntry(std::size_t position, const T& newValue)
{
  if(position<0 || position>=itemCount){
    throw std::range_error("Position is out of range");
  }
  
  Node<T>* loc = find(position);
  loc->setItem(newValue);
  return;
}
