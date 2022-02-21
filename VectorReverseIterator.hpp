/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rverse_iterator.hpp                         :+:      :+:    :+:   */
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
class VectorReverseIterator 
{
  public:
        typedef std::random_access_iterator_tag iterator_category;
        typedef T value_type;
        typedef T difference_type;
        typedef T* pointer;
        typedef T& reference;

    public:

        VectorReverseIterator()
        : _M_ptr(0) {}

        VectorReverseIterator(pointer _ptr)
        : _M_ptr(_ptr) {}

        ~VectorReverseIterator() {}

        VectorReverseIterator&
        operator=(VectorReverseIterator& rval) {
            _M_ptr = rval._M_current();
            return (*this);
        }

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

        VectorReverseIterator&
        operator++() {
            _M_ptr = _M_ptr - 1;
            return (*this);
        }

        VectorReverseIterator&
        operator--() {
            _M_ptr = _M_ptr + 1;
            return (*this);
        }
        
        VectorReverseIterator
        operator++(int post) {
            VectorReverseIterator tmp = *this;
        //    std::cout << "ptr before\t" << _M_ptr << std::endl;
            --this->_M_ptr;
         //   std::cout << "ptr after\t" << _M_ptr << std::endl;
            return (tmp);
        }

        VectorReverseIterator
        operator--(int post) {
            VectorReverseIterator tmp = *this;
            ++_M_ptr;
            return (tmp);
        }

        bool
        operator==(VectorReverseIterator<T> rval) const {
            return (_M_ptr == rval._M_current() ? true : false);
        }

        bool
        operator!=(VectorReverseIterator<T> rval) const {
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
                || _M_ptr == rval._M_current()) ? true : false);
        }
        reference
        operator[](int index) {
            return (*(_M_ptr + index));
        }

        pointer
        _M_current() const {
            return (_M_ptr);
        }
	private:
		pointer _M_ptr;

};