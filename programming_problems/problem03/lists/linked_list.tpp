#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList()
{
  size = 0;
  head = nullptr;

}

template <typename T>
LinkedList<T>::~LinkedList()
{
  //TODO
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{  
  // item(x);
  // next(nullptr);
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

}

template <typename T>
bool LinkedList<T>::isEmpty() const noexcept
{
  //TODO
  return true;
}

template <typename T>
std::size_t LinkedList<T>::getLength() const noexcept
{
  //TODO
  return 0;
}

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  if (position == 0){
    Node<T>* temp = new Node<T>(item);
    temp->next = head;
    head = temp;
  } else {
    Node<T>* loc = find(position);
    Node<T>* temp = new Node<T>(item);
    temp->next = loc->next;
    loc->next = temp;
    size++;
  }
}

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  //TODO
  return true;
}

template <typename T>
void LinkedList<T>::clear()
{
  //TODO
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  //TODO
  return T();
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  //TODO
}
