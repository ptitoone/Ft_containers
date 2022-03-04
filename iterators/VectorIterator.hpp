#pragma once

#include "NormalIterator.hpp"

/* debug */ #include <ostream>

namespace ft {

		template <class T>
		class VectorIterator : public NormalIterator<T> {

		public:
            typedef typename ft::NormalIterator<T>::difference_type difference_type;
            typedef typename ft::NormalIterator<T>::value_type value_type;
            typedef typename ft::NormalIterator<T>::pointer pointer;
            typedef typename ft::NormalIterator<T>::reference reference;
            typedef typename ft::NormalIterator<T>::iterator_category iterator_category;

            VectorIterator()
            : NormalIterator<T>()
            {}

            VectorIterator(const VectorIterator & _rval)
            : NormalIterator<T>(_rval._M_current())
            {}

            VectorIterator(const pointer & _rval)
            : NormalIterator<T>(_rval)
            {}

            const VectorIterator & operator=(const VectorIterator & _rval) {
                this->_M_ptr = _rval._M_current();
                return (*this);
            }

            ~VectorIterator()
            {}

            pointer
            operator-(const VectorIterator & _rval) {
                std::cout << "iterator this->_M_ptr address= \t\t" << this->_M_ptr << std::endl;
                std::cout << "iterator _rval._M_current() address= \t" << _rval._M_current() << std::endl;
                pointer ret = this->_M_ptr - *_rval;
                std::cout << "Substraction artihmetic address= \t" << ret << std::endl;
                return (ret);
            }

            pointer
            operator-(const int & _rval) {
                return (this->_M_ptr - _rval);
            }
		};
};