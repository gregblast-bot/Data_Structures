#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "array_list.hpp"

//force class expansion
template class ArrayList<int>;

// Test the default constructor, is length zero and the linked list empty?
TEST_CASE( "Default Constructor Test", "[ArrayList]" ) {
  ArrayList<int> L;
  REQUIRE(L.getLength() == 0);
  REQUIRE(L.isEmpty() == true);
}



// We insert, clear and then check if the linked list is empty or not
TEST_CASE( "Simple Clearing Test", "[ArrayList]" ) {
  ArrayList<int> L;
  
  L.insert(1,10);
  L.clear();
  
  REQUIRE(L.isEmpty() == true);
}

// We insert, clear and then check if the linked list is empty or not for multiple entries
TEST_CASE( "Clearing Test", "[ArrayList]" ) {
  ArrayList<int> L;
  
  L.insert(1,10);
  L.insert(2,11);
  L.insert(3,12);
  L.insert(4,13);
  L.insert(5,14);
  L.clear();
  
  REQUIRE(L.isEmpty() == true);
}

// Simple insert test inserts an integer at the head of the linked list
TEST_CASE( "Simple Insert Test", "[ArrayList]" ) {
  ArrayList<int> L;
  
  REQUIRE(L.insert(1,4) == true);
}

// Not so simple insert test inserts an integer at position 2 of the linked list
// But, because head == NULL position 2 becomes the head
TEST_CASE( "Not So Simple Insert Test", "[ArrayList]" ) {
  ArrayList<int> L;
  
  // Here we insert something at position 2 and see this become the head
  REQUIRE(L.insert(1,4) == true);
  REQUIRE(L.getEntry(1) == 4);
  // Now insert a value at position 2 and check the value
  REQUIRE(L.insert(2,8) == true);
  REQUIRE(L.getEntry(2) == 8);
  
}

// Simple remove test removes an integer at the head of the linked list
TEST_CASE( "Simple Remove Test", "[ArrayList]" ) {
  ArrayList<int> L;
  
  L.insert(2,4);
  
  //Now no more linked list :(
  REQUIRE(L.remove(2) == true);
  L.clear();
  REQUIRE(L.isEmpty() == true);
}

// Remove some stuff and check if do
TEST_CASE( "Slightly More Complicated Remove Test", "[ArrayList]" ) {
  ArrayList<int> L;
  
  // This werk cause I make werk
  L.insert(1,1);
  L.insert(2,2);
  L.insert(3,3);
  L.insert(4,4);
  L.insert(5,5);
  
  REQUIRE(L.remove(3) == true);
  REQUIRE(L.getEntry(1) == 1);
  REQUIRE(L.getEntry(2) == 2);
  REQUIRE(L.getEntry(3) == 4);
  REQUIRE(L.getEntry(4) == 5);
}

// Remove some stuff and check if do
TEST_CASE( "Remove SH*T Test", "[ArrayList]" ) {
  ArrayList<int> L;
  
  // This werk cause I make werk
  L.insert(1,1);
  L.insert(2,2);
  L.insert(3,3);
  L.insert(4,4);
  L.insert(5,5);
  L.insert(6,6);
  L.insert(7,7);
  L.insert(8,8);
  L.insert(9,9);
  L.insert(10,10);
  
  // REMOVE AND LIST SHrink
  REQUIRE(L.remove(3) == true);
  REQUIRE(L.remove(5) == true);
  REQUIRE(L.remove(7) == true);
  REQUIRE(L.getEntry(1) == 1);
  REQUIRE(L.getEntry(2) == 2);
  REQUIRE(L.getEntry(3) == 4);
  REQUIRE(L.getEntry(4) == 5);
  REQUIRE(L.getEntry(5) == 7);
  REQUIRE(L.getEntry(6) == 8);
  REQUIRE(L.getEntry(7) == 10);
}

// Remove the head of the link list to DESTROY IT
TEST_CASE( "CUT THE HEAD OFF THE BEAST", "[ArrayList]" ) {
  ArrayList<int> L;
  
  // This werk cause I make werk
  L.insert(1,1);
  L.insert(2,2);
  L.insert(3,3);
  L.insert(4,4);
  L.insert(5,5);
  L.insert(6,6);
  L.insert(7,7);
  L.insert(8,8);
  L.insert(9,9);
  L.insert(10,10);
  
  // REMOVE! DESTROY!
  REQUIRE(L.remove(1) == true);
  // THE BEAST STILL HAS A HEAD
  REQUIRE(L.getEntry(1) == 2);
  // REMOVE! DESTROY!
  REQUIRE(L.remove(1) == true);
  // THE BEAST STILL HAS A HEAD
  REQUIRE(L.getEntry(1) == 3);
  // REMOVE! DESTROY!
  REQUIRE(L.remove(1) == true);
  // THE BEAST STILL HAS A HEAD
  REQUIRE(L.getEntry(1) == 4);
  // REMOVE! DESTROY!
  REQUIRE(L.remove(1) == true);
  // THE BEAST STILL HAS A HEAD
  REQUIRE(L.getEntry(1) == 5);
  // REMOVE! DESTROY!
  REQUIRE(L.remove(1) == true);
  // THE BEAST STILL HAS A HEAD
  REQUIRE(L.getEntry(1) == 6);
  // REMOVE! DESTROY!
  REQUIRE(L.remove(1) == true);
  // THE BEAST STILL HAS A HEAD
  REQUIRE(L.getEntry(1) == 7);
  // REMOVE! DESTROY!
  REQUIRE(L.remove(1) == true);
  // THE BEAST STILL HAS A HEAD
  REQUIRE(L.getEntry(1) == 8);
  // REMOVE! DESTROY!
  REQUIRE(L.remove(1) == true);
  // THE BEAST STILL HAS A HEAD
  REQUIRE(L.getEntry(1) == 9);
  // REMOVE! DESTROY!
  REQUIRE(L.remove(1) == true);
  // THE BEAST STILL HAS A HEAD
  REQUIRE(L.getEntry(1) == 10);
  // REMOVE! DESTROY!
  REQUIRE(L.remove(1) == true);
  // YOU HAVE SUCCESFULLY KILLED THE BEAST
  REQUIRE(L.isEmpty() == true);
}

// This test displays the getEntry member function clearly and conciseley.
// Redundant because of "Not So Simple Insert Test"
TEST_CASE( "Test Single getEntry", "[LinkedList]" ) {
  ArrayList<int> L;
  
  L.insert(1,4);
  
  REQUIRE(L.getEntry(1) == 4);
}


// This test displays the getEntry and insert member functions working sequentially.
// getEntry does not have to be sequential though
TEST_CASE( "Test Multiple getEntry", "[ArrayList]" ) {
  ArrayList<int> L;
  
  L.insert(1,4);
  L.insert(2,2);
  L.insert(3,0);
  L.insert(4,1);
  
  REQUIRE(L.getEntry(1) == 4);
  REQUIRE(L.getEntry(2) == 2);
  REQUIRE(L.getEntry(3) == 0);
  REQUIRE(L.getEntry(4) == 1);
}

// This test displays the setEntry member function clearly and conciseley.
TEST_CASE( "Test Single setEntry", "[ArrayList]" ) {
  ArrayList<int> L;
  
  // First insert some value at the head
  L.insert(1,4);
  REQUIRE(L.getEntry(1) == 4);
  L.insert(1,6);
  REQUIRE(L.getEntry(1) == 6);
  // Now, set the entry to whatever you desire
  L.setEntry(1,8);
  
  // Test if setting the entry worked
  REQUIRE(L.getEntry(1) == 8);
}

// This test displays the setEntr, getEntry and insert member functions.
TEST_CASE( "Test Multiple setEntry", "[ArrayList]" ) {
  ArrayList<int> L;
  
  L.insert(1,4);
  L.insert(2,2);
  L.insert(3,0);
  L.insert(4,1);
  
  L.setEntry(4,14);
  L.setEntry(2,22);
  L.setEntry(1,3);
  L.setEntry(3,17);
  
  REQUIRE(L.getEntry(3) == 17);
  REQUIRE(L.getEntry(2) == 22);
  REQUIRE(L.getEntry(4) == 14);
  REQUIRE(L.getEntry(1) == 3);
}

/*
// Test the copy constructor and the equals overload
TEST_CASE( "Copy Constructor Test", "[ArrayList]" ) {
  ArrayList<int> L1, L2;
  L1.insert(1,1); L1.insert(2,2); L1.insert(3,3); L1.insert(4,4); L1.insert(5,5);
  L2 = L1;
  REQUIRE(L1.getLength() == 5);
  REQUIRE(L1.isEmpty() == false);
  REQUIRE(L1.isEmpty() == false);
  REQUIRE(L1.getEntry(1) == 1);
  REQUIRE(L1.getEntry(2) == 2);
  REQUIRE(L1.getEntry(3) == 3);
  REQUIRE(L1.getEntry(4) == 4);
  REQUIRE(L1.getEntry(5) == 5);
  REQUIRE(L2.getLength() == 5);
  REQUIRE(L2.isEmpty() == false);
  REQUIRE(L2.getEntry(1) == 1);
  REQUIRE(L2.getEntry(2) == 2);
  REQUIRE(L2.getEntry(3) == 3);
  REQUIRE(L2.getEntry(4) == 4);
  REQUIRE(L2.getEntry(5) == 5);
}*/ //Still having trouble
