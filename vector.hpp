/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:53:28 by akotzky           #+#    #+#             */
/*   Updated: 2022/02/12 11:17:36 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#include "vector_const_iterator.hpp"
#include "vector_iterator.hpp"
#include <iostream>
#include <memory>

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{

		public:

			typedef T value_type;
			typedef Allocator allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;

			typedef VectorIterator<T> iterator;
			typedef VectorConstIterator<T> const_iterator;
			typedef ptrdiff_t difference_type;
			typedef size_t size_type;

			allocator_type _M_alloc_intr;
			value_type* _M_start;
			value_type* _M_finish;
			value_type* _M_end_of_storage;


		public:

			vector(void) {}

			explicit vector(Allocator const& _alloc) :
			_M_alloc_intr(_alloc) {}

			explicit vector(size_type _count,
							T const& _value,
							const allocator_type& _alloc = allocator_type())
			: _M_alloc_intr(_alloc),
			_M_start(_M_alloc_intr.allocate(_count)),
			_M_finish(_M_start + _count),
			_M_end_of_storage(_M_start + _count) {
				std::uninitialized_fill_n(begin(), _count, _value);
			}

//							template< class InputIt >
//							vector(	InputIt first, InputIt last,
//									Allocator const& alloc = Allocator());
//							vector(vector const& other);
//
							~vector(void) {}
//
//			vector&			operator=(vector const& other);
//
//			void			assign(size_type count, T const& value);
//			template <class InputIt>
//			void			assign(InputIt first, InputIt last);
//
//			allocator_type	get_allocator(void)	const;
//
//			reference		at(size_type pos);
//			const_reference	at(size_type pos) const;
//
//			reference		operator[](size_type pos);
//			const_reference	operator[](size_type pos) const;
//
			// ITERATORS //
			
			/**
			 *	Returns a read/write iterator that points to the first element
			 *	of %vector. Iteration is done in foward order.
			 */
			iterator
			begin() {
				return iterator(this->_M_start);
			}

			/**
			 *	Returns a read iterator that points to the first element
			 *	of %vector. Iteration is done in foward order.
			 */
			const_iterator
			begin() const {
				return (const_iterator(this->_M_start));
			}
			

			/**
			 *	Returns a read/write iterator that points to the last element
			 *	of %vector. Iteration is done in foward order.
			 */
			iterator
			end() {
				return (iterator(this->_M_finish));
			}

			/**
			 *	Returns a read iterator that points to the last element
			 *	of %vector. Iteration is done in foward order.
			 */
			const_iterator
			end() const {
				return (const_iterator(this->_M_finish));
			}
			
			/**
			 *	Returns a read/write iterator that points to the last element
			 *	of %vector. Iteration is done in reverse order.
			 */
//			reverse_iterator
//			rbegin() {
//				return (reverse_iterator(this->_M_start));
//			}

			/**
			 *	Returns a read/ iterator that points to the last element
			 *	of %vector. Iteration is done foward order.
			 */
//			const_reverse_iterator
//			rbegin() const {
//				return (reverse_const_iterator(this->_M_start));
//			}

//			reverse_iterator
//			rend() {
//				return (reverse_iterator(this->_M_finish));
//			}

//			const_reverse_iterator
//			rend() const {
//				return (reverse_const_iterator(this->_M_finish));
//			}
//			reference		front(void);
//			const_reference	front(void) const;
//
//			reference		back(void);
//			const_reference	back(void) const;
//
//			T*				data(void);
//			T const*		data(void) const;
//
			bool
			empty(void) const {
				return (this->_M_finish == this->_M_start ? true : false);
			}
//			size_type		size(void) const;
//
//			size_type		max_size(void) const;
//
//			void			reserve(size_type new_cap);
//
//			size_type		capacity(void) const;
//
//			void			clear(void);
//
//			iterator		insert(iterator pos, const T& value);
//			void			insert(iterator pos, size_type count, const T& value);
//			template <class InputIt>
//			void			insert(iterator pos, InputIt first, InputIt last);
//
//			iterator		erase(iterator pos);
//			iterator		erase(iterator first, iterator last);
//
//			void			push_back(const T& value);
//
//			void			pop_back(void);
//
//			void			resize(size_type count, T value = T());
//
//			void			swap(vector& other);
//
		private:

	    pointer _M_allocate(size_type _size) {
            return (_M_alloc_intr.allocate(_size));
        }

		void _M_deallocate(pointer _ptr, size_type _size) {
			_M_alloc_intr.deallocate(_ptr, _size);
		}
	
	};
}

/*
template<class T, class Alloc>
bool
operator==(std::vector<T, Alloc> const& lhs, std::vector<T, Alloc> const& rhs);

template<class T, class Alloc>
constexpr bool
operator==(std::vector<T, Alloc> const& lhs, std::vector<T, Alloc> const& rhs);

template<class T, class Alloc>
bool
operator!=(std::vector<T, Alloc> const& lhs, std::vector<T, Alloc> const& rhs);

template<class T, class Alloc>
bool
operator<(std::vector<T, Alloc> const& lhs, std::vector<T, Alloc> const& rhs);

template<class T, class Alloc>
bool
operator<=(std::vector<T, Alloc> const& lhs, std::vector<T, Alloc> const& rhs);

template<class T, class Alloc>
bool
operator>(std::vector<T, Alloc> const& lhs, std::vector<T, Alloc> const& rhs);

template<class T, class Alloc>
bool
operator>=(std::vector<T, Alloc> const& lhs, std::vector<T, Alloc> const& rhs);
*/
