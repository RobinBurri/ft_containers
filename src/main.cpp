/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:46:54 by rburri            #+#    #+#             */
/*   Updated: 2022/10/30 16:06:28 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

int testVectors(int);

int main()
{
    int retVal = 0;
    int testSize = 100;
    retVal = testVector(testSize);
    if (retVal != 0)
    {
        return retVal;
    }

    return retVal;

    // struct timeval begin, end;
    // gettimeofday(&begin, 0);

    // srand(time(0));
    // std::vector<int> original;
    // std::vector<int> copy;

    // for (int i = 0; i < 10; i++)
    // {
    //     int tmp = rand();
    //     original.push_back(tmp);
    //     copy.push_back(tmp);
    // }

    // for (int i = 0; i < 10; i++)
    // {
    //     std::cout << original[i] << std::endl;
    //     std::cout << copy[i] << std::endl;
    // }

    // gettimeofday(&end, 0);

    // long seconds = end.tv_sec - begin.tv_sec;
    // long microsec = end.tv_usec - begin.tv_usec;
    // double elapsed = seconds + microsec * 1e-6;
    // std::cout << "Time: " << elapsed << std::endl;
    /*
     Modifiers
    */
    // PUSH_BACK adds an element at the end !
    // CLEAR clear the content
    // INSERT insert element
    // ERASE erase element
    // POP_BACK remove last element
    // RESIZE change the number of element stored
    // SWAP swap the content

    /*
    Capacity
    */
    // EMPTY check wheter the container is empty
    // SIZE returns the number of elements
    // MAX_SIZE return the maximum possible of elements
    // RESERVE reserve storage
    // CAPACITY return the number of el that can be held in current allocated storage

    /**
     Iterator
    */
    // BEGIN return an iterator to the beginning
    // END return an iterator to the end
    // RBEGIN return a reverse iterator to the beginning
    // REND return a reverse iterator to the end.

    /**
     Element access
    */
    // AT access specified element with bounds checking
    // OPERATOR []  access specified element
    // FRONT access the first element
    // BACK access the last element
    // DATA direct access to the underlying array

    // OPERATOR= assigns values to the container
    // ASSIGN assigns values to the container
    // GET_ALLOCATOR return the associated allocator
}