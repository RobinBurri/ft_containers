#ifndef FT_REVERSE_ITERATOR_HPP
#define FT_REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
    template <class Iterator>
    class reverse_iterator
    {
    private:
        iterator_type _elem;

    public:
        typedef Iterator iterator_type;
        typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
        typedef typename ft::iterator_traits<Iterator>::value_type value_type;
        typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
        typedef typename ft::iterator_traits<Iterator>::pointer pointer;
        typedef typename ft::iterator_traits<Iterator>::reference reference;

        //   Default construtor:
        reverse_iterator()
            : _elem()
        {
        }
        // Copy Constructor
        explicit reverse_iterator(iterator_type it)
            : _elem(it)
        {
        }
        // Assignable =
        template <class Iter>
        reverse_iterator(const reverse_iterator<Iter> &rev_it)
            : _elem(rev_it.base())
        {
        }
        // Constructor from pointer
        iterator_type base() const
        {
            return (_elem);
        }
        // Destructor
        virtual ~reverse_iterator() {}

        // OPERATORS:
        reference operator*() const
        {
            iterator_type tmp = _elem;
            return (*(--tmp));
        }

        reverse_iterator operator+(difference_type n) const { return (reverse_iterator(_elem - n)); }

        reverse_iterator &operator++()
        {
            --_elem;
            return (*this);
        }

        reverse_iterator operator++(int)
        {
            reverse_iterator tmp = *this;
            ++(*this);
            return (tmp);
        }

        reverse_iterator &operator+=(difference_type n)
        {
            _elem -= n;
            return (*this);
        }

        reverse_iterator operator-(difference_type n) const { return (reverse_iterator(_elem + n)); }

        reverse_iterator &operator--()
        {
            ++_elem;
            return (*this);
        }

        reverse_iterator operator--(int)
        {
            reverse_iterator tmp = *this;
            --(*this);
            return (tmp);
        }

        reverse_iterator &operator-=(difference_type n)
        {
            _elem += n;
            return (*this);
        }

        pointer operator->() const { return &(operator*()); }

        reference operator[](difference_type n) const { return (this->base()[-n - 1]); }
    };
}

template <class Iterator>
bool operator==(const reverse_iterator<Iterator> &lhs,
                const reverse_iterator<Iterator> &rhs) { return (lhs.base() == rhs.base()); }

template <class Iterator_L, class Iterator_R>
bool operator==(const reverse_iterator<Iterator_L> &lhs,
                const reverse_iterator<Iterator_R> &rhs) { return (lhs.base() == rhs.base()); }

template <class Iterator>
bool operator!=(const reverse_iterator<Iterator> &lhs,
                const reverse_iterator<Iterator> &rhs) { return (lhs.base() != rhs.base()); }

template <class Iterator_L, class Iterator_R>
bool operator!=(const reverse_iterator<Iterator_L> &lhs,
                const reverse_iterator<Iterator_R> &rhs) { return (lhs.base() != rhs.base()); }

template <class Iterator>
bool operator<(const reverse_iterator<Iterator> &lhs,
               const reverse_iterator<Iterator> &rhs) { return (lhs.base() > rhs.base()); }

template <class Iterator_L, class Iterator_R>
bool operator<(const reverse_iterator<Iterator_L> &lhs,
               const reverse_iterator<Iterator_R> &rhs) { return (lhs.base() > rhs.base()); }

template <class Iterator>
bool operator<=(const reverse_iterator<Iterator> &lhs,
                const reverse_iterator<Iterator> &rhs) { return (lhs.base() >= rhs.base()); }

template <class Iterator_L, class Iterator_R>
bool operator<=(const reverse_iterator<Iterator_L> &lhs,
                const reverse_iterator<Iterator_R> &rhs) { return (lhs.base() >= rhs.base()); }

template <class Iterator>
bool operator>(const reverse_iterator<Iterator> &lhs,
               const reverse_iterator<Iterator> &rhs) { return (lhs.base() < rhs.bash()); }

template <class Iterator_L, class Iterator_R>
bool operator>(const reverse_iterator<Iterator_L> &lhs,
               const reverse_iterator<Iterator_R> &rhs) { return (lhs.base() < rhs.base()); }

template <class Iterator>
bool operator>=(const reverse_iterator<Iterator> &lhs,
                const reverse_iterator<Iterator> &rhs) { return (lhs.base() <= rhs.base()); }

template <class Iterator_L, class Iterator_R>
bool operator>=(const reverse_iterator<Iterator_L> &lhs,
                const reverse_iterator<Iterator_R> &rhs) { return (lhs.base() <= rhs.base()); }

template <class Iterator>
reverse_iterator<Iterator> operator+(
    typename reverse_iterator<Iterator>::difference_type n,
    const reverse_iterator<Iterator> &rev_it) { return (rev_it + n); }

template <class Iterator>
typename reverse_iterator<Iterator>::difference_type operator-(
    const reverse_iterator<Iterator> &lhs,
    const reverse_iterator<Iterator> &rhs) { return (lhs.base() - rhs.base()); }

template <class Iterator_L, class Iterator_R>
bool operator-(const reverse_iterator<Iterator_L> &lhs,
               const reverse_iterator<Iterator_R> &rhs) { return (lhs.base() - rhs.base()); }

#endif