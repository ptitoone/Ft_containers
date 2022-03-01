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
#include "IteratorTraits.hpp"
#include "Iterator.hpp"
#include "RandomAccessIterator.hpp"
#include <cstddef>

template <class T, class Category = class random_access_iterator_tag>
class VectorIterator : public ft::iterator<T, Category>, public RandomAccessIterator<T>
{
      public:
            typedef typename ft::iterator_traits<T>::difference_type      difference_type;
            typedef typename ft::iterator_traits<T>::value_type           value_type;
            typedef typename ft::iterator_traits<T>::pointer              pointer;
            typedef typename ft::iterator_traits<T>::reference            reference;
            typedef typename ft::iterator_traits<T>::iterator_category    iterator_category;
        
            VectorIterator()
            : _M_ptr(0)
            {}

            VectorIterator(pointer const _ptr)
            : _M_ptr(_ptr)
            {}

            VectorIterator(RandomAccessIterator<T> const & _rval)
            : _M_ptr(_rval._M_current())
            {}

            ~VectorIterator() {}

            VectorIterator const & operator=(const RandomAccessIterator<T> & _rval) {
                this->_M_ptr = _rval._M_current();
        		return (*this);
            }

            private:
				pointer _M_ptr;
 };