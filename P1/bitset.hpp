//Start include guard and define BITSET_HPP
#ifndef BITSET_HPP
#define BITSET_HPP

//Include iostream and c standard library
#include <iostream>
#include <cstdint>

class Bitset{
public:

  /*This default constructor sets the bitset size to 8 and initializes
  the bitset to zero. Sets validity equal to true.*/
  Bitset();

  /*This copy constructor sets the bitset size to size and initializes
  the bitset to zero. Sets validity equal to true if size is greater than zero.*/
  Bitset(intmax_t size);

  /*This copy constructor sets the bitset size to the length of the string 
  value and initializes the bitset to the string vlue. If the index of the 
  bitset is not equal to zero and one it is not valid. Sets validity equal
  to true otherwise */
  Bitset(const std::string & value);

  //This destructor deallocated the bitsets memory if it has allocated memory
  ~Bitset();

  Bitset(const Bitset & ) = delete;
  
  Bitset & operator=(const Bitset &) = delete;

  //This member function returns the size of the bitset
  intmax_t size() const;

  /*This member function checks to see if the bitset is valid or not.
  the bitset is valid if the index of the bitset is equal to zero or one
  (account for characters and integers) and if the bit set size is greater 
  than zero.*/
  bool good() const;

  /*This member function sets the chosen index of the bitset, given by the 
  argument, equal to one and the validity equal to true.*/
  void set(intmax_t index);

  /*This member function sets the chosen index of the bitset, given by the 
  argument, equal to zero and the validity equal to true.*/
  void reset(intmax_t index);

  /*This member function sets the chosen index of the bitset, given by the 
  argument, equal to one if it is zero and equal to zero if it is one. In 
  other words, it toggles. The validity equal to true if conditions are met.*/
  void toggle(intmax_t index);

  /*This member function tests to see if the index inputted by the user
  is set (equal to one), if so return true. Else, return false.*/
  bool test(intmax_t index);

  //This member function represents the bitset as a string
  std::string asString() const;

private:

  //Here we have initialized our private member variables
  uint8_t *bitset;
  bool validity;
  int bitsize;
};

//End include guard
#endif
