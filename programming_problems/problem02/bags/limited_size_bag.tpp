#include "limited_size_bag.hpp"

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag() {
  itemCount = 0;
}
  
template<typename T>
bool LimitedSizeBag<T>::add(const T& item)
{
  if (itemCount >= maxsize){
    return false; 
  } else {
    items[itemCount] = item;
    itemCount++;
    return true;
  }
}

template<typename T>
bool LimitedSizeBag<T>::remove(const T& item)
{
  for (int i=0 ; i<itemCount;i++){
    if (items[i] == item){      
      for (int j=i+1; j<itemCount;j++){
        items[j-1]=items[j];
      }      
      itemCount--;
      return true;
    }
  }
  return false;
}

template<typename T>
bool LimitedSizeBag<T>::isEmpty() const
{
  if (itemCount == 0){
    return true;
  }
  return false;
}

template<typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const
{
  return itemCount;
}

template<typename T>
bool LimitedSizeBag<T>::contains(const T& item) const
{  
  for (int i=0 ; i<itemCount;i++){
    if (items[i] == item){
      return true;
    }
  }
  return false;
}

template<typename T>
void LimitedSizeBag<T>::clear(){
  itemCount = 0;
}

template<typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T & item) const
{
  std::size_t frequencyNumber = 0;
  for (int i=0 ; i<itemCount;i++){
    if (items[i] == item){
      frequencyNumber++;
    }
  }
  return frequencyNumber;
};
