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
        /**
         * ? data
         */
        /**
         * ? begin
         */
        /**
         * ? end
         */
        /**
         * ? rbegin
         */
        /**
         * ? rend
         */
        /**
         * ? empty
         */
        /**
         * ? size
         */
        /**
         * ? max_size
         */
        /**
         * ? reserve
         */
        /**
         * ? capacity
         */
        /**
         * ? clear
         */
        /**
         * ? insert
         */
        /**
         * ? erase
         */
        /**
         * ? push_back
         */
        /**
         * ? pop_back
         */
        /**
         * ? resize
         */
        /**
         * ? swap
         */

        // NON-MEMBER FUNCITONS
        
        /**
         * ? operator==
         */
        /**
         * ? operator!=
         */
        /**
         * ? operator<
         */
        /**
         * ? operator<=
         */
        /**
         * ? operator>
         */
        /**
         * ? operator>=
         */
     
        
    }

};

#endif