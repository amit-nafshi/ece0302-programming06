/**
 * @file test_linked_list.cpp
 * @author Amit Nafshi (amn102@pitt.edu)
 * @brief 
 * @version 0.1
 * @date 2023-06-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"

template class LinkedList<int>;

TEST_CASE("Test Construction/Destruction", "[LinkedList]") {
  LinkedList<int> list;
  REQUIRE(list.getLength() == 0);
  REQUIRE(list.isEmpty());
}

TEST_CASE("Test Insert", "[LinkedList]") {
  LinkedList<int> list;
  REQUIRE(list.getLength() == 0);
  REQUIRE(list.isEmpty());

  int position = 0, item = 42;
  REQUIRE(list.insert(position, item));
  REQUIRE(list.getLength() == 1);
  REQUIRE(!list.isEmpty());
  REQUIRE(list.getEntry(position) == item);
}

TEST_CASE("Test Remove", "[LinkedList]") {
  LinkedList<int> list;
  REQUIRE(list.getLength() == 0);
  REQUIRE(list.isEmpty());

  int position = 0, item = 42;
  REQUIRE(list.insert(position, item));
  REQUIRE(list.getLength() == 1);
  REQUIRE(!list.isEmpty());

  REQUIRE(list.remove(position));
  REQUIRE(list.getLength() == 0);
  REQUIRE(list.isEmpty());
}

TEST_CASE("Test Clear", "[LinkedList]") {
  LinkedList<int> list;
  REQUIRE(list.getLength() == 0);
  REQUIRE(list.isEmpty());
  list.clear();
  REQUIRE(list.getLength() == 0);
  REQUIRE(list.isEmpty());
}

TEST_CASE("Test Get Entry", "[LinkedList]") {
  LinkedList<int> list;
  REQUIRE(list.getLength() == 0);
  REQUIRE(list.isEmpty());

  int position = 0, item = 42;
  REQUIRE(list.insert(position, item));
  REQUIRE(list.getLength() == 1);
  REQUIRE(!list.isEmpty());

  REQUIRE(list.getEntry(position) == item);
}

TEST_CASE("Test Set Entry", "[LinkedList]") {
  LinkedList<int> list;
  REQUIRE(list.getLength() == 0);
  REQUIRE(list.isEmpty());

  int position = 0, item = 42;
  REQUIRE(list.insert(position, item));
  REQUIRE(list.getLength() == 1);
  REQUIRE(!list.isEmpty());

  int newItem = 99;
  list.setEntry(position, newItem);
  REQUIRE(list.getEntry(position) == newItem);
}
