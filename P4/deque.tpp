//#include "deque.hpp"

#include <algorithm>
#include <stdexcept>

#include <iostream>

  template <typename T>
  Deque<T>::Deque()
  {
  	DynamicArrayList<T> *internal_list = new DynamicArrayList<T>();
  }
  
  template <typename T>
  Deque<T>::~Deque()
  {
  	internal_list.clear();
  }
  
  template <typename T>
  void Deque<T>::pushFront(const T& item)
  {
  	internal_list.insert(0, item);
  }
  
  template <typename T>
  void Deque<T>::pushBack(const T& item)
  {
  	internal_list.insert(internal_list.getLength(), item);
  }
  
   template <typename T>
  void Deque<T>::popFront()
  {
  	internal_list.remove(0);
  }
  
  template <typename T>
  void Deque<T>::popBack()
  {
  	internal_list.remove(internal_list.getLength()-1);
  }
  
  template <typename T>
  T Deque<T>::front() const
  {
  	return internal_list.getEntry(0);
  }
  
   template <typename T>
  T Deque<T>::back() const
  {
  	return internal_list.getEntry(internal_list.getLength()-1);
  }
  
  template <typename T>
  bool Deque<T>::isEmpty() const noexcept
  {
  	return internal_list.isEmpty();
  }
