#pragma once
#include "BidirectionalIterator.hpp"
#include "IteratorTraits.hpp"

template <typename T>
class RandomAccessIterator : public BidirectionalIterator<T> {
public:
		typedef typename BidirectionalIterator<T>::difference_type difference_type;
		typedef typename BidirectionalIterator<T>::value_type value_type;
		typedef typename BidirectionalIterator<T>::pointer pointer;
		typedef typename BidirectionalIterator<T>::reference reference;

		RandomAccessIterator()
		: _M_ptr(0) {}

		RandomAccessIterator(RandomAccessIterator const& _rval)
		: _M_ptr(_rval._M_current()) {}

		~RandomAccessIterator() {}

		RandomAccessIterator const&
		operator=(const RandomAccessIterator& _rval) {
				this->_M_ptr = _rval._M_current();
				return (*this);
		}

		// Arithmetic operators//
		// a + n
		pointer
		operator+(difference_type _n) {
				return (_M_ptr + _n);
		}
		// n + a

		// a - n
		pointer
		operator-(int _n) {
				return (_M_ptr - _n);
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

private:
		pointer _M_ptr;
};