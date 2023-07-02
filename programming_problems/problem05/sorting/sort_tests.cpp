/**
 * @file sort_tests.cpp
 * @author Amit Nafshi (amn102@pitt.edu)
 * @brief Programming Problem 5
 * @version 0.1
 * @date 2023-06-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"
#include "sort.hpp"

// write your test cases here
TEST_CASE("Test case", "sorting"){

  LinkedList<int> lst;

  lst.insert(0, 100);
  lst.insert(1, 4);
  lst.insert(2, 10);
  lst.insert(3, 25);
  lst.insert(4, 11);

  LinkedList<int> sorted = sort(lst);

  // check sorted list
  REQUIRE(sorted.getEntry(0) == 4);
  REQUIRE(sorted.getEntry(1) == 10);
  REQUIRE(sorted.getEntry(2) == 11);
  REQUIRE(sorted.getEntry(3) == 25);
  REQUIRE(sorted.getEntry(4) == 100);
  
}

TEST_CASE("Test Char", "sorting") {
    LinkedList<char> list;

    list.insert(0, 'b');
    list.insert(1, 'a');
    list.insert(2, 'c');
    list.insert(3, 'e');
    list.insert(4, 'd');

    LinkedList<char> sorted = sort(list);

    REQUIRE(sorted.getEntry(0) == 'a');
    REQUIRE(sorted.getEntry(1) == 'b');
    REQUIRE(sorted.getEntry(2) == 'c');
    REQUIRE(sorted.getEntry(3) == 'd');
    REQUIRE(sorted.getEntry(4) == 'e');
}

TEST_CASE("Sort list with duplicate elements", "[sorting]") {
    LinkedList<int> list;

    list.insert(0, 8);
    list.insert(1, 5);
    list.insert(2, 3);
    list.insert(3, 5);
    list.insert(4, 8);

    LinkedList<int> sorted = sort(list);

    REQUIRE(sorted.getEntry(0) == 3);
    REQUIRE(sorted.getEntry(1) == 5);
    REQUIRE(sorted.getEntry(2) == 5);
    REQUIRE(sorted.getEntry(3) == 8);
    REQUIRE(sorted.getEntry(4) == 8);
}
