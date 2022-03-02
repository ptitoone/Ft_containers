#pragma once
#include "FowardIterator.hpp"
#include "VectorIterator.hpp"

template <typename T>
class BidirectionalIterator : public FowardIterator<T> {
public:
		typedef typename FowardIterator<T>::difference_type difference_type;
		typedef typename FowardIterator<T>::value_type value_type;
		typedef typename FowardIterator<T>::pointer pointer;
		typedef typename FowardIterator<T>::reference reference;

		BidirectionalIterator()
		: _M_ptr(0) {}

		BidirectionalIterator(BidirectionalIterator const& _rval)
		: _M_ptr(_rval._M_current()) {}

		~BidirectionalIterator() {}

		BidirectionalIterator const&
		operator=(const BidirectionalIterator& _rval) {
				this->_M_ptr = _rval._M_current();
				return (*this);
		}

		BidirectionalIterator&
		operator--() {
				_M_ptr = _M_ptr - 1;
				return (*this);
		}

		BidirectionalIterator
		operator--(int post) {
				BidirectionalIterator tmp = this;
				--_M_ptr;
				return (tmp);
		}

private:
		pointer _M_ptr;
};