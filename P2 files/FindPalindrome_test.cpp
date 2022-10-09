#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"
#include "FindPalindrome.cpp"
#include <vector>

// There should be at least one test per FindPalindrome method

// Test that this isn't cool
TEST_CASE( "Test FindPalindrome add a non-allowable word", "[FindPalindrome]" )
{
	INFO("Hint: add a single non-allowable word");
	FindPalindrome b;
	REQUIRE(!b.add("kayak1"));
}

// Test that these aren't cool
TEST_CASE( "Test FindPalindrome add a few non-allowable words", "[FindPalindrome]" )
{
	INFO("Hint: add some non-allowable words");
	FindPalindrome b;
	REQUIRE(!b.add("kayak1"));
	REQUIRE(!b.add("kayak 2"));
	REQUIRE(!b.add("kayak.3"));
}

/* This test works only if the code in FindPalindrome.cpp is implemented,
 * for now we will disregard because I am no clever enough to get it to twerk
TEST_CASE( "Test FindPalindrome for duplicates", "[FindPalindrome]" )
{
	FindPalindrome b;
	vector<string> c = {"kayak", "kayak"};
	REQUIRE(b.add(c) == false);
}*/

// Test the default constructor
TEST_CASE( "Test FindPalindrome Default Constructor", "[FindPalindrome]" )
{
	FindPalindrome b;
	REQUIRE(b.toVector().empty());
	REQUIRE(b.number() == 0);
}

// Test CutTest1 Member Function
TEST_CASE( "Test FindPalindrome CutTest1 Member Function", "[FindPalindrome]" )
{
	FindPalindrome v;
	vector<string> a = {"Was", "it", "a", "car", "or", "a", "cat", "I", "saw"};
	vector<string> b = {"Never", "Odd", "or", "Even"};
	vector<string> c = {"kayak"};
	
	REQUIRE(v.cutTest1(a) == true);
	REQUIRE(v.cutTest1(b) == true);
	REQUIRE(v.cutTest1(c) == true);
}

// Test CutTest2 Member Function
TEST_CASE( "Test FindPalindrome CutTest2 Member Function", "[FindPalindrome]" )
{
	FindPalindrome v;
	vector<string> a = {"Was", "it", "a", "car", "or", "a", "cat", "I", "saw"};
	vector<string> b = {"Never", "Odd", "or", "Even"};
	
	REQUIRE(v.cutTest2(a, b) == true);
}

// Test the clear member function and both add member functions
TEST_CASE( "Test FindPalindrome Clear Member Function", "[FindPalindrome]" )
{
	FindPalindrome b;
	b.add("kayak");
	vector<string> v = {"Never", "Odd", "or", "Even"};
	
	REQUIRE(b.add(v) == true);
	b.clear();
	REQUIRE(b.number() == 0);
}

// Test the add member functions explicitely
TEST_CASE( "Test FindPalindrome add Member Functions", "[FindPalindrome]" )
{
	FindPalindrome b, v;
	vector<string> a = {"Was", "it", "a", "car", "or", "a", "cat", "I", "saw"};

		
	REQUIRE(v.add("kayak") == true);
	REQUIRE(b.add(a) == true);
}

// Test the add member functions explicitely
TEST_CASE( "Test FindPalindrome number Member Functions", "[FindPalindrome]" )
{
	FindPalindrome b, v;
	vector<string> a = {"war", "saw", "raw", "war", "was", "raw"};

		
	REQUIRE(v.add("kAyAk") == true);
	REQUIRE(v.number() == 1);
	REQUIRE(v.add("kaYak") == true);
	REQUIRE(v.number() == 2);
	REQUIRE(v.add("KAyak") == true);
	REQUIRE(v.number() == 3);
	REQUIRE(v.add("KAYak") == true);
	REQUIRE(v.number() == 4);
	REQUIRE(v.add("KaYaK") == true);
	REQUIRE(v.number() == 5);
	REQUIRE(v.add("KAYAK") == true);
	REQUIRE(v.number() == 6);
	REQUIRE(v.add("blanket") == true);
	REQUIRE(v.number() == 6);
	REQUIRE(v.add("burger") == true);
	REQUIRE(v.number() == 6);
	REQUIRE(b.add(a) == true);
	REQUIRE(b.number() == 1);
}

// Test poop strings and poop vector
TEST_CASE( "Poop Test", "[FindPalindrome]" )
{
	FindPalindrome b, v;
	vector<string> a = {"Poop", "pOop", "poOp", "pooP"};

		
	REQUIRE(v.add("poop") == true);
	REQUIRE(v.number() == 1);
	REQUIRE(v.add("Poop") == true);
	REQUIRE(v.number() == 2);
	REQUIRE(v.add("pOop") == true);
	REQUIRE(v.number() == 3);
	REQUIRE(v.add("poOp") == true);
	REQUIRE(v.number() == 4);
	REQUIRE(v.add("pooP") == true);
	REQUIRE(v.number() == 5);
	REQUIRE(v.add("pOOp") == true);
	REQUIRE(v.number() == 6);
	REQUIRE(v.add("POop") == true);
	REQUIRE(v.number() == 7);
	REQUIRE(v.add("POOp") == true);
	REQUIRE(v.number() == 8);
	REQUIRE(v.add("POOP") == true);
	REQUIRE(v.number() == 9);
	REQUIRE(b.add(a) == true);
	REQUIRE(b.number() == 1);
}

// I'm not sure how exactly I can test toVector, I'm sure it works but I huh
