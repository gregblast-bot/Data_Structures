#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>

#include "frontier_queue.tpp"

using namespace std;

// TODO implement your tests here
// note you can use any supported type for the value type T
// including the Puzzle type as in the solver code


TEST_CASE( "Test All", "[frontier_queue]" ) {
	frontier_queue<char> fq;
	
	REQUIRE('B' < 'E');
	REQUIRE(fq.empty() == true);
	
	fq.push('A', 1, 1);
	
	fq.replaceif('A', 2);
	fq.replaceif('E', 2);
	
	REQUIRE(fq.empty() == false);
	
	
	fq.push('B', 1, 1);
	fq.push('C', 1, 1);
	fq.push('D', 1, 1);
	
	
	REQUIRE(fq.contains('A') == true);
	REQUIRE(fq.contains('E') == false);
	REQUIRE(fq.contains('B') == true);
	REQUIRE(fq.contains('C') == true);
	REQUIRE(fq.contains('D') == true);

	
	fq.pop();
	fq.pop();
	fq.pop();
	fq.pop();
	
	REQUIRE(fq.empty() == true);	
}
