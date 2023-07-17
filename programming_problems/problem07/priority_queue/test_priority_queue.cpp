/**
 * @file test_priority_queue.cpp
 * @author Amit Nafshi (amn102@pitt.edu)
 * @brief Programming Problem: 07
 * @version 0.1
 * @date 2023-07-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "list.hpp"
#include "sorted_list.hpp"
#include "priority_queue.hpp"

TEST_CASE("Testing Priority Queue", "[priority queue]") {
  typedef SortedList<int, List<int>> SortedListType;
  typedef PriorityQueue<int, SortedListType>  PriorityQueueType;

  PriorityQueueType pq;

  SECTION("Testing Priority Queue Construction and isEmpty") 
  {
    REQUIRE(pq.isEmpty() == true);
  }

  SECTION("Testing Priority Queue Add and isEmpty") 
  {
    pq.add(5);
    REQUIRE(pq.isEmpty() == false);
  }

  SECTION("Testing Priority Queue Add and Peek") 
  {
    pq.add(5);
    REQUIRE(pq.peek() == 5);
  }

  SECTION("Testing Priority Queue Add Multiple") 
  {
    pq.add(5);
    pq.add(10);
    pq.add(15);
    REQUIRE(pq.peek() == 15);
  }

  SECTION("Testing Priority Queue Add and Remove") 
  {
    pq.add(5);
    pq.remove();
    REQUIRE(pq.isEmpty() == true);
  }

  SECTION("Testing Priority Queue Add and Remove Multiple") 
  {
    pq.add(5);
    pq.add(10);
    pq.add(15);
    pq.remove();
    REQUIRE(pq.peek() == 10);
  }
}
