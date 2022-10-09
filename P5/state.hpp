#ifndef STATE_HPP
#define STATE_HPP

#include <iostream>
// generic state holding a value of type T
template <typename T>
class State {
public:
  State();

  State(const T &p, std::size_t cost, std::size_t heur);

  State<T>& operator=(const State<T>& rhs);

  T getValue() const;

  void updatePathCost(std::size_t cost);
  
  std::size_t getPathCost() const;

  std::size_t getFCost() const;

private:
  
  T value;
  std::size_t g {0};
  std::size_t h {0};
  std::size_t f {0};
};

#endif
