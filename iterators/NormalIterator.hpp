#pragma once

#include "Iterator.hpp"
#include "IteratorTraits.hpp"

namespace ft {
		template <class _Iterator>
		class NormalIterator : public ft::iterator {
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
				: _M_ptr(_Iterator) {}

				NormalIterator(_Iterator const& _rval)
				: _M_ptr(_rval) {}

				~NormalIterator() {}

// Foward iterator requirements
				bool
				operator==(NormalIterator rval) const {
						return (_M_ptr == rval._M_current() ? true : false);
				}

				bool
				operator!=(NormalIterator rval) const {
						return (! (_M_ptr == rval._M_current()));
				}

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

				pointer
				_M_current() const {
						return (_M_ptr);
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
				// a + n
				pointer
				operator+(NormalIterator& _n) {
						return (_M_ptr + _n._M_current());
				}

				pointer
				operator+(int _n) {
						return (_M_ptr + _n);
				}
				// n + a

				// a - n
				pointer
				operator-(int _n) {
						return (_M_ptr - _n);
				}

				pointer
				operator-(NormalIterator& _n) {
						return (_M_ptr - _n._M_current());
				}
				// a - b
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
				// Compound assignment operators//
				// a += n
				// a -= n
				// Offset difference operator//
				reference
				operator[](int index) {
						return (*(_M_ptr + index));
				}
		};
};