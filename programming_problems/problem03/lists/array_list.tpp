/**
 * @file array_list.tpp
 * @author Amit Nafshi (amn102@pitt.edu)
 * @brief 
 * @version 0.1
 * @date 2023-06-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "array_list.hpp"

template <typename T>
ArrayList<T>::ArrayList() 
{
  // initialize list
  items = nullptr;
  arrSize = 0;
  arrCount = 0;
}

template <typename T>
ArrayList<T>::~ArrayList() 
{
  // deconstruct the pointer
  delete [] items;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList& rhs)
{
  // initialize list to parameter
  arrSize = rhs.arrSize;
  arrCount = rhs.arrCount;
  items = new T[arrSize];
  for (std::size_t i = 0; i < arrCount; i++)
  {
    items[i] = rhs.items[i];
  }
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(ArrayList rhs)
{
  // call swap, point to this to deallocate
  swap(rhs);
  return *this;
}

template <typename T>
void ArrayList<T>::swap(ArrayList& rhs) 
{
  // swap list parameters for = operator
  std::swap(arrSize, rhs.arrSize);
  std::swap(arrCount, rhs.arrCount);
  std::swap(items, rhs.items);
}

template <typename T>
bool ArrayList<T>::isEmpty() const noexcept 
{
  // empty if arrCount == 0
  return (arrCount == 0);
}

template <typename T>
std::size_t ArrayList<T>::getLength() const noexcept 
{
  // return # of items in list
  return arrCount;
}

template<typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item)
{
  // check if position is valid
  if (position > arrCount || position < 0)
  {
    return false;
  }
  else
  {
    T* newItems = new T[arrCount + 1]; // create a new array with increased size

    // copy elements before the specified position
    for (std::size_t i = 0; i < position; i++)
    {
      newItems[i] = items[i];
    }

    // insert new item at position
    newItems[position] = item;

    // copy elements after position
    for (std::size_t i = position; i < arrCount; i++)
    {
      newItems[i + 1] = items[i];
    }

    delete[] items; // clear and adjust array
    items = newItems; 
    arrCount++; 

    return true;
  }
}

template <typename T>
bool ArrayList<T>::remove(std::size_t position)
{
  // check if position is valid
  if (position > arrCount || position < 0)
  {
    return false;
  }
  else
  {
    // if valid, remove item and shift array
    for (std::size_t i = position; i < arrCount - 1; i++)
    {
      items[i] = items[i + 1];
    }
    arrCount--;
    return true;
  }
}

template <typename T>
void ArrayList<T>::clear() 
{
  // clear array
  delete [] items;
  items = nullptr;
  arrSize = 0;
  arrCount = 0;
}

template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const
{
  // check if position is valid
  if (position > arrCount || position < 0)
  {
    return T(); // return empty object T() if invalid
  }
  else
  {
    return items[position]; 
  }
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue)
{
  // check if position is valid
  if (position >= arrCount || position < 0)
  {
    return; // return nothing if invalid
  }
  else
  {
    items[position] = newValue; 
  }
}

