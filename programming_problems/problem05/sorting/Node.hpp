/**
 * @file Node.hpp
 * @author Amit Nafshi (amn102@pitt.edu)
 * @brief Programming Problem 5
 * @version 0.1
 * @date 2023-06-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef NODE_
#define NODE_

template<class ItemType>
class Node
{
private:
   ItemType        item; // A data item
   Node<ItemType>* next; // Pointer to next node
   
public:
   Node();
   Node(const ItemType& anItem);
   Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
   void setItem(const ItemType& anItem);
   void setNext(Node<ItemType>* nextNodePtr);
   ItemType getItem() const ;
   Node<ItemType>* getNext() const ;
}; // end Node

#include "Node.tpp"
#endif