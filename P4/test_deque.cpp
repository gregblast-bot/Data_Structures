#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "deque.hpp"

TEST_CASE( "Bitchass Test 1", "[deque]" ) {
	Deque<int> D;
	
	REQUIRE(D.isEmpty() == true);
}

TEST_CASE( "Bitchass Test 2", "[deque]" ) {
	Deque<int> D;
	
	D.pushFront(1);
	REQUIRE(D.front() == 1);
	REQUIRE(D.back() == 1);
	REQUIRE(D.isEmpty() == false);
	
	D.pushBack(2);
	REQUIRE(D.front() == 1);
	REQUIRE(D.back() == 2);
	REQUIRE(D.isEmpty() == false);
	
	D.popFront();
	REQUIRE(D.front() == 2);
	REQUIRE(D.front() == 2);
	REQUIRE(D.isEmpty() == false);
	
	D.pushBack(3);
	REQUIRE(D.front() == 2);
	REQUIRE(D.back() == 3);
	REQUIRE(D.isEmpty() == false);
	
	D.popBack();
	REQUIRE(D.front() == 2);
	REQUIRE(D.back() == 2);
	REQUIRE(D.isEmpty() == false);
	
	D.popFront();
	REQUIRE(D.isEmpty() == true);
	
}

