#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <memory>

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
        // value_type       T
        typedef T value_type;
        // allocator_type   Alloctor
        typedef Alloc allocator_type;
        // size_type        std::size_t
        typedef std::size_t size_type;
        // difference_type  std::ptrdiff_t
        typedef std::ptrdiff_t difference_type;
        // reference        value_type&
        // const_reference  const value_type&
        // pointer          Allocator::pointer
        // const_pointer    Allocator::const_pointer
        // iterator
        // const_iterator
        // reverse_iterator
        // const_reverse_iterator

        /**
         * * MEMBER FUNCTIONS:
        https://en.cppreference.com/w/cpp/container/vector/vector
         * ? constructors
         */
        // vector();
        // explicit vector(const Allocator &alloc);

        // explicit vector(size_type count,
        //                 const T &value = T(),
        //                 const Allocator &alloc = Allocator());

        // template <class InputIt>
        // vector(InputIt first, InputIt last,
        //        const Allocator &alloc = Allocator());

        // vector(const vector &other);

        /**
         * ? destructor
         */
        // ~vector();

        /**
         * ? operator=
         */
        // vector &operator=(const vector &other);

        /**
         * ? assign
         */
        // std::vector<T, Allocator>::assign
        // template <class InputIt>
        // void assign(InputIt first, InputIt last);

        /**
         * ? get_allocator
         */
        // allocator_type get_allocator() const;

        /**
         * ? at
         */
        // reference at(size_type pos);

        // const_reference at( size_type pos ) const;

        /**
         * ? operator []
         */

        // reference operator[]( size_type pos );

        // const_reference operator[]( size_type pos ) const;

        /**
         * ? front
         */
        // reference front();

        // const_reference front() const;

        /**
         * ? back
         */
        // reference back();

        // const_reference back() const;

        /**
         * ? data
         */

        // T* data();

        // const T *data() const;

        /**
         * ? begin
         */

        // iterator begin();

        // const_iterator begin() const;


        /**
         * ? end
         */
        // iterator end();

        // const_iterator end() const;

        /**
         * ? rbegin
         */
        // reverse_iterator rbegin();

        // const_reverse_iterator rbegin() const;

        /**
         * ? rend
         */
        // reverse_iterator rend();

        // const_reverse_iterator rend() const;

        /**
         * ? empty
         */
        // bool empty() const;

        /**
         * ? size
         */
        // size_type size() const;

        /**
         * ? max_size
         */
        // size_type max_size() const;
        /**
         * ? reserve
         */
        // void reserve( size_type new_cap );

        /**
         * ? capacity
         */
        // size_type capacity() const;

        /**
         * ? clear
         */
        // void clear();

        /**
         * ? insert
         */
        // iterator insert(const_iterator pos, const T &value);

        // iterator insert(const_iterator pos, size_type count, const T &value);

        // template< class InputIt >
        // iterator insert(const_iterator pos, InputIt first, InputIt last);


        /**
         * ? erase
         */
        // iterator erase(iterator pos);

        // iterator erase( iterator first, iterator last );

        /**
         * ? push_back
         */
        // void push_back( const T& value );

        // 
        /**
         * ? pop_back
         */
        // void pop_back();

        /**
         * ? resize
         */
        // void resize( size_type count, T value = T() );
        
        /**
         * ? swap
         */
        // void swap(vector &other);

        // NON-MEMBER FUNCITONS
        
        /**
         * ? operator==
         */
        // bool operator==( const std::vector<T,Alloc>& lhs,
                //  const std::vector<T,Alloc>& rhs );
        /**
         * ? operator!=
         */
        // bool operator!=( const std::vector<T,Alloc>& lhs,
                //  const std::vector<T,Alloc>& rhs );

        /**
         * ? operator<
         */
        // bool operator<(const std::vector<T, Alloc> &lhs,
                    //    const std::vector<T, Alloc> &rhs);

        /**
         * ? operator<=
         */
        // bool operator<=( const std::vector<T,Alloc>& lhs,
                //  const std::vector<T,Alloc>& rhs );

        /**
         * ? operator>
         */
        // bool operator>( const std::vector<T,Alloc>& lhs,
                // const std::vector<T,Alloc>& rhs );

        /**
         * ? operator>=
         */
        // bool operator>=(const std::vector<T, Alloc> &lhs,
                        // const std::vector<T, Alloc> &rhs);
        }

};

#endif