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
ArrayList<T>::ArrayList() {}

template <typename T>
ArrayList<T>::~ArrayList() {}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList& rhs){}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(ArrayList rhs){
  return *this;
}

template <typename T>
void ArrayList<T>::swap(ArrayList& rhs) {}

template <typename T>
bool ArrayList<T>::isEmpty() const noexcept {
  return false;
}

template <typename T>
std::size_t ArrayList<T>::getLength() const noexcept {
  return 0;
}

template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item){
  return false;
}

template <typename T>
bool ArrayList<T>::remove(std::size_t position){
  return false;
}

template <typename T>
void ArrayList<T>::clear() {}

template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const {
  return T();
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue) {}
