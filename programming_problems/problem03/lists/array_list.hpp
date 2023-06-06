/**
 * @file array_list.hpp
 * @author Amit Nafshi (amn102@pitt.edu)
 * @brief 
 * @version 0.1
 * @date 2023-06-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ARRAY_LIST_HPP
#define ARRAY_LIST_HPP

#include "abstract_list.hpp"

template<typename T>
class ArrayList: public AbstractList<T>
{
public:

  // default constructor
  ArrayList();

  // destructor
  ~ArrayList();

  // copy constructor
  ArrayList(const ArrayList& rhs);

  // copy assignment
  ArrayList& operator=(ArrayList rhs);

  // swap 
  void swap(ArrayList& rhs);
  
  // determine if a list is empty
  bool isEmpty() const noexcept;

  // return current length of the list
  std::size_t getLength() const noexcept;
  
  // insert item at position in the list 
  bool insert(std::size_t position, const T& item);

  // remove item at position in the list 
  bool remove(std::size_t position);

  // remove all items from the list
  void clear();

  // get a copy of the item at position 
  T getEntry(std::size_t position) const;

  // set the value of the item at position 
  void setEntry(std::size_t position, const T& newValue);

private:

  // TODO
  
};

#include "array_list.tpp"

#endif
