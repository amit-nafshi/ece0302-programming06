/**
 * @file linked_list.tpp
 * @author Amit Nafshi (amn102@pitt.edu)
 * @brief Programming Problem 06
 * @version 0.1
 * @date 2023-07-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "linked_list.hpp"
#include "Node.hpp"

template <typename T>
LinkedList<T>::LinkedList()
{
  // initialize linked list
  headPtr = nullptr;
  listNum = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  // deconstruct node through clear
  clear();
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
  // initialize linked list, then copy parameter
  headPtr = nullptr;
  listNum = 0;

  Node<T>* newPtr = x.headPtr;
  while (newPtr != nullptr)
  {
    insert(listNum, newPtr->getItem());
    newPtr = newPtr->getNext();
  }
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> x)
{
  // call swap, point to this to deallocate
  swap(x);
  return *this;
}

template <typename T>
void LinkedList<T>::swap(LinkedList& x) 
{
  // swap list parameters for = operator
  std::swap(listNum, x.listNum);
  std::swap(headPtr, x.headPtr);
}

template <typename T>
bool LinkedList<T>::isEmpty() const noexcept
{
  // empty if listNum == 0
  return (listNum == 0);
}

template <typename T>
std::size_t LinkedList<T>::getLength() const noexcept
{
  // return listNum
  return listNum;
}

template <typename T>
void LinkedList<T>::insert(std::size_t position, const T& item)
{
  if (position < 0 || position >+ listNum) 
  {
    throw std::range_error("Invalid position");
  }

  // create temp pointer
  Node<T>* temp = new Node<T>(item);

  // check if at head already
  if (position == 0)
  {
    temp->setNext(headPtr);
    headPtr = temp;
  }
  else
  {
    Node<T>* prev = getNodeAt(position - 1);
    temp->setNext(prev->getNext());
    prev->setNext(temp);
  }

  listNum++;
}

template <typename T>
void LinkedList<T>::remove(std::size_t position)
{
  // check for invalid position
  if (position < 0 || position >= listNum)
  {
    throw std::range_error("Invalid position");
  }

  // current node pointer
  Node<T>* cur;

  // check if at head already
  if (position == 0) 
  {
    cur = headPtr;
    headPtr = headPtr->getNext();
  } 
  else 
  {
    Node<T>* prev = getNodeAt(position - 1);
    cur = prev->getNext();
    prev->setNext(cur->getNext());
  }

  delete cur;
  listNum--;
}

template <typename T>
void LinkedList<T>::clear()
{
  // clear/deconstruct linked list
  while(!isEmpty())
  {
    remove(0);
  }
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  Node<T>* cur = getNodeAt(position);
  return cur->getItem();
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  Node<T>* cur = getNodeAt(position);
  cur->setItem(newValue);
}

//-----------------------------------------------------------------------------------
// helper function to find current node
// eliminated node seg faults when debugging 
template <typename T>
Node<T>* LinkedList<T>::getNodeAt(std::size_t position) const 
{
  if (position < 0 || position >= listNum)
  {
    throw std::range_error("Invalid position");
  }

  Node<T>* cur = headPtr;
  for (std::size_t i = 0; i < position; i++) 
  {
    cur = cur->getNext();
  }

  return cur;
}