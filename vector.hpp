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


#include "NormalIterator.hpp"
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
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;

			typedef ft::NormalIterator<pointer, vector>   		iterator;
			typedef VectorConstIterator<T>			            const_iterator;
			typedef VectorReverseIterator<T>		            reverse_iterator;
			typedef VectorConstReverseIterator<T>           	const_reverse_iterator;
			typedef ptrdiff_t	            					difference_type;
			typedef size_t				            			size_type;

			allocator_type _M_alloc_intr;
			pointer _M_start;
			pointer _M_finish;
			pointer _M_end_of_storage;

		public:

			explicit vector(const allocator_type& _alloc = allocator_type())
			: _M_alloc_intr(_alloc),
			_M_start(0),
			_M_finish(0),
			_M_end_of_storage(0) {}

			explicit vector(size_type _count,
							const T& _value,
							const allocator_type& _alloc = allocator_type())
			: _M_alloc_intr(_alloc),
			_M_start(_M_alloc_intr.allocate(_count)),
			_M_finish(_M_start + _count),
			_M_end_of_storage(_M_start + _count) {
				std::uninitialized_fill_n(begin(), _count, _value);
			}

            vector&
            operator=(const vector& _rhs) {
                size_type _prev_size = size();
                pointer _tmp = _M_alloc_intr.allocate(_rhs.size());
                
                std::uninitialized_copy(_rhs.begin(), _rhs.end(), _tmp);
                _M_deallocate(_M_start, _prev_size);
                _M_start = _tmp;
                _M_finish = _M_start + _prev_size;
                _M_end_of_storage = _M_finish;
            }

//			template< class InputIt >
//			vector(	InputIt first, InputIt last,
//			Allocator const& alloc = Allocator());
//
//			vector(vector const& other);
//
			~vector(void) {
				_M_deallocate(_M_start, capacity());
				std::cout << "Vector destructor called" << std::endl;
			}
//
//			vector&
//			operator=(const vector& _rval) {
//				pointer _tmp;
//				if (_M_start)
//					_tmp = _M_allocate(_rval.size());
//				std::uninitialized_copy(_rval.begin(), _rval.end(), _tmp);
//				return (*this);
//			}
//
//			template <class InputIt>
//			void
//			assign(InputIt _first, InputIt _last) {
//				_M_deallocate(_M_start, size());
//				_M_start = _M_allocate(_count);
//				_M_finish = _M_start + _count;
//				_M_end_of_storage = _M_start + _count;
//				std::uninitialized_fill_n(begin(), _count, _value);
//			}

			/**
			 *  Empties %vecotr, resizes if necessary and fills with _count _value. 
			 */
			void
			assign(size_type _count, T const& _value) {
				size_type	_tmp_size;

				if (_count > capacity())
				{
					_M_deallocate(_M_start, size());
					_M_start = _M_allocate(_count);
					_M_end_of_storage = _M_start + _count;
				}
				else
				{
					_tmp_size = size();
					for (size_type i = 0; i < _tmp_size; i++)
						_M_alloc_intr.destroy(_M_start + i);
				}
				_M_finish = _M_start + _count;
// Does not want to EAT THE FUCKING ITERATOR !!!! ////////////////////////////
				std::uninitialized_fill_n(_M_start, _count, _value);        //
//////////////////////////////////////////////////////////////////////////////
			}

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
				return (iterator(this->_M_start));
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

			void
			reserve(size_type _new_cap) {
				pointer		_tmp;
				size_type	_tmp_prev_size;

				if (_new_cap > capacity())
				{
					_tmp_prev_size = size();
					_tmp = _M_allocate(_new_cap);
					std::uninitialized_copy(_M_start, _M_finish, _tmp);
					_M_deallocate(_M_start, _tmp_prev_size);
					_M_start = _tmp;
					_M_finish = _M_start + _tmp_prev_size;
					_M_end_of_storage = _M_start + _new_cap;
				}
			}

			size_type
			capacity() const {
				return (_M_end_of_storage - _M_start);
			}

			void
			clear(void) {
				size_type	_tmp_size = size();
				if (_tmp_size) {
					for (size_type i = 0; i < _tmp_size; i++)
						_M_alloc_intr.destroy(_M_start + i);
					_M_finish = _M_start;
				}
			}

//			iterator		insert(iterator pos, const T& value);
//			void			insert(iterator pos, size_type count, const T& value);
//			template <class InputIt>
//			void			insert(iterator pos, InputIt first, InputIt last);
//
			iterator
			erase(iterator _it) {
				pointer			_tmp;
				difference_type _return_pos;
				size_type		_new_size = _M_check_len(1);
				size_type		_prev_size = size();
				size_type		_prev_capacity = capacity();

				if (_it != end())
				{
					_tmp = _M_alloc_intr.allocate(_prev_capacity);
					if (_it == begin())
					{
						std::uninitialized_copy(_it + 1, end(), _tmp);
						_M_finish = _tmp + (_prev_size - 1);
						_M_end_of_storage = _M_start + _prev_capacity;
						_M_deallocate(_M_start, _prev_capacity);
						_M_start = _tmp;
						return (begin());
					}
					else
					{
						_return_pos = std::distance(begin(), _it);
/* debug */return 0;
						std::uninitialized_copy(begin(), _it - 1, _tmp);
						std::uninitialized_copy(_it + 1, end(), _tmp);
						_M_finish = _tmp + (_prev_size - 1);
						_M_end_of_storage = _M_start + _prev_capacity;
						_M_deallocate(_M_start, _prev_size);
						_M_start = _tmp;
					//	return (_return_pos);
					}
				}
				_M_alloc_intr.destroy(_it.base());
				_M_finish--;
				return (end() - 1);
			}
//			iterator		erase(iterator first, iterator last);
//
			void
			push_back(const T& _value) {
				pointer		_tmp;
				size_type	_new_size = _M_check_len(1);
				size_type	_prev_size = size();
				size_type	_prev_capacity = capacity();

				if (size() < capacity())
				{
					_M_alloc_intr.construct(_M_finish, _value);
					_M_finish++;
					std::cout << "here push_back" << std::endl;
				}
				else
				{
					_tmp = _M_allocate(_new_size);
					std::uninitialized_copy(_M_start, _M_finish, _tmp);
					_M_finish = _tmp + _prev_size;
					_M_end_of_storage = _M_start + _new_size;
					_M_alloc_intr.construct(_M_finish, _value);
					_M_finish++;
					_M_deallocate(_M_start, _prev_capacity);
					_M_start = _tmp;
				}
			}

			void
			pop_back() {
				if (size()) {
					_M_alloc_intr.destroy(_M_finish);
					_M_finish--;
				}
			}
//
//			void			resize(size_type count, T value = T());
//
//			void			swap(vector& other);
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
			size_type	_tmp_size = size();
			if (_M_start != 0) {
				for (size_type i = 0; i < _tmp_size; i++)
					_M_alloc_intr.destroy(_M_start + i);
				_M_alloc_intr.deallocate(_ptr, _size);
				_M_start = 0;
				_M_finish = 0;
				_M_end_of_storage = 0;
			}
		}
	};
}

template<class T, class Alloc>
bool
operator==(ft::vector<T, Alloc> const& _lhs, ft::vector<T, Alloc> const& _rhs) {
    return(_lhs.size() == _rhs.size()
        && std::equal(_lhs.begin(), _lhs.end(), _rhs.begin()));
}

template<class T, class Alloc>
bool
operator!=(ft::vector<T, Alloc> const& _lhs, ft::vector<T, Alloc> const& _rhs) {
    return (!(_lhs == _rhs));
}

template<class T, class Alloc>
bool
operator<(ft::vector<T, Alloc> const& _lhs, ft::vector<T, Alloc> const& _rhs) {
    return (_lhs < _rhs);
}

template<class T, class Alloc>
bool
operator<=(ft::vector<T, Alloc> const& _lhs, ft::vector<T, Alloc> const& _rhs) {
    return (_lhs <= _rhs);
}

template<class T, class Alloc>
bool
operator>(ft::vector<T, Alloc> const& _lhs, ft::vector<T, Alloc> const& _rhs) {
    return (_lhs > _rhs);
}

template<class T, class Alloc>
bool
operator>=(ft::vector<T, Alloc> const& _lhs, ft::vector<T, Alloc> const& _rhs) {
    return (_lhs >= _rhs);
}

//template<class T, class Alloc>
//typename ft::vector<T, Alloc>::iterator
//operator-(typename ft::vector<T, Alloc>::iterator const& _lhs, typename ft::vector<T, Alloc>::iterator const& _rhs) {
    //return (typename ft::vector<T, Alloc>::iterator(_lhs.base() - _rhs.base()));
//}