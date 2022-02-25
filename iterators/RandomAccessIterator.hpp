#pragma once
#include "BidirectionalIterator.hpp"

template <typename T>
class RandomAccessIterator :    public BidirectionalIterator<T>,
                                public VectorIterator<ft::random_access_iterator_tag, T>
{

    public:

    RandomAccessIterator()
    : _M_ptr(0)
    {}

    RandomAccessIterator(RandomAccessIterator const & _rval)
    : _M_ptr(_rval._M_current())
    {}

    ~RandomAccessIterator() {}

    RandomAccessIterator const & =operator(const RandomAccessIterator & _rval) {
        this->_M_ptr = _rval._M_current();
        return (*this);
    }

    //Arithmetic operators//
//a + n
    pointer
    operator+(difference_type _n) {
        return (_M_ptr + _n);
    }
//n + a

//a - n
    pointer
    operator-(int _n) {
        return (_M_ptr - _n);
    }
//a - b
    //Comparaison operators//
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
    //Compound assignment operators//
//a += n
//a -= n
    //Offset difference operator//
    reference
    operator[](int index) {
        return (*(_M_ptr + index));
    }
    private:
		pointer _M_ptr;

};