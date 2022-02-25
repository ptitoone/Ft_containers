#pragma once
#include <iterator>
#include "InputIterator.hpp"

template <typename T>
class FowardIterator : public InputIterator
{
    public:
        typedef std::foward_iterator_tag iterator_category;
        typedef T   value_type;
        typedef T   difference_type;
        typedef T*  pointer;
        typedef T&  reference;

    FowardIterator()
    : _M_ptr(0)
    {}

    FowardIterator(FowardIterator const & _rval)
    : _M_ptr(_rval._M_current())
    {}

    ~FowardIterator() {}

    FowardIterator const & =operator(const FowardIterator & _rval) {
        this->_M_ptr = _rval._M_current();
        return (*this);
    }

    private:
		pointer _M_ptr;

};
