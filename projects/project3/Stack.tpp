//  Adapated from Frank M. Carrano and Timothy M. Henry.

/** ADT Stack implementation.
    @file Stack.cpp */

#include <iostream>
#include <cstddef>
#include "Stack.hpp"
#include "Node.hpp"

// TODO: Implement the constructor here
template<class ItemType>
Stack<ItemType>::Stack() : headPtr(nullptr)
{
}  // end default constructor

// TODO: Implement the destructor here
template<class ItemType>
Stack<ItemType>::~Stack()
{
	// Pop until stack is empty
	while (!isEmpty())
	{
		pop();
	}
}  // end destructor

// TODO: Implement the isEmpty method here
template<class ItemType>
bool Stack<ItemType>::isEmpty() const
{
	return headPtr == nullptr;
}  // end isEmpty

// TODO: Implement the size method here
template<class ItemType>
int Stack<ItemType>::size() const
{
	return currentSize;
}  // end size

// TODO: Implement the push method here
template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newItem)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newItem, headPtr);

	headPtr = newNodePtr;
	newNodePtr = nullptr;
	return true;
}  // end push

// TODO: Implement the peek method here
template<class ItemType>
ItemType Stack<ItemType>::peek() const
{
	assert(!isEmpty());			
	return headPtr->getItem();  // Stack not empty, return head
}  // end peek

// TODO: Implement the pop method here
template<class ItemType>
bool Stack<ItemType>::pop() 
{
	bool result = false;
	if (!isEmpty())
	{
		// Stack is not empty; delete top
		Node<ItemType>* nodeToDelete = headPtr;
		headPtr = headPtr->getNext();
		
		// Return deleted node to system
		nodeToDelete->setNext(nullptr);
		delete nodeToDelete;
		nodeToDelete = nullptr;

		result = true;
	}

	return result;
}  // end pop

// TODO: Implement the clear method here
template<class ItemType>
void Stack<ItemType>::clear()
{
	while (!isEmpty())
	{
		pop();
	}
}  // end clear

