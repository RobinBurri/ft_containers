#ifndef FT_ITERATOR_TRAITS_HPP
#define FT_ITERATOR_TRAITS_HPP

namespace ft
{
    /**
     * * Iterator base class:
     * This is a base class template that can be used to derive iterator classes from it.
     * It is not an iterator class and does not provide any of the functionality an iterator is expected to have.
     * https://cplusplus.com/reference/iterator/iterator/
     */
    class input_iterator_tag {};
    class output_iterator_tag {};
    class forward_iterator_tag {};
    class bidirectional_iterator_tag {};
    class random_access_iterator_tag {};
    /**
     * * Iterator traits:
     * Standard algorithms determine certain properties of the iterators passed to them and the range they represent,
     *  by using the members of the corresponding iterator_traits instantiation.
     * https://cplusplus.com/reference/iterator/iterator_traits/
     */
    template <class Iterator>
    class iterator_traits
    {
        typedef typename Iterator::difference_type      difference_type;
        typedef typename Iterator::value_type           value_type;
        typedef typename Iterator::pointer              pointer;
        typedef typename Iterator::reference            reference;
        typedef typename Iterator::iterator_category    iterator_category;
    };

    template <class T>
    class iterator_traits<T *>
    {
        typedef ptrdiff_t                               difference_type;
        typedef T                                       value_type;
        typedef T*                                      pointer;
        typedef T&                                      reference;
        typedef ft::random_access_iterator_tag          iterator_category;
    };

    template <class T>
    class iterator_traits<const T *>
    {
        typedef ptrdiff_t                               difference_type;
        typedef T                                       value_type;
        typedef const T*                                pointer;
        typedef const T&                                reference;
        typedef ft::random_access_iterator_tag          iterator_category;
    };
    /**
     * * Predefined iterators:
     * https://cplusplus.com/reference/iterator/
    */
   template<class InputIterator>
        typename ft::iterator_traits<InputIterator>::difference_type
            distance (InputIterator first, InputIterator last)
        {
            typename ft::iterator_traits<InputIterator>::difference_type rtn = 0;
            while (first != last)
            {
                first++;
                rtn++;
            }
            return (rtn);
        }
    template <class Iterator> class reverse_iterator;
}

#endif
