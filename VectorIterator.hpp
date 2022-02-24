/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:05:22 by akotzky           #+#    #+#             */
/*   Updated: 2022/02/21 21:30:28 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#include <iterator>

template <typename T>
class VectorIterator
{
    public:
        typedef std::random_access_iterator_tag iterator_category;
        typedef T value_type;
        typedef T difference_type;
        typedef T* pointer;
        typedef T& reference;

    public:

        VectorIterator()
        : _M_ptr(0) {}

        VectorIterator(pointer _ptr)
        : _M_ptr(_ptr) {}

        ~VectorIterator() {}

        reference
        operator*() {
            return (*_M_ptr);
        }
        
        reference
        operator&() {
            return (_M_ptr); 
        }

        pointer
        operator->() {
            return(_M_ptr);
        }

        VectorIterator&
        operator+(size_type _n) {
            return (_M_ptr + _n);
        }

        VectorIterator&
        operator-(size_type _n) {
            return (_M_ptr - _n);
        }

        VectorIterator&
        operator++() {
            _M_ptr = _M_ptr + 1;
            return (*this);
        }

        VectorIterator&
        operator--() {
            _M_ptr = _M_ptr - 1;
            return (*this);
        }
        
        VectorIterator
        operator++(int post) {
            VectorIterator tmp = *this;
            ++_M_ptr;
            return (tmp);
        }

        VectorIterator
        operator--(int post) {
            VectorIterator tmp = this;
            --_M_ptr;
            return (tmp);
        }

        bool
        operator==(VectorIterator<T> rval) const {
            return (_M_ptr == rval._M_current() ? true : false);
        }

        bool
        operator!=(VectorIterator<T> rval) const {
            return (!(_M_ptr == rval._M_current()));
        }

        bool
        operator<(reference rval) const {
            return (_M_ptr < rval._M_current() ? true : false);
        }

        bool 
        operator<=(reference rval) const {
            return ((_M_ptr < rval._M_current()
                || _M_ptr == rval._M_current()) ? true : false);
        }

        bool
        operator>(reference rval) const {
            return (_M_ptr > rval._M_current() ? true : false);
        }

        bool
        operator>=(reference rval) const {
            return ((_M_ptr > rval._M_current()
                || _M_ptr == rval)._M_current() ? true : false);
        }
        reference
        operator[](int index) {
            return (*(_M_ptr + index));
        }

        pointer
        _M_current() {
            return (_M_ptr);
        }
	private:
		pointer _M_ptr;

};