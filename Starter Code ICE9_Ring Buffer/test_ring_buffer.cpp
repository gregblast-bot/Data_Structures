#include "ring_buffer.h"

#include <cassert>

int main()
{
  RingBuffer<int> buff(3);
  RingBuffer<int> buff2(6);
    
  buff.enqueue(89);
  buff.enqueue(4);
  buff.enqueue(45);
  buff.enqueue(12);
  buff.enqueue(455);
  buff.enqueue(1);

  //RingBuffer<int> buff2 = buff;
    
  assert(buff.getCount() == 6);
  assert(buff.dequeue() == 89);
  assert(buff.dequeue() == 4);
  assert(buff.dequeue() == 45);
  assert(buff.dequeue() == 12);
  assert(buff.dequeue() == 455);
  assert(buff.dequeue() == 1);
  assert(buff.getCount() == 0);
  
  buff2.enqueueFront(89);
  buff2.enqueueFront(4);
  buff2.enqueueFront(45);
  buff2.enqueueFront(12);
  buff2.enqueueFront(455);
  buff2.enqueueFront(1);

  //RingBuffer<int> buff2 = buff;
    
  assert(buff2.getCount() == 6);
  assert(buff2.dequeueBack() == 1041);
  assert(buff2.dequeueBack() == 455);
  assert(buff2.dequeueBack() == 12);
  assert(buff2.dequeueBack() == 45);
  assert(buff2.dequeueBack() == 4);
  assert(buff2.dequeueBack() == 89);
  assert(buff2.getCount() == 0);

  
  return 0;
}
