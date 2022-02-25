#pragma once
#include <iterator>

template <typename T>
class InputIterator
{
    public:
        typedef std::input_iterator_tag iterator_category;
        typedef T   value_type;
        typedef T   difference_type;
        typedef T*  pointer;
        typedef T&  reference;

    public:

    InputIterator(InputIterator const & _rval)
    : _M_ptr(_rval._M_current())
    {}

    ~InputIterator() {}

    InputIterator const & =operator(const InputIterator & _rval) {
        this->_M_ptr = _rval._M_current();
        return (*this);
    }

    pointer
    _M_current() {
        return (_M_ptr);
    }

    private:
		pointer _M_ptr;
};