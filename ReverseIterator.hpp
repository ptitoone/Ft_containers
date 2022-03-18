#pragma once

#include "Iterator.hpp"
#include "NormalIterator.hpp"
#include "IteratorTraits.hpp"

namespace ft {

		template <class _Iterator, class _Container>
		class ReverseIterator {

        private:
				_Iterator _M_ptr;


		public:
				typedef typename ft::iterator_traits<_Iterator>::difference_type difference_type;
				typedef typename ft::iterator_traits<_Iterator>::value_type value_type;
				typedef typename ft::iterator_traits<_Iterator>::pointer pointer;
				typedef typename ft::iterator_traits<_Iterator>::reference reference;
				typedef typename ft::iterator_traits<_Iterator>::iterator_category iterator_category;

                ReverseIterator()
                : _M_ptr(_Iterator())
                {}

				ReverseIterator(_Iterator const& _copy)
				: _M_ptr(_copy)
                {}

                ReverseIterator&  operator=(ReverseIterator const & _rhs) {
                    _M_ptr = _rhs.base();
                    return (*this);
                }

				~ReverseIterator()
                {}
                
				const _Iterator&
				base() const {
					return (_M_ptr);
				}

				reference
				operator*() const {
					return (*_M_ptr);
				}

				pointer
				operator->() const {
					return (_M_ptr);
				}

				ReverseIterator&
				operator++() {
					_M_ptr = _M_ptr - 1;
					return (*this);
				}

				ReverseIterator
				operator++(int ) {
					ReverseIterator tmp = *this;
					--_M_ptr;
					return (tmp);
				}

				ReverseIterator&
				operator--() {
					_M_ptr = _M_ptr + 1;
					return (*this);
				}

				ReverseIterator
				operator--(int ) {
					ReverseIterator tmp = *this;
					_M_ptr = _M_ptr + 1;
					return (tmp);
				}

				ReverseIterator
				operator+(difference_type _n) const {
					return (ReverseIterator(_M_ptr - _n));
				}

				ReverseIterator
				operator-(difference_type _n) const {
					return (ReverseIterator(_M_ptr + _n));
				}

				difference_type
				operator-(ReverseIterator &_n) const {
					return (_M_ptr + _n.base());
				}

                ReverseIterator
                operator+=(difference_type _n) {
                    _M_ptr -= _n;
                    return (*this);
                }

                ReverseIterator
                operator-=(difference_type _n) {
                    _M_ptr += _n;
                    return (*this);
                }

				reference
				operator[](difference_type _index) const {
					return (*(_M_ptr - _index));
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
			return (_lhs.base() + _rhs.base());
		}

		template <typename _Iter, typename _Container >
		typename ReverseIterator<_Iter, _Container>::diffrence_type
		operator-( const ReverseIterator<_Iter, _Container> &_lhs,
					const ReverseIterator<_Iter, _Container> &_rhs ) {
			return (_lhs.base() + _rhs.base());
		}

		template <typename _Iter, typename _Container >
		ReverseIterator<_Iter, _Container>
		operator+(  const ReverseIterator<_Iter, _Container> &_lhs,
					const typename ReverseIterator<_Iter, _Container>::difference_type &_rhs ) {
			return (ReverseIterator<_Iter, _Container>(_lhs.base() - _rhs));
		}
};