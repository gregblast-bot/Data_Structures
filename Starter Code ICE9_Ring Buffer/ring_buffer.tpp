#include "ring_buffer.h"

#include <cassert>
#include <iostream>


template <typename T>
RingBuffer<T>::RingBuffer(std::size_t size)
{
  queueLength = size;
  data.reset(new T[queueLength]);
  front = 0;
  back = queueLength-1;
  count = 0;
}

template <typename T>
RingBuffer<T>& RingBuffer<T>::operator=(RingBuffer<T> x)
{
  // Use swap function for this assignment overload and return this
  swap(*this, x);
  return *this;
}

template <typename T>
void RingBuffer<T>::swap(RingBuffer<T>& x, RingBuffer<T>& y)
{
  // Cool, use the swap function from the library
  std::swap(x.data, y.data);
  std::swap(x.queueLength, y.queueLength);
}

template <typename T>
bool RingBuffer<T>::enqueue(const T& item)
{
  //assert((back + 1) % queueLength != front);
  
  if(count != queueLength){
    back = (back + 1) % queueLength;
    data[back] = item;
    std::cout << data[back] << std::endl;
    ++count;
    return true;
  }

  else{
    queueLength = queueLength + 1;
    back = (back + 1) % queueLength;
    data[back] = item;
    ++count;
    return true;
  }
  
  return false;
}

template <typename T>
T RingBuffer<T>::dequeue()
{
  assert(count > 0);
  
  //assert(front != back);
  
  T value;

  value = data[front];
  std::cout << data[front] << std::endl;
  front = (front + 1) % queueLength;
  --count;

  return value;
}

template <typename T>
T RingBuffer<T>::dequeueBack()
{
  assert(count > 0);
  
  //assert(front != back);
  back = count;
  T value;
  value = data[back];
  std::cout << back << std::endl;
  std::cout << data[back] << std::endl;
  back = (back*2 + 1) % queueLength;
  --count;

  return value;
}

template <typename T>
bool RingBuffer<T>::enqueueFront(const T& item)
{
  if(count != queueLength){
     front = (front + 1) % queueLength;
     data[front] = item;
     std::cout << data[front] << std::endl;
     ++count;
     return true;
    }

  else{
    queueLength = queueLength + 1;
    front = (front + 1) % queueLength;
    data[front] = item;
    ++count;
    return true;
  }
  
  return false;
}

template <typename T>
long int RingBuffer<T>::getCount()
{
  return count;
}

template <typename T>
bool RingBuffer<T>::isEmpty()
{
  return (front == back);
}

template <typename T>
bool RingBuffer<T>::isFull()
{
  return (front == (back+1));
}
