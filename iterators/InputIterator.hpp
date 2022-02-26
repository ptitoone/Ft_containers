#pragma once
#include "VectorIterator.hpp"

template <typename T>
class InputIterator : public VectorIterator<ft::input_iterator_tag, T>
{
    public:

        InputIterator(InputIterator const & _rval)
        : _M_ptr(_rval._M_current())
        {}

        ~InputIterator() {}

        InputIterator const &
        operator=(const InputIterator & _rval) {
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
//ne pas oublier typename !!! 
        typename reference
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