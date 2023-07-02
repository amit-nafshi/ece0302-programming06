/**
 * @file sort.hpp
 * @author Amit Nafshi (amn102@pitt.edu)
 * @brief Programming Problem 5 
 * @version 0.1
 * @date 2023-06-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _SORT_HPP
#define _SORT_HPP

#include "linked_list.hpp"
// used lecture 10 and 11 bubble sort implementation
template<typename T> LinkedList<T> sort(LinkedList<T> list)
{
	int N = list.getLength();
	int swaps;
    int last;

    do {
        swaps = 0;
        last = N - 1;

        for (int j = 0; j < last; j++) 
		{
            if (list.getEntry(j) > list.getEntry(j+1)) 
			{
                T temp = list.getEntry(j);
                list.setEntry(j, list.getEntry(j + 1));
                list.setEntry(j + 1, temp);

                swaps++;
            }
        }

        last--;
    } while (swaps > 0); 

	return list;
}

#endif
