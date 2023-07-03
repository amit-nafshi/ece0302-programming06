/**
 * @file sorted_linked_list.tpp
 * @author Amit Nafshi (amn102@pitt.edu)
 * @brief Programming Problem 06
 * @version 0.1
 * @date 2023-07-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "sorted_linked_list.hpp"
#include <stdexcept>

template <typename T>
SortedLinkedList<T>::SortedLinkedList() : LinkedList<T>()
{
}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(LinkedList<T> unsorted_list) 
{
  for (std::size_t i = 0; i < unsorted_list.getLength(); i++)
  {
    insert(unsorted_list.getEntry(i));
  }
}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList<T> & x):
  LinkedList<T>(x)
{
}

template <typename T>
SortedLinkedList<T>& SortedLinkedList<T>::operator=(SortedLinkedList<T> x)
{
  LinkedList<T>::operator=(x);
  return *this;
}

template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
  // base destructor gets called automatically
}

template <typename T>
bool SortedLinkedList<T>::isEmpty() const noexcept
{
  return LinkedList<T>::isEmpty();
}

template <typename T>
std::size_t SortedLinkedList<T>::getLength() const noexcept
{
  return LinkedList<T>::getLength();
}

template <typename T>
void SortedLinkedList<T>::insert(const T& item)
{
  std::size_t position = 1;
  std::size_t len = getLength();

  // find the position to insert
  while (position <= len && item > LinkedList<T>::getEntry(position))
  {
    ++position;
  }

  // insert the item at the position
  LinkedList<T>::insert(position, item);
}

template <typename T>
void SortedLinkedList<T>::remove(const T& item)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  
  long int position = getPosition(item);
  if (position != -1)
  {
    LinkedList<T>::remove(position + 1);
  }
}

template <typename T>
void SortedLinkedList<T>::removeAt(std::size_t position)
{
  if(isEmpty()) throw std::range_error("empty list in remove");
  
  LinkedList<T>::remove(position);
}

template <typename T>
void SortedLinkedList<T>::clear()
{
  LinkedList<T>::clear();
}

template <typename T>
T SortedLinkedList<T>::getEntry(std::size_t position) const
{
  return LinkedList<T>::getEntry(position);
}

template <typename T>
long int SortedLinkedList<T>::getPosition(const T& item)
{
  std::size_t len = getLength();
  for (std::size_t i = 1; i <= len; ++i)
  {
    if (LinkedList<T>::getEntry(i) == item)
    {
      return i - 1;
    }
  }
  return -1;
}
