#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "dynamic_array_list.hpp"
#include "abstract_deque.hpp"

template <typename T>
class Deque: public AbstractDeque<T>{
public:
  Deque();
  ~Deque();
  bool isEmpty() const noexcept;
  void pushFront(const T & item);
  void popFront();
  T front() const;
  void pushBack(const T & item);
  void popBack();
  T back() const;

private:
  DynamicArrayList<T> internal_list;
};

#include "deque.tpp"

#endif
