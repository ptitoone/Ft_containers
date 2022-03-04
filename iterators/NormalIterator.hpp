#pragma once

#include "Iterator.hpp"
#include "IteratorTraits.hpp"

namespace ft {
        using ft::iterator;
        using ft::iterator_traits;
		template <class _Iterator, class _Container>
		class NormalIterator {
		protected:
				_Iterator _M_ptr;
				typedef typename ft::iterator_traits<_Iterator> _traits;

		public:
				typedef typename _traits::difference_type difference_type;
				typedef typename _traits::value_type value_type;
				typedef typename _traits::pointer pointer;
				typedef typename _traits::reference reference;
				typedef typename _traits::iterator_category iterator_category;

                NormalIterator()
                : _M_ptr(_Iterator())
                {}

				NormalIterator(_Iterator const& _rval)
				: _M_ptr(_rval)
                {}

				~NormalIterator()
                {}

				_Iterator&
				base() const {
						return (_M_ptr);
				}

// Foward iterator requirements


				reference
				operator*() {
						return (*_M_ptr);
				}

				pointer
				operator->() {
						return (_M_ptr);
				}

				NormalIterator&
				operator++() {
						_M_ptr = _M_ptr + 1;
						return (*this);
				}

				NormalIterator
				operator++(int post) {
						NormalIterator tmp = *this;
						++_M_ptr;
						return (tmp);
				}

// Bidirectional iterator requirements

				NormalIterator&
				operator--() {
						_M_ptr = _M_ptr - 1;
						return (*this);
				}

				NormalIterator
				operator--(int post) {
						NormalIterator tmp = this;
						--_M_ptr;
						return (tmp);
				}

// Random Access iterator requirements
				// Arithmetic operators//
				NormalIterator
				operator+(difference_type _n) {
						return (NormalIterator(_M_ptr + _n));
				}

				NormalIterator
				operator-(difference_type _n) {
						return (NormalIterator(_M_ptr - _n));
				}

                NormalIterator
                operator+=(difference_type _n) {
                        this->_M_ptr += _n;
                        return (*this);
                }

                NormalIterator
                operator+=(difference_type _n) {
                        this->_M_ptr -= _n;
                        return (*this);
                }

/*
				// Comparaison operators//
				bool
				operator<(reference rval) const {
						return (_M_ptr < rval._M_current() ? true : false);
				}

				bool
				operator<=(reference rval) const {
						return ((_M_ptr < rval._M_current() || _M_ptr == rval._M_current()) ?
																true :
																false);
				}

				bool
				operator>(reference rval) const {
						return (_M_ptr > rval._M_current() ? true : false);
				}

				bool
				operator>=(reference rval) const {
						return ((_M_ptr > rval._M_current() || _M_ptr == rval)._M_current() ?
																true :
																false);
				}

                bool
				operator==(NormalIterator rval) const {
						return (_M_ptr == rval._M_current() ? true : false);
				}

				bool
				operator!=(NormalIterator rval) const {
						return (! (_M_ptr == rval._M_current()));
				}
				// Compound assignment operators//
				// a += n
				// a -= n*/

				// Offset difference operator//
				reference
				operator[](difference_type index) {
						return (*(_M_ptr + index));
				}
		};
};