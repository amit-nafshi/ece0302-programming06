/**
 * @file limited_size_bag.tpp
 * @author Amit Nafshi (amn102@pitt.edu)
 * @brief 
 * @version 0.1
 * @date 2023-06-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "limited_size_bag.hpp"

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag() 
{
  bagCount = 0;
}
  
template<typename T>
bool LimitedSizeBag<T>::add(const T& item)
{
  if (bagCount >= maxsize) 
  {
    // bag is full
    return false;
  }
  
  // add item to the bag
  items[bagCount++] = item;
  return true;
}

template<typename T>
bool LimitedSizeBag<T>::remove(const T& item)
{
  std::size_t index = 0;
  while (index < bagCount && items[index] != item) 
  {
    index++;
  }

  if (index == bagCount) 
  {
    return false; // item not found
  }

  // remove item, shift array
  for (std::size_t i = index; i < bagCount - 1; i++) 
  {
    items[i] = items[i + 1];
  }
  bagCount--;
  return true;
}

template<typename T>
bool LimitedSizeBag<T>::isEmpty() const
{
  return (bagCount == 0); // return true if == 0
}

template<typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const
{
  return bagCount;
}

template<typename T>
bool LimitedSizeBag<T>::contains(const T& item) const
{
  for (std::size_t i = 0; i < bagCount; i++) 
  {
    if (items[i] == item) 
    {
      return true;
    }
  }
  return false;
}

template<typename T>
void LimitedSizeBag<T>::clear()
{
  bagCount = 0;
}

template<typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T & item) const
{
  std::size_t freq = 0;
  for (std::size_t i = 0; i < bagCount; i++) {
    if (items[i] == item) {
      freq++;
    }
  }
  return freq;
};
