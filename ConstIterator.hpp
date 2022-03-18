#pragma once

#include "Iterator.hpp"
#include "IteratorTraits.hpp"

namespace ft {

		template <class _Iterator, class _Container>
		class ConstIterator {
		private:
				_Iterator _M_ptr;

		public:
				typedef typename ft::iterator_traits<_Iterator>::difference_type difference_type;
				typedef typename ft::iterator_traits<_Iterator>::value_type value_type;
				typedef typename ft::iterator_traits<_Iterator>::pointer pointer;
				typedef typename ft::iterator_traits<_Iterator>::reference reference;
				typedef typename ft::iterator_traits<_Iterator>::iterator_category iterator_category;

                ConstIterator()
                : _M_ptr(_Iterator())
                {}

				ConstIterator(_Iterator const& _copy)
				: _M_ptr(_copy)
                {}

                ConstIterator const & operator=(ConstIterator const & _rhs) {
                    _M_ptr = _rhs.base();
                    return (*this);
                }

				~ConstIterator()
                {}

				const _Iterator&
				base() const {
						return (_M_ptr);
				}
				
// Foward iterator requirements
				reference
				operator*() const {
						return (*_M_ptr);
				}

				pointer
				operator->() const {
						return (_M_ptr);
				}

				ConstIterator&
				operator++() {
						_M_ptr = _M_ptr + 1;
						return (*this);
				}

				ConstIterator
				operator++(int ) {
						ConstIterator tmp = *this;
						++_M_ptr;
						return (tmp);
				}

// Bidirectional iterator requirements
				ConstIterator&
				operator--() {
						_M_ptr = _M_ptr - 1;
						return (*this);
				}

				ConstIterator
				operator--(int ) {
						ConstIterator tmp = *this;
						--_M_ptr;
						return (tmp);
				}
// Random Access iterator requirements
				// Arithmetic operators//
				ConstIterator
				operator+(difference_type _n) const {
						return (ConstIterator(_M_ptr + _n));
				}

				ConstIterator
				operator-(difference_type _n) const {
						return (ConstIterator(_M_ptr - _n));
				}

				difference_type
				operator-(ConstIterator &_n) const {
						return (_M_ptr - _n.base());
				}

				// Offset difference operator//
				reference
				operator[](difference_type _index) const {
						return (*(_M_ptr + _index));
				}
		};

		template <typename _IterL, typename _IterR, typename _Container >
		bool
		operator==( const ConstIterator<_IterL, _Container> &_lhs,
					const ConstIterator<_IterR, _Container> &_rhs ) {
			return (_lhs.base() == _rhs.base());
		}

		template <typename _Iter, typename _Container >
		bool
		operator==( const ConstIterator<_Iter, _Container> &_lhs,
					const ConstIterator<_Iter, _Container> &_rhs ) {
			return (_lhs.base() == _rhs.base());
		}

		template <typename _IterL, typename _IterR, typename _Container >
		bool
		operator!=( const ConstIterator<_IterL, _Container> &_lhs,
					const ConstIterator<_IterR, _Container> &_rhs ) {
			return (_lhs.base() != _rhs.base());
		}

		template <typename _Iter, typename _Container>
		bool
		operator!=( const ConstIterator<_Iter, _Container> &_lhs,
					const ConstIterator<_Iter, _Container> &_rhs ) {
			return (_lhs.base() != _rhs.base());
		}

		template <typename _IterL, typename _IterR, typename _Container >
		bool
		operator<( const ConstIterator<_IterL, _Container> &_lhs,
					const ConstIterator<_IterR, _Container> &_rhs ) {
			return (_lhs.base() != _rhs.base());
		}

		template <typename _Iter, typename _Container >
		bool
		operator<(	const ConstIterator<_Iter, _Container> &_lhs,
					const ConstIterator<_Iter, _Container> &_rhs ) {
			return (_lhs.base() != _rhs.base());
		}

		template <typename _IterL, typename _IterR, typename _Container >
		bool
		operator<=( const ConstIterator<_IterL, _Container> &_lhs,
					const ConstIterator<_IterR, _Container> &_rhs ) {
			return (_lhs.base() != _rhs.base());
		}

		template <typename _Iter, typename _Container >
		bool
		operator<=( const ConstIterator<_Iter, _Container> &_lhs,
					const ConstIterator<_Iter, _Container> &_rhs ) {
			return (_lhs.base() != _rhs.base());
		}

		template <typename _IterL, typename _IterR, typename _Container >
		bool
		operator>( const ConstIterator<_IterL, _Container> &_lhs,
					const ConstIterator<_IterR, _Container> &_rhs ) {
			return (_lhs.base() != _rhs.base());
		}

		template <typename _Iter, typename _Container >
		bool
		operator>( const ConstIterator<_Iter, _Container> &_lhs,
					const ConstIterator<_Iter, _Container> &_rhs ) {
			return (_lhs.base() != _rhs.base());
		}

		template <typename _IterL, typename _IterR, typename _Container >
		bool
		operator>=( const ConstIterator<_IterL, _Container> &_lhs,
					const ConstIterator<_IterR, _Container> &_rhs ) {
			return (_lhs.base() != _rhs.base());
		}

		template <typename _Iter, typename _Container >
		bool
		operator>=( const ConstIterator<_Iter, _Container> &_lhs,
					const ConstIterator<_Iter, _Container> &_rhs ) {
			return (_lhs.base() != _rhs.base());
		}

		template <typename _IterL, typename _IterR, typename _Container >
		typename ConstIterator<_IterL, _Container>::diffrence_type
		operator-( const ConstIterator<_IterL, _Container> &_lhs,
					const ConstIterator<_IterR, _Container> &_rhs ) {
			return (_lhs.base() - _rhs.base());
		}

		template <typename _Iter, typename _Container >
		typename ConstIterator<_Iter, _Container>::diffrence_type
		operator-( const ConstIterator<_Iter, _Container> &_lhs,
					const ConstIterator<_Iter, _Container> &_rhs ) {
			return (_lhs.base() - _rhs.base());
		}

		template <typename _Iter, typename _Container >
		ConstIterator<_Iter, _Container>
		operator+(  const ConstIterator<_Iter, _Container> &_lhs,
					const typename ConstIterator<_Iter, _Container>::difference_type &_rhs ) {
			return (ConstIterator<_Iter, _Container>(_lhs.base() + _rhs));
		}
};