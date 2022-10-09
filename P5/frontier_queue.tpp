#include "frontier_queue.hpp"

// TODO implement the member functions here

template <typename T>
State<T> frontier_queue<T>::pop() {

  //TODO
  
  //implement this the same way we implemented pop in the heap lecture. Compare using getFCost
	
  	if (size == 0){
		std::cout << "Can't pop what's not there." << std::endl;
		exit(EXIT_FAILURE);
	}
	
	else{		
		State<T> root = heap.getEntry(0);
		heap.setEntry(0, heap.getEntry(size-1));
		heap.remove(size-1); // Remove last
		size--;
		
		MinHeapify(0);
		
		return root;
	}

		
}

template <typename T>
void frontier_queue<T>::MinHeapify(int i) {
	
	unsigned int l = 2*i+1; 
    unsigned int r = 2*i+2; 
    int smallest = i; 
    if (l < size && heap.getEntry(l).getPathCost() < heap.getEntry(i).getPathCost()) 
        smallest = l; 
    if (r < size && heap.getEntry(r).getPathCost() < heap.getEntry(smallest).getPathCost()) 
        smallest = r; 
    if (smallest != i) 
    { 
		State<T> swap = heap.getEntry(i);
		heap.setEntry(i, heap.getEntry(smallest));
		heap.setEntry(smallest, swap);
        MinHeapify(smallest); 
    } 
}
    
template <typename T>
void frontier_queue<T>::push(const T &p, std::size_t cost, std::size_t heur) {

  //TODO
  
  State<T> state(p,cost,heur);
  
  //implement this the same way we implemented pop in the heap lecture. Compare using getFCost

  	if (size == 0){
		heap.insert(0, state);
		heap.getEntry(0).updatePathCost(cost);
	}
	
	else{		
		
		size_t k = size; // Location of new item
		size_t pops = k >> 1; // Parent
		
		// swap with pops
		while ((pops >= 1) && (heap.getEntry(pops).getPathCost() > state.getPathCost())){
			heap.setEntry(k, heap.getEntry(pops));
			k = pops;
			pops = pops >> 1;
		}
		
		heap.insert(k, state);
		heap.getEntry(k).updatePathCost(cost);
	}
	size++;
}

template <typename T>
bool frontier_queue<T>::empty() {

  //TODO

  return (size == 0);
}

template <typename T> 
bool frontier_queue<T>::contains(const T &p) {

  //TODO
	for(size_t i = 0; i < size; i++){
		if(heap.getEntry(i).getValue() == p)
			return true;
	}
	
  return false;

}

template <typename T>
void frontier_queue<T>::replaceif(const T &p, std::size_t cost) {

    //TODO
    
	for(size_t i = 0; i < size; i++){
		size_t g = heap.getEntry(i).getPathCost();
		size_t f = heap.getEntry(i).getFCost();
		
		if(g < cost && (cost == heap.getEntry(i).getPathCost())){
			heap.getEntry(i).updatePathCost(cost);
			break;
		}
	}
}


