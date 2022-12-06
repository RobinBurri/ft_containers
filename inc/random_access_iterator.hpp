#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "interator_traits.hpp"

/**
 * Random-access iterators are iterators that can be used to access elements at an arbitrary offset position
 * relative to the element they point to, offering the same functionality as pointers.
 * Random-access iterators are the most complete iterators in terms of functionality.
 * All random access iterators support -at least- the following operations:
 * https://cplusplus.com/reference/iterator/RandomAccessIterator/
 *
 */

// /*
// ** @brief Constructor from pointer:
// ** Construct a random access iterator and point to the
// ** element passed in argument.
// **
// ** @param elem the pointer to the element to iterate.
// */
// random_access_iterator(pointer elem)
//     : _elem(elem)
// {
// }

namespace ft
{
    template <typename T>
    class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>
    {
    public:
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type value_type;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type difference_type;
        typedef T *pointer;
        typedef T &reference;

    private:
        pointer _elem;

    public:
        //   Default construtor:
        random_access_iterator(void)
            : _elem(u_nullptr)
        {
        }
        // Copy Constructor
        random_access_iterator(const random_access_iterator &op)
            : _elem(op._elem)
        {
        }
        // Assignable =
        random_access_iterator &operator=(const random_access_iterator &op)
        {
            if (this == &op)
                return (*this);
            this->_elem = op._elem;
            return (*this);
        }
        // Destructor
        virtual ~random_access_iterator() {}

        pointer base() const
        {
            return (this->_elem);
        }
        // OPERATORS:
        reference operator*(void) const { return (*_elem); }

        pointer operator->(void) { return &(this->operator*()); }

        random_access_iterator &operator++(void)
        {
            _elem++;
            return (*this);
        }

        random_access_iterator operator++(int)
        {
            random_access_iterator rtn(*this);
            operator++();
            return (rtn);
        }

        random_access_iterator &operator--(void)
        {
            _elem--;
            return (*this);
        }

        random_access_iterator operator--(int)
        {
            random_access_iterator rtn(*this);
            operator--();
            return (rtn);
        }

        random_access_iterator operator+(difference_type n) const { return (_elem + n); }

        random_access_iterator operator-(difference_type n) const { return (_elem - n); }

        random_access_iterator &operator+=(difference_type n)
        {
            _elem += n;
            return (*this);
        }

        random_access_iterator &operator-=(difference_type n)
        {
            _elem -= n;
            return (*this);
        }

        reference operator[](difference_type n) { return (*(operator+(n))); }

        operator random_access_iterator<const T>() const
        {
            return (random_access_iterator<const T>(this->_elem));
        }
    };

    // COMPARISON OPERATOR BETWEEN TWO ITERATORS:
    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator==(const ft::random_access_iterator<T> lhs,
               const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() == rhs.base());
    }
    // CONST ITERATORS
    template <typename T_L, typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator==(const ft::random_access_iterator<T_L> lhs,
               const ft::random_access_iterator<T_R> rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator!=(const ft::random_access_iterator<T> lhs,
               const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() != rhs.base());
    }

    template <typename T_L, typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator!=(const ft::random_access_iterator<T_L> lhs,
               const ft::random_access_iterator<T_R> rhs)
    {
        return (lhs.base() != rhs.base());
    }

    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator<(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() < rhs.base());
    }

    template <typename T_L, typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator<(const ft::random_access_iterator<T_L> lhs,
              const ft::random_access_iterator<T_R> rhs)
    {
        return (lhs.base() < rhs.base());
    }

    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator>(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() > rhs.base());
    }

    template <typename T_L,
              typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator>(const ft::random_access_iterator<T_L> lhs,
              const ft::random_access_iterator<T_R> rhs)
    {
        return (lhs.base() > rhs.base());
    }

   
    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator<=(const ft::random_access_iterator<T> lhs,
               const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() <= rhs.base());
    }

    template <typename T_L, typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator<=(const ft::random_access_iterator<T_L> lhs,
               const ft::random_access_iterator<T_R> rhs)
    {
        return (lhs.base() <= rhs.base());
    }

    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator>=(const ft::random_access_iterator<T> lhs,
               const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() >= rhs.base());
    }

    template <typename T_L,
              typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator>=(const ft::random_access_iterator<T_L> lhs,
               const ft::random_access_iterator<T_R> rhs)
    {
        return (lhs.base() >= rhs.base());
    }

    template <typename T>
    ft::random_access_iterator<T> operator+(
        typename ft::random_access_iterator<T>::difference_type n,
        typename ft::random_access_iterator<T> &rai)
    {
        return (&(*rai) + n);
    }

    template <typename T>
    typename ft::random_access_iterator<T>::difference_type
    operator-(const ft::random_access_iterator<T> lhs,
              const ft::random_access_iterator<T> rhs)
    {
        return (lhs.base() - rhs.base());
    }

    template <typename T_L, typename T_R>
    typename ft::random_access_iterator<T_L>::difference_type
    operator-(const ft::random_access_iterator<T_L> lhs,
              const ft::random_access_iterator<T_R> rhs)
    {
        return (lhs.base() - rhs.base());
    }
}

#endif