/**
 * @file abstract_priority_queue.hpp
 * @author Amit Nafshi (amn102@pitt.edu)
 * @brief Programming Problem: 07
 * @version 0.1
 * @date 2023-07-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _ABSTRACT_PRIORITY_QUEUE_HPP_
#define _ABSTRACT_PRIORITY_QUEUE_HPP_

// type T must be orderable (support operator<)
template <typename T>
class AbstractPriorityQueue
{
public:

  // return true if the priority queue is empty
  virtual bool isEmpty() const = 0;

  // insert item into the queue
  virtual void add(const T& item) = 0;

  // remove highest priority item from the queue
  virtual void remove() = 0;

  // get the item with the highest priority from the queue
  virtual T peek() = 0;
};

#endif // _ABSTRACT_PRIORITY_QUEUE_HPP_
