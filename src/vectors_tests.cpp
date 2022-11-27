#include "../inc/colors.hpp"
#include <vector>
#include <iostream>
#include <sys/time.h>
#include <cstdlib>

int checkIterators(std::vector<int> &original, std::vector<int> &copy)
{
    std::vector<int>::iterator it_bo = original.begin();
    std::vector<int>::iterator it_eo = original.end();
    std::vector<int>::iterator it_bc = copy.begin();
    std::vector<int>::iterator it_ec = copy.end();
    std::vector<int>::reverse_iterator it_rbo = original.rbegin();
    std::vector<int>::reverse_iterator it_reo = original.rend();
    std::vector<int>::reverse_iterator it_rbc = copy.rbegin();
    std::vector<int>::reverse_iterator it_rec = copy.rend();

    while (it_bo != it_eo && it_bc != it_ec)
    {
        if (*it_bo++ != *it_bc++)
        {
            std::cout << RED << "Values are not equal!!!\n"
                      << RESET << std::endl;
            return 1;
        }
    }
    while (it_rbo != it_reo && it_rbc != it_rec)
    {
        if (*it_rbo++ != *it_rbc++)
        {
            std::cout << RED << "Values are not equal!!!\n"
                      << RESET << std::endl;
            return 1;
        }
    }
    std::cout << GREEN << "Values are all the same.\n"
              << RESET << std::endl;
    return 0;
}

int testValues(std::vector<int> &original, std::vector<int> &copy)
{
    int s = original.size();
    if (original.size() != copy.size())
    {
        std::cout << RED << "Values are not equal!!!\n"
                  << RESET << std::endl;
        return 1;
    }
    for (int i = 0; i < s; i++)
    {
        // std::cout << original[i] << std::endl;
        // std::cout << copy[i] << std::endl;
        if (original[i] != copy[i])
        {
            std::cout << RED << "Values are not equal!!!\n"
                      << RESET << std::endl;
            return 1;
        }
    }
    std::cout << GREEN << "Values are all the same.\n"
              << RESET << std::endl;
    return 0;
}
int testAccess(std::vector<int> &original, std::vector<int> &copy)
{
    int s = original.size();
    // AT access specified element with bounds checking
    if (original.at(s - 1) != copy.at(s - 1))
    {
        std::cout << RED << "at() Fail!\n"
                  << RESET << std::endl;
        return 1;
    }
    // OPERATOR []  access specified element
    if (original[s - 1] != copy[s - 1])
    {
        std::cout << RED << "OPERATOR [] Fail\n"
                  << RESET << std::endl;
        return 1;
    }
    // BACK access the last element
    if (original.back() != copy.back())
    {
        std::cout << RED << "back() Fail\n"
                  << RESET << std::endl;
        return 1;
    }
    // FRONT access the first element
    if (original.front() != copy.front())
    {
        std::cout << RED << "front() Fail\n"
                  << RESET << std::endl;
        return 1;
    }
    // DATA direct access to the underlying array
    if (copy.data() != &copy[0])
    {
        std::cout << RED << "data()  Fail\n"
                  << RESET << std::endl;
        return 1;
    }
    std::cout << GREEN << "at(): ok\n"
              << "OPERATOR []: ok\n"
              << "back(): ok\n"
              << "front(): ok\n"
              << "data(): ok\n"
              << RESET << std::endl;
    return 0;
}

int IntVectorTestOutput(std::vector<int> &original, std::vector<int> &copy, int testSize)
{
    // GET_ALLOCATOR return the associated allocator

    // PUSH_BACK adds an element at the end !
    std::cout << "test push_back(): " << std::endl;
    for (int i = 0; i < testSize; i++)
    {
        int tmp = rand();
        original.push_back(tmp);
        copy.push_back(tmp);
    }
    if (testValues(original, copy))
    {
        return 1;
    }

    // AT access specified element with bounds checking
    // OPERATOR []  access specified element
    // FRONT access the first element
    // BACK access the last element
    // DATA direct access to the underlying array
    std::cout << "test element access: " << std::endl;
    if (testAccess(original, copy))
    {
        return 1;
    }

    // ERASE erase element
    std::cout << "test erase(): " << std::endl;
    std::vector<int>::iterator oit = original.begin();
    std::vector<int>::iterator cit = copy.begin();
    original.erase(oit, (oit + 5));
    copy.erase(cit, (cit + 5));
    if (testValues(original, copy))
    {
        return 1;
    }

    // INSERT insert element
    std::cout << "test insert(): " << std::endl;
    oit = original.begin();
    cit = copy.begin();
    original.insert((oit + (testSize / 2)), 100);
    copy.insert((cit + (testSize / 2)), 100);
    if (testValues(original, copy))
    {
        return 1;
    }

    // POP_BACK remove last element
    std::cout << "test pop_back(): " << std::endl;
    for (int i = 0; i < testSize / 2; i++)
    {
        original.pop_back();
        copy.pop_back();
    }
    if (testValues(original, copy))
    {
        return 1;
    }

    // SWAP swap the content
    // OPERATOR= assigns values to the container
    // ASSIGN assigns values to the container
    std::cout << "test swap() & OPERATOR= & assign():" << std::endl;
    std::vector<int> foo1;
    foo1.assign(testSize, 123);
    std::vector<int> foo2 = foo1;

    original.swap(foo1);
    copy.swap(foo2);

    if (testValues(original, copy))
    {
        return 1;
    }

    // RESIZE change the number of element stored
    std::cout << "test resize(): " << std::endl;

    original.resize(original.size() / 2);
    copy.resize(copy.size() / 2);

    if (testValues(original, copy))
    {
        return 1;
    }
    // CLEAR clear the content
    std::cout << "test clear(): " << std::endl;
    original.clear();
    copy.clear();
    if (original.size() != copy.size())
    {
        std::cout << RED << "Values are not equal!!!\n"
                  << RESET << std::endl;
        return 1;
    }
    else
    {
        std::cout << GREEN << "Values are all the same.\n"
                  << RESET << std::endl;
    }

    // CAPACITY METHODS:
    // SIZE returns the number of elements
    std::cout << "test size(): " << std::endl;

    if (original.size() != copy.size())
    {
        std::cout << RED << "Values are not equal!!!\n"
                  << RESET << std::endl;
        return 1;
    }
    else
    {
        std::cout << GREEN << "Values are all the same.\n"
                  << RESET << std::endl;
    }
    // MAX_SIZE return the maximum possible of elements
    std::cout << "test max_size(): " << std::endl;

    if (original.max_size() != copy.max_size())
    {
        std::cout << RED << "Values are not equal!!!\n"
                  << RESET << std::endl;
        return 1;
    }
    else
    {
        std::cout << GREEN << "Values are all the same.\n"
                  << RESET << std::endl;
    }

    // CAPACITY return the number of el that can be held in current allocated storage
    // RESERVE reserve storage
    std::cout << "test capacity() & reserve(): " << std::endl;
    std::vector<int> reservedOriginal;
    std::vector<int> reservedCopy;
    reservedOriginal.reserve(200);
    reservedCopy.reserve(200);

    if (reservedOriginal.capacity() != reservedCopy.capacity())
    {
        std::cout << RED << "Values are not equal!!!\n"
                  << RESET << std::endl;
        return 1;
    }
    else
    {
        std::cout << GREEN << "Values are all the same.\n"
                  << RESET << std::endl;
    }

    // EMPTY check wheter the container is empty
    std::cout << "test empty(): " << std::endl;

    if (original.empty() != copy.empty())
    {
        std::cout << RED << "Values are not equal!!!\n"
                  << RESET << std::endl;
        return 1;
    }
    else
    {
        std::cout << GREEN << "Values are all the same.\n"
                  << RESET << std::endl;
    }

    // Iterator
    for (int i = 0; i < testSize; i++)
    {
        int tmp = rand();
        original.push_back(tmp);
        copy.push_back(tmp);
    }
    // BEGIN return an iterator to the beginning
    // END return an iterator to the end
    // RBEGIN return a reverse iterator to the beginning
    // REND return a reverse iterator to the end.
    std::cout << "test ITERATORS: " << std::endl;

    if (checkIterators(original, copy))
    {
        return 1;
    }

    return 0;
}

template <class T>
int speedTest(std::vector<T> &toTest, int testSize)
{

    for (int i = 0; i < testSize; i++)
    {
        int tmp = rand();
        toTest.push_back(tmp);
    }

    // ERASE erase element
    typename std::vector<T>::iterator oit = toTest.begin();
    toTest.erase(oit, (oit + 5));

    // INSERT insert element
    oit = toTest.begin();
    toTest.insert((oit + (testSize / 2)), 100);

    // POP_BACK remove last element
    for (int i = 0; i < testSize / 2; i++)
    {
        toTest.pop_back();
    }

    // SWAP swap the content
    std::vector<T> foo1(testSize, 123);
    toTest.swap(foo1);

    // RESIZE change the number of element stored
    toTest.resize(toTest.size() / 2);

    // CLEAR clear the content
    toTest.clear();

    // CAPACITY METHODS:
    // SIZE returns the number of elements
    toTest.size();
    // MAX_SIZE return the maximum possible of elements
    toTest.max_size();
    // RESERVE reserve storage
    toTest.capacity();
    // EMPTY check wheter the container is empty
    toTest.empty();

    // Iterator
    for (int i = 0; i < testSize; i++)
    {
        int tmp = rand();
        toTest.push_back(tmp);
    }
    // BEGIN return an iterator to the beginning
    // END return an iterator to the end
    // RBEGIN return a reverse iterator to the beginning
    // REND return a reverse iterator to the end.
    typename std::vector<T>::iterator it_bo = toTest.begin();
    typename std::vector<T>::iterator it_eo = toTest.end();

    while (it_bo != it_eo)
    {
        it_bo++;
    }
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

    return 0;
}

template <class T>
int speedTestHandler(std::vector<T> &original, std::vector<T> &copy, int testSize)
{
    struct timeval obegin, oend, cbegin, cend;
    gettimeofday(&obegin, 0);
    speedTest(original, testSize);
    gettimeofday(&oend, 0);
    gettimeofday(&cbegin, 0);
    speedTest(copy, testSize);
    gettimeofday(&cend, 0);
    long seconds = oend.tv_sec - obegin.tv_sec;
    long microseconds = oend.tv_usec - obegin.tv_usec;
    double OriginalElapsed = seconds + microseconds * 1e-6;
    seconds = oend.tv_sec - obegin.tv_sec;
    microseconds = oend.tv_usec - obegin.tv_usec;
    double CopyElapsed = seconds + microseconds * 1e-6;
    std::cout << YELLOW << "Original, time: " << std::fixed << OriginalElapsed << std::endl;
    std::cout << YELLOW << "Copy, time: " << std::fixed << CopyElapsed << std::endl;
    if (CopyElapsed > OriginalElapsed * 20)
    {
        std::cout << RED << "Copy is too slow!\n"
                  << RESET << std::endl;
        return 1;
    }

    std::cout << GREEN << "Copy is fast enough!\n"
              << RESET << std::endl;

    return 0;
}

int testIntVectors(int testSize)
{
    int result = 0;
    std::vector<int> original;
    std::vector<int> copy;

    std::cout << MAGENTA << "INT VECTORS TESTS STARTS:\n"
              << RESET << std::endl;
    std::cout << CYAN << "INT VECTORS OUTPUT: \n"
              << RESET << std::endl;

    result = IntVectorTestOutput(original, copy, testSize);

    if (result != 0)
    {
        std::cout << RED << "INT VECTORS OUTPUT TEST FAIL!" << RESET << std::endl;
        return result;
    }
    std::cout << CYAN << "INT VECTORS SPEED: \n"
              << RESET << std::endl;

    result = speedTestHandler(original, copy, testSize);

    if (result)
    {
        std::cout << RED << "INT VECTORS SPEED TEST FAIL!" << RESET << std::endl;
        return result;
    }

    std::cout << GREEN << "INT VECTORS TESTS SUCCESS!!!" << RESET << std::endl;

    return result;
}

int testStringVectors(int testSize)
{
    int result = 0;
    std::vector<std::string> original;
    std::vector<std::string> copy;

    std::cout << MAGENTA << "STRING VECTORS TESTS STARTS:\n"
              << RESET << std::endl;
    std::cout << CYAN << "STRING VECTORS OUTPUT: \n"
              << RESET << std::endl;

    result = IntVectorTestOutput(original, copy, testSize);

    if (result != 0)
    {
        std::cout << RED << "STRING VECTORS OUTPUT TEST FAIL!" << RESET << std::endl;
        return result;
    }
    std::cout << CYAN << "STRING VECTORS SPEED: \n"
              << RESET << std::endl;

    result = IntSpeedTest(original, copy, testSize);

    if (result)
    {
        std::cout << RED << "STRING VECTORS SPEED TEST FAIL!" << RESET << std::endl;
        return result;
    }

    std::cout << GREEN << "STRING VECTORS TESTS SUCCESS!!!" << RESET << std::endl;

    return result;
}

// int testClassVectors(int testSize)
// {
//     int result = 0;
//     std::vector<int> original;
//     std::vector<int> copy;
//
//     std::cout << MAGENTA << "INT VECTORS TESTS STARTS:\n"
//               << RESET << std::endl;
//     std::cout << CYAN << "VECTORS OUTPUT: \n"
//               << RESET << std::endl;

//     result = IntVectorTestOutput(original, copy, testSize);

//     if (result != 0)
//     {
//         std::cout << RED << "VECTORS OUTPUT TEST FAIL!" << RESET << std::endl;
//         return result;
//     }
//     std::cout << CYAN << "VECTORS SPEED: \n"
//               << RESET << std::endl;

//     result = IntSpeedTest(original, copy, testSize);

//     if (result)
//     {
//         std::cout << RED << "VECTORS SPEED TEST FAIL!" << RESET << std::endl;
//         return result;
//     }

//     std::cout << GREEN << "VECTORS TESTS SUCCESS!!!" << RESET << std::endl;

//     return result;
// }

int testVectors(int testSize)
{
    testIntVectors(testSize);
    // testStringVectors();
    // testClassVectors();
    return 0;
}
