/**
 * @file dynamic_bag.tpp
 * @author Amit Nafshi (amn102@pitt.edu)
 * @brief 
 * @version 0.1
 * @date 2023-06-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "dynamic_bag.hpp"

template<typename T>
DynamicBag<T>::DynamicBag() 
{
  items = nullptr;
  bagSize = 0;
  bagCount = 0;
}
  

template<typename T>
DynamicBag<T>::DynamicBag(const DynamicBag<T>& x)
{
  bagSize = x.bagSize;
  bagCount = x.bagCount;
  items = new T[bagSize];
  for (std::size_t i = 0; i < bagCount; i++)
  {
    items[i] = x.items[i];
  }
}
    
template<typename T>
DynamicBag<T>::~DynamicBag()
{
  delete [] items;
}
  
template<typename T>
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T> x)
{  
  swap(x);
  return *this;
}

template<typename T>
void DynamicBag<T>::swap(DynamicBag<T>& x)
{
  std::swap(bagSize, x.bagSize);
  std::swap(bagCount, x.bagCount);
  std::swap(items, x.items);
}

// Add an item to the bag
template<typename T>
bool DynamicBag<T>::add(const T& item)
{
  T* newItems = new T[bagCount + 1];          // adjust bag size, throws errors if just sending false
  for (std::size_t i = 0; i < bagCount; i++)
  {
    newItems[i] = items[i];
  }
  newItems[bagCount] = item;

  delete[] items;
  items = newItems;
  bagCount++;

  return true;
}

// remove an item from the bag
template<typename T>
bool DynamicBag<T>::remove(const T& item)
{
  std::size_t index = 0;
  while (index < bagCount && items[index] != item)
  {
    index++;
  }

  // item not found in the bag
  if (index == bagCount)
  {
    return false; 
  }

  // item removal and shift
  for (std::size_t i = index; i < bagCount - 1; i++)
  {
    items[i] = items[i + 1];
  }
  bagCount--;
  return true;
}


template<typename T>
bool DynamicBag<T>::isEmpty() const
{
  return (bagCount == 0); // return true if == 0
}

template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const
{
  return bagCount; // return bag size
}

template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{  
  // search array for item
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
void DynamicBag<T>::clear()
{
  // clear bag
  delete[] items;
  items = nullptr;
  bagSize = 0;
  bagCount = 0;
}

template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{
  // count the frquency of item in bag
  std::size_t freq = 0;
  for (std::size_t i = 0; i < bagCount; i++)
  {
    if (items[i] == item)
    {
      freq++;
    }
  }
  return freq;
};
