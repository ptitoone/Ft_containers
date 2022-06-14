#pragma once

#include "IteratorTraits.hpp"

namespace ft {

		template <class _Iterator, class _Container>
		class NormalIterator {

		private:
				_Iterator _M_ptr;

		public:
				typedef typename ft::iterator_traits<_Iterator>::difference_type	difference_type;
				typedef typename ft::iterator_traits<_Iterator>::value_type			value_type;
				typedef typename ft::iterator_traits<_Iterator>::pointer			pointer;
				typedef typename ft::iterator_traits<_Iterator>::reference			reference;
				typedef typename ft::iterator_traits<_Iterator>::iterator_category	iterator_category;

                NormalIterator()
                : _M_ptr(_Iterator())
                {}

				NormalIterator(const _Iterator& _copy)
				: _M_ptr(_copy)
                {}

                template<typename Iter>
                NormalIterator(const NormalIterator<Iter, _Container>& it)
                : _M_ptr( it.base() )
                {}

                NormalIterator&  operator=(const NormalIterator& _rhs)
				{
                    _M_ptr = _rhs.base();
                    return (*this);
                }

				_Iterator
				base() const
				{
						return (_M_ptr);
				}
				
				reference
				operator*() const
				{
						return (*_M_ptr);
				}

				pointer
				operator->() const
				{
						return (_M_ptr);
				}

				NormalIterator&
				operator++()
				{
						_M_ptr = _M_ptr + 1;
						return (*this);
				}

				NormalIterator
				operator++(int)
				{
						NormalIterator tmp = *this;
						++_M_ptr;
						return (tmp);
				}

				NormalIterator&
				operator--()
				{
						_M_ptr = _M_ptr - 1;
						return (*this);
				}

				NormalIterator
				operator--(int )
				{
						NormalIterator tmp = *this;
						--_M_ptr;
						return (tmp);
				}

				NormalIterator
				operator+(difference_type _n) const
				{
						return (NormalIterator(_M_ptr + _n));
				}

				NormalIterator
				operator-(difference_type _n) const
				{
						return (NormalIterator(_M_ptr - _n));
				}

				difference_type
				operator-(NormalIterator& _n) const
				{
						return (_M_ptr - _n.base());
				}

                NormalIterator
                operator+=(difference_type _n)
				{
                        this->_M_ptr += _n;
                        return (*this);
                }

                NormalIterator
                operator-=(difference_type _n)
				{
                        this->_M_ptr -= _n;
                        return (*this);
                }

				reference
				operator[](difference_type _index) const
				{
						return (*(_M_ptr + _index));
				}
		};

		template <typename _IterL, typename _IterR, typename _Container >
		bool
		operator==( const NormalIterator<_IterL, _Container>& _lhs,
					const NormalIterator<_IterR, _Container>& _rhs )
		{
			return (_lhs.base() == _rhs.base());
		}

		template <typename _Iter, typename _Container >
		bool
		operator==( const NormalIterator<_Iter, _Container>& _lhs,
					const NormalIterator<_Iter, _Container>& _rhs )
		{
			return (_lhs.base() == _rhs.base());
		}

		template <typename _IterL, typename _IterR, typename _Container >
		bool
		operator!=( const NormalIterator<_IterL, _Container>& _lhs,
					const NormalIterator<_IterR, _Container>& _rhs )
		{
			return (_lhs.base() != _rhs.base());
		}

		template <typename _Iter, typename _Container>
		bool
		operator!=( const NormalIterator<_Iter, _Container>& _lhs,
					const NormalIterator<_Iter, _Container>& _rhs )
		{
			return (_lhs.base() != _rhs.base());
		}

		template <typename _IterL, typename _IterR, typename _Container >
		bool
		operator<( const NormalIterator<_IterL, _Container>& _lhs,
					const NormalIterator<_IterR, _Container>& _rhs )
		{
			return (_lhs.base() < _rhs.base());
		}

		template <typename _Iter, typename _Container >
		bool
		operator<(	const NormalIterator<_Iter, _Container>& _lhs,
					const NormalIterator<_Iter, _Container>& _rhs )
		{
			return (_lhs.base() < _rhs.base());
		}

		template <typename _IterL, typename _IterR, typename _Container >
		bool
		operator<=( const NormalIterator<_IterL, _Container>& _lhs,
					const NormalIterator<_IterR, _Container>& _rhs )
		{
			return (_lhs.base() <= _rhs.base());
		}

		template <typename _Iter, typename _Container >
		bool
		operator<=( const NormalIterator<_Iter, _Container>& _lhs,
					const NormalIterator<_Iter, _Container>& _rhs )
		{
			return (_lhs.base() <= _rhs.base());
		}

		template <typename _IterL, typename _IterR, typename _Container >
		bool
		operator>( const NormalIterator<_IterL, _Container>& _lhs,
					const NormalIterator<_IterR, _Container>& _rhs )
		{
			return (_lhs.base() > _rhs.base());
		}

		template <typename _Iter, typename _Container >
		bool
		operator>( const NormalIterator<_Iter, _Container>& _lhs,
					const NormalIterator<_Iter, _Container>& _rhs )
		{
			return (_lhs.base() > _rhs.base());
		}

		template <typename _IterL, typename _IterR, typename _Container >
		bool
		operator>=( const NormalIterator<_IterL, _Container>& _lhs,
					const NormalIterator<_IterR, _Container>& _rhs )
		{
			return (_lhs.base() >= _rhs.base());
		}

		template <typename _Iter, typename _Container >
		bool
		operator>=( const NormalIterator<_Iter, _Container>& _lhs,
					const NormalIterator<_Iter, _Container>& _rhs )
		{
			return (_lhs.base() >= _rhs.base());
		}

		template <typename _IterL, typename _IterR, typename _Container >
		typename NormalIterator<_IterL, _Container>::difference_type
		operator-(  const NormalIterator<_IterL, _Container>& _lhs,
					const NormalIterator<_IterR, _Container>& _rhs )
		{
			return (_lhs.base() - _rhs.base());
		}

		template <typename _Iter, typename _Container >
		typename NormalIterator<_Iter, _Container>::difference_type
		operator-(  const NormalIterator<_Iter, _Container>& _lhs,
				    const NormalIterator<_Iter, _Container>& _rhs )
		{
			return (_lhs.base() - _rhs.base());
		}

		template <typename _Iter, typename _Container >
		NormalIterator<_Iter, _Container>
		operator+(  const typename NormalIterator<_Iter, _Container>::difference_type& _lhs,
					const NormalIterator<_Iter, _Container>& _rhs )
		{
			return (NormalIterator<_Iter, _Container>(_rhs.base() + _lhs));
		}
};
