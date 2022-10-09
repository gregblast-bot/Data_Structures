#ifndef FRONTIER_QUEUE_HPP
#define FRONTIER_QUEUE_HPP

#include "state.tpp"
#include "dynamic_array_list.tpp"

// TODO add necessary includes
#include <vector>
#include <iostream>

template <typename T>
class frontier_queue {
public:

  /* Returns true if the frontier is empty, else false
   */
  bool empty();

  /* push a State with value p, cost, and heuristic into the frontier.
   * This should be a O(log n) operation
   */
  void push(const T &p, std::size_t cost, std::size_t heur);

  /* this will be a queue of states.
   * you need to create a state from the passed inputs, and then add it to the queue.
   * pop the state from the frontier with the smallest f-cost
   * This should be a O(log n) operation
   */
  State<T> pop();

  /* Returns true if the T p is in the frontier
   * This may be at most an O(n) operation
   */
  bool contains(const T &p);

  /* Replaces a state in the container if the path cost is lower.
   * The frontier should be updated to reflect the new value.
   * This should be at most a O(n) operation.
   */
  void replaceif(const T &p, std::size_t cost);

  // SORT DAT LIST	
  void MinHeapify(int i); 
  
private:

  //std::vector<State<T>> queue; Nah, no vectors for daddy today
  DynamicArrayList<State<T>> heap;
  size_t size = 0;
  
};

#endif
