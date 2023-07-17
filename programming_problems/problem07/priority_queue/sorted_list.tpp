/**
 * @file sorted_list.tpp
 * @author Amit Nafshi (amn102@pitt.edu)
 * @brief Programming Problem: 07
 * @version 0.1
 * @date 2023-07-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "sorted_list.hpp"

template <typename T, typename L>
SortedList<T, L>::SortedList()
{
  // nothing to do, plist gets created on the stack
}

template <typename T, typename L>
SortedList<T, L>::SortedList(const SortedList<T, L> & x)
{
  plist = x.plist; // use copy assignment to implement copy construction
}

template <typename T, typename L>
SortedList<T, L>& SortedList<T, L>::operator=(SortedList<T, L> x)
{
  plist = x.plist;
  return *this;
}

template <typename T, typename L>
SortedList<T, L>::~SortedList()
{
  // plist destructor gets called automatically
}

template <typename T, typename L>
bool SortedList<T, L>::isEmpty() const noexcept
{
  return plist.isEmpty();
}

template <typename T, typename L>
std::size_t SortedList<T, L>::getLength() const noexcept
{
  return plist.getLength();
}

template <typename T, typename L>
void SortedList<T, L>::insert(const T& item)
{
  // position = length
  // search word from last position to head
  std::size_t position = getLength();
  // check for valid position
  while (position > 0 && item < getEntry(position - 1)) 
  {
    position--;
  }
  plist.insert(position, item);
}

template <typename T, typename L>
void SortedList<T, L>::remove(const T& item)
{
  long int position = getPosition(item);
  if (position != -1) 
  {
    plist.remove(position);
  }
}

template <typename T, typename L>
void SortedList<T, L>::removeAt(std::size_t position)
{
  plist.remove(position);
}

template <typename T, typename L>
void SortedList<T, L>::clear()
{
  plist.clear();
}

template <typename T, typename L>
T SortedList<T, L>::getEntry(std::size_t position) const
{
  return plist.getEntry(position);
}

template <typename T, typename L>
long int SortedList<T, L>::getPosition(const T& newValue)
{
  // search through list until newValue is found at position 
  for (std::size_t position = 0; position < getLength(); position++) 
  {
    if (getEntry(position) == newValue) 
    {
      return position;
    }
  }
  // return -1 if not found 
  return -1;
}
