/**
 * @file test_array_list.cpp
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

#include "array_list.hpp"

//force class expansion
template class ArrayList<int>;

TEST_CASE( "Test", "[ArrayList]" ) {
  ArrayList<int> list;
}

TEST_CASE("Test Construction/Destruction", "[ArrayList]") {
  ArrayList<int> arr;
  REQUIRE(arr.getLength() == 0);
  REQUIRE(arr.isEmpty());
}

TEST_CASE("Test Insert", "[ArrayList]") {
  ArrayList<int> arr;
  REQUIRE(arr.getLength() == 0);
  REQUIRE(arr.isEmpty());

  int position = 0, item = 42;
  REQUIRE(arr.insert(position, item));
  REQUIRE(arr.getLength() == 1);
  REQUIRE(!arr.isEmpty());
}

TEST_CASE("Test Remove", "[ArrayList]") {
  ArrayList<int> arr;
  REQUIRE(arr.getLength() == 0);
  REQUIRE(arr.isEmpty());

  int position = 0, item = 42;
  REQUIRE(arr.insert(position, item));
  REQUIRE(arr.getLength() == 1);
  REQUIRE(!arr.isEmpty());

  REQUIRE(arr.remove(position));
  REQUIRE(arr.getLength() == 0);
  REQUIRE(arr.isEmpty());
}

TEST_CASE("Test Clear", "[ArrayList]") {
  ArrayList<int> arr;
  REQUIRE(arr.getLength() == 0);
  REQUIRE(arr.isEmpty());
  arr.clear();
  REQUIRE(arr.getLength() == 0);
  REQUIRE(arr.isEmpty());
}

TEST_CASE("Test Is Empty", "[ArrayList]") {
  ArrayList<int> arr;
  REQUIRE(arr.getLength() == 0);
  REQUIRE(arr.isEmpty());
}


