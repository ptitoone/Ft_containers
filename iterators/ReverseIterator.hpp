#pragma once

#include "Iterator.hpp"
#include "NormalIterator.hpp"
#include "IteratorTraits.hpp"

namespace ft {

		template <class _Iterator, class _Container>
		class ReverseIterator : public NormalIterator<_Iterator, _Container> {

		public:
				typedef typename ft::iterator_traits<_Iterator>::difference_type difference_type;
				typedef typename ft::iterator_traits<_Iterator>::value_type value_type;
				typedef typename ft::iterator_traits<_Iterator>::pointer pointer;
				typedef typename ft::iterator_traits<_Iterator>::reference reference;
				typedef typename ft::iterator_traits<_Iterator>::iterator_category iterator_category;
				typedef	NormalIterator<_Iterator, _Container> NormalIterator;

                ReverseIterator()
                : NormalIterator()
                {}

				ReverseIterator(_Iterator const& _copy)
				: NormalIterator(_copy)
                {}

				~ReverseIterator()
                {}

				ReverseIterator&
				operator++() {
						NormalIterator::_M_ptr = NormalIterator::_M_ptr - 1;
						return (*this);
				}

				ReverseIterator
				operator++(int post) {
						ReverseIterator tmp = *this;
						--NormalIterator::_M_ptr;
						return (tmp);
				}

				ReverseIterator&
				operator--() {
						NormalIterator::_M_ptr = NormalIterator::_M_ptr + 1;
						return (*this);
				}

				ReverseIterator
				operator--(int post) {
						ReverseIterator tmp = this;
						++NormalIterator::_M_ptr;
						return (tmp);
				}
		};

		template <typename _IterL, typename _IterR, typename _Container >
		bool
		operator==( const ReverseIterator<_IterL, _Container> &_lhs,
					const ReverseIterator<_IterR, _Container> &_rhs ) {
			return (_lhs.base() == _rhs.base());
		}

		template <typename _Iter, typename _Container >
		bool
		operator==( const ReverseIterator<_Iter, _Container> &_lhs,
					const ReverseIterator<_Iter, _Container> &_rhs ) {
			return (_lhs.base() == _rhs.base());
		}

		template <typename _IterL, typename _IterR, typename _Container >
		bool
		operator!=( const ReverseIterator<_IterL, _Container> &_lhs,
					const ReverseIterator<_IterR, _Container> &_rhs ) {
			return (_lhs.base() != _rhs.base());
		}

		template <typename _Iter, typename _Container>
		bool
		operator!=( const ReverseIterator<_Iter, _Container> &_lhs,
					const ReverseIterator<_Iter, _Container> &_rhs ) {
			return (_lhs.base() != _rhs.base());
		}

		template <typename _IterL, typename _IterR, typename _Container >
		bool
		operator<( const ReverseIterator<_IterL, _Container> &_lhs,
					const ReverseIterator<_IterR, _Container> &_rhs ) {
			return (_lhs.base() != _rhs.base());
		}

		template <typename _Iter, typename _Container >
		bool
		operator<(	const ReverseIterator<_Iter, _Container> &_lhs,
					const ReverseIterator<_Iter, _Container> &_rhs ) {
			return (_lhs.base() != _rhs.base());
		}

		template <typename _IterL, typename _IterR, typename _Container >
		bool
		operator<=( const ReverseIterator<_IterL, _Container> &_lhs,
					const ReverseIterator<_IterR, _Container> &_rhs ) {
			return (_lhs.base() != _rhs.base());
		}

		template <typename _Iter, typename _Container >
		bool
		operator<=( const ReverseIterator<_Iter, _Container> &_lhs,
					const ReverseIterator<_Iter, _Container> &_rhs ) {
			return (_lhs.base() != _rhs.base());
		}

		template <typename _IterL, typename _IterR, typename _Container >
		bool
		operator>( const ReverseIterator<_IterL, _Container> &_lhs,
					const ReverseIterator<_IterR, _Container> &_rhs ) {
			return (_lhs.base() != _rhs.base());
		}

		template <typename _Iter, typename _Container >
		bool
		operator>( const ReverseIterator<_Iter, _Container> &_lhs,
					const ReverseIterator<_Iter, _Container> &_rhs ) {
			return (_lhs.base() != _rhs.base());
		}

		template <typename _IterL, typename _IterR, typename _Container >
		bool
		operator>=( const ReverseIterator<_IterL, _Container> &_lhs,
					const ReverseIterator<_IterR, _Container> &_rhs ) {
			return (_lhs.base() != _rhs.base());
		}

		template <typename _Iter, typename _Container >
		bool
		operator>=( const ReverseIterator<_Iter, _Container> &_lhs,
					const ReverseIterator<_Iter, _Container> &_rhs ) {
			return (_lhs.base() != _rhs.base());
		}

		template <typename _IterL, typename _IterR, typename _Container >
		typename ReverseIterator<_IterL, _Container>::diffrence_type
		operator-( const ReverseIterator<_IterL, _Container> &_lhs,
					const ReverseIterator<_IterR, _Container> &_rhs ) {
			return (_lhs.base() - _rhs.base());
		}

		template <typename _Iter, typename _Container >
		typename ReverseIterator<_Iter, _Container>::diffrence_type
		operator-( const ReverseIterator<_Iter, _Container> &_lhs,
					const ReverseIterator<_Iter, _Container> &_rhs ) {
			return (_lhs.base() - _rhs.base());
		}

		template <typename _Iter, typename _Container >
		ReverseIterator<_Iter, _Container>
		operator+(  const ReverseIterator<_Iter, _Container> &_lhs,
					const typename ReverseIterator<_Iter, _Container>::difference_type &_rhs ) {
			return (ReverseIterator<_Iter, _Container>(_lhs.base() + _rhs));
		}
};