// implement a deque as a ring buffer
#ifndef _RING_BUFFER_H_
#define _RING_BUFFER_H_

#include <memory>
#include <cstdlib>

template <typename T>
class RingBuffer
{  
public:
  RingBuffer(std::size_t size);
  
  bool enqueue(const T& item);
  T dequeue();
  bool enqueueFront(const T& item);
  T dequeueBack();
  long int getCount();
  bool isEmpty();
  bool isFull();
  RingBuffer<T>& operator=(RingBuffer<T> x);
  void swap(RingBuffer<T>& x, RingBuffer<T>& y);
  
private:

  std::size_t queueLength;
  long int front;
  long int back;
  long int count;
  
  std::unique_ptr<T[]> data;
};

#include "ring_buffer.tpp"

#endif // _RING_BUFFER_H_
