#include "array_list.hpp"

template <typename T>
ArrayList<T>::ArrayList() {
  listCount = 0;
  items = new T[5];
}

template <typename T>
ArrayList<T>::~ArrayList() {
  delete[] items;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList& rhs){
  items = new T[rhs.getLength()];
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

  

  return true;
}

template <typename T>
bool ArrayList<T>::remove(std::size_t position){
  return false;
}

template <typename T>
void ArrayList<T>::clear() {}

template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const {
  return T();
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue) {}
