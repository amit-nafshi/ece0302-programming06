#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "dynamic_bag.hpp"

// Force template expansion for ints
template class DynamicBag<int>;

TEST_CASE("Test Type", "[DynamicBag]"){
  REQUIRE((std::is_base_of<AbstractBag<int>, DynamicBag<int>>::value) == 1);
}

TEST_CASE("Test Construction/Destruction", "[DynamicBag]"){

  DynamicBag<int> bag;
  REQUIRE(bag.getCurrentSize() == 0);
  REQUIRE(bag.isEmpty());
}

TEST_CASE("Test add", "[DynamicBag]"){

  DynamicBag<int> bag;
  REQUIRE(bag.getCurrentSize() == 0);
  REQUIRE(bag.isEmpty());

  int item = 42;
  REQUIRE(bag.add(item));
  REQUIRE(bag.getCurrentSize() == 1);
  REQUIRE(!bag.isEmpty());
}

TEST_CASE("Test remove", "[DynamicBag]"){

  DynamicBag<int> bag;
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

TEST_CASE("Test clear", "[DynamicBag]"){

  DynamicBag<int> bag;
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

TEST_CASE("Test frequency", "[DynamicBag]"){

  DynamicBag<int> bag;
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

TEST_CASE("Test contains", "[DynamicBag]"){

  DynamicBag<int> bag;
  REQUIRE(bag.getCurrentSize() == 0);
  REQUIRE(bag.isEmpty());

  int item = 42;
  REQUIRE(!bag.contains(item));

  REQUIRE(bag.add(item));
  REQUIRE(bag.getCurrentSize() == 1);
  REQUIRE(!bag.isEmpty());
  REQUIRE(bag.contains(item));
}

