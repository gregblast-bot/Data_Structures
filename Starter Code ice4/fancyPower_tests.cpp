#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "fancyPower.hpp"

// write your test cases here
// TEST THEM POWERS OF TWO
TEST_CASE("Test case 2^0", "fancyPower"){

  REQUIRE(fancyPower(2,0) == 1);
  
}

// TEST THEM POWERS OF TWO
TEST_CASE("Test case 2^1", "fancyPower"){

  REQUIRE(fancyPower(2,1) == 2);
  
}

// TEST THEM POWERS OF TWO
TEST_CASE("Test case 2^2", "fancyPower"){

  REQUIRE(fancyPower(2,2) == 4);
  
}

// TEST THEM POWERS OF TWO
TEST_CASE("Test case 2^3", "fancyPower"){

  REQUIRE(fancyPower(2,3) == 8);
  
}

// TEST THEM POWERS OF TWO
TEST_CASE("Test case 2^4", "fancyPower"){

  REQUIRE(fancyPower(2,4) == 16);
  
}

// TEST THEM POWERS OF TWO
TEST_CASE("Test case 2^5", "fancyPower"){

  REQUIRE(fancyPower(2,5) == 32);
  
}

// TEST THEM POWERS OF TWO
TEST_CASE("Test case 2^6", "fancyPower"){

  REQUIRE(fancyPower(2,6) == 64);
  
}

// TEST THEM POWERS OF TWO
TEST_CASE("Test case 2^7", "fancyPower"){

  REQUIRE(fancyPower(2,7) == 128);
  
}

// TEST THEM POWERS OF TWO
TEST_CASE("Test case 2^8", "fancyPower"){

  REQUIRE(fancyPower(2,8) == 256);
  
}
