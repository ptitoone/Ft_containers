/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:53:28 by akotzky           #+#    #+#             */
/*   Updated: 2022/03/15 23:56:47 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "VectorException.hpp"
#include "iterators/NormalIterator.hpp"
#include "iterators/VectorConstIterator.hpp"
#include "iterators/VectorReverseIterator.hpp"
#include "iterators/VectorConstReverseIterator.hpp"
#include <iostream>
#include <memory>

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{

		public:

			typedef T 											value_type;
			typedef Allocator									allocator_type;
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
							const T& _value = value_type(),
							const allocator_type& _alloc = allocator_type())
			: _M_alloc_intr(_alloc),
			_M_start(_M_alloc_intr.allocate(_count)),
			_M_finish(_M_start + _count),
			_M_end_of_storage(_M_start + _count) {
				std::uninitialized_fill_n(_M_start, _count, _value);
			}

            vector&
            operator=(const vector& _rhs) {
                _M_deallocate(_M_start, capacity());
                _M_start = _M_alloc_intr.allocate(_rhs.capacity());
                std::uninitialized_copy(_rhs.begin(), _rhs.end(), _M_start);
                _M_finish = _M_start + _rhs.size();
                _M_end_of_storage = _M_start + _rhs.capacity();
                return (*this);
            }

//			template< class InputIt >
//			vector(	InputIt first, InputIt last,
//			Allocator const& alloc = Allocator()) {
//				
//
//			}
//
//			vector(vector const& other) {
//
//			}

			~vector(void) {
				_M_deallocate(_M_start, capacity());
			}

			void
			assign(iterator _first, iterator _last) {
				size_type _count = std::distance(_first, _last);

				if (_count > capacity())
				{
					_M_deallocate(_M_start, capacity());
					_M_start = _M_allocate(_count);
					_M_finish = _M_start + _count;
					_M_end_of_storage = _M_start + _count;
					std::uninitialized_copy(_first, _last, _M_start);
				}
				else
				{
					for (size_type i = size() - 1; i >= _count; i--)
						_M_alloc_intr.destroy(_M_start + i);
					_M_finish = _M_start + _count;
					for (size_type i = 0; _first != _last; _first++)
						*(_M_start + i++) = *_first;
				}
			}

			void
			assign(size_type _count, T const& _value) {
				if (_count > capacity())
				{
					_M_deallocate(_M_start, capacity());
					_M_start = _M_allocate(_count);
					_M_finish = _M_start + _count;
					_M_end_of_storage = _M_start + _count;
					std::uninitialized_fill_n(_M_start, _count, _value);
				}
				else
				{
					for (size_type i = size() - 1; i >= _count; i--)
						_M_alloc_intr.destroy(_M_start + i);
					_M_finish = _M_start + _count;
					for (size_type i = 0; i < _count; i++)
						*(_M_start + i) = _value;
				}
			}

			allocator_type
			get_allocator() const {
				return (_M_alloc_intr);
			}

			reference
			at(size_type _pos) {
				if (_pos < size())
					return (_M_start[_pos]);
			}

			const_reference
			at(size_type _pos) const {
				if (_pos < size())
					return (_M_start[_pos]);
			}

			reference
			operator[](size_type _pos) {
				return (*(_M_start + _pos));
			}

			const_reference
			operator[](size_type _pos) const {
				return (*(_M_start + _pos));
			}

			iterator
			begin() {
				return (iterator(this->_M_start));
			}

			const_iterator
			begin() const {
				return (const_iterator(this->_M_start));
			}

			iterator
			end() {
				return (iterator(this->_M_finish));
			}

			const_iterator
			end() const {
				return (const_iterator(this->_M_finish));
			}
			
			reverse_iterator
			rbegin() {
				return (reverse_iterator(this->_M_finish - 1));
			}

			const_reverse_iterator
			rbegin() const {
				return (const_reverse_iterator(this->_M_finish - 1));
			}

			reverse_iterator
			rend() {
				return (reverse_iterator(this->_M_start - 1));
			}

			const_reverse_iterator
			rend() const {
				return (const_reverse_iterator(this->_M_start - 1));
			}

			reference
			front() {
				return (*_M_start);
			}

			const_reference
			front() const {
				return (*_M_start);
			}

			reference
			back() {
				return (*_M_finish);
			}

			const_reference
			back() const {
				return (*_M_finish);
			}

			pointer
			data() {
				return (_M_start);
			}

			const_pointer
			data() const {
				return (_M_start);
			}

			bool
			empty(void) const {
				return (this->_M_finish == this->_M_start ? true : false);
			}

			size_type
			size() const {
			//	std::cout << "start = " << _M_start << std::endl;
			//	std::cout << "finish = " << _M_finish << std::endl;
				return (_M_finish - _M_start);
			}

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
					_M_deallocate(_M_start, capacity());
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
                difference_type _return_pos = std::distance(begin(), _it);
                pointer         _tmp = _it.base();

                _M_alloc_intr.destroy(_it.base());
                if (_it != end())
                {
                    while (_tmp != _M_finish)
                    {
                        *_tmp = *(_tmp + 1);
                        _tmp++;
                    }
                }
                _M_finish--;
                return (begin() + _return_pos); 
            }

			iterator
            erase(iterator _first, iterator _last) {
                pointer         _f = _first.base();
                pointer         _l = _last.base();
                difference_type _return_pos = std::distance(_first, _last);

                while (_first != _last)
                    _M_alloc_intr.destroy((_first++).base());
                while (_l != _M_finish)
                {
                    *_f = *_l;
                    _f++;
                    _l++;
                }
                _M_finish -= _return_pos;
                return (begin() + _return_pos);
            }

			void
			push_back(const value_type& _value) {
				pointer		_tmp;
				size_type	_new_size = _M_check_len(1);
				size_type	_prev_size = size();
				size_type	_prev_capacity = capacity();

				if (size() < capacity())
				{
					_M_alloc_intr.construct(_M_finish, _value);
					_M_finish++;
				}
				else
				{
					_tmp = _M_allocate(_new_size);
					std::uninitialized_copy(_M_start, _M_finish, _tmp);
					_M_deallocate(_M_start, _prev_capacity);
					_M_start = _tmp;
					_M_finish = _M_start + _prev_size;
					_M_end_of_storage = _M_start + _new_size;
					_M_alloc_intr.construct(_M_finish, _value);
					_M_finish++;
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
			void
            swap(vector& other) {
                pointer _tmp_start = other._M_start;
                pointer _tmp_finish = other._M_finish;
                pointer _tmp_end_of_storage = other._M_end_of_storage;

                other._M_start = _M_start;
                other._M_finish = _M_finish;
                other._M_end_of_storage = _M_end_of_storage;

                _M_start = _tmp_start;
                _M_finish = _tmp_finish;
                _M_end_of_storage = _tmp_end_of_storage;
            }

		private:

		size_type _M_check_len(size_type _size) {
			if (_M_alloc_intr.max_size() - size() < _size)
				throw(VectorException::OutOfMemoryException());
			size_type _len = size() + std::max(size(), _size);
			return ((_len < size() || _len < max_size()) ? max_size() : _len);
		}

	    pointer _M_allocate(size_type _size) {
            return (_M_alloc_intr.allocate(_size));
        }

		void _M_deallocate(pointer _ptr, size_type _capacity) {
			if (_ptr != 0) {
				for (size_type i = 0; i < size(); i++)
					_M_alloc_intr.destroy(_ptr + i);
				_M_alloc_intr.deallocate(_ptr, _capacity);
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