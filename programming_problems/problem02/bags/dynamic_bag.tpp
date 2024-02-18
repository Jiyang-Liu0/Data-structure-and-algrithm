#include "dynamic_bag.hpp"

template<typename T>
DynamicBag<T>::DynamicBag() {
  itemCount = 0;
  arraySize = 6;
  items = new T[arraySize];
}
  
template<typename T>
DynamicBag<T>::~DynamicBag() {
  delete[] items;
}

template<typename T>
DynamicBag<T>::DynamicBag(const DynamicBag<T>& x){
  items = new T[x.arraySize];
  itemCount = x.itemCount;
  for (int i=0;i<x.getCurrentSize();i++){
    items[i] = x.items[i];
  }
}

template<typename T>
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T> x)
{ 
  items = new T[x.arraySize];
  itemCount = x.itemCount;
  for (int i=0;i<x.getCurrentSize();i++){
    items[i] = x.items[i];
  }
  return *this;
}

template<typename T>
void DynamicBag<T>::swap(DynamicBag<T>& x){}

template<typename T>
bool DynamicBag<T>::add(const T& item)
{
  if (itemCount >= arraySize){
    T* oldItems = items;
    items = new T[2*arraySize];
    for (int i=0; i < arraySize; i++) {
      items[i] = oldItems[i];
    }
    delete [] oldItems;
  }
  items[itemCount] = item;
  itemCount++;
  return true;
}

template<typename T>
bool DynamicBag<T>::remove(const T& item)
{
  for (int i=0;i<itemCount;i++){
    if (items[i]==item){
      for (int j=i+1;j<itemCount;j++){
        items[j-1]=items[j];
      }
    itemCount--;
    return true;
    }
  }
  return false;
}

template<typename T>
bool DynamicBag<T>::isEmpty() const
{
  return (itemCount==0);
}

template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const
{
  return itemCount;
}

template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{  
  for (int i=0;i<itemCount;i++){
    if (items[i]==item){
      return true;
    }
  }
  return false;
}

template<typename T>
void DynamicBag<T>::clear(){
  itemCount = 0;
  arraySize = 6;
  items = new T[arraySize];
}

template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{
  std::size_t frequencyNumber = 0;
  for (int i=0;i<itemCount;i++){
    if (items[i]==item){
      frequencyNumber++;
    }
  }
  return frequencyNumber;
};
