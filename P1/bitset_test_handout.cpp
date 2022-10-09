/**
    ECE-1570 Project 1 Test
    bitset_test_handout.cpp
    Purpose: Test the Bitset implementation

    @author Haihui Zhu
    @version 1.1 9/7/19
*/

#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include <iostream>

#include "bitset.hpp"
#include "bitset.cpp"

// Test 1
TEST_CASE( "Test-1", "[bitset]" ) {
    std::string s("00010001");
    Bitset b;
    b.set(3);
    b.set(7);
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);
}

// Test 2
TEST_CASE( "Test-2", "[bitset]" ) {
    std::string s("00010");
    Bitset b(5);
    b.set(3);
    REQUIRE(b.size() == 5);
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);
}

// Test 3, only works when I compare b.asString().compare(s) == 4
TEST_CASE( "Test-3", "[bitset]" ) {
    std::string s((1<<15) + 3, '0');
    Bitset b(s);
    REQUIRE(b.size() == s.size());
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);

    for (int i = 1; i < (1<<10); i++) {
        b.set(i);
        b.reset(i + (1<<10));
        b.toggle(i + (1<<11));
        REQUIRE(b.good());
        REQUIRE(b.test(i));
        REQUIRE_FALSE(b.test(i + (1<<10)));
        REQUIRE(((b.test(i + (1<<11)) == true && s.at(i + (1<<11)) == '0') || (b.test(i + (1<<11)) == false && s.at(i + (1<<11)) == '1')));
    }
}
