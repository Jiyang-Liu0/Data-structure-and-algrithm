#include "frontier_queue.hpp"

// TODO implement the member functions here

template <typename T>
State<T> frontier_queue<T>::pop() {

  State<T> root = queue[0];
  std::swap(queue[0],queue.back());
  queue.pop_back();

  std::size_t swapCount = 1;
  while (swapCount>0)
  {
    swapCount = sort(0);
  }
  return root;
}

template <typename T>
std::size_t frontier_queue<T>::sort(std::size_t rootIndex){
  std::size_t swapCount = 0 ;
  std::size_t leftChildIndex = 2*rootIndex+1;
  std::size_t rightChildIndex = leftChildIndex+1;
  
  std::size_t minChildIndex = -1;
  if (rightChildIndex < queue.size())
  {
    if (queue[leftChildIndex].getFCost()<queue[rightChildIndex].getFCost())
    {
      minChildIndex = leftChildIndex;
    } else {
      minChildIndex = rightChildIndex;
    }
  } else if (leftChildIndex < queue.size()) {
    minChildIndex = leftChildIndex;
  } else {
    return swapCount;
  }
  
  if (queue[rootIndex].getFCost() > queue[minChildIndex].getFCost())
  {
    std::swap(queue[rootIndex],queue[minChildIndex]);
    swapCount++;
  }
  swapCount += sort(leftChildIndex);
  swapCount += sort(rightChildIndex);
  return swapCount;
}

template <typename T>
void frontier_queue<T>::push(const T &p, std::size_t cost, std::size_t heur) {
  State<T> s(p,cost,heur);
  queue.push_back(s);

  std::size_t child_idx = queue.size()-1;
  if(child_idx == 0)
  {
    return;
  }
  std::size_t parent_idx = (child_idx-1) >>1;
  while((parent_idx>=0) && (queue[parent_idx].getFCost()>queue[child_idx].getFCost()))
  {
    queue[child_idx] = queue[parent_idx];
    queue[parent_idx] = s;
    child_idx = parent_idx;
    parent_idx = (parent_idx - 1) >> 1;
  }

}

template <typename T>
bool frontier_queue<T>::empty() {

  return queue.empty();
}

template <typename T> 
bool frontier_queue<T>::contains(const T &p) {

  for (size_t i = 0; i < queue.size(); i++)
  {
    if (queue[i].getValue() == p)
    {
      return true;
    }
  }
  return false;
}

template <typename T>
void frontier_queue<T>::replaceif(const T &p, std::size_t cost) {

  for (size_t i = 0; i < queue.size(); i++)
  {
    if (queue[i].getValue() == p)
    {
      if (queue[i].getPathCost() > cost)
      {
        queue[i].updatePathCost(cost);
        return;
      }
    }
  }
}

