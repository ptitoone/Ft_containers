#pragma once

#include "Iterator.hpp"
#include "IteratorTraits.hpp"

namespace ft {
        using ft::iterator;
        using ft::iterator_traits;
		template <class _Iterator, class _Container>
		class NormalIterator {
		protected:
				_Iterator _M_ptr;
				typedef typename ft::iterator_traits<_Iterator> _traits;

		public:
				typedef typename _traits::difference_type difference_type;
				typedef typename _traits::value_type value_type;
				typedef typename _traits::pointer pointer;
				typedef typename _traits::reference reference;
				typedef typename _traits::iterator_category iterator_category;

                NormalIterator()
                : _M_ptr(_Iterator())
                {}

				NormalIterator(_Iterator const& _rval)
				: _M_ptr(_rval)
                {}

				~NormalIterator()
                {}

				_Iterator&
				base() {
						return (_M_ptr);
				}

// Foward iterator requirements


				reference
				operator*() {
						return (*_M_ptr);
				}

				pointer
				operator->() {
						return (_M_ptr);
				}

				NormalIterator&
				operator++() {
						_M_ptr = _M_ptr + 1;
						return (*this);
				}

				NormalIterator
				operator++(int post) {
						NormalIterator tmp = *this;
						++_M_ptr;
						return (tmp);
				}

// Bidirectional iterator requirements

				NormalIterator&
				operator--() {
						_M_ptr = _M_ptr - 1;
						return (*this);
				}

				NormalIterator
				operator--(int post) {
						NormalIterator tmp = this;
						--_M_ptr;
						return (tmp);
				}

// Random Access iterator requirements
				// Arithmetic operators//
				NormalIterator
				operator+(difference_type _n) {
						return (NormalIterator(_M_ptr + _n));
				}

				NormalIterator
				operator-(difference_type _n) {
						return (NormalIterator(_M_ptr - _n));
				}

                NormalIterator
                operator+=(difference_type _n) {
                        this->_M_ptr += _n;
                        return (*this);
                }

                NormalIterator
                operator-=(difference_type _n) {
                        this->_M_ptr -= _n;
                        return (*this);
                }

				// Offset difference operator//
				reference
				operator[](difference_type _index) {
						return (*(_M_ptr + _index));
				}
		};
};

template <typename _IterL, typename _IterR, typename _Container >
bool
operator==( ft::NormalIterator<_IterL, _Container> _lhs,
            ft::NormalIterator<_IterR, _Container> _rhs ) {
    return (_lhs == _rhs);
}

template <typename _Iter, typename _Container >
bool
operator==( ft::NormalIterator<_Iter, _Container> _lhs,
            ft::NormalIterator<_Iter, _Container> _rhs ) {
    return (_lhs == _rhs);
}

template <typename _IterL, typename _IterR, typename _Container >
bool
operator!=( ft::NormalIterator<_IterL, _Container> _lhs,
            ft::NormalIterator<_IterR, _Container> _rhs ) {
    return (_lhs != _rhs);
}

template <typename _Iter, typename _Container >
bool
operator!=( ft::NormalIterator<_Iter, _Container> _lhs,
            ft::NormalIterator<_Iter, _Container> _rhs ) {
    return (_lhs != _rhs);
}

template <typename _IterL, typename _IterR, typename _Container >
bool
operator<( ft::NormalIterator<_IterL, _Container> _lhs,
            ft::NormalIterator<_IterR, _Container> _rhs ) {
    return (_lhs != _rhs);
}

template <typename _Iter, typename _Container >
bool
operator<( ft::NormalIterator<_Iter, _Container> _lhs,
            ft::NormalIterator<_Iter, _Container> _rhs ) {
    return (_lhs != _rhs);
}

template <typename _IterL, typename _IterR, typename _Container >
bool
operator<=( ft::NormalIterator<_IterL, _Container> _lhs,
            ft::NormalIterator<_IterR, _Container> _rhs ) {
    return (_lhs != _rhs);
}

template <typename _Iter, typename _Container >
bool
operator<=( ft::NormalIterator<_Iter, _Container> _lhs,
            ft::NormalIterator<_Iter, _Container> _rhs ) {
    return (_lhs != _rhs);
}

template <typename _IterL, typename _IterR, typename _Container >
bool
operator>( ft::NormalIterator<_IterL, _Container> _lhs,
            ft::NormalIterator<_IterR, _Container> _rhs ) {
    return (_lhs != _rhs);
}

template <typename _Iter, typename _Container >
bool
operator>( ft::NormalIterator<_Iter, _Container> _lhs,
            ft::NormalIterator<_Iter, _Container> _rhs ) {
    return (_lhs != _rhs);
}

template <typename _IterL, typename _IterR, typename _Container >
bool
operator>=( ft::NormalIterator<_IterL, _Container> _lhs,
            ft::NormalIterator<_IterR, _Container> _rhs ) {
    return (_lhs != _rhs);
}

template <typename _Iter, typename _Container >
bool
operator>=( ft::NormalIterator<_Iter, _Container> _lhs,
            ft::NormalIterator<_Iter, _Container> _rhs ) {
    return (_lhs != _rhs);
}

template <typename _IterL, typename _IterR, typename _Container >
typename ft::NormalIterator<_IterL, _Container>::diffrence_type
operator-( ft::NormalIterator<_IterL, _Container> _lhs,
            ft::NormalIterator<_IterR, _Container> _rhs ) {
    return (_lhs.base() - _rhs.base());
}

template <typename _Iter, typename _Container >
typename ft::NormalIterator<_Iter, _Container>::diffrence_type
operator-( ft::NormalIterator<_Iter, _Container> _lhs,
            ft::NormalIterator<_Iter, _Container> _rhs ) {
    return (_lhs.base() - _rhs.base());
}

template <typename _Iter, typename _Container >
typename ft::NormalIterator<_Iter, _Container>
operator+(  ft::NormalIterator<_Iter, _Container> _lhs,
            typename ft::NormalIterator<_Iter, _Container>::difference_type _rhs ) {
    return (ft::NormalIterator<_Iter, _Container>(_lhs.base() + _rhs));
}