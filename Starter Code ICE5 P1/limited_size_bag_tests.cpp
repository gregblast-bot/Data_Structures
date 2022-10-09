#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "limited_size_bag.hpp"

// force template expansion for ints
template class LimitedSizeBag<int>;

TEST_CASE("Test Construction/Destruction", "[Bag]"){

  LimitedSizeBag<int> b;
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());
}

TEST_CASE("Test add", "[Bag]"){

  LimitedSizeBag<int> b;
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());

  for(unsigned int i = 0; i < LimitedSizeBag<int>::MAXSIZE; ++i){
    REQUIRE(b.add(i));
    REQUIRE(b.getCurrentSize() == i+1);
    REQUIRE(!b.isEmpty());
  }
  REQUIRE(!b.add(0));
}

TEST_CASE("Test remove", "[Bag]"){

  LimitedSizeBag<int> b;
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());

  for(unsigned int i = 0; i < LimitedSizeBag<int>::MAXSIZE; ++i){
    REQUIRE(b.add(i));
    REQUIRE(b.getCurrentSize() == i+1);
    REQUIRE(!b.isEmpty());
  }

  REQUIRE(!b.remove(-1));
  
  for(unsigned int i = 0; i <  LimitedSizeBag<int>::MAXSIZE; ++i){
    REQUIRE(b.remove(i));
  }
  REQUIRE(!b.remove(0));
}

TEST_CASE("Test clear", "[Bag]"){

  LimitedSizeBag<int> b;
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());
  b.clear();
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());

  for(unsigned int i = 0; i < LimitedSizeBag<int>::MAXSIZE; ++i){
    REQUIRE(b.add(i));
    REQUIRE(b.getCurrentSize() == i+1);
    REQUIRE(!b.isEmpty());
  }

  b.clear();
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());
  
}

TEST_CASE("Test frequency", "[Bag]"){

  {
    LimitedSizeBag<int> b;
    REQUIRE(b.getCurrentSize() == 0);
    REQUIRE(b.isEmpty());
    REQUIRE(b.getFrequencyOf(0) == 0);
    
    for(unsigned int i = 0; i < LimitedSizeBag<int>::MAXSIZE; ++i){
      REQUIRE(b.add(i));
      REQUIRE(b.getCurrentSize() == i+1);
      REQUIRE(!b.isEmpty());
    }
    
    for(unsigned int i = 0; i < LimitedSizeBag<int>::MAXSIZE; ++i){
      REQUIRE(b.getFrequencyOf(i) == 1);
    }
  }
  
  {
    LimitedSizeBag<int> b;
    REQUIRE(b.getCurrentSize() == 0);
    REQUIRE(b.isEmpty());
    
    for(unsigned int i = 0; i < LimitedSizeBag<int>::MAXSIZE; ++i){
      REQUIRE(b.add(-1));
      REQUIRE(b.getCurrentSize() == i+1);
      REQUIRE(!b.isEmpty());
    }

    std::size_t EXPECTED = LimitedSizeBag<int>::MAXSIZE;
    REQUIRE(b.getFrequencyOf(-1) == EXPECTED);
    REQUIRE(b.getFrequencyOf(0) == 0);
  }
}


TEST_CASE("Test contains", "[Bag]"){

  {
    LimitedSizeBag<int> b;
    REQUIRE(b.getCurrentSize() == 0);
    REQUIRE(b.isEmpty());
    REQUIRE(!b.contains(0));
	
    for(unsigned int i = 0; i < LimitedSizeBag<int>::MAXSIZE; ++i){
      REQUIRE(b.add(i));
      REQUIRE(b.getCurrentSize() == i+1);
      REQUIRE(!b.isEmpty());
    }
    
    for(unsigned int i = 0; i < LimitedSizeBag<int>::MAXSIZE; ++i){
      REQUIRE(b.contains(i));
    }
    REQUIRE(!b.contains(-1));
  }
  
  {
    LimitedSizeBag<int> b;
    REQUIRE(b.getCurrentSize() == 0);
    REQUIRE(b.isEmpty());
    REQUIRE(!b.contains(0));
    
    for(unsigned int i = 0; i < LimitedSizeBag<int>::MAXSIZE; ++i){
      REQUIRE(b.add(-1));
      REQUIRE(b.getCurrentSize() == i+1);
      REQUIRE(!b.isEmpty());
    }

    REQUIRE(b.contains(-1));
    REQUIRE(!b.contains(0));
  }
}

//Bagception
TEST_CASE("Test Copy Construction/Destruction", "[Bag]"){

  LimitedSizeBag<int> b;
  b.add(10); b.add(10); b.add(10); b.add(10); b.add(10);
  //b is a bag that contains 5 items (5 number 10's)
  REQUIRE(b.getCurrentSize() == 5);
  b.add(10); b.add(10); b.add(10); b.add(10); b.add(10);
  LimitedSizeBag<int> b1(b);
  //b is a bag that now contains 10 items (10 number 10's)
  REQUIRE(b.getCurrentSize() == 10);
  //b1 now contains b that now contains 10 items
  REQUIRE(b1.getCurrentSize() == 10);
}
