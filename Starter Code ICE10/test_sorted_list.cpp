#include "dynamic_array_list.h"
#include "sorted_list.h"
#include <iostream>
#include <assert.h>

using namespace std;

typedef SortedList<char, DynamicArrayList<char> > slst;

int main()
{
  slst S1;
  
  S1.insert('h');
  S1.insert('n');
  S1.insert('e');
  S1.insert('r');
  S1.insert('f');
  S1.insert('b');
  S1.insert('c');
  S1.insert('d');
  
  assert(S1.getPosition('b') == 0);
  assert(S1.getEntry(1) == 'c');
  assert(S1.getPosition('d') == 2);
  assert(S1.getEntry(3) == 'e');
  assert(S1.getPosition('f') == 4);
  assert(S1.getEntry(5) == 'h');
  assert(S1.getPosition('n') == 6);
  assert(S1.getEntry(7) == 'r');
  
  // Extra check
  for(int i = 0; i < 7; i++){
    cout << S1.getEntry(i) << endl;
  }
  
  S1.clear();
  assert(S1.isEmpty() == true);
  
  return 0;
}
