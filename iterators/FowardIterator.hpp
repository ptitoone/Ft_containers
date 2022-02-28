#pragma once
#include "InputIterator.hpp"
#include "VectorIterator.hpp"

template <typename T>
class FowardIterator : public InputIterator<T>
{
    public:
        typedef typename InputIterator<T>::difference_type		difference_type;
        typedef typename InputIterator<T>::value_type			value_type;
        typedef typename InputIterator<T>::pointer				pointer;
        typedef typename InputIterator<T>::reference			reference;

    FowardIterator()
    : _M_ptr(0)
    {}

    FowardIterator(FowardIterator const & _rval)
    : _M_ptr(_rval._M_current())
    {}

    ~FowardIterator() {}

    FowardIterator const & operator=(const FowardIterator & _rval) {
        this->_M_ptr = _rval._M_current();
        return (*this);
    }

    private:
		pointer _M_ptr;

};
