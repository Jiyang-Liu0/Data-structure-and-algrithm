#include "queue.hpp"

template <typename T, typename L>
void Queue<T,L>::enqueue(const T& item)
{
  std::size_t length = internal_list.getLength();
  internal_list.insert(length,item);
}

template <typename T, typename L>
void Queue<T,L>::dequeue()
{
  if(internal_list.isEmpty())
  {
    throw std::range_error("Queue is empty.");
  }

  internal_list.remove(0);
}

template <typename T, typename L>
T Queue<T,L>::peekFront()
{
  if(internal_list.isEmpty())
  {
    throw std::range_error("Queue is empty.");
  }

  return internal_list.getEntry(0);
}

template <typename T, typename L>
bool Queue<T,L>::isEmpty() const
{
  return internal_list.isEmpty();
}

