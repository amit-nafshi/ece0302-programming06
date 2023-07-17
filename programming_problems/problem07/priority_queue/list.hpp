/**
 * @file list.hpp
 * @author Amit Nafshi (amn102@pitt.edu)
 * @brief Programming Problem: 07
 * @version 0.1
 * @date 2023-07-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _LIST_HPP_
#define _LIST_HPP_

#include "abstract_list.hpp"
#include "Node.hpp"

template <typename T>
class List: public AbstractList<T>
{
public:
  
  // default constructor
  List();
  
  // copy constructor
  List(const List& x);
    
  // destructor
  ~List();
  
  // copy assignment
  List& operator=(List x);

  // swap
  void swap(List& x);
  
  // determine if a list is empty
  bool isEmpty() const noexcept;

  // return current length of the list
  std::size_t getLength() const noexcept;

  // insert item at position in the list 
  void insert(std::size_t position, const T& item);

  // remove item at position in the list 
  void remove(std::size_t position);

  // remove all items from the list
  void clear();

  // get a copy of the item at position 
  T getEntry(std::size_t position) const;

  // set the value of the item at position 
  void setEntry(std::size_t position, const T& newValue);

  // helper function 
  Node<T>* getNodeAt(std::size_t position) const;

private:
  Node<T>* head;
  std::size_t size;
};

#include "list.tpp"

#endif
