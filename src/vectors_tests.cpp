#include "../inc/colors.hpp"
#include <vector>
#include <iostream>
#include <sys/time.h>
#include <cstdlib>
#include <string>
#include "../inc/dummyClass.hpp"


std::string gen_random(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}

template <class T>
int checkIterators(std::vector<T> &original, std::vector<T> &copy)
{
    typename std::vector<T>::iterator it_bo = original.begin();
    typename std::vector<T>::iterator it_eo = original.end();
    typename std::vector<T>::iterator it_bc = copy.begin();
    typename std::vector<T>::iterator it_ec = copy.end();
    typename std::vector<T>::reverse_iterator it_rbo = original.rbegin();
    typename std::vector<T>::reverse_iterator it_reo = original.rend();
    typename std::vector<T>::reverse_iterator it_rbc = copy.rbegin();
    typename std::vector<T>::reverse_iterator it_rec = copy.rend();
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
int testString(std::vector<std::string> &original, std::vector<std::string> &copy)
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
        if (original[i].compare(copy[i]) != 0)
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
int testClass(std::vector<Zombie> &original, std::vector<Zombie> &copy)
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
int testAccessString(std::vector<std::string> &original, std::vector<std::string> &copy)
{
    int s = original.size();
    // AT access specified element with bounds checking
    if (original.at(s - 1).compare(copy.at(s -1 )) != 0)
    {
        std::cout << RED << "at() Fail!\n"
                  << RESET << std::endl;
        return 1;
    }
    // OPERATOR []  access specified element
    if (original[s - 1].compare(copy[s - 1]) != 0)
    {
        std::cout << RED << "OPERATOR [] Fail\n"
                  << RESET << std::endl;
        return 1;
    }
    // BACK access the last element
    if (original.back().compare(copy.back()) != 0)
    {
        std::cout << RED << "back() Fail\n"
                  << RESET << std::endl;
        return 1;
    }
    // FRONT access the first element
    if (original.front().compare(copy.front()) != 0)
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
int testAccessClass(std::vector<Zombie> &original, std::vector<Zombie> &copy)
{
    int s = original.size();
    // AT access specified element with bounds checking
    if (original.size() != copy.size())
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
    if (original.back() != copy.back()) {
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
int StringVectorTestOutput(std::vector<std::string> &original, std::vector<std::string> &copy, int testSize)
{
    std::cout << "test push_back(): " << std::endl;
    for (int i = 0; i < testSize; i++)
    {
        std::string tmp = gen_random(8);
        original.push_back(tmp);
        copy.push_back(tmp);
    }
    if (testString(original, copy))
    {
        return 1;
    }

    std::cout << "test element access: " << std::endl;
    if (testAccessString(original, copy))
    {
        return 1;
    }

    std::cout << "test erase(): " << std::endl;
    std::vector<std::string>::iterator oit = original.begin();
    std::vector<std::string>::iterator cit = copy.begin();
    original.erase(oit, (oit + 5));
    copy.erase(cit, (cit + 5));
    if (testString(original, copy))
    {
        return 1;
    }

    std::cout << "test insert(): " << std::endl;
    oit = original.begin();
    cit = copy.begin();
    original.insert((oit + (testSize / 2)), "test");
    copy.insert((cit + (testSize / 2)), "test");
    if (testString(original, copy))
    {
        return 1;
    }

    std::cout << "test pop_back(): " << std::endl;
    for (int i = 0; i < testSize / 2; i++)
    {
        original.pop_back();
        copy.pop_back();
    }
    if (testString(original, copy))
    {
        return 1;
    }

    std::cout << "test swap() & OPERATOR= & assign():" << std::endl;
    std::vector<std::string> foo1;
    foo1.assign(testSize, "newTest");
    std::vector<std::string> foo2 = foo1;

    original.swap(foo1);
    copy.swap(foo2);

    if (testString(original, copy))
    {
        return 1;
    }

    std::cout << "test resize(): " << std::endl;

    original.resize(original.size() / 2);
    copy.resize(copy.size() / 2);

    if (testString(original, copy))
    {
        return 1;
    }

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
        std::string tmp = gen_random(8);
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
int ClassVectorTestOutput(std::vector<Zombie> &original, std::vector<Zombie> &copy, int testSize)
{
    std::cout << "test push_back(): " << std::endl;
    for (int i = 0; i < testSize; i++)
    {
        std::string name = gen_random(8);
        Zombie z(name);
        original.push_back(z);
        copy.push_back(z);
    }
    if (testClass(original, copy))
    {
        return 1;
    }
    std::cout << "test element access: " << std::endl;
    if (testAccessClass(original, copy))
    {
        return 1;
    }

    std::cout << "test erase(): " << std::endl;
    std::vector<Zombie>::iterator oit = original.begin();
    std::vector<Zombie>::iterator cit = copy.begin();
    original.erase(oit, (oit + 5));
    copy.erase(cit, (cit + 5));
    if (testClass(original, copy))
    {
        return 1;
    }

    std::cout << "test insert(): " << std::endl;
    oit = original.begin();
    cit = copy.begin();
    Zombie t("test");
    original.insert((oit + (testSize / 2)), t);
    copy.insert((cit + (testSize / 2)), t);
    if (testClass(original, copy))
    {
        return 1;
    }

    std::cout << "test pop_back(): " << std::endl;
    for (int i = 0; i < testSize / 2; i++)
    {
        original.pop_back();
        copy.pop_back();
    }
    if (testClass(original, copy))
    {
        return 1;
    }

    std::cout << "test swap() & OPERATOR= & assign():" << std::endl;
    std::vector<Zombie> foo1;
    foo1.assign(testSize, t);
    std::vector<Zombie> foo2 = foo1;

    original.swap(foo1);
    copy.swap(foo2);

    if (testClass(original, copy))
    {
        return 1;
    }

    std::cout << "test resize(): " << std::endl;

    original.resize(original.size() / 2);
    copy.resize(copy.size() / 2);

    if (testClass(original, copy))
    {
        return 1;
    }

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
        std::string tmp = gen_random(8);
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


int speedTestInt(std::vector<int> &toTest, int testSize)
{

    for (int i = 0; i < testSize; i++)
    {
        int tmp = rand();
        toTest.push_back(tmp);
    }

    // ERASE erase element
     std::vector<int>::iterator oit = toTest.begin();
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
    std::vector<int> foo1(testSize, 123);
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
   std::vector<int>::iterator it_bo = toTest.begin();
   std::vector<int>::iterator it_eo = toTest.end();

    while (it_bo != it_eo)
    {
        it_bo++;
    }
    Zombie firstZombie("peter");
    return 0;
}
int speedTestString(std::vector<std::string> &toTest, int testSize)
{

    for (int i = 0; i < testSize; i++)
    {
        toTest.push_back(gen_random(8));
    }

    // ERASE erase element
     std::vector<std::string>::iterator oit = toTest.begin();
    toTest.erase(oit, (oit + 5));

    // INSERT insert element
    oit = toTest.begin();
    toTest.insert((oit + (testSize / 2)), "test");

    // POP_BACK remove last element
    for (int i = 0; i < testSize / 2; i++)
    {
        toTest.pop_back();
    }

    // SWAP swap the content
    std::vector<std::string> foo1(testSize, "test");
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
        toTest.push_back(gen_random(8));
    }
   std::vector<std::string>::iterator it_bo = toTest.begin();
   std::vector<std::string>::iterator it_eo = toTest.end();

    while (it_bo != it_eo)
    {
        it_bo++;
    }
    return 0;
}
int ClassSpeedTest(std::vector<Zombie> &toTest, int testSize)
{

     for (int i = 0; i < testSize; i++)
    {
        std::string name = gen_random(8);
        Zombie z(name);
        toTest.push_back(z);
    }
    // ERASE erase element
     std::vector<Zombie>::iterator oit = toTest.begin();
    toTest.erase(oit, (oit + 5));

    // INSERT insert element
    Zombie t("test");
    oit = toTest.begin();
    toTest.insert((oit + (testSize / 2)), t);

    // POP_BACK remove last element
    for (int i = 0; i < testSize / 2; i++)
    {
        toTest.pop_back();
    }

    // SWAP swap the content
    std::vector<Zombie> foo1(testSize, t);
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
        std::string name = gen_random(8);
        Zombie z(name);
        toTest.push_back(z);
    }
   std::vector<Zombie>::iterator it_bo = toTest.begin();
   std::vector<Zombie>::iterator it_eo = toTest.end();

    while (it_bo != it_eo)
    {
        it_bo++;
    }
    return 0;
}


int speedTestHandlerInt(std::vector<int> &original, std::vector<int> &copy, int testSize)
{
    struct timeval obegin, oend, cbegin, cend;
    gettimeofday(&obegin, 0);
    speedTestInt(original, testSize);
    gettimeofday(&oend, 0);
    gettimeofday(&cbegin, 0);
    speedTestInt(copy, testSize);
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
int speedTestHandlerString(std::vector<std::string> &original, std::vector<std::string> &copy, int testSize)
{
    struct timeval obegin, oend, cbegin, cend;
    gettimeofday(&obegin, 0);
    speedTestString(original, testSize);
    gettimeofday(&oend, 0);
    gettimeofday(&cbegin, 0);
    speedTestString(copy, testSize);
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
int speedTestHandlerClass(std::vector<Zombie> &original, std::vector<Zombie> &copy, int testSize)
{
    struct timeval obegin, oend, cbegin, cend;
    gettimeofday(&obegin, 0);
    ClassSpeedTest(original, testSize);
    gettimeofday(&oend, 0);
    gettimeofday(&cbegin, 0);
    ClassSpeedTest(copy, testSize);
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

    result = IntVectorTestOutput(original, copy, testSize);

    if (result != 0)
    {
        std::cout << RED << "INT VECTORS OUTPUT TEST FAIL!" << RESET << std::endl;
        return result;
    }
    std::cout << CYAN << "INT VECTORS SPEED: \n"
              << RESET << std::endl;

    result = speedTestHandlerInt(original, copy, testSize);

    if (result)
    {
        std::cout << RED << "INT VECTORS SPEED TEST FAIL!" << RESET << std::endl;
        return result;
    }

    std::cout << GREEN << "INT VECTORS TESTS SUCCESS!!!\n" << RESET << std::endl;

    return result;
}

int testStringVectors(int testSize)
{
    int result = 0;
    std::vector<std::string> original;
    std::vector<std::string> copy;

    std::cout << MAGENTA << "STRING VECTORS TESTS STARTS:\n"
              << RESET << std::endl;

    result = StringVectorTestOutput(original, copy, testSize);

    if (result != 0)
    {
        std::cout << RED << "STRING VECTORS OUTPUT TEST FAIL!" << RESET << std::endl;
        return result;
    }
    std::cout << CYAN << "STRING VECTORS SPEED: \n"
              << RESET << std::endl;

    result = speedTestHandlerString(original, copy, testSize);

    if (result)
    {
        std::cout << RED << "STRING VECTORS SPEED TEST FAIL!" << RESET << std::endl;
        return result;
    }

    std::cout << GREEN << "STRING VECTORS TESTS SUCCESS!!!\n" << RESET << std::endl;

    return result;
}

int testClassVectors(int testSize)
{
    int result = 0;
    result = testSize;
    std::vector<Zombie> original;
    std::vector<Zombie> copy;

    std::cout << MAGENTA << "CLASS VECTORS TESTS STARTS:\n"
              << RESET << std::endl;

    result = ClassVectorTestOutput(original, copy, testSize);

    if (result != 0)
    {
        std::cout << RED << "CLASS VECTORS OUTPUT TEST FAIL!" << RESET << std::endl;
        return result;
    }
    std::cout << CYAN << "CLASS VECTORS SPEED: \n"
              << RESET << std::endl;

    result = speedTestHandlerClass(original, copy, testSize);

    if (result)
    {
        std::cout << RED << "CLASS VECTORS SPEED TEST FAIL!" << RESET << std::endl;
        return result;
    }

    std::cout << GREEN << "CLASS VECTORS TESTS SUCCESS!!!" << RESET << std::endl;

    return result;
}

int testVectors(int testSize)
{
    testIntVectors(testSize);
    testStringVectors(testSize);
    testClassVectors(testSize);
    return 0;
}
