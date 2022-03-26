#pragma once

#include "NormalIterator.hpp"
#include "IteratorTraits.hpp"

namespace ft {

		template <class _Iterator>
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
                : _M_ptr()
                {}

				ReverseIterator(_Iterator _copy)
				: _M_ptr(_copy)
                {}

                template <typename Iter>
                ReverseIterator(ReverseIterator<Iter> const & it)
                : _M_ptr( it.base() ) {}

                ReverseIterator(ReverseIterator const & it)
                : _M_ptr( it.base() ) {}

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
					return (*(_M_ptr - 1));
				}

				pointer
				operator->() const {
					return (&(operator*()));
				}

				ReverseIterator&
				operator++() {
                    --_M_ptr;
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
					++_M_ptr;
					return (*this);
				}

				ReverseIterator
				operator--(int ) {
					ReverseIterator tmp = *this;
					++_M_ptr;
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
					return (_M_ptr[-_index - 1]);
				}
		};

		template <typename _IterL, typename _IterR>
		bool
		operator==( const ReverseIterator<_IterL> &_lhs,
					const ReverseIterator<_IterR> &_rhs ) {
			return (_lhs.base() == _rhs.base());
		}

		template <typename _Iter>
		bool
		operator==( const ReverseIterator<_Iter> &_lhs,
					const ReverseIterator<_Iter> &_rhs ) {
			return (_lhs.base() == _rhs.base());
		}

		template <typename _IterL, typename _IterR>
		bool
		operator!=( const ReverseIterator<_IterL> &_lhs,
					const ReverseIterator<_IterR> &_rhs ) {
			return (_lhs.base() != _rhs.base());
		}

		template <typename _Iter>
		bool
		operator!=( const ReverseIterator<_Iter> &_lhs,
					const ReverseIterator<_Iter> &_rhs ) {
			return (_lhs.base() != _rhs.base());
		}

		template <typename _IterL, typename _IterR>
		bool
		operator<( const ReverseIterator<_IterL> &_lhs,
					const ReverseIterator<_IterR> &_rhs ) {
			return (_lhs.base() > _rhs.base());
		}

		template <typename _Iter>
		bool
		operator<(	const ReverseIterator<_Iter> &_lhs,
					const ReverseIterator<_Iter> &_rhs ) {
			return (_lhs.base() > _rhs.base());
		}

		template <typename _IterL, typename _IterR>
		bool
		operator<=( const ReverseIterator<_IterL> &_lhs,
					const ReverseIterator<_IterR> &_rhs ) {
			return (_lhs.base() >= _rhs.base());
		}

		template <typename _Iter>
		bool
		operator<=( const ReverseIterator<_Iter> &_lhs,
					const ReverseIterator<_Iter> &_rhs ) {
			return (_lhs.base() >= _rhs.base());
		}

		template <typename _IterL, typename _IterR>
		bool
		operator>( const ReverseIterator<_IterL> &_lhs,
					const ReverseIterator<_IterR> &_rhs ) {
			return (_lhs.base() < _rhs.base());
		}

		template <typename _Iter>
		bool
		operator>( const ReverseIterator<_Iter> &_lhs,
					const ReverseIterator<_Iter> &_rhs ) {
			return (_lhs.base() < _rhs.base());
		}

		template <typename _IterL, typename _IterR>
		bool
		operator>=( const ReverseIterator<_IterL> &_lhs,
					const ReverseIterator<_IterR> &_rhs ) {
			return (_lhs.base() <= _rhs.base());
		}

		template <typename _Iter>
		bool
		operator>=( const ReverseIterator<_Iter> &_lhs,
					const ReverseIterator<_Iter> &_rhs ) {
			return (_lhs.base() <= _rhs.base());
		}

		template <typename _IterL, typename _IterR>
		typename ReverseIterator<_IterL>::difference_type
		operator-(  const ReverseIterator<_IterL> &_lhs,
					const ReverseIterator<_IterR> &_rhs ) {
			return (_rhs.base() - _lhs.base());
		}

		template <typename _Iter>
		typename ReverseIterator<_Iter>::difference_type
		operator-(  const ReverseIterator<_Iter> &_lhs,
				    const ReverseIterator<_Iter> &_rhs ) {
			return (_rhs.base() - _lhs.base());
		}

		template <typename _Iter>
		ReverseIterator<_Iter>
		operator+(  const typename ReverseIterator<_Iter>::difference_type &_lhs,
					const ReverseIterator<_Iter> &_rhs ) {
			return (ReverseIterator<_Iter>(_rhs.base() - _lhs));
		}
};