//Define catch and include it so you can utilize it
#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

//Include bitset.hpp and bitset.cpp so you can test those
#include "bitset.hpp"
#include "bitset.cpp"

// THIS IS JUST AN EXAMPLE
// There should be at least one test per Bitset method
//This tests the default bitset constuctor
TEST_CASE( "Test bitset construction", "[bitset]" ) {

    Bitset b;  
    REQUIRE(b.size() == 8);
    REQUIRE(b.good() == true);
}

//This tests the overload constructor with argument intmax_t 
TEST_CASE( "Test valid bitset intmax_t copy constructor", "[bitset]" ) {

    Bitset b(10);  
    REQUIRE(b.size() == 10);
    REQUIRE(b.good() == true);
}

//This tests the overload constructor with argument string 
TEST_CASE( "Test valid bitset string copy constructor", "[bitset]" ) {

    Bitset b("0101010101010101");  
    REQUIRE(b.size() == 16);
    REQUIRE(b.good() == true);
}

//This test for valid bitset and size, already tested in the constructors
//This has slightly different cases
TEST_CASE( "Test valid bitset and size", "[bitset]" ) {

    Bitset b1(54321); 
    Bitset b2("11011001010010110111011111000101000100111010000000010000");
    REQUIRE(b1.size() == 54321);
    REQUIRE(b1.good() == true);
    REQUIRE(b2.size() == 56);
    REQUIRE(b2.good() == true);
}

//Test to see if a bitset of size zero is invalid
//Tested negative but kept getting std::bad_alloc exception, don't know how to work around that
TEST_CASE( "Test invalid bitset size zero", "[bitset]" ) {

    Bitset b(0);
    REQUIRE(b.good() == false);
}

//Test the set member function (make a zero a one)
TEST_CASE( "Test valid set member function", "[bitset]" ) {

    Bitset b(6);
    b.set(2);
    REQUIRE(b.test(2) == true);
}

//Test the set member function (make a zero a one) for string
TEST_CASE( "Test valid set member function for string", "[bitset]" ) {

    Bitset b("000000");
    b.set(2);
    REQUIRE(b.test(2) == true);
}

//Test the reset member function (make a one a zero)
TEST_CASE( "Test valid reset member function", "[bitset]" ) {

    Bitset b(6);
    b.reset(5);
    REQUIRE(b.test(5) == false);
}

//Test the reset member function (make a one a zero) for string
TEST_CASE( "Test valid reset member function for string", "[bitset]" ) {

    Bitset b("111111");
    b.reset(5);
    REQUIRE(b.test(5) == false);
}

//Test the toggle member function (make a one a zero snd make zero one)
TEST_CASE( "Test valid toggle member function", "[bitset]" ) {

    Bitset b(6);
    b.toggle(5);
    REQUIRE(b.test(5) == true);
}

//Test the toggle member function (make a one a zero snd make zero one)
TEST_CASE( "Test valid toggle member function for string", "[bitset]" ) {

    Bitset b("111111");
    b.toggle(5);
    REQUIRE(b.test(5) == false);
}

//Test the asString member function to make thing string
TEST_CASE( "Test valid asString member function", "[bitset]" ) {

    Bitset b(6);
    b.asString();
    REQUIRE(b.good() == true);
}




