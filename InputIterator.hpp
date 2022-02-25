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

    InputIterator(InputIterator const & _rval)
    : _M_ptr(_rval._M_current())
    {}

    ~InputIterator() {}

    InputIterator const & =operator(const InputIterator & _rval) {
        this->_M_ptr = _rval._M_current();
        return (*this);
    }

    bool
    operator==(InputIterator<T> rval) const {
        return (_M_ptr == rval._M_current() ? true : false);
    }

    bool
    operator!=(InputIterator<T> rval) const {
        return (!(_M_ptr == rval._M_current()));
    }

    reference
    operator*() {
        return (*_M_ptr);
    }

    pointer
    operator->() {
        return(_M_ptr);
    }

    VectorIterator&
    operator++() {
        _M_ptr = _M_ptr + 1;
        return (*this);
    }

    VectorIterator
    operator++(int post) {
        VectorIterator tmp = *this;
        ++_M_ptr;
        return (tmp);
    }

    pointer
    _M_current() {
        return (_M_ptr);
    }

    private:
		pointer _M_ptr;
};