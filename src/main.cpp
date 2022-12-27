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
#include <ctime>
#include <iostream>
#include <unistd.h>

int testVectors(int);


int main()
{
    int retVal = 0;
    int testSize = 10000;
    retVal = testVectors(testSize);
    if (retVal != 0)
    {
        return retVal;
    }

    return retVal;
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