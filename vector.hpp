/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:53:28 by akotzky           #+#    #+#             */
/*   Updated: 2022/02/21 22:34:59 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "VectorIterator.hpp"
#include "VectorException.hpp"
#include "VectorConstIterator.hpp"
#include "VectorReverseIterator.hpp"
#include "VectorConstReverseIterator.hpp"
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
			typedef VectorReverseIterator<T> reverse_iterator;
			typedef VectorConstReverseIterator<T> const_reverse_iterator;
			typedef ptrdiff_t difference_type;
			typedef size_t size_type;

			allocator_type _M_alloc_intr;
			value_type* _M_start;
			value_type* _M_finish;
			value_type* _M_end_of_storage;


		public:

			vector(void) {}

			explicit vector(const Allocator& _alloc) :
			_M_alloc_intr(_alloc) {}

			explicit vector(size_type _count,
							const T& _value,
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
			vector&
			operator=(const vector& _rval) {
				pointer _tmp;
				if (_M_start)
				{
					_tmp = _M_allocate(_rval.size());
				}
				this->swap(_rval);	
				return (*this);
			}
//
//			void			assign(size_type count, T const& value);
//			template <class InputIt>
//			void			assign(InputIt first, InputIt last);

			/**
			 *  Returns a copy of the internal allocator of %vector.
			 */
			allocator_type
			get_allocator() const {
				return (_M_alloc_intr);
			}

			/**
			 *  Checks if _pos is in range and returns a reference at 
			 * 	element at _pos in %vector.
			 */
			reference
			at(size_type _pos) {
				if (_pos < size())
					return (_M_start[_pos]);
			}

			/**
			 *  Checks if _pos is in range and returns a const reference
			 *  at element at _pos in %vector.
			 */
			const_reference
			at(size_type _pos) const {
				if (_pos < size())
					return (_M_start[_pos]);
			}
			/**
			 *  Returns a reference to the object at element _pos.
			 *  Does not check if _pos is in range.
			 */
			reference
			operator[](size_type _pos) {
				return (_M_start + _pos);
			}

			/**
			 *  Returns a const reference to the object at element _pos.
			 *  Does not check if _pos is in range.
			 */
			const_reference
			operator[](size_type _pos) const {
				return (_M_start + _pos);
			}
			
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
			reverse_iterator
			rbegin() {
				return (reverse_iterator(this->_M_finish - 1));
			}

			/**
			 *	Returns a read iterator that points to the last element
			 *	of %vector. Iteration is done in reverse order.
			 */
			const_reverse_iterator
			rbegin() const {
				return (const_reverse_iterator(this->_M_finish - 1));
			}

			/**
			 *	Returns a read/ iterator that points to the last element
			 *	of %vector. Iteration is done foward order.
			 */
			reverse_iterator
			rend() {
				return (reverse_iterator(this->_M_start - 1));
			}

			/**
			 *	Returns a read/ iterator that points to the last element
			 *	of %vector. Iteration is done foward order.
			 */
			const_reverse_iterator
			rend() const {
				return (const_reverse_iterator(this->_M_start - 1));
			}

			/**
			 *  Returns a read/write referece to the first element of %vector.
			 */
			reference
			front() {
				return (*_M_start);
			}

			/**
			 *  Returns a read referece to the first element of %vector.
			 */
			const_reference
			front() const {
				return (*_M_start);
			}

			/**
			 *  Returns a read/write referece to the last element of %vector.
			 */
			reference
			back() {
				return (*_M_finish);
			}

			/**
			 *  Returns a read referece to the last element of %vector.
			 */
			const_reference
			back() const {
				return (*_M_finish);
			}

			/**
			 *  Returns a read/write direct pointer to the internal storage array.
			 */
			pointer
			data() {
				return (_M_start);
			}

			/**
			 *  Returns a read direct pointer to the internal storage array.
			 */
			const_pointer
			data() const {
				return (_M_start);
			}

			/**
			 *  Evaluates to true if %vector has no elements.
			 */
			bool
			empty(void) const {
				return (this->_M_finish == this->_M_start ? true : false);
			}

			/**
			 *  Returns the number of elements stored in %vector.
			 */
			size_type
			size() const {
				return (_M_finish - _M_start);
			}

			/**
			 *  Returns the maximum storage capacity in %vector.
			 */
			size_type
			max_size() const {
				return (_M_end_of_storage - _M_start);
			}

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
			void			swap(vector& other) {
				swap(this->_M_start, other._M_start);
				swap(this->_M_finish, other._M_finish);
				swap(this->_M_end_of_storage, other._M_end_of_storage);
			}
//
		private:

		size_type _M_check_len(size_type _size) {
			if (_M_alloc_intr.max_size() - size() < _size)
				throw(VectorException::OutOfMemoryException());
			size_type _len = size() + std::max(max_size(), _size);
			return ((_len < size() || _len < max_size()) ? max_size() : _len);
		}

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