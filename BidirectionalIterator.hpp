#pragma once
#include "FowardIterator.hpp"

template <typename T>
class BidirectionalIterator : public FowardIterator
{
    public:
        typedef std::bidirectional_iterator_tag iterator_category;
        typedef T   value_type;
        typedef T   difference_type;
        typedef T*  pointer;
        typedef T&  reference;

    BidirectionalIterator()
    : _M_ptr(0)
    {}

    BidirectionalIterator(BidirectionalIterator const & _rval)
    : _M_ptr(_rval._M_current())
    {}

    ~BidirectionalIterator() {}

    BidirectionalIterator const & =operator(const BidirectionalIterator & _rval) {
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