#pragma once
#include "InputIterator.hpp"
#include "VectorIterator.hpp"

template <typename T>
class FowardIterator :  public InputIterator<T>,
                        public VectorIterator<ft::foward_iterator_tag, T>
{
    public:

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
