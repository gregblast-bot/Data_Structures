#include "array_list.hpp"

template <typename T>
ArrayList<T>::ArrayList() {
	length = 0;
	capacity = 0;
	arr = nullptr;
}

//Don't need a destructor for an array
template <typename T>
ArrayList<T>::~ArrayList() { 
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList & rhs){
	// Data now has the parameter's capacity
      arr = new T[rhs.capacity];

	  // Loop through the array and replace the data with the parameter's data
      for(std::size_t i = 0; i < rhs.length; i++){
          arr[i] = rhs.arr[i];
      }
	  
	  // New size and new capacity
      length = rhs.length;
      capacity = rhs.capacity;
}

template <typename T>
void ArrayList<T>::swap(ArrayList<T>& x, ArrayList<T>& y)
{
  // Cool, use the swap function from the library
  std::swap(x.arr, y.arr);
  std::swap(x.capacity, y.capacity);
  std::swap(x.length, y.length);
}

/*template <typename T>
ArrayList<T> & ArrayList<T>::operator=(const ArrayList & rhs){
    // Use swap function for this assignment overload and return this
    swap(*this, rhs);
    return *this;
}*/

template <typename T>
bool ArrayList<T>::isEmpty() const{

   if(length == 0){
      return true;
   }
   
   else{
      return false;
   }
}

template <typename T>
std::size_t ArrayList<T>::getLength() const{
  return length;
}

template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item){

	unsigned int temp = position - 1;
	//std::cout << position << std::endl << item << std::endl << temp << std::endl << length;
	if(position < 1 || temp > length){
        return false;
    }
    
    else{
        arr[temp] = item;
        length++;
        return true;
    }
    
}

template <typename T>
bool ArrayList<T>::remove(std::size_t position){
   
    if((position-1) >= 0){
        for(unsigned int i = (position-1); i < length; i++){
           arr[i] = arr[i+1];
        }
       length--;
       return true;
    }
    
    else{
        return false;
    }
}

template <typename T>
void ArrayList<T>::clear() {
	length = 0;
	arr[100] = 0;
}

template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const {
       return arr[position-1];
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue) {
     arr[position-1] = newValue; 
 }

