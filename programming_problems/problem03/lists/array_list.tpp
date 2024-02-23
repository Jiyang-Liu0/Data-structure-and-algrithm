#include "array_list.hpp"

template <typename T>
ArrayList<T>::ArrayList() {
  listCount = 0;
  listSize = 5;
  items = new T[listSize];
}

template <typename T>
ArrayList<T>::~ArrayList() {
  delete[] items;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList& rhs){
  items = new T[rhs.getLength()];
  listSize = rhs.getLength();
  listCount = rhs.getLength();
  for (int i=0;i<rhs.getLength();i++){
    items[i]=rhs.getEntry(i);
  }

}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(ArrayList rhs){
  swap(rhs);
  return *this;
}

template <typename T>
void ArrayList<T>::swap(ArrayList& rhs) {
  // std::swap(listCount,rhs.getLength());
  // for(int i=0;i<rhs.getLength();i++){
  //   std::swap(items[i],rhs.getEntry(i));
  // }
  std::swap(items,rhs.items);
  std::swap(listCount,rhs.listCount);
}

template <typename T>
bool ArrayList<T>::isEmpty() const noexcept {

  return (listCount==0);
}

template <typename T>
std::size_t ArrayList<T>::getLength() const noexcept {
  return listCount;
}

template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item){
  if (position<0 || position>listCount){
    return false;
  }

  if (listCount>=listSize){
    T* oldList = items;
    listSize = 2*listSize;
    items = new T[listSize];
    for (int i=0;i<listSize;i++){
      items[i]=oldList[i];
    }
    delete[] oldList;
  }

  if (position==listCount){
    items[position] = item;
    listCount++;
    return true;
  }

  for (int i=listCount-1;i>=position;i--)
  {
    items[i+1]=items[i];
  }
  items[position] = item;
  listCount++;

  return true;
}

template <typename T>
bool ArrayList<T>::remove(std::size_t position){
  if (position<0 || position>=listCount){
    return false;
  }

  if (position==listCount-1){
    listCount--;
    return true;
  }

  for (int i=position;i<listCount;i++)
  {
    items[i]=items[i+1];
  }
  listCount--;

  return true;
}

template <typename T>
void ArrayList<T>::clear() {
  listCount=0;
  delete[] items;
  listSize = 5;
  items = new T[listSize];
}

template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const {
  if (position<0 || position>listCount-1){
    return T();
  }

  return items[position];
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue) {
  if (position<0 || position>listCount-1){
    return;
  }

  items[position] = newValue;
  return;
}
