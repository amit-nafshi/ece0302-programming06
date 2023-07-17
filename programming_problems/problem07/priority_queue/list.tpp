/**
 * @file list.tpp
 * @author Amit Nafshi (amn102@pitt.edu)
 * @brief Programming Problem: 07
 * @version 0.1
 * @date 2023-07-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "list.hpp"

template <typename T>
List<T>::List() : head(nullptr), size(0) {}

template <typename T>
List<T>::~List()
{
  clear();
}

template <typename T>
List<T>::List(const List<T>& x) : head(nullptr), size(0)
{
  Node<T>* cur = x.head;
  while (cur != nullptr) 
  {
    insert(size, cur->getItem);
    cur = cur->getNext;
  }
}

template <typename T>
List<T>& List<T>::operator=(List<T> x)
{
  swap(x);
  return *this;
}

template <typename T>
void List<T>::swap(List<T>& x) 
{
  std::swap(head, x.head);
  std::swap(size, x.size);
}

template <typename T>
bool List<T>::isEmpty() const noexcept
{
  return size == 0;
}

template <typename T>
std::size_t List<T>::getLength() const noexcept
{
  return size;
}

template <typename T>
void List<T>::insert(std::size_t position, const T& item)
{
  // check for invalid position
  if (position < 0 || position > size) 
  {
    throw std::out_of_range("Invalid position");
  }

  Node<T>* temp = new Node<T>(item);

  // check if at head pointer 
  if (position == 0) 
  {
    temp->setNext(head);
    head = temp;
  } 
  else 
  {
    Node<T>* prev = getNodeAt(position - 1);
    temp->setNext(prev->getNext());
    prev->setNext(temp);
  }

  // adjust size
  size++;
}

template <typename T>
void List<T>::remove(std::size_t position)
{
  // check for invalid position
  if (position < 0 || position > size) 
  {
    throw std::out_of_range("Invalid position");
  }

  // temp node for current node
  Node<T>* cur;

  if (position == 0) 
  {
    cur = head;
    head = head->getNext();
  } 
  else 
  {
    Node<T>* prev = getNodeAt(position - 1);
    cur = prev->getNext();
    prev->setNext(cur->getNext());
  }

  // adjust size and reset current node
  delete cur;
  size--;
}

template <typename T>
void List<T>::clear()
{
  while(!isEmpty())
  {
    remove(0);
  }
}

template <typename T>
T List<T>::getEntry(std::size_t position) const
{
  Node<T>* cur = getNodeAt(position);
  return cur->getItem();
}

template <typename T>
void List<T>::setEntry(std::size_t position, const T& newValue)
{
  Node<T>* cur = getNodeAt(position);
  cur->setItem(newValue);
}
//------------------------------------------------------------------------------------
// helper function to find current node
template <typename T>
Node<T>* List<T>::getNodeAt(std::size_t position) const 
{
  // check position
  if (position < 0 || position >= size)
  {
    throw std::out_of_range("Invalid position");
  }

  // search and find current node
  Node<T>* cur = head;
  for (std::size_t i = 0; i < position; i++) 
  {
    cur = cur->getNext();
  }

  return cur;
}