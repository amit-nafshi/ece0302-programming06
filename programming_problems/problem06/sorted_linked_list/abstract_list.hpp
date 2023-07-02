/**
 * @file abstract_list.hpp
 * @author Amit Nafshi (amn102@pitt.edu)
 * @brief Programming Problem 06
 * @version 0.1
 * @date 2023-07-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _ABSTRACT_LIST_HPP_
#define _ABSTRACT_LIST_HPP_

#include <cstdlib>

template <typename T>
class AbstractList
{
public:
  // determine if a list is empty
  virtual bool isEmpty() const noexcept = 0;

  // return current lenght of the list
  virtual std::size_t getLength() const noexcept = 0;

  // insert item at position in the list using 0-based indexing
  virtual void insert(std::size_t position, const T& item) = 0;

  // remove item at position in the list using 0-based indexing
  virtual void remove(std::size_t position) = 0;

  // remove all items from the list
  virtual void clear() = 0;

  // get a copy of the item at position using 0-based indexing
  virtual T getEntry(std::size_t position) const = 0;

  // set the value of the item at position using 0-based indexing
  virtual void setEntry(std::size_t position, const T& newValue) = 0;
};

#endif 
