/**
 * @file linked_list.hpp
 * @author Amit Nafshi (amn102@pitt.edu)
 * @brief Programming Problem 06
 * @version 0.1
 * @date 2023-07-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _LINKED_LIST_HPP_
#define _LINKED_LIST_HPP_

#include "abstract_list.hpp"
#include "Node.hpp"

template <typename T>
class LinkedList: public AbstractList<T>
{
public:
  
  // default constructor
  LinkedList();
  
  // copy constructor
  LinkedList(const LinkedList& x);
    
  // destructor
  ~LinkedList();
  
  // copy assignment
  LinkedList& operator=(LinkedList x);

  // swap
  void swap(LinkedList& x);
  
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

  // helper function to find current node
  Node<T>* getNodeAt(std::size_t position) const;


private:
  // head node pointer
  Node<T>* headPtr;

  // number of items in list 
  std::size_t listNum;
};

#include "linked_list.tpp"

#endif
