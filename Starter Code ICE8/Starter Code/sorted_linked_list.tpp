#include "sorted_linked_list.hpp"
#include <stdexcept>

template <typename T>
SortedLinkedList<T>::SortedLinkedList(): LinkedList<T>()
{
}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList<T> & x):
  LinkedList<T>(x)
{
}

template <typename T>
SortedLinkedList<T>& SortedLinkedList<T>::operator=(const SortedLinkedList<T>& x)
{
  LinkedList<T>::operator=(x);
  return *this;
}

template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
  // base destructor gets called automatically
}

template <typename T>
bool SortedLinkedList<T>::isEmpty()
{
  return LinkedList<T>::isEmpty();
}

template <typename T>
std::size_t SortedLinkedList<T>::getLength()
{
  return LinkedList<T>::getLength();
}

template <typename T>
void SortedLinkedList<T>::insert(const T& item)
{
  LinkedList<T>::insert(item);  
}

template <typename T>
void SortedLinkedList<T>::remove(const T& item)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
 
	  // Create a generic pointer, set equal to head
      Node<T>* tempNode = head;
      
      /* While looping through the linked list (starting from base 1)
	   * continue to get the next entry until the postion before the desired 
	   * position is reached. tempNode holds the next node.
	   */
      for(unsigned int i = 1; i < getPosition(item); i++){
		tempNode = tempNode->getNext();
      }
     
	  // Finally, set node to the next next tempNode (at your desired position)
      tempNode->setNext(tempNode->getNext()->getNext());
      
      length--;
}

template <typename T>
void SortedLinkedList<T>::removeAt(std::size_t position)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
    
  LinkedList<T>::remove(position);
}

template <typename T>
void SortedLinkedList<T>::clear()
{
  LinkedList<T>::clear();
}

template <typename T>
T SortedLinkedList<T>::getEntry(std::size_t position)
{
  return LinkedList<T>::getEntry(position);
}

template <typename T>
long int SortedLinkedList<T>::getPosition(const T& newValue)
{
  // Create a generic node pointer and set equal to head
    Node<T>* current = head;

	/* While looping through the linked list (starting from base 1)
	 * continue to get the next entry until the desired position is reached.
	 */
	 std::size_t i = 1;
	while(head != nullptr){
		current = current->getNext();
		if(i == newValue){
			return i;
		}
		i++;
	}
	
  return 0;
}
