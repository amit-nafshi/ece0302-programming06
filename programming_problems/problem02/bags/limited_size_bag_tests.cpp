/**
 * @file limited_size_bag_tests.cpp
 * @author Amit Nafshi (amn102@pitt.edu)
 * @brief 
 * @version 0.1
 * @date 2023-06-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "limited_size_bag.hpp"

// force template expansion for ints
template class LimitedSizeBag<int>;

TEST_CASE("Calling all public members", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  b.add(0);
  b.remove(0);
  b.isEmpty();
  b.getCurrentSize();
  b.clear();
  b.getFrequencyOf(0);
  b.contains(0);

}

TEST_CASE("Test Construction/Destruction", "[Bag]"){
  LimitedSizeBag<int> b;
  
  REQUIRE(b.getCurrentSize() == 0);
  REQUIRE(b.isEmpty());
}

TEST_CASE("Test add", "[LimitedSizeBag]"){
  LimitedSizeBag<int> bag;
  
  REQUIRE(bag.getCurrentSize() == 0);
  REQUIRE(bag.isEmpty());

  int item = 42;
  REQUIRE(bag.add(item));
  REQUIRE(bag.getCurrentSize() == 1);
  REQUIRE(!bag.isEmpty());
}

TEST_CASE("Test remove", "[LimitedSizeBag]"){
  LimitedSizeBag<int> bag;
  
  REQUIRE(bag.getCurrentSize() == 0);
  REQUIRE(bag.isEmpty());

  int item = 42;
  REQUIRE(bag.add(item));
  REQUIRE(bag.getCurrentSize() == 1);
  REQUIRE(!bag.isEmpty());

  REQUIRE(bag.remove(item));
  REQUIRE(bag.getCurrentSize() == 0);
  REQUIRE(bag.isEmpty());
}

TEST_CASE("Test clear", "[LimitedSizeBag]"){
  LimitedSizeBag<int> bag;
  
  REQUIRE(bag.getCurrentSize() == 0);
  REQUIRE(bag.isEmpty());
  bag.clear();
  REQUIRE(bag.getCurrentSize() == 0);
  REQUIRE(bag.isEmpty());

  int item = 42;
  REQUIRE(bag.add(item));
  REQUIRE(bag.getCurrentSize() == 1);
  REQUIRE(!bag.isEmpty());

  bag.clear();
  REQUIRE(bag.getCurrentSize() == 0);
  REQUIRE(bag.isEmpty());
}

TEST_CASE("Test frequency", "[LimitedSizeBag]"){
  LimitedSizeBag<int> bag;
  
  REQUIRE(bag.getCurrentSize() == 0);
  REQUIRE(bag.isEmpty());
  REQUIRE(bag.getFrequencyOf(0) == 0);

  int item = 42;
  REQUIRE(bag.add(item));
  REQUIRE(bag.getCurrentSize() == 1);
  REQUIRE(!bag.isEmpty());
  REQUIRE(bag.getFrequencyOf(item) == 1);

  int duplicateItem = 42;
  REQUIRE(bag.add(duplicateItem));
  REQUIRE(bag.getCurrentSize() == 2);
  REQUIRE(bag.getFrequencyOf(item) == 2);
}

TEST_CASE("Test contains", "[LimitedSizeBag]"){
  LimitedSizeBag<int> bag;
  
  REQUIRE(bag.getCurrentSize() == 0);
  REQUIRE(bag.isEmpty());

  int item = 42;
  REQUIRE(!bag.contains(item));

  REQUIRE(bag.add(item));
  REQUIRE(bag.getCurrentSize() == 1);
  REQUIRE(!bag.isEmpty());
  REQUIRE(bag.contains(item));
}
