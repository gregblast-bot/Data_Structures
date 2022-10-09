#include "dynamic_array_list.hpp"

#include <algorithm>
#include <stdexcept>

#include <iostream>

template <typename T>
DynamicArrayList<T>::DynamicArrayList()
{
  // Initialize every value to zero and empty
  data = nullptr;
  capacity = 10000;
  size = 0;
}
  
template <typename T>
DynamicArrayList<T>::DynamicArrayList(const DynamicArrayList<T>& x)
{
      // Data now has the parameter's capacity
      data = new T[x.capacity];

	  // Loop through the array and replace the data with the parameter's data
      for(std::size_t i = 0; i < x.size; i++){
          data[i] = x.data[i];
      }
	  
	  // New size and new capacity
      size = x.size;
      capacity = x.capacity;
}
    
template <typename T>
DynamicArrayList<T>::~DynamicArrayList()
{
  // Clog?
  std::clog << "DynamicArrayList Destructor called." << std::endl;
  
  // Delete data
  delete [] data;
  
}

template <typename T>
DynamicArrayList<T>& DynamicArrayList<T>::operator=(DynamicArrayList<T> x)
{
  // Use swap function for this assignment overload and return this
  swap(*this, x);
  return *this;
}

template <typename T>
void DynamicArrayList<T>::swap(DynamicArrayList<T>& x, DynamicArrayList<T>& y)
{
  // Cool, use the swap function from the library
  std::swap(x.data, y.data);
  std::swap(x.capacity, y.capacity);
  std::swap(x.size, y.size);
}

template <typename T>
bool DynamicArrayList<T>::isEmpty() const noexcept
{
  // If size is equal to zero, return true
  return (size == 0);
}

template <typename T>
std::size_t DynamicArrayList<T>::getLength() const
{
  // Retrun DAT size
  return size;
}

template <typename T>
void DynamicArrayList<T>::insert(std::size_t position, const T& item)
{
   // If position is greater than size, throw an error
   if(position > size) throw std::range_error("Position out of range in insert member function.");
   
   // If size is equal to this capacity, fall into this case
   if(size == capacity){
    // Double newcapacity and declare generic pointer to newdata
	std::size_t newcapacity = 2*capacity;
	T* newdata = new T[newcapacity];
	
	// Loop through the array and put data into newdata 
    for(std::size_t i = 0; i < size; i++){
		newdata[i] = data[i];
	}
	
	// Delete, set capacity and set data
    delete [] data;
    capacity = newcapacity;
    data = newdata;
  }

  // Loop through the array until the specified position, replacing data
  for(long i = size-1; i >= static_cast<long>(position); --i){
     data[i+1] = data[i];
  }
  
  // Put the item at this position in the array and increment size
  data[position] = item;
  size++;
}

template <typename T>
void DynamicArrayList<T>::remove(std::size_t position)
{
   // Throw an error if size is equal to zero
   if(size == 0) throw std::range_error("You cannot remove what isn't there.");

   // Throw an error if position is greater than or equal to size
   if(position >= size) throw std::range_error("Position out of range in remove member function.");

   // Loop through the array and replace the data from the position to the end of the array
   for(std::size_t i = position; i < size; i++){
     data[i] = data[i+1];
   }
  
   // Decrement size
   size--;
}

template <typename T>
void DynamicArrayList<T>::clear()
{
  // Set the size equal to zero
  size = 0;
}

template <typename T>
T DynamicArrayList<T>::getEntry(std::size_t position) const
{
	//std::cout << position << " " << size << std::endl;

  // Throw an error if position is greater than or equal to size
  if(position >= size) throw std::range_error("Position out of range in getEntry member function. asdasd");

  // Return the data at this entry
  return data[position];
}

template <typename T>
void DynamicArrayList<T>::setEntry(std::size_t position, const T& newValue)
{
   // Throw an error if position is greater than or equal to size
   if(position >= size) throw std::range_error("Position out of range in setEntry member function.");

   // Set the new value and the desired position in the array
   data[position] = newValue;
}

/*
template <typename T>
DynamicArrayList<T>::DynamicArrayList(): data(nullptr), capacity(1000000), size(0)
{}
  
template <typename T>
DynamicArrayList<T>::DynamicArrayList(const DynamicArrayList<T>& x)
{
  capacity = x.capacity;
  size = x.size;
  data = capacity ? new T[capacity] : nullptr;
  std::copy(x.data, x.data + x.capacity, data);
}
    
template <typename T>
DynamicArrayList<T>::~DynamicArrayList()
{
  std::clog << "DynamicArrayList Destructor called." << std::endl;
  delete [] data;
}

template <typename T>
DynamicArrayList<T>& DynamicArrayList<T>::operator=(DynamicArrayList<T> x)
{
  swap(*this, x);
  return *this;
}

template <typename T>
void DynamicArrayList<T>::swap(DynamicArrayList<T>& x, DynamicArrayList<T>& y)
{
  std::swap(x.data, y.data);
  std::swap(x.capacity, y.capacity);
  std::swap(x.size, y.size);
}

template <typename T>
bool DynamicArrayList<T>::isEmpty() const noexcept
{
  return (size == 0);
}

template <typename T>
std::size_t DynamicArrayList<T>::getLength() const
{
  return size;
}

template <typename T>
void DynamicArrayList<T>::insert(std::size_t position, const T& item)
{
  //std::clog << "Insert at " << position << " with size " << size << std::endl;
  
  if(position > size) throw std::range_error("position out of range in insert");
  
  if(size == 0){ // need to realloc
    T* newdata = new T[capacity];
    data = newdata;
  }
  
  if(size == capacity){ // need to realloc
    std::size_t newcapacity = capacity ? 2*capacity: 1;
    T* newdata = new T[newcapacity];
    std::copy(data, data+capacity, newdata);
    delete [] data;
    capacity = newcapacity;
    data = newdata;
  }
  
  for(long i = size-1; i >= static_cast<long>(position); --i){
    data[i+1] = data[i];
    //std::clog << "Shifting " << i << " > " << position << std::endl;
  }
  
  //std::clog << std::endl;
  data[position] = item;
  ++size;
}

template <typename T>
void DynamicArrayList<T>::remove(std::size_t position)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  if(position >= size) throw std::range_error("position out of range in remove");
  
  for(long i = position; i < size-1; ++i){
    data[i] = data[i+1];
  }
  --size;
}

template <typename T>
void DynamicArrayList<T>::clear()
{
  size = 0;
}

template <typename T>
T DynamicArrayList<T>::getEntry(std::size_t position) const
{
  if(position >= size) throw std::range_error("position out of range in getEntry");

  return data[position];
}

template <typename T>
void DynamicArrayList<T>::setEntry(std::size_t position, const T& newValue)
{
  if(position >= size) throw std::range_error("position out of range in setEntry");

  data[position] = newValue;
}*/
