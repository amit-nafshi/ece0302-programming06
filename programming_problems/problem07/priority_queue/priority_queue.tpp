/**
 * @file priority_queue.tpp
 * @author Amit Nafshi (amn102@pitt.edu)
 * @brief Programming Problem: 07
 * @version 0.1
 * @date 2023-07-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "priority_queue.hpp"

template <typename T, typename L >
bool PriorityQueue<T, L>::isEmpty() const {
    return slist.isEmpty();
}

template <typename T, typename L >
void PriorityQueue<T, L>::add(const T& item){
    slist.insert(item);
}

template <typename T, typename L >
void PriorityQueue<T, L>::remove(){
    slist.removeAt(slist.getLength()-1);
}

template <typename T, typename L >
T PriorityQueue<T, L>::peek(){
    return slist.getEntry(slist.getLength()-1);
}
