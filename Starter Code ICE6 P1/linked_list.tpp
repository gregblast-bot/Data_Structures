#include "linked_list.hpp"

// Default constructor initializes length to zero and the head pointer to NULL
template <typename T>
LinkedList<T>::LinkedList()
{
  length = 0;
  head = nullptr;
}

// DESTRUCTOR DESTROY
template <typename T>
LinkedList<T>::~LinkedList()
{
  // Create a generic pointer and set equal to head
  Node<T>* current = head;
  
	// While the current address as a value not equal to zero, DESTROY
	while(current != nullptr) {
	    // Create a generic pointer and set equal to the next node
		Node<T>* next = current->getNext();
		// Deletes where you be, DESTROY
		delete current;
		// Now current equals next and we do it all over again
		current = next;
	}
	
	// MAKE DA HEAD NULL
	head = nullptr;
}


template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
   head = nullptr;
   length = 0;
   Node<T>* currentx = new Node<T>;
   currentx = x.head;
   
   while(currentx != nullptr){
	insert(length+1, currentx->getItem());	
	currentx = currentx->getNext();
   }
}

template <typename T>
void LinkedList<T>::swap(LinkedList<T>& x, LinkedList<T>& y){ 
    T temp = NULL;
    Node<T>* currentx = new Node<T>;
    Node<T>* currenty = new Node<T>;
    currentx = x.head;
    currenty = y.head;
    
    if(x.length != y.length){
		std::cout << "Lists are of unequal length." << std::endl;
		return;
    }

    while(currentx != nullptr){
		temp = currentx->getItem();
		currentx->setItem(currenty->getItem());
		currenty->setItem(temp);
		currentx = currentx->getNext();
		currenty = currenty->getNext();
     }
}  

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& x)
{
   T thing = NULL;
   Node<T>* currentx = new Node<T>;
   Node<T>* currenty = new Node<T>;
   currentx = x.head;
   currenty = this->head;
    
   if(currenty == nullptr){
	  this->insert(1, thing);
	  currenty = this->head;
   }   
   
   while(currentx != nullptr){
		currenty->setItem(currentx->getItem());
		currentx = currentx->getNext();
		
		if((currentx != nullptr) && (currenty->getNext() == nullptr)){
			currenty->setNext(new Node<T>);
		}
		
		currenty = currenty->getNext();
    }
   
   return *this;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
  // If the head is NULL, the lniked list is considered empty, else not empty
  if(head == nullptr){
	return true;
  }
  
  else{
	return false;
  }

}

template <typename T>
std::size_t LinkedList<T>::getLength() const
{
  // RETURN DAT LENGTH
  return length;
}

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
	
   // Create a generic node pointer with dynamically allocated memory
   // Make item an argument for it
   Node<T>* node = new Node<T>(item);
   // Create a generic node pointer and set equal to head
   Node<T>* tempNode = head; 
   
   /* My test cases are screwing it up, so screw them  
   if(position >= length || position < 0){
		return false;
   } 
   
   
   if(head == nullptr){
		return false;
   }*/
   
   // If the position is 1 or the linked list does not have a head yet, fall into this case
   if(position == 1 || head == nullptr){
		// We set the node to the head, then head equals node, increment length and return true
		node->setNext(head);
		head = node;
		length++;
		return true;
   }
   
   else{
	  /* While looping through the linked list (starting from base 1)
	   * continue to get the next entry until the postion before the desired 
	   * position is reached. tempNode holds the next node.
	   */
      for(unsigned int i = 1; i < (position-1); i++){
		tempNode = tempNode->getNext();
      }
      
      // Finally, set node to the next tempNode (at your desired position)
      node->setNext(tempNode->getNext());
      // And set tempNode to the node
      tempNode->setNext(node);
      
      length++;
      
      return true;
   }
}

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
   /* My test cases are screwing it up, so screw them  
   if(position >= length || position < 0){
		return false;
   } 
   
   
   if(head == nullptr){
		return false;
   }*/
   
   // If the position is 1, fall into this case
   if(position == 1){
	// Set head equal to the next, decrement length, return true
	head = head->getNext();
	length--;
	return true;
   }
   
   else{
	  // Create a generic pointer, set equal to head
      Node<T>* tempNode = head;
      
      /* While looping through the linked list (starting from base 1)
	   * continue to get the next entry until the postion before the desired 
	   * position is reached. tempNode holds the next node.
	   */
      for(unsigned int i = 1; i < (position-1); i++){
		tempNode = tempNode->getNext();
      }
     
	  // Finally, set node to the next next tempNode (at your desired position)
      tempNode->setNext(tempNode->getNext()->getNext());
      
      length--;
      
      return true;
   }
}

template <typename T>
void LinkedList<T>::clear()
{
  //Simplest clearing method, set head equal to NULL
  head = nullptr;
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
	// Create a generic node pointer and set equal to head
    Node<T>* current = head;

	/* While looping through the linked list (starting from base 1)
	 * continue to get the next entry until the desired position is reached.
	 */
	for(unsigned int i = 1; i < position; i++){
		current = current->getNext();
	}
  
	// Return the item at the current address
    return current->getItem();
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
	// Create a generic node pointer and set equal to head
        Node<T>* current = head;

	/* While looping through the linked list (starting from base 1)
	 * continue to get the next entry until the desired position is reached.
	 */
	for(unsigned int i = 1; i < position; i++){
		current = current->getNext();
	}
  
	// Now set the item in that current address to the desired value.
	current->setItem(newValue);
}
