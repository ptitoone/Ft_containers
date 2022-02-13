/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_const_iterator.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:05:22 by akotzky           #+#    #+#             */
/*   Updated: 2022/02/12 12:50:38 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#include <iterator>

template <typename T>
class VectorConstIterator
{
    public:
        typedef std::random_access_iterator_tag iterator_category;
        typedef T value_type;
        typedef T difference_type;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef const T& const_reference;

    public:

        VectorConstIterator()
        : _M_ptr(0) {}

        VectorConstIterator(pointer _ptr)
        : _M_ptr(_ptr) {}

        ~VectorConstIterator() {}

        const_reference
        operator*() const {
            return (*_M_ptr);
        }
        
        const VectorConstIterator&
        operator++() {
            _M_ptr = _M_ptr + 1;
            return (*this);
        }

        const VectorConstIterator&
        operator--() {
            _M_ptr = _M_ptr - 1;
            return (*this);
        }
        
        const VectorConstIterator
        operator++(int post) {
            VectorConstIterator tmp = *this;
            ++_M_ptr;
            return (tmp);
        }

        const VectorConstIterator
        operator--(int post) {
            VectorConstIterator tmp = this;
            --_M_ptr;
            return (tmp);
        }

        bool
        operator==(const VectorConstIterator rval) const {
            return (*_M_ptr == *rval ? true : false);
        }

        bool
        operator!=(const VectorConstIterator rval) const {
            return (!(*_M_ptr == *rval));
        }

        bool
        operator<(const VectorConstIterator rval) const {
            return (*_M_ptr < rval ? true : false);
        }

        bool 
        operator<=(const VectorConstIterator rval) const {
            return ((*_M_ptr < rval || *_M_ptr == rval) ? true : false);
        }

        bool
        operator>(const VectorConstIterator rval) const {
            return (*_M_ptr > rval ? true : false);
        }

        bool
        operator>=(const VectorConstIterator rval) const {
            return ((*_M_ptr > rval || *_M_ptr == rval) ? true : false);
        }
        const_reference
        operator[](int index) {
            return (*(_M_ptr + index));
        }

        const_reference
        operator&() {
            return (_M_ptr); 
        }

        const_pointer
        operator->() {
            return(_M_ptr);
        }

	private:
		pointer _M_ptr;

};