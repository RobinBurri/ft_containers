#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <memory>
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft
{
        template <class T, class Alloc = std::allocator<T>>
        class vector
        {
                /**
                * * MEMBER TYPES:
                https://en.cppreference.com/w/cpp/container/vector
                */
        public:
                typedef T value_type;
                typedef Alloc allocator_type;
                typedef std::size_t size_type;
                typedef std::ptrdiff_t difference_type;
                typedef typename allocator_type::reference reference;
                typedef typename allocator_type::const_reference const_reference;
                typedef typename allocator_type::pointer pointer;
                typedef typename allocator_type::const_pointer const_pointer;
                typedef ft::random_access_iterator<value_type> iterator;
                typedef ft::random_access_iterator<const value_type> const_iterator;
                typedef ft::reverse_iterator<iterator> reverse_iterator;
                typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

                /**
                 * * MEMBER FUNCTIONS:
                https://en.cppreference.com/w/cpp/container/vector/vector
                 */
                // CONSTRUCTORS:
                // vector();
                explicit vector(const allocator_type &alloc = allocator_type())
                    : _alloc(alloc),
                      _start(u_nullptr),
                      _end(u_nullptr),
                      _end_capacity(u_nullptr)
                {
                }

                // explicit vector(size_type count,
                //                 const T &value = T(),
                //                 const Allocator &alloc = Allocator());
                explicit vector(size_type n, const value_type &val = value_type(),
                                const allocator_type &alloc = allocator_type())
                    : _alloc(alloc),
                      _start(u_nullptr),
                      _end(u_nullptr),
                      _end_capacity(u_nullptr)
                {
                        _start = _alloc.allocate(n);
                        _end_capacity = _start + n;
                        _end = _start;
                        while (n--)
                        {
                                _alloc.construct(_end, val);
                                _end++;
                        }
                }

                // template <class InputIt>
                // vector(InputIt first, InputIt last,
                //        const Allocator &alloc = Allocator());
                template <class InputIterator>
                vector(InputIterator first, InputIterator last,
                       const allocator_type &alloc = allocator_type(),
                       typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = u_nullptr)
                    : _alloc(alloc)
                {
                        bool is_valid;
                        if (!(is_valid = ft::is_ft_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category>::value))
                                throw(ft::InvalidIteratorException<typename ft::is_ft_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category>::type>());

                        difference_type n = ft::distance(first, last);
                        _start = _alloc.allocate(n);
                        _end_capacity = _start + n;
                        _end = _start;
                        while (n--)
                        {
                                _alloc.construct(_end, *first++);
                                _end++;
                        }
                }

                // vector(const vector &other);
                vector(const vector &x)
                    : _alloc(x._alloc),
                      _start(u_nullptr),
                      _end(u_nullptr),
                      _end_capacity(u_nullptr)
                {
                        this->insert(this->begin(), x.begin(), x.end());
                }

                /**
                 * ? destructor
                 */
                // ~vector();
                ~vector()
                {
                        this->clear();
                        _alloc.deallocate(_start, this->capacity());
                }

                /**
                 * ? operator=
                 */
                // vector &operator=(const vector &other);
                vector &operator=(const vector &x)
                {
                        if (x == *this)
                                return (*this);
                        this->clear();
                        this->insert(this->end(), x.begin(), x.end());
                        return (*this);
                }

                /**
                 * ? assign
                 */
                // std::vector<T, Allocator>::assign
                // template <class InputIt>
                // void assign(InputIt first, InputIt last);
                template <class InputIterator>
                void assign(InputIterator first, InputIterator last,
                            typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = u_nullptr)
                {
                        bool is_valid;
                        if (!(is_valid = ft::is_ft_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category>::value))
                                throw(ft::InvalidIteratorException<typename ft::is_ft_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category>::type>());
                        this->clear();
                        size_type dist = ft::distance(first, last);
                        if (size_type(_end_capacity - _start) >= dist)
                        {
                                for (; &(*first) != &(*last); first++, _end++)
                                        _alloc.construct(_end, *first);
                        }
                        else
                        {
                                pointer new_start = pointer();
                                pointer new_end = pointer();
                                pointer new_end_capacity = pointer();

                                new_start = _alloc.allocate(dist);
                                new_end = new_start;
                                new_end_capacity = new_start + dist;

                                for (; &(*first) != &(*last); first++, new_end++)
                                        _alloc.construct(new_end, *first);

                                _alloc.deallocate(_start, this->capacity());

                                _start = new_start;
                                _end = new_end;
                                _end_capacity = new_end_capacity;
                        }
                }
                void assign(size_type n, const value_type &val)
                {
                        this->clear();
                        if (n == 0)
                                return;
                        if (size_type(_end_capacity - _start) >= n)
                        {
                                while (n)
                                {
                                        _alloc.construct(_end++, val);
                                        n--;
                                }
                        }
                        else
                        {
                                _alloc.deallocate(_start, this->capacity());
                                _start = _alloc.allocate(n);
                                _end = _start;
                                _end_capacity = _start + n;
                                while (n)
                                {
                                        _alloc.construct(_end++, val);
                                        n--;
                                }
                        }
                }

                /**
                 * ? get_allocator
                 */
                // allocator_type get_allocator() const;

                /**
                 * ? at
                 */
                // reference at(size_type pos);
                reference at(size_type n)
                {
                        checkRange(n);
                        return ((*this)[n]);
                }

                // const_reference at( size_type pos ) const;
                const_reference at(size_type n) const
                {
                        checkRange(n);
                        return ((*this)[n]);
                }
                /**
                 * ? operator []
                 */

                // reference operator[]( size_type pos );
                reference operator[](size_type n) { return (*(_start + n)); }

                // const_reference operator[]( size_type pos ) const;
                const_reference operator[](size_type n) const { return (*(_start + n)); }

                /**
                 * ? front
                 */
                // reference front();
                reference front() { return (*_start); }

                // const_reference front() const;
                const_reference front() const { return (*_start); }

                /**
                 * ? back
                 */
                // reference back();
                reference back() { return (*(_end - 1)); }

                // const_reference back() const;
                const_reference back() const { return (*(_end - 1)); }

                /**
                 * ? data
                 */

                // T* data();

                // const T *data() const;

                /**
                 * ? begin
                 */

                // iterator begin();
                iterator begin() { return (_start); };

                // const_iterator begin() const;
                const_iterator begin() const { return (_start); }

                /**
                 * ? end
                 */
                // iterator end();
                iterator end()
                {
                        if (this->empty())
                                return (this->begin());
                        return (_end);
                }

                // const_iterator end() const;
                const_iterator end() const
                {
                        if (this->empty())
                                return (this->begin());
                        return (_end);
                }

                /**
                 * ? rbegin
                 */
                // reverse_iterator rbegin();
                reverse_iterator rbegin() { return (reverse_iterator(this->end())); }

                // const_reverse_iterator rbegin() const;
                const_reverse_iterator rbegin() const { return (reverse_iterator(this->end())); }

                /**
                 * ? rend
                 */
                // reverse_iterator rend();
                reverse_iterator rend() { return (reverse_iterator(this->begin())); }

                // const_reverse_iterator rend() const;
                const_reverse_iterator rend() const { return (reverse_iterator(this->begin())); }

                /**
                 * ? empty
                 */
                // bool empty() const;
                bool empty(void) const { return (size() == 0 ? true : false); }

                /**
                 * ? size
                 */
                // size_type size() const;
                size_type size(void) const { return (this->_end - this->_start); }

                /**
                 * ? max_size
                 */
                // size_type max_size() const;
                size_type max_size(void) const { return allocator_type().max_size(); }

                /**
                 * ? reserve
                 */
                // void reserve( size_type new_cap );
                void reserve(size_type n)
                {
                        if (n > this->max_size())
                                throw(std::length_error("vector::reserve"));
                        else if (n > this->capacity())
                        {
                                pointer prev_start = _start;
                                pointer prev_end = _end;
                                size_type prev_size = this->size();
                                size_type prev_capacity = this->capacity();

                                _start = _alloc.allocate(n);
                                _end_capacity = _start + n;
                                _end = _start;
                                while (prev_start != prev_end)
                                {
                                        _alloc.construct(_end, *prev_start);
                                        _end++;
                                        prev_start++;
                                }
                                _alloc.deallocate(prev_start - prev_size, prev_capacity);
                        }
                }

                /**
                 * ? capacity
                 */
                // size_type capacity() const;
                size_type capacity(void) const { return (this->_end_capacity - this->_start); }

                /**
                 * ? clear
                 */
                // void clear();
                void clear()
                {
                        size_type save_size = this->size();
                        for (size_type i = 0; i < save_size; i++)
                        {
                                _end--;
                                _alloc.destroy(_end);
                        }
                }

                /**
                 * ? insert
                 */
                // iterator insert(const_iterator pos, const T &value);
                iterator insert(iterator position, const value_type &val)
                {
                        size_type pos_len = &(*position) - _start;
                        if (size_type(_end_capacity - _end) >= this->size() + 1)
                        {
                                for (size_type i = 0; i < pos_len; i++)
                                        _alloc.construct(_end - i, *(_end - i - 1));
                                _end++;
                                _alloc.construct(&(*position), val);
                        }
                        else
                        {
                                pointer new_start = pointer();
                                pointer new_end = pointer();
                                pointer new_end_capacity = pointer();

                                int next_capacity = (this->size() * 2 > 0) ? this->size() * 2 : 1;
                                new_start = _alloc.allocate(next_capacity);
                                new_end = new_start + this->size() + 1;
                                new_end_capacity = new_start + next_capacity;

                                for (size_type i = 0; i < pos_len; i++)
                                        _alloc.construct(new_start + i, *(_start + i));
                                _alloc.construct(new_start + pos_len, val);
                                for (size_type j = 0; j < this->size() - pos_len; j++)
                                        _alloc.construct(new_end - j - 1, *(_end - j - 1));

                                for (size_type l = 0; l < this->size(); l++)
                                        _alloc.destroy(_start + l);
                                if (_start)
                                        _alloc.deallocate(_start, this->capacity());

                                _start = new_start;
                                _end = new_end;
                                _end_capacity = new_end_capacity;
                        }
                        return (iterator(_start + pos_len));
                }

                // iterator insert(const_iterator pos, size_type count, const T &value);
                void insert(iterator position, size_type n, const value_type &val)
                {
                        if (n == 0)
                                return;
                        if (n > this->max_size())
                                throw(std::length_error("vector::insert (fill)"));
                        size_type pos_len = &(*position) - _start;
                        if (size_type(_end_capacity - _end) >= n)
                        {
                                for (size_type i = 0; i < this->size() - pos_len; i++)
                                        _alloc.construct(_end - i + (n - 1), *(_end - i - 1));
                                _end += n;
                                while (n)
                                {
                                        _alloc.construct(&(*position) + (n - 1), val);
                                        n--;
                                }
                        }
                        else
                        {
                                pointer new_start = pointer();
                                pointer new_end = pointer();
                                pointer new_end_capacity = pointer();

                                int next_capacity = (this->capacity() > 0) ? (int)(this->size() * 2) : 1;
                                new_start = _alloc.allocate(next_capacity);
                                new_end_capacity = new_start + next_capacity;

                                if (size_type(new_end_capacity - new_start) < this->size() + n)
                                {
                                        if (new_start)
                                                _alloc.deallocate(new_start, new_start - new_end_capacity);
                                        next_capacity = this->size() + n;
                                        new_start = _alloc.allocate(next_capacity);
                                        new_end = new_start + this->size() + n;
                                        new_end_capacity = new_start + next_capacity;
                                }

                                new_end = new_start + this->size() + n;

                                for (int i = 0; i < (&(*position) - _start); i++)
                                        _alloc.construct(new_start + i, *(_start + i));
                                for (size_type k = 0; k < n; k++)
                                        _alloc.construct(new_start + pos_len + k, val);
                                for (size_type j = 0; j < (this->size() - pos_len); j++)
                                        _alloc.construct(new_end - j - 1, *(_end - j - 1));

                                for (size_type u = 0; u < this->size(); u++)
                                        _alloc.destroy(_start + u);
                                _alloc.deallocate(_start, this->capacity());

                                _start = new_start;
                                _end = new_end;
                                _end_capacity = new_end_capacity;
                        }
                }

                // template< class InputIt >
                // iterator insert(const_iterator pos, InputIt first, InputIt last);
                template <class InputIterator>
                void insert(iterator position, InputIterator first, InputIterator last,
                            typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = u_nullptr)
                {
                        bool is_valid;
                        if (!(is_valid = ft::is_ft_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category>::value))
                                throw(ft::InvalidIteratorException<typename ft::is_ft_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category>::type>());

                        size_type dist = ft::distance(first, last);
                        if (size_type(_end_capacity - _end) >= dist)
                        {
                                for (size_type i = 0; i < this->size() - (&(*position) - _start); i++)
                                        _alloc.construct(_end - i + (dist - 1), *(_end - i - 1));
                                _end += dist;
                                for (; &(*first) != &(*last); first++, position++)
                                        _alloc.construct(&(*position), *first);
                        }
                        else
                        {
                                pointer new_start = pointer();
                                pointer new_end = pointer();
                                pointer new_end_capacity = pointer();

                                new_start = _alloc.allocate(this->size() * 2);
                                new_end = new_start + this->size() + dist;
                                new_end_capacity = new_start + (this->size() * 2);

                                if (size_type(new_end_capacity - new_start) < this->size() + dist)
                                {
                                        if (new_start)
                                                _alloc.deallocate(new_start, new_end_capacity - new_start);
                                        new_start = _alloc.allocate(this->size() + dist);
                                        new_end = new_start + this->size() + dist;
                                        new_end_capacity = new_end;
                                }

                                for (int i = 0; i < &(*position) - _start; i++)
                                        _alloc.construct(new_start + i, *(_start + i));
                                for (int j = 0; &(*first) != &(*last); first++, j++)
                                        _alloc.construct(new_start + (&(*position) - _start) + j, *first);
                                for (size_type k = 0; k < this->size() - (&(*position) - _start); k++)
                                        _alloc.construct(new_start + (&(*position) - _start) + dist + k, *(_start + (&(*position) - _start) + k));

                                for (size_type l = 0; l < this->size(); l++)
                                        _alloc.destroy(_start + l);
                                _alloc.deallocate(_start, this->capacity());

                                _start = new_start;
                                _end = new_end;
                                _end_capacity = new_end_capacity;
                        }
                }
                /**
                 * ? erase
                 */
                // iterator erase(iterator pos);
                iterator erase(iterator position)
                {
                        pointer p_pos = &(*position);
                        _alloc.destroy(&(*position));
                        if (&(*position) + 1 == _end)
                                _alloc.destroy(&(*position));
                        else
                        {
                                for (int i = 0; i < _end - &(*position) - 1; i++)
                                {
                                        _alloc.construct(&(*position) + i, *(&(*position) + i + 1));
                                        _alloc.destroy(&(*position) + i + 1);
                                }
                        }
                        _end -= 1;
                        return (iterator(p_pos));
                }
                // iterator erase( iterator first, iterator last );
                iterator erase(iterator first, iterator last)
                {
                        pointer p_first = &(*first);
                        for (; &(*first) != &(*last); first++)
                                _alloc.destroy(&(*first));
                        for (int i = 0; i < _end - &(*last); i++)
                        {
                                _alloc.construct(p_first + i, *(&(*last) + i));
                                _alloc.destroy(&(*last) + i);
                        }
                        _end -= (&(*last) - p_first);
                        return (iterator(p_first));
                }

                /**
                 * ? push_back
                 */
                // void push_back( const T& value );
                void push_back(const value_type &val)
                {
                        if (_end == _end_capacity)
                        {
                                int next_capacity = (this->size() > 0) ? (int)(this->size() * 2) : 1;
                                this->reserve(next_capacity);
                        }
                        _alloc.construct(_end, val);
                        _end++;
                }
                //
                /**
                 * ? pop_back
                 */
                // void pop_back();
                void pop_back()
                {
                        _alloc.destroy(&this->back());
                        _end--;
                }

                /**
                 * ? resize
                 */
                // void resize( size_type count, T value = T() );
                void resize(size_type n, value_type val = value_type())
                {
                        if (n > this->max_size())
                                throw(std::length_error("vector::resize"));
                        else if (n < this->size())
                        {
                                while (this->size() > n)
                                {
                                        --_end;
                                        _alloc.destroy(_end);
                                }
                        }
                        else
                                this->insert(this->end(), n - this->size(), val);
                }

                /**
                 * ? swap
                 */
                // void swap(vector &other);
                void swap(vector &x)
                {
                        if (x == *this)
                                return;

                        pointer save_start = x._start;
                        pointer save_end = x._end;
                        pointer save_end_capacity = x._end_capacity;
                        allocator_type save_alloc = x._alloc;

                        x._start = this->_start;
                        x._end = this->_end;
                        x._end_capacity = this->_end_capacity;
                        x._alloc = this->_alloc;

                        this->_start = save_start;
                        this->_end = save_end;
                        this->_end_capacity = save_end_capacity;
                        this->_alloc = save_alloc;
                }

        private:
                allocator_type _alloc;
                pointer _start;
                pointer _end;
                pointer _end_capacity;

                /*
                ** @brief Check if "n" is in the range of the container.
                ** If "n" is out of range that's throw an std::out_of_range
                ** exception.
                **
                ** @param n The position of the element to check.
                */
                void checkRange(const size_type &n) const
                {
                        if (n >= this->size())
                                throw(std::out_of_range("vector::checkRange: n (which is " + ft::to_string(n) + ") >= this->size() (which is " + ft::to_string(this->size()) + ")"));
                }
        }
        // NON-MEMBER FUNCITONS

        /**
         * ? operator==
         */
        // bool operator==( const std::vector<T,Alloc>& lhs,
        //  const std::vector<T,Alloc>& rhs );
        template <class T, class Alloc>
        bool operator==(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
        {
                if (lhs.size() != rhs.size())
                        return (false);
                typename ft::vector<T>::const_iterator first1 = lhs.begin();
                typename ft::vector<T>::const_iterator first2 = rhs.begin();
                while (first1 != lhs.end())
                {
                        if (first2 == rhs.end() || *first1 != *first2)
                                return (false);
                        ++first1;
                        ++first2;
                }
                return (true);
        }
        /**
         * ? operator!=
         */
        // bool operator!=( const std::vector<T,Alloc>& lhs,
        //  const std::vector<T,Alloc>& rhs );
        template <class T, class Alloc>
        bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
        {
                return (!(lhs == rhs));
        }

        /**
         * ? operator<
         */
        // bool operator<(const std::vector<T, Alloc> &lhs,
        //    const std::vector<T, Alloc> &rhs);
        template <class T, class Alloc>
        bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
        {
                return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
        }

        /**
         * ? operator<=
         */
        // bool operator<=( const std::vector<T,Alloc>& lhs,
        //  const std::vector<T,Alloc>& rhs );
        template <class T, class Alloc>
        bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
        {
                return (!(rhs < lhs));
        }

        /**
         * ? operator>
         */
        // bool operator>( const std::vector<T,Alloc>& lhs,
        // const std::vector<T,Alloc>& rhs );
        template <class T, class Alloc>
        bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
        {
                return (rhs < lhs);
        }

        /**
         * ? operator>=
         */
        // bool operator>=(const std::vector<T, Alloc> &lhs,
        // const std::vector<T, Alloc> &rhs);
        template <class T, class Alloc>
        bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
        {
                return (!(lhs < rhs));
        }
        /*
         ** @brief Overload of swap (vector).
         ** The contents of container are swaped.
         **
         ** @param x, y the containers to swap.
         */
        template <class T, class Alloc>
        void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
        {
                x.swap(y);
        }
};

#endif