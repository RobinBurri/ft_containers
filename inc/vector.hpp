#ifndef FT__VECTOR_HPP
#define FT__VECTOR_HPP

#include <iostream>
#include <memory>

#include "compare.hpp"
#include "iterator.hpp"
#include "random_access_iterator.hpp"
#include "type_traits.hpp"
#include "util.hpp"

namespace ft
{
    template <class T, class Alloc = std::allocator<T>>
    class vector
    {
    public:
        typedef T value_type;
        typedef T const const_value_type;
        typedef Alloc allocator_type;

        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef typename ft::random_access_iterator<value_type> iterator;
        typedef typename ft::random_access_iterator<const_value_type> const_iterator;
        typedef typename ft::reverse_iterator<iterator> reverse_iterator;
        typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
        typedef typename allocator_type::size_type size_type;

    private:
        allocator_type alloc;
        pointer start;
        pointer end;
        pointer end_capacity;

    public:
        explicit vector(const allocator_type &alloc = allocator_type())
            : alloc(alloc),
              start(u_nullptr),
              end(u_nullptr),
              end_capacity(u_nullptr){};

        explicit vector(size_type n, const value_type &val = value_type(),
                        const allocator_type &alloc = allocator_type())
            : alloc(alloc)
        {
            this->start = this->alloc.allocate(n);
            this->end = this->start;
            this->end_capacity = this->start + n;
            while (n--)
                this->alloc.construct(this->end++, val);
        };

        template <class InputIterator>
        vector(InputIterator first, InputIterator last,
               const allocator_type &alloc = allocator_type(),
               typename ft::enable_if<
                   !ft::is_integral<InputIterator>::value>::type * = u_nullptr)
            : alloc(alloc)
        {
            size_type n = ft::difference(first, last);
            this->start = this->alloc.allocate(n);
            this->end_capacity = this->start + n;
            this->end = this->start;
            while (n--)
                this->alloc.construct(this->end++, *first++);
        };

        vector(const vector &x) : alloc(x.alloc)
        {
            size_type n = x.size();
            this->start = this->alloc.allocate(n);
            this->end_capacity = this->start + n;
            this->end = this->start;

            pointer other = x.start;
            while (n--)
                this->alloc.construct(this->end++, *other++);
        };

        vector &operator=(const vector &x)
        {
            if (this != &x)
            {
                this->clear();
                this->insert(this->start, x.begin(), x.end());
            }
            return *this;
        };

        ~vector()
        {
            this->clear();
            this->alloc.deallocate(this->start, this->capacity());
        };

        iterator begin() { return (this->start); };

        const_iterator begin() const { return (this->start); };

        reverse_iterator rbegin() { return reverse_iterator(iterator(this->end)); };

        const_reverse_iterator rbegin() const { return (this->end); };

        iterator end() { return (this->end); };

        const_iterator end() const { return (this->end); };

        reverse_iterator rend() { return reverse_iterator(this->start); };

        const_reverse_iterator rend() const { return (this->start); };

        size_type size() const { return (this->end - this->start); };

        size_type max_size() const { return (this->alloc.max_size()); };

        void resize(size_type n, value_type val = value_type())
        {
            if (n > this->max_size())
            {
                throw std::out_of_range("ft::vector");
            }
            size_type prev_size = this->size();
            if (prev_size > n)
            {
                while (prev_size-- > n)
                {
                    this->alloc.destroy(--this->end);
                }
                return;
            }
            this->insert(this->end, n - prev_size, val);
        };

        size_type capacity() const { return (this->end_capacity - this->start); };

        bool empty() const { return (this->size() == 0); };

        void reserve(size_type n)
        {
            if (n > this->max_size())
            {
                throw std::out_of_range("ft::vector");
            }

            if (this->capacity() >= n)
            {
                return;
            }

            pointer prevstart = this->start;
            pointer prevend = this->end;
            size_type prev_capacity = this->capacity();

            this->start = this->alloc.allocate(n);
            this->end_capacity = this->start + n;
            this->end = this->start;

            for (pointer target = prevstart; target != prevend; ++target)
            {
                this->alloc.construct(this->end++, *target);
            }
            for (size_type len = prevend - prevstart; len > 0; --len)
            {
                this->alloc.destroy(--prevend);
            }
            this->alloc.deallocate(prevstart, prev_capacity);
        };

        reference operator[](size_type n) { return (this->start[n]); };

        const_reference operator[](size_type n) const { return (this->start[n]); };

        reference at(size_type n)
        {
            if (this->size() < n)
            {
                throw std::out_of_range("ft::vector");
            }
            return (this->start[n]);
        };

        const_reference at(size_type n) const
        {
            if (this->size() < n)
            {
                throw std::out_of_range("ft::vector");
            }
            return (this->start[n]);
        };

        reference front() { return (*this->start); };

        const_reference front() const { return (*this->start); };

        reference back() { return *(this->end - 1); };

        const_reference back() const { return *(this->end - 1); };

        // value_type* data() noexcept;
        // const value_type* data() const noexcept;

        template <class InputIterator>
        void assign(
            InputIterator first, InputIterator last,
            typename ft::enable_if<
                !ft::is_integral<InputIterator>::value>::type * = u_nullptr)
        {
            size_type n = ft::difference(first, last);
            if (this->capacity() < n)
            {
                this->start = this->alloc.allocate(n);
                this->end_capacity = this->start + n;
                this->end = this->start;
            }
            else
            {
                this->clear();
            }
            while (n--)
                this->alloc.construct(this->end++, *first++);
        };

        void assign(size_type n, const value_type &val)
        {
            this->clear();
            if (this->capacity() >= n)
            {
                while (n--)
                    this->alloc.construct(this->end++, val);
            }
            else
            {
                this->start = this->alloc.allocate(n);
                this->end_capacity = this->start + n;
                this->end = this->start;
                while (n--)
                    this->alloc.construct(this->end++, val);
            }
        };

        void push_back(const value_type &val)
        {
            if (this->end_capacity == this->end)
            {
                size_type capacity =
                    (this->size() == 0) ? 1 : (this->end_capacity - this->start) * 2;
                this->reserve(capacity);
            }
            this->alloc.construct(this->end++, val);
        };

        void pop_back() { this->alloc.destroy(--this->end); };

        iterator insert(iterator position, const value_type &val)
        {
            size_type pos_at = &(*position) - this->start;
            this->insert(position, 1, val);
            return (this->start + pos_at);
        };

        void insert(iterator position, size_type n, const value_type &val)
        {
            size_type pos_at = &(*position) - this->start;

            if (this->capacity() >= this->size() + n)
            {
                for (size_type i = 0; i < this->size() - pos_at; ++i)
                {
                    this->alloc.construct(this->end + n - i, *(this->end - i));
                    this->alloc.destroy(this->end - i);
                }
                this->end = this->start + this->size() + n;
                for (size_type i = 0; i < n; ++i)
                {
                    this->alloc.construct(this->start + pos_at + i, val);
                }
                return;
            }

            size_type next_capacity = this->size() + n;

            pointer prevstart = this->start;
            pointer prevend = this->end;
            size_type prev_size = this->size();
            size_type prev_capacity = this->capacity();

            this->start = this->alloc.allocate(next_capacity);
            this->end = this->start + prev_size + n;
            this->end_capacity = this->end;

            for (size_type i = 0; i < pos_at; ++i)
            {
                this->alloc.construct(this->start + i, *(prevstart + i));
                this->alloc.destroy(prevstart + i);
            }

            for (size_type i = 0; i < prev_size - pos_at; ++i)
            {
                this->alloc.construct(this->end - i - 1, *(prevend - i - 1));
                this->alloc.destroy(prevend - i - 1);
            }

            for (size_type i = 0; i < n; ++i)
            {
                this->alloc.construct(this->start + pos_at + i, val);
            }

            this->alloc.deallocate(prevstart, prev_capacity);
            return;
        };

        template <class InputIterator>
        void insert(
            iterator position, InputIterator first, InputIterator last,
            typename ft::enable_if<
                !ft::is_integral<InputIterator>::value>::type * = u_nullptr)
        {
            size_type pos_at = &(*position) - this->start;
            size_type n = ft::difference(first, last);

            if (this->capacity() >= this->size() + n)
            {
                for (size_type i = 0; i < this->size() - pos_at; ++i)
                {
                    this->alloc.construct(this->end + n - i, *(this->end - i));
                    this->alloc.destroy(this->end - i);
                }
                this->end = this->start + this->size() + n;
                for (size_type i = 0; i < n; ++i)
                {
                    this->alloc.construct(this->start + pos_at + i, *first++);
                }
                return;
            }

            size_type next_capacity = this->size() + n;

            pointer prevstart = this->start;
            pointer prevend = this->end;
            size_type prev_size = this->size();
            size_type prev_capacity = this->capacity();

            this->start = this->alloc.allocate(next_capacity);
            this->end = this->start + prev_size + n;
            this->end_capacity = this->end;

            for (size_type i = 0; i < pos_at; ++i)
            {
                this->alloc.construct(this->start + i, *(prevstart + i));
                this->alloc.destroy(prevstart + i);
            }

            for (size_type i = 0; i < prev_size - pos_at; ++i)
            {
                this->alloc.construct(this->end - i - 1, *(prevend - i - 1));
                this->alloc.destroy(prevend - i - 1);
            }

            for (size_type i = 0; i < n; ++i)
            {
                this->alloc.construct(this->start + pos_at + i, *first++);
            }
            this->alloc.deallocate(prevstart, prev_capacity);
            return;
        }

        iterator erase(iterator position)
        {
            size_type pos_at = &(*position) - this->start;
            this->alloc.destroy(&(*position));
            for (size_type i = 0; i < this->size() - pos_at; ++i)
            {
                this->alloc.construct(this->start + pos_at + i,
                                      *(this->start + pos_at + i + 1));
                this->alloc.destroy(this->start + pos_at + i + 1);
            }
            --this->end;
            return this->start + pos_at;
        };

        iterator erase(iterator first, iterator last)
        {
            size_type pos_at = &(*first) - this->start;
            size_type n = last - first;
            for (size_type i = 0; i < n; ++i)
            {
                this->alloc.destroy(&(*(first + i)));
            }
            for (size_type i = 0; i < this->size() - pos_at; ++i)
            {
                this->alloc.construct(this->start + pos_at + i,
                                      *(this->start + pos_at + i + n));
                this->alloc.destroy(this->start + pos_at + i + n);
            }
            this->end = this->start + this->size() - n;
            return this->start + pos_at;
        };

        void swap(vector &x)
        {
            if (&x == this)
            {
                return;
            }

            pointer start = x.start;
            pointer end = x.end;
            pointer end_capacity = x.end_capacity;
            x.start = this->start;
            x.end = this->end;
            x.end_capacity = this->end_capacity;
            this->start = start;
            this->end = end;
            this->end_capacity = end_capacity;
        };

        void clear()
        {
            while (this->start != this->end)
            {
                this->alloc.destroy(--this->end);
            }
        };

        allocator_type getallocator() const { return this->alloc; };
    };

    template <class T, class Alloc>
    bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        if (lhs.size() != rhs.size())
        {
            return false;
        }
        return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
    };

    template <class T, class Alloc>
    bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return !(lhs == rhs);
    };

    template <class T, class Alloc>
    bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                           rhs.end());
    };

    template <class T, class Alloc>
    bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return (!(rhs < lhs));
    };

    template <class T, class Alloc>
    bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return (rhs < lhs);
    };

    template <class T, class Alloc>
    bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return (!(lhs < rhs));
    };

    template <class T, class Alloc>
    void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
    {
        x.swap(y);
    };

};

#endif