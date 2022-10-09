#include "dynamic_bag.hpp"

template<typename T>
DynamicBag<T>::DynamicBag() 
{
	size = 0;
	startingSize = 100;
	data = new int[startingSize];
}
  

template<typename T>
DynamicBag<T>::DynamicBag(const DynamicBag& x)
{
      data = new int[x.startingSize];

      for(unsigned int i = 0; i < x.size; i++){
          data[i]=x.data[i];
      }

      size = x.size;
      startingSize = x.startingSize;
}
    
template<typename T>
DynamicBag<T>::~DynamicBag()
{
  if(data != NULL){
	delete [] data;
  }
}
  
template<typename T>
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T>& x)
{  
  return *this;
}

template<typename T>
bool DynamicBag<T>::add(const T& item)
{

  bool logic;

  if(size == startingSize){
    int newsize = startingSize + (startingSize/2);
    int *newdata, *olddata;

     olddata = data;
     newdata = new int[newsize];

     for(unsigned int i = 0; i < startingSize; i++)
         newdata[i] = olddata[i];

     delete [] data;

     data = newdata;
     startingSize = newsize; 
  }

  else if(size < startingSize){
	data[size] = item;
	++size;
  	logic = true;
  }

  else if(size <= 0){
  	logic = false;
  }
  
  else{
	logic = false;
  }
  
  return logic;
}

template<typename T>
bool DynamicBag<T>::remove(const T& item)
{
   if(size == 0) return false;

  std::size_t idx = 0;
  for(std::size_t i = 0; i < size; ++i){
    if(data[i] == item) break;
    ++idx;
  }

  if(idx == size) return false;

  --size;
  for(std::size_t i = idx; i < size; ++i){
    data[i] = data[i+1];
  }

  return true;
}

template<typename T>
bool DynamicBag<T>::isEmpty() const
{
  return (size == 0);
}

template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const
{
  return size;
}

template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{  
   return (getFrequencyOf(item) != 0);
}

template<typename T>
void DynamicBag<T>::clear(){ size = 0; }

template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{
   std::size_t freq = 0;

  for(std::size_t i = 0; i < size; ++i){
    if(data[i] == item) ++freq;
  }
  
  return freq;
};
