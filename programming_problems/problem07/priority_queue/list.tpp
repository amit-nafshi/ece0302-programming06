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
  if (position < 0 || position > size) 
  {
    throw std::out_of_range("Invalid position");
  }

  Node<T>* newNode = new Node<T>(item);

  if (position == 0) 
  {
    newNode->setNext(head);
    head = newNode;
  } 
  else 
  {
    Node<T>* prev = getNodeAt(position - 1);
    newNode->setNext(prev->getNext());
    prev->setNext(newNode);
  }

  size++;
}

template <typename T>
void List<T>::remove(std::size_t position)
{
  if (position < 0 || position > size) 
  {
    throw std::out_of_range("Invalid position");
  }

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

template <typename T>
Node<T>* List<T>::getNodeAt(std::size_t position) const 
{
  if (position < 0 || position >= size)
  {
    throw std::out_of_range("Invalid position");
  }

  Node<T>* cur = head;
  for (std::size_t i = 0; i < position; i++) 
  {
    cur = cur->getNext();
  }

  return cur;
}