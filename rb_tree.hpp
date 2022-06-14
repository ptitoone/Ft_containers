#ifndef RB_TREE_HPP
# define RB_TREE_HPP

#include <algorithm>
#include "IteratorTraits.hpp"
#include "utils.hpp"

namespace ft
{
	enum _rbt_color { _s_red = false, _s_black = true };
		

	struct _rbt_node_base
	{
		typedef _rbt_node_base*				_base_ptr;
		typedef const _rbt_node_base*		_const_base_ptr;

		_rbt_color							_M_color;
		_base_ptr							_M_parent;
		_base_ptr							_M_left;
		_base_ptr							_M_right;
		
		static _base_ptr
		_S_minimum(_base_ptr _x)
		{
			while (_x->_M_left != 0)
				_x = _x->_M_left;
			return (_x);
		}
		
		static _const_base_ptr
		_S_minimum(_const_base_ptr _x)
		{
			while (_x->_M_left != 0)
				_x = _x->_M_left;
			return (_x);
		}
		
		static _base_ptr
		_S_maximum(_base_ptr _x)
		{
			while (_x->_M_right != 0)
				_x = _x->_M_right;
			return (_x);
		}
		
		static _const_base_ptr
		_S_maximum(_const_base_ptr _x)
		{
			while (_x->_M_right != 0)
				_x = _x->_M_right;
			return (_x);
		}
	};
		
	template<typename _val>
	struct _rbt_node : public _rbt_node_base
	{
		typedef _rbt_node*	_link_type;
		_val				_M_value_field;
	};
		
	_rbt_node_base*			_rbt_increment(_rbt_node_base* _x);
	const _rbt_node_base*	_rbt_increment(const _rbt_node_base* _x);
	_rbt_node_base*			_rbt_decrement(_rbt_node_base* _x);
	const _rbt_node_base*	_rbt_decrement(const _rbt_node_base* _x);
	
	template<typename T>
	struct _rbt_iterator
	{
		typedef T	value_type;
		typedef T&	reference;
		typedef T*	pointer;
	
		typedef ft::bidirectional_iterator_tag	iterator_category;
		typedef ptrdiff_t						difference_type;
	
		typedef _rbt_iterator<T>			_Self;
		typedef _rbt_node_base::_base_ptr	_base_ptr;
		typedef _rbt_node<T>*				_link_type;
		_base_ptr							_M_node;

		_rbt_iterator():
		_M_node()
		{}
	
		explicit
		_rbt_iterator(_link_type _x):
		_M_node(_x)
		{}
	
		reference
		operator*() const
		{
			return (static_cast<_link_type>(_M_node)->_M_value_field);
		}
	
		pointer
		operator->() const
		{
			return (&static_cast<_link_type>(_M_node)->_M_value_field);
		}
	
		_Self&
		operator++(void)
		{
			_M_node = _rbt_increment(_M_node);
			return (*this);
		}
	
		_Self
		operator++(int)
		{
			_Self _tmp = *this;
			_M_node = _rbt_increment(_M_node);
			return (_tmp);
		}
	
		_Self&
		operator--()
		{
			_M_node = _rbt_decrement(_M_node);
			return (*this);
		}
		
		_Self
		operator--(int)
		{
			_Self _tmp = *this;
			_M_node = _rbt_decrement(_M_node);
			return (_tmp);
		}
		
		bool
		operator==(const _Self& _x) const
		{
			return (_M_node == _x._M_node);
		}

		bool
		operator!=(const _Self& _x) const
		{
			return (_M_node != _x._M_node);
		}			
	};
		
	template<typename T>
	struct _rbt_const_iterator
	{
		typedef T									value_type;
		typedef const T&							reference;
		typedef const T*							pointer;
	
		typedef _rbt_iterator<T>					iterator;
	
		typedef ft::bidirectional_iterator_tag		iterator_category;
		typedef ptrdiff_t							difference_type;
	
		typedef _rbt_const_iterator<T>				_Self;
		typedef _rbt_node_base::_const_base_ptr		_base_ptr;
		typedef const _rbt_node<T>*					_link_type;

		_base_ptr									_M_node;
		
		_rbt_const_iterator(void):
		_M_node()
		{}
		
		explicit
		_rbt_const_iterator(_link_type _x):
		_M_node(_x)
		{}
		
		_rbt_const_iterator(const iterator& _it):
		_M_node(_it._M_node)
		{}
		
		reference
		operator*() const
		{
			return (static_cast<_link_type>(_M_node)->_M_value_field);
		}
	
		pointer
		operator->() const
		{
			return (&static_cast<_link_type>(_M_node)->_M_value_field);
		}
	
		_Self&
		operator++()
		{
			_M_node = _rbt_increment(_M_node);
			return (*this);
		}
		
		_Self
		operator++(int)
		{
			_Self _tmp = *this;
			_M_node = _rbt_increment(_M_node);
			return (_tmp);
		}
	
		_Self&
		operator--()
		{
			_M_node = _rbt_decrement(_M_node);
			return (*this);
		}
	
		_Self
		operator--(int)
		{
			_Self _tmp = *this;
			_M_node = _rbt_decrement(_M_node);
			return (_tmp);
		}
	
		bool
		operator==(const _Self& _x) const
		{
			return (_M_node == _x._M_node);
		}

		bool
		operator!=(const _Self& _x) const
		{
			return (_M_node != _x._M_node);
		}
	};
		
	template<typename _val>
	inline bool
	operator==(const _rbt_iterator<_val>& _x, const _rbt_const_iterator<_val>& _y)
	{
		return (_x._M_node == _y._M_node);
	}
	
	template<typename _val>
	inline bool
	operator!=(const _rbt_iterator<_val>& _x, const _rbt_const_iterator<_val>& _y)
	{
		return _x._M_node != _y._M_node;
	}
	
	void
	_rbt_rotate_left(_rbt_node_base* const _x, _rbt_node_base*& _root);
	
	void
	_rbt_rotate_right(_rbt_node_base* const _x, _rbt_node_base*& _root);

	void
	_rbt_insert_and_rebalance(const bool _insert_left, _rbt_node_base* _x, _rbt_node_base* _p, _rbt_node_base& _header);
	
	_rbt_node_base*
	_rbt_rebalance_for_erase(_rbt_node_base* const _z, _rbt_node_base& _header);
	
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc = std::allocator<_val> >
	class _rbt
	{
		typedef typename _alloc::template rebind<_rbt_node<_val> >::other	_node_allocator;
	
		protected:

			typedef _rbt_node_base*			_base_ptr;
			typedef const _rbt_node_base*	_const_base_ptr;
			typedef _rbt_node<_val>			_rbt_node;

		public:

			typedef _key					key_type;
			typedef _val					value_type;
			typedef value_type*				pointer;
			typedef const value_type*		const_pointer;
			typedef value_type&				reference;
			typedef const value_type&		const_reference;
			typedef _rbt_node*				_link_type;
			typedef const _rbt_node*		_const_link_type;
			typedef size_t					size_type;
			typedef ptrdiff_t				difference_type;
			typedef _alloc					allocator_type;
	
			allocator_type
			get_allocator() const
			{
				return (*static_cast<const _node_allocator*>(&this->_M_impl));
			}
	
		protected:

			_rbt_node*
			_M_get_node()
			{
				return (_M_impl._node_allocator::allocate(1));
			}
	
			void
			_M_put_node(_rbt_node* _p)
			{
				_M_impl._node_allocator::deallocate(_p, 1);
			}
	
			_link_type
			_M_create_node(const value_type& _x)
			{
				_link_type	_tmp = _M_get_node();
				try
				{ get_allocator().construct(&_tmp->_M_value_field, _x); }
				catch(std::exception &err)
				{
					_M_put_node(_tmp);
					throw(err.what());
				}
				return (_tmp);
			}
	
			_link_type
			_M_clone_node(_const_link_type _x)
			{
				_link_type	_tmp = _M_create_node(_x->_M_value_field);
				_tmp->_M_color = _x->_M_color;
				_tmp->_M_left = 0;
				_tmp->_M_right = 0;
				return (_tmp);
			}
	
			void
			destroy_node(_link_type _p)
			{
				get_allocator().destroy(&_p->_M_value_field);
				_M_put_node(_p);
			}
	

			template<typename _key_compare, bool _Is_pod_comparator = ft::is_integral<_key_compare>::value>
			struct _rbt_impl : public _node_allocator
			{
				_key_compare		_M_key_compare;
				_rbt_node_base		_M_header;
				size_type			_M_node_count;

				_rbt_impl(const _node_allocator& _allocate= _node_allocator(),
						const _key_compare& _comp = _key_compare()):
				_node_allocator(_allocate), _M_key_compare(_comp), _M_header(), _M_node_count(0)
				{
					this->_M_header._M_color = _s_red;
					this->_M_header._M_parent = 0;
					this->_M_header._M_left = &this->_M_header;
					this->_M_header._M_right = &this->_M_header;
				}
			};

			template<typename _key_compare>
			struct _rbt_impl<_key_compare, true> : public _node_allocator 
			{
				_key_compare		_M_key_compare;
				_rbt_node_base		_M_header;
				size_type			_M_node_count;

				_rbt_impl(const _node_allocator& _allocate= _node_allocator(),
						const _key_compare& _comp = _key_compare()):
				_node_allocator(_allocate), _M_key_compare(_comp), _M_header(), _M_node_count(0)
				{
					this->_M_header._M_color = _s_red;
					this->_M_header._M_parent = 0;
					this->_M_header._M_left = &this->_M_header;
					this->_M_header._M_right = &this->_M_header;
				}
			};

			_rbt_impl<_compare>	_M_impl;

			_base_ptr&
			_M_root()
			{
				return (this->_M_impl._M_header._M_parent);
			}

			_const_base_ptr
			_M_root() const
			{
				return (this->_M_impl._M_header._M_parent);
			}

			_base_ptr&
			_M_leftmost()
			{
				return (this->_M_impl._M_header._M_left);
			}

			_const_base_ptr
			_M_leftmost() const
			{
				return (this->_M_impl._M_header._M_left);
			}

			_base_ptr&
			_M_rightmost()
			{
				return (this->_M_impl._M_header._M_right);
			}

			_const_base_ptr 
			_M_rightmost() const
			{
				return (this->_M_impl._M_header._M_right);
			}

			_link_type
			_M_begin()
			{
				return (static_cast<_link_type>(this->_M_impl._M_header._M_parent));
			}

			_const_link_type
			_M_begin() const
			{
				return (static_cast<_const_link_type>(this->_M_impl._M_header._M_parent));
			}

			_link_type
			_M_end()
			{
				return (static_cast<_link_type>(&this->_M_impl._M_header));
			}

			_const_link_type
			_M_end() const
			{
				return (static_cast<_const_link_type>(&this->_M_impl._M_header));
			}

			static const_reference
			_S_value(_const_link_type _x)
			{
				return (_x->_M_value_field);
			}

			static const _key&
			_S_key(_const_link_type _x)
			{
				return (_keyOfValue()(_S_value(_x)));
			}

			static _link_type
			_S_left(_base_ptr _x)
			{
				return (static_cast<_link_type>(_x->_M_left));
			}

			static _const_link_type
			_S_left(_const_base_ptr _x)
			{
				return (static_cast<_const_link_type>(_x->_M_left));
			}

			static _link_type
			_s_right(_base_ptr _x)
			{
				return (static_cast<_link_type>(_x->_M_right));
			}

			static _const_link_type
			_s_right(_const_base_ptr _x)
			{
				return (static_cast<_const_link_type>(_x->_M_right));
			}

			static const_reference
			_S_value(_const_base_ptr _x)
			{
				return (static_cast<_const_link_type>(_x)->_M_value_field);
			}

			static const _key&
			_S_key(_const_base_ptr _x)
			{
				return (_keyOfValue()(_S_value(_x)));
			}

			static _base_ptr
			_S_minimum(_base_ptr _x)
			{
				return (_rbt_node_base::_S_minimum(_x));
			}

			static _const_base_ptr
			_S_minimum(_const_base_ptr _x)
			{
				return (_rbt_node_base::_S_minimum(_x));
			}

			static _base_ptr
			_S_maximum(_base_ptr _x)
			{
				return (_rbt_node_base::_S_maximum(_x));
			}

			static _const_base_ptr
			_S_maximum(_const_base_ptr _x)
			{
				return (_rbt_node_base::_S_maximum(_x));
			}
	
		public:

			typedef _rbt_iterator<value_type>				iterator;
			typedef _rbt_const_iterator<value_type>			const_iterator;

			typedef std::reverse_iterator<iterator>			reverse_iterator;
			typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;

		private:

			iterator
			_M_insert(_base_ptr _x, _base_ptr _y, const value_type& _value);

			const_iterator
			_M_insert(_const_base_ptr _x, _const_base_ptr _y, const value_type& _value);

			_link_type
			_M_copy(_const_link_type _x, _link_type _p);
	
			void
			_M_erase(_link_type _x);

		public:

			_rbt()
			{}

			_rbt(const _compare& _comp):
			_M_impl(allocator_type(), _comp)
			{}

			_rbt(const _compare& _comp, const allocator_type& _allocate):
			_M_impl(_allocate, _comp)
			{}

			_rbt(const _rbt<_key, _val, _keyOfValue, _compare, _alloc>& _x):
			_M_impl(_x.get_allocator(), _x._M_impl._M_key_compare)
			{
				if (_x._M_root() != 0)
				{
					_M_root() = _M_copy(_x._M_begin(), _M_end());
					_M_leftmost() = _S_minimum(_M_root());
					_M_rightmost() = _S_maximum(_M_root());
					_M_impl._M_node_count = _x._M_impl._M_node_count;
				}
			}

			~_rbt()
			{
				_M_erase(_M_begin());
			}
	
			_rbt<_key, _val, _keyOfValue, _compare, _alloc>&
			operator=(const _rbt<_key, _val, _keyOfValue, _compare, _alloc>& _x);
	
			_compare
			key_comp() const
			{
				return (_M_impl._M_key_compare);
			}
	
			iterator 
			begin()
			{
				return (iterator(static_cast<_link_type>(this->_M_impl._M_header._M_left)));
			}
	
			const_iterator
			begin() const
			{
				return (const_iterator(static_cast<_const_link_type>(this->_M_impl._M_header._M_left)));
			}
	
			iterator
			end()
			{
				return (iterator(static_cast<_link_type>(&this->_M_impl._M_header)));
			}
	
			const_iterator
			end() const
			{
				return (const_iterator(static_cast<_const_link_type>(&this->_M_impl._M_header)));
			}
	
			reverse_iterator
			rbegin()
			{
				return (reverse_iterator(end()));
			}
	
			const_reverse_iterator
			rbegin() const
			{
				return (const_reverse_iterator(end()));
			}
	
			reverse_iterator
			rend()
			{
				return (reverse_iterator(begin()));
			}
	
			const_reverse_iterator
			rend() const
			{
				return (const_reverse_iterator(begin()));
			}
	
			bool
			empty() const
			{
				return (_M_impl._M_node_count == 0);
			}
	
			size_type
			size() const
			{
				return (_M_impl._M_node_count);
			}
	
			size_type
			max_size() const
			{
				return (size_type(-1));
			}
	
			void
			swap(_rbt<_key, _val, _keyOfValue, _compare, _alloc>& _t);
	
			ft::pair<iterator,bool>
			insert_unique(const value_type& _x);
	
			iterator
			insert_equal(const value_type& _x);
	
			iterator
			insert_unique(iterator _position, const value_type& _x);
	
			const_iterator
			insert_unique(const_iterator _position, const value_type& _x);
	
			iterator
			insert_equal(iterator _position, const value_type& _x);
	
			const_iterator
			insert_equal(const_iterator _position, const value_type& _x);
	
			template<typename _InputIterator>
			void
			insert_unique(_InputIterator _first, _InputIterator _last);
	
			template<typename _InputIterator>
			void
			insert_equal(_InputIterator _first, _InputIterator _last);
	
			void
			erase(iterator _position);
	
			void
			erase(const_iterator _position);
	
			size_type
			erase(const key_type& _x);
	
			void
			erase(iterator _first, iterator _last);
	
			void
			erase(const_iterator _first, const_iterator _last);
	
			void
			erase(const key_type* _first, const key_type* _last);
	
			void
			clear()
			{
				_M_erase(_M_begin());
				_M_leftmost() = _M_end();
				_M_root() = 0;
				_M_rightmost() = _M_end();
				_M_impl._M_node_count = 0;
			}
	
			iterator
			find(const key_type& _x);
	
			const_iterator
			find(const key_type& _x) const;
	
			size_type
			count(const key_type& _x) const;
	
			iterator
			lower_bound(const key_type& _x);
	
			const_iterator
			lower_bound(const key_type& _x) const;
	
			iterator
			upper_bound(const key_type& _x);
	
			const_iterator
			upper_bound(const key_type& _x) const;
	
			ft::pair<iterator,iterator>
			equal_range(const key_type& _x);
	
			ft::pair<const_iterator, const_iterator>
			equal_range(const key_type& _x) const;
	
			bool
			_rb_verify() const;
		};
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	inline bool
	operator==( const _rbt<_key, _val, _keyOfValue, _compare, _alloc>& _x,
				const _rbt<_key, _val, _keyOfValue, _compare, _alloc>& _y )
	{
		return (_x.size() == _y.size() && std::equal(_x.begin(), _x.end(), _y.begin()));
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	inline bool
	operator<(	const _rbt<_key, _val, _keyOfValue, _compare, _alloc>& _x,
				const _rbt<_key, _val, _keyOfValue, _compare, _alloc>& _y )
	{
		return (std::lexicographical_compare(_x.begin(), _x.end(), _y.begin(), _y.end()));
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	inline bool
	operator!=(	const _rbt<_key, _val, _keyOfValue, _compare, _alloc>& _x,
				const _rbt<_key, _val, _keyOfValue, _compare, _alloc>& _y )
	{
		return (!(_x == _y));
	}
	
	template<typename _key, typename _val, typename _keyOfValue,
	typename _compare, typename _alloc>
	inline bool
	operator>(	const _rbt<_key, _val, _keyOfValue, _compare, _alloc>& _x,
				const _rbt<_key, _val, _keyOfValue, _compare, _alloc>& _y )
	{
		return (_y < _x);
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	inline bool
	operator<=(	const _rbt<_key, _val, _keyOfValue, _compare, _alloc>& _x,
				const _rbt<_key, _val, _keyOfValue, _compare, _alloc>& _y )
	{
		return (!(_y < _x));
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	inline bool
	operator>=(	const _rbt<_key, _val, _keyOfValue, _compare, _alloc>& _x,
				const _rbt<_key, _val, _keyOfValue, _compare, _alloc>& _y )
	{
		return (!(_x < _y));
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	inline void
	swap(	_rbt<_key, _val, _keyOfValue, _compare, _alloc>& _x,
			_rbt<_key, _val, _keyOfValue, _compare, _alloc>& _y )
	{
		_x.swap(_y);
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	_rbt<_key, _val, _keyOfValue, _compare, _alloc>&
	_rbt<_key, _val, _keyOfValue, _compare, _alloc>::operator=(const _rbt<_key, _val, _keyOfValue, _compare, _alloc>& _x)
	{
		if (this != &_x)
		{
			clear();
			_M_impl._M_key_compare = _x._M_impl._M_key_compare;
			if (_x._M_root() != 0)
			{
					_M_root() = _M_copy(_x._M_begin(), _M_end());
					_M_leftmost() = _S_minimum(_M_root());
					_M_rightmost() = _S_maximum(_M_root());
					_M_impl._M_node_count = _x._M_impl._M_node_count;
			}
		}
		return (*this);
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	typename _rbt<_key, _val, _keyOfValue, _compare, _alloc>::iterator
	_rbt<_key, _val, _keyOfValue, _compare, _alloc>::_M_insert(_base_ptr _x, _base_ptr _p, const _val& _value)
	{
		bool		_insert_left = (_x != 0 || _p == _M_end() || _M_impl._M_key_compare(_keyOfValue()(_value), _S_key(_p)));
		_link_type	_z = _M_create_node(_value);
	
			_rbt_insert_and_rebalance(_insert_left, _z, _p, this->_M_impl._M_header);
			++_M_impl._M_node_count;
			return (iterator(_z));
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	typename _rbt<_key, _val, _keyOfValue, _compare, _alloc>::const_iterator
	_rbt<_key, _val, _keyOfValue, _compare, _alloc>::_M_insert(_const_base_ptr _x, _const_base_ptr _p, const _val& _value)
	{
		bool		_insert_left = (_x != 0 || _p == _M_end()
			|| _M_impl._M_key_compare(_keyOfValue()(_value), _S_key(_p)));
	
		_link_type	_z = _M_create_node(_value);
	
		_rbt_insert_and_rebalance(_insert_left, _z, const_cast<_base_ptr>(_p), this->_M_impl._M_header);
		++_M_impl._M_node_count;
		return (const_iterator(_z));
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	typename _rbt<_key, _val, _keyOfValue, _compare, _alloc>::iterator
	_rbt<_key, _val, _keyOfValue, _compare, _alloc>::insert_equal(const _val& _value)
	{
		_link_type _x = _M_begin();
		_link_type _y = _M_end();
		while (_x != 0)
		{
			_y = _x;
			_x = _M_impl._M_key_compare(_keyOfValue()(_value), _S_key(_x)) ? _S_left(_x) : _s_right(_x);
		}
		return (_M_insert(_x, _y, _value));
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	void
	_rbt<_key, _val, _keyOfValue, _compare, _alloc>::swap(_rbt<_key, _val, _keyOfValue, _compare, _alloc>& _t)
	{
		if (_M_root() == 0)
		{
			if (_t._M_root() != 0)
			{
				_M_root() = _t._M_root();
				_M_leftmost() = _t._M_leftmost();
				_M_rightmost() = _t._M_rightmost();
				_M_root()->_M_parent = _M_end();
	
				_t._M_root() = 0;
				_t._M_leftmost() = _t._M_end();
				_t._M_rightmost() = _t._M_end();
			}
		}
		else if (_t._M_root() == 0)
		{
			_t._M_root() = _M_root();
			_t._M_leftmost() = _M_leftmost();
			_t._M_rightmost() = _M_rightmost();
			_t._M_root()->_M_parent = _t._M_end();
	
			_M_root() = 0;
			_M_leftmost() = _M_end();
			_M_rightmost() = _M_end();
		}
		else
		{
			std::swap(_M_root(),_t._M_root());
			std::swap(_M_leftmost(),_t._M_leftmost());
			std::swap(_M_rightmost(),_t._M_rightmost());
	
			_M_root()->_M_parent = _M_end();
			_t._M_root()->_M_parent = _t._M_end();
		}
		
		std::swap(this->_M_impl._M_node_count, _t._M_impl._M_node_count);
		std::swap(this->_M_impl._M_key_compare, _t._M_impl._M_key_compare);
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	ft::pair<typename _rbt<_key, _val, _keyOfValue, _compare, _alloc>::iterator, bool>
	_rbt<_key, _val, _keyOfValue, _compare, _alloc>::insert_unique(const _val& _value)
	{
		_link_type _x = _M_begin();
		_link_type _y = _M_end();
		bool _comp = true;
		while (_x != 0)
		{
			_y = _x;
			_comp = _M_impl._M_key_compare(_keyOfValue()(_value), _S_key(_x));
			_x = _comp ? _S_left(_x) : _s_right(_x);
		}
		iterator _j = iterator(_y);
		if (_comp)
		{
			if (_j == begin())
				return (ft::pair<iterator,bool>(_M_insert(_x, _y, _value), true));
			else
				--_j;
		}
		if (_M_impl._M_key_compare(_S_key(_j._M_node), _keyOfValue()(_value)))
			return (ft::pair<iterator, bool>(_M_insert(_x, _y, _value), true));
		return (ft::pair<iterator, bool>(_j, false));
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	typename _rbt<_key, _val, _keyOfValue, _compare, _alloc>::iterator
	_rbt<_key, _val, _keyOfValue, _compare, _alloc>::insert_unique(iterator _position, const _val& _value)
	{
		if (_position._M_node == _M_end())
		{
			if (size() > 0 && _M_impl._M_key_compare(_S_key(_M_rightmost()), _keyOfValue()(_value)))
				return (_M_insert(0, _M_rightmost(), _value));
			else
				return (insert_unique(_value).first);
		}
		else if (_M_impl._M_key_compare(_keyOfValue()(_value), _S_key(_position._M_node)))
		{
			iterator	_before = _position;
			if (_position._M_node == _M_leftmost())
				return (_M_insert(_M_leftmost(), _M_leftmost(), _value));
			else if (_M_impl._M_key_compare(_S_key((--_before)._M_node), _keyOfValue()(_value)))
			{
				if (_s_right(_before._M_node) == 0)
					return (_M_insert(0, _before._M_node, _value));
				else
					return (_M_insert(_position._M_node, _position._M_node, _value));
			}
			else
				return (insert_unique(_value).first);
		}
		else if (_M_impl._M_key_compare(_S_key(_position._M_node), _keyOfValue()(_value)))
		{
			iterator _after = _position;
			if (_position._M_node == _M_rightmost())
				return (_M_insert(0, _M_rightmost(), _value));
			else if (_M_impl._M_key_compare(_keyOfValue()(_value), _S_key((++_after)._M_node)))
			{
				if (_s_right(_position._M_node) == 0)
					return (_M_insert(0, _position._M_node, _value));
				else
					return (_M_insert(_after._M_node, _after._M_node, _value));
			}
			else
				return (insert_unique(_value).first);
		}
		else
			return (_position);
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	typename _rbt<_key, _val, _keyOfValue, _compare, _alloc>::const_iterator
	_rbt<_key, _val, _keyOfValue, _compare, _alloc>::insert_unique(const_iterator _position, const _val& _value)
	{
		if (_position._M_node == _M_end())
		{
			if (size() > 0 && _M_impl._M_key_compare(_S_key(_M_rightmost()), _keyOfValue()(_value)))
				return (_M_insert(0, _M_rightmost(), _value));
			else
				return (const_iterator(insert_unique(_value).first));
		}
		else if (_M_impl._M_key_compare(_keyOfValue()(_value), _S_key(_position._M_node)))
		{
			const_iterator _before = _position;
			if (_position._M_node == _M_leftmost())
				return (_M_insert(_M_leftmost(), _M_leftmost(), _value));
			else if (_M_impl._M_key_compare(_S_key((--_before)._M_node), _keyOfValue()(_value)))
			{
				if (_s_right(_before._M_node) == 0)
					return (_M_insert(0, _before._M_node, _value));
				else
					return (_M_insert(_position._M_node, _position._M_node, _value));
			}
			else
				return (const_iterator(insert_unique(_value).first));
		}
		else if (_M_impl._M_key_compare(_S_key(_position._M_node), _keyOfValue()(_value)))
		{
			const_iterator _after = _position;
			if (_position._M_node == _M_rightmost())
				return (_M_insert(0, _M_rightmost(), _value));
			else if (_M_impl._M_key_compare(_keyOfValue()(_value), _S_key((++_after)._M_node)))
			{
				if (_s_right(_position._M_node) == 0)
					return (_M_insert(0, _position._M_node, _value));
				else
					return (_M_insert(_after._M_node, _after._M_node, _value));
			}
			else
				return (const_iterator(insert_unique(_value).first));
		}
		else
			return (_position);
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
			typename _rbt<_key, _val, _keyOfValue, _compare, _alloc>::iterator
			_rbt<_key, _val, _keyOfValue, _compare, _alloc>::insert_equal(iterator _position, const _val& _value)
			{
				if (_position._M_node == _M_end())
				{
					if (size() > 0 && !_M_impl._M_key_compare(_keyOfValue()(_value), _S_key(_M_rightmost())))
						return (_M_insert(0, _M_rightmost(), _value));
					else
						return (insert_equal(_value));
				}
				else if (!_M_impl._M_key_compare(_S_key(_position._M_node), _keyOfValue()(_value)))
				{
					iterator _before = _position;
					if (_position._M_node == _M_leftmost())
						return (_M_insert(_M_leftmost(), _M_leftmost(), _value));
					else if (!_M_impl._M_key_compare(_keyOfValue()(_value), _S_key((--_before)._M_node)))
					{
						if (_s_right(_before._M_node) == 0)
							return (_M_insert(0, _before._M_node, _value));
						else
							return (_M_insert(_position._M_node, _position._M_node, _value));
					}
					else
						return (insert_equal(_value));
				}
				else
				{
					iterator _after = _position;
					if (_position._M_node == _M_rightmost())
						return (_M_insert(0, _M_rightmost(), _value));
					else if (!_M_impl._M_key_compare(_S_key((++_after)._M_node), _keyOfValue()(_value)))
					{
						if (_s_right(_position._M_node) == 0)
							return (_M_insert(0, _position._M_node, _value));
						else
							return (_M_insert(_after._M_node, _after._M_node, _value));
					}
					else
						return (insert_equal(_value));
				}
			}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	typename _rbt<_key, _val, _keyOfValue, _compare, _alloc>::const_iterator
	_rbt<_key, _val, _keyOfValue, _compare, _alloc>::insert_equal(const_iterator _position, const _val& _value)
	{
		if (_position._M_node == _M_end())
		{
			if (size() > 0 && !_M_impl._M_key_compare(_keyOfValue()(_value), _S_key(_M_rightmost())))
				return (_M_insert(0, _M_rightmost(), _value));
			else
				return (const_iterator(insert_equal(_value)));
		}
		else if (!_M_impl._M_key_compare(_S_key(_position._M_node), _keyOfValue()(_value)))
		{
			const_iterator	_before = _position;
			if (_position._M_node == _M_leftmost())
				return (_M_insert(_M_leftmost(), _M_leftmost(), _value));
			else if (!_M_impl._M_key_compare(_keyOfValue()(_value), _S_key((--_before)._M_node)))
			{
				if (_s_right(_before._M_node) == 0)
					return (_M_insert(0, _before._M_node, _value));
				else
					return (_M_insert(_position._M_node, _position._M_node, _value));
			}
			else
				return (const_iterator(insert_equal(_value)));
		}
		else
		{
			const_iterator	_after = _position;
			if (_position._M_node == _M_rightmost())
				return (_M_insert(0, _M_rightmost(), _value));
			else if (!_M_impl._M_key_compare(_S_key((++_after)._M_node), _keyOfValue()(_value)))
			{
					if (_s_right(_position._M_node) == 0)
						return (_M_insert(0, _position._M_node, _value));
					else
						return (_M_insert(_after._M_node, _after._M_node, _value));
			}
			else
				return (const_iterator(insert_equal(_value)));
		}
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _cmp, typename _alloc>
	template<class _II>
	void
	_rbt<_key, _val, _keyOfValue, _cmp, _alloc>::insert_equal(_II _first, _II _last)
	{
		for (; _first != _last; ++_first)
			insert_equal(end(), *_first);
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _cmp, typename _alloc>
	template<class _II>
	void
	_rbt<_key, _val, _keyOfValue, _cmp, _alloc>::insert_unique(_II _first, _II _last)
	{
		for (; _first != _last; ++_first)
			insert_unique(end(), *_first);
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	inline void
	_rbt<_key, _val, _keyOfValue, _compare, _alloc>::erase(iterator _position)
	{
		_link_type	_y = static_cast<_link_type>(_rbt_rebalance_for_erase(_position._M_node, this->_M_impl._M_header));
		destroy_node(_y);
		--_M_impl._M_node_count;
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	inline void
	_rbt<_key, _val, _keyOfValue, _compare, _alloc>::erase(const_iterator _position)
	{
		_link_type _y = static_cast<_link_type>(
			_rbt_rebalance_for_erase(
				const_cast<_base_ptr>(_position._M_node), this->_M_impl._M_header));
			destroy_node(_y);
			--_M_impl._M_node_count;
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	typename _rbt<_key, _val, _keyOfValue, _compare, _alloc>::size_type
	_rbt<_key, _val, _keyOfValue, _compare, _alloc>::erase(const _key& _x)
	{
		ft::pair<iterator,iterator>	_p = equal_range(_x);
		size_type				_n = std::distance(_p.first, _p.second);
		erase(_p.first, _p.second);
		return (_n);
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	typename _rbt<_key, _val, _keyOfValue, _compare, _alloc>::_link_type
	_rbt<_key, _val, _keyOfValue, _compare, _alloc>::_M_copy(_const_link_type _x, _link_type _p)
	{
		_link_type		_top = _M_clone_node(_x);
		_top->_M_parent = _p;
		try
		{
			if (_x->_M_right)
				_top->_M_right = _M_copy(_s_right(_x), _top);
			_p = _top;
			_x = _S_left(_x);
			while (_x != 0)
			{
				_link_type _y = _M_clone_node(_x);
				_p->_M_left = _y;
				_y->_M_parent = _p;
				if (_x->_M_right)
					_y->_M_right = _M_copy(_s_right(_x), _y);
				_p = _y;
				_x = _S_left(_x);
			}
		}
		catch(std::exception& err)
		{
			_M_erase(_top);
			throw(err.what());
		}
		return (_top);
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	void
	_rbt<_key, _val, _keyOfValue, _compare, _alloc>::_M_erase(_link_type _x)
	{
		while (_x != 0)
		{
			_M_erase(_s_right(_x));
			_link_type _y = _S_left(_x);
			destroy_node(_x);
			_x = _y;
		}
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	void
	_rbt<_key, _val, _keyOfValue, _compare, _alloc>::erase(iterator _first, iterator _last)
	{
		if (_first == begin() && _last == end())
			clear();
		else
			while (_first != _last)
				erase(_first++);
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	void
	_rbt<_key, _val, _keyOfValue, _compare, _alloc>::erase(const_iterator _first, const_iterator _last)
	{
		if (_first == begin() && _last == end())
			clear();
		else
			while (_first != _last)
		erase(_first++);
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	void
	_rbt<_key, _val, _keyOfValue, _compare, _alloc>::erase(const _key* _first, const _key* _last)
	{
		while (_first != _last)
			erase(*_first++);
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	typename _rbt<_key, _val, _keyOfValue, _compare, _alloc>::iterator
	_rbt<_key, _val, _keyOfValue, _compare, _alloc>::find(const _key& _k)
	{
		_link_type _x = _M_begin();
		_link_type _y = _M_end();
	
		while (_x != 0)
		{
			if (!_M_impl._M_key_compare(_S_key(_x), _k))
				_y = _x, _x = _S_left(_x);
			else
			_x = _s_right(_x);
		}
		iterator _j = iterator(_y);
		return ((_j == end() || _M_impl._M_key_compare(_k, _S_key(_j._M_node))) ? end() : _j);
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	typename _rbt<_key, _val, _keyOfValue, _compare, _alloc>::const_iterator
	_rbt<_key, _val, _keyOfValue, _compare, _alloc>::find(const _key& _k) const
	{
		_const_link_type _x = _M_begin();
		_const_link_type _y = _M_end();
	
		while (_x != 0)
		{
			if (!_M_impl._M_key_compare(_S_key(_x), _k))
				_y = _x, _x = _S_left(_x);
			else
				_x = _s_right(_x);
		}
		const_iterator _j = const_iterator(_y);
		return ((_j == end() || _M_impl._M_key_compare(_k, _S_key(_j._M_node))) ? end() : _j);
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	typename _rbt<_key, _val, _keyOfValue, _compare, _alloc>::size_type
	_rbt<_key, _val, _keyOfValue, _compare, _alloc>::count(const _key& _k) const
	{
		ft::pair<const_iterator, const_iterator> _p = equal_range(_k);
		const size_type _n = std::distance(_p.first, _p.second);
		return (_n);
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	typename _rbt<_key, _val, _keyOfValue, _compare, _alloc>::iterator
	_rbt<_key, _val, _keyOfValue, _compare, _alloc>::lower_bound(const _key& _k)
	{
		_link_type _x = _M_begin();
		_link_type _y = _M_end();

		while (_x != 0)
		{
			if (!_M_impl._M_key_compare(_S_key(_x), _k))
				_y = _x, _x = _S_left(_x);
			else
				_x = _s_right(_x);
		}
		return (iterator(_y));
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	typename _rbt<_key, _val, _keyOfValue, _compare, _alloc>::const_iterator
	_rbt<_key, _val, _keyOfValue, _compare, _alloc>::lower_bound(const _key& _k) const
	{
		_const_link_type _x = _M_begin();
		_const_link_type _y = _M_end();
	
		while (_x != 0)
		{
			if (!_M_impl._M_key_compare(_S_key(_x), _k))
				_y = _x, _x = _S_left(_x);
			else
				_x = _s_right(_x);
		}
		return (const_iterator(_y));
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	typename _rbt<_key, _val, _keyOfValue, _compare, _alloc>::iterator
	_rbt<_key, _val, _keyOfValue, _compare, _alloc>::upper_bound(const _key& _k)
	{
		_link_type _x = _M_begin();
		_link_type _y = _M_end();
	
		while (_x != 0)
		{
			if (_M_impl._M_key_compare(_k, _S_key(_x)))
				_y = _x, _x = _S_left(_x);
			else
				_x = _s_right(_x);
		}
		return (iterator(_y));
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	typename _rbt<_key, _val, _keyOfValue, _compare, _alloc>::const_iterator
	_rbt<_key, _val, _keyOfValue, _compare, _alloc>::upper_bound(const _key& _k) const
	{
		_const_link_type _x = _M_begin();
		_const_link_type _y = _M_end();
	
		while (_x != 0)
		{
			if (_M_impl._M_key_compare(_k, _S_key(_x)))
				_y = _x, _x = _S_left(_x);
			else
				_x = _s_right(_x);
		}
		return (const_iterator(_y));
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	inline	ft::pair<typename _rbt<_key, _val, _keyOfValue,_compare, _alloc>::iterator,
					 typename _rbt<_key, _val, _keyOfValue, _compare, _alloc>::iterator>
	_rbt<_key, _val, _keyOfValue, _compare, _alloc>::equal_range(const _key& _k)
	{
		return (ft::pair<iterator, iterator>(lower_bound(_k), upper_bound(_k)));
	}
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	inline	ft::pair<typename _rbt<_key, _val, _keyOfValue, _compare, _alloc>::const_iterator,
					 typename _rbt<_key, _val, _keyOfValue, _compare, _alloc>::const_iterator>
	_rbt<_key, _val, _keyOfValue, _compare, _alloc>::equal_range(const _key& _k) const
	{
		return (ft::pair<const_iterator, const_iterator>(lower_bound(_k), upper_bound(_k)));
	}
	
	unsigned int	_rbt_black_count(const _rbt_node_base* _node,const _rbt_node_base* _root);
	
	template<typename _key, typename _val, typename _keyOfValue, typename _compare, typename _alloc>
	bool
	_rbt<_key,_val,_keyOfValue,_compare,_alloc>::_rb_verify() const
	{
		if (_M_impl._M_node_count == 0 || begin() == end())
			return (_M_impl._M_node_count == 0 && begin() == end() && this->_M_impl._M_header._M_left == _M_end() && this->_M_impl._M_header._M_right == _M_end());
		unsigned int _len = _rbt_black_count(_M_leftmost(), _M_root());
		for (const_iterator _it = begin(); _it != end(); ++_it)
		{
			_const_link_type _x = static_cast<_const_link_type>(_it._M_node);
			_const_link_type _l = _S_left(_x);
			_const_link_type _R = _s_right(_x);
	
			if (_x->_M_color == _s_red)
				if ((_l && _l->_M_color == _s_red) || (_R && _R->_M_color == _s_red))
					return (false);
			if (_l && _M_impl._M_key_compare(_S_key(_x), _S_key(_l)))
				return (false);
			if (_R && _M_impl._M_key_compare(_S_key(_R), _S_key(_x)))
				return (false);
			if (!_l && !_R && _rbt_black_count(_x, _M_root()) != _len)
				return (false);
		}
	
		if (_M_leftmost() != _rbt_node_base::_S_minimum(_M_root()))
			return (false);
		if (_M_rightmost() != _rbt_node_base::_S_maximum(_M_root()))
			return (false);
		return (true);
	}

	_rbt_node_base*
	_rbt_increment(_rbt_node_base* _x)
	{
		if (_x->_M_right != 0) 
		{
			_x = _x->_M_right;
			while (_x->_M_left != 0)
				_x = _x->_M_left;
		}
		else 
		{
			_rbt_node_base* _y = _x->_M_parent;
			while (_x == _y->_M_right) 
			{
				_x = _y;
				_y = _y->_M_parent;
			}
			if (_x->_M_right != _y)
				_x = _y;
		}
		return (_x);
	}
 
	const _rbt_node_base*
	_rbt_increment(const _rbt_node_base* _x)
	{
		return (_rbt_increment(const_cast<_rbt_node_base*>(_x)));
	}
 
	_rbt_node_base*
	_rbt_decrement(_rbt_node_base* _x)
	{
		if (_x->_M_color == _s_red && _x->_M_parent->_M_parent == _x)
			_x = _x->_M_right;
		else if (_x->_M_left != 0) 
		{
			_rbt_node_base* _y = _x->_M_left;
			while (_y->_M_right != 0)
				_y = _y->_M_right;
			_x = _y;
		}
		else
		{
			_rbt_node_base* _y = _x->_M_parent;
			while (_x == _y->_M_left) 
			{
				_x = _y;
				_y = _y->_M_parent;
			}
			_x = _y;
		}
		return (_x);
	}
 
	const _rbt_node_base*
	_rbt_decrement(const _rbt_node_base* _x)
	{
		return (_rbt_decrement(const_cast<_rbt_node_base*>(_x)));
	}
 
	void
	_rbt_rotate_left(_rbt_node_base* const _x, _rbt_node_base*& _root)
	{
		_rbt_node_base* const _y = _x->_M_right;
		_x->_M_right = _y->_M_left;
		if (_y->_M_left !=0)
			_y->_M_left->_M_parent = _x;
		_y->_M_parent = _x->_M_parent;
	 
		if (_x == _root)
			_root = _y;
		else if (_x == _x->_M_parent->_M_left)
			_x->_M_parent->_M_left = _y;
		else
			_x->_M_parent->_M_right = _y;
		_y->_M_left = _x;
		_x->_M_parent = _y;
	}
 
	void
	_rbt_rotate_right(_rbt_node_base* const _x, _rbt_node_base*& _root)
	{
		_rbt_node_base* const _y = _x->_M_left;
		_x->_M_left = _y->_M_right;
		if (_y->_M_right != 0)
			_y->_M_right->_M_parent = _x;
		_y->_M_parent = _x->_M_parent;
		if (_x == _root)
			_root = _y;
		else if (_x == _x->_M_parent->_M_right)
			_x->_M_parent->_M_right = _y;
		else
			_x->_M_parent->_M_left = _y;
		_y->_M_right = _x;
		_x->_M_parent = _y;
	}
 
	void
	_rbt_insert_and_rebalance(const bool _insert_left, _rbt_node_base* _x, _rbt_node_base* _p, _rbt_node_base& _header)
	{
		_rbt_node_base *& _root = _header._M_parent;
 
		_x->_M_parent = _p;
		_x->_M_left = 0;
		_x->_M_right = 0;
		_x->_M_color = _s_red;
 

		if (_insert_left)
		{
			_p->_M_left = _x;
 
			if (_p == &_header)
			{
				_header._M_parent = _x;
				_header._M_right = _x;
		 	}
			else if (_p == _header._M_left)
				_header._M_left = _x;
		}
		else
		{
			_p->_M_right = _x;
			if (_p == _header._M_right)
				_header._M_right = _x;
		}
		while (_x != _root && _x->_M_parent->_M_color == _s_red) 
		{
			_rbt_node_base* const _xpp = _x->_M_parent->_M_parent;
 			if (_x->_M_parent == _xpp->_M_left) 
			{
				_rbt_node_base* const _y = _xpp->_M_right;
				if (_y && _y->_M_color == _s_red) 
				{
		 			_x->_M_parent->_M_color = _s_black;
					_y->_M_color = _s_black;
					_xpp->_M_color = _s_red;
					_x = _xpp;
				}
				else 
				{
					if (_x == _x->_M_parent->_M_right) 
					{
						_x = _x->_M_parent;
						_rbt_rotate_left(_x, _root);
					}
					_x->_M_parent->_M_color = _s_black;
					_xpp->_M_color = _s_red;
					_rbt_rotate_right(_xpp, _root);
				}
			}
			else
			{
				_rbt_node_base* const _y = _xpp->_M_left;
				if (_y && _y->_M_color == _s_red) 
				{
		 			_x->_M_parent->_M_color = _s_black;
		 			_y->_M_color = _s_black;
		 			_xpp->_M_color = _s_red;
		 			_x = _xpp;
				}
				else
				{
					if (_x == _x->_M_parent->_M_left) 
					{
			 			_x = _x->_M_parent;
			 			_rbt_rotate_right(_x, _root);
					}
					_x->_M_parent->_M_color = _s_black;
					_xpp->_M_color = _s_red;
					_rbt_rotate_left(_xpp, _root);
				}
			}
		}
		_root->_M_color = _s_black;
	}
 
	_rbt_node_base*
	_rbt_rebalance_for_erase(_rbt_node_base* const _z, _rbt_node_base& _header)
	{
		_rbt_node_base *& _root = _header._M_parent;
		_rbt_node_base *& _leftmost = _header._M_left;
		_rbt_node_base *& _rightmost = _header._M_right;
		_rbt_node_base* _y = _z;
		_rbt_node_base* _x = 0;
		_rbt_node_base* _x_parent = 0;
 
		if (_y->_M_left == 0)
			_x = _y->_M_right;
		else
		{
			if (_y->_M_right == 0)
				_x = _y->_M_left;
			else
			{
				_y = _y->_M_right;
				while (_y->_M_left != 0)
					_y = _y->_M_left;
				_x = _y->_M_right;
			}
		}
		if (_y != _z) 
		{
			_z->_M_left->_M_parent = _y; 
			_y->_M_left = _z->_M_left;
			if (_y != _z->_M_right) 
			{
				_x_parent = _y->_M_parent;
				if (_x) _x->_M_parent = _y->_M_parent;
				_y->_M_parent->_M_left = _x;
				_y->_M_right = _z->_M_right;
				_z->_M_right->_M_parent = _y;
			}
			else
				_x_parent = _y;  
			if (_root == _z)
				_root = _y;
			else if (_z->_M_parent->_M_left == _z)
				_z->_M_parent->_M_left = _y;
			else 
				_z->_M_parent->_M_right = _y;
			_y->_M_parent = _z->_M_parent;
			std::swap(_y->_M_color, _z->_M_color);
			_y = _z;
		}
		else
		{
			_x_parent = _y->_M_parent;
			if (_x)
				_x->_M_parent = _y->_M_parent;	
	 		if (_root == _z)
				_root = _x;
			else
			{
				if (_z->_M_parent->_M_left == _z)
					_z->_M_parent->_M_left = _x;
				else
					_z->_M_parent->_M_right = _x;
			}
			if (_leftmost == _z)
			{
				if (_z->_M_right == 0)
					_leftmost = _z->_M_parent;
				else
					_leftmost = _rbt_node_base::_S_minimum(_x);
			}
	 		if (_rightmost == _z)
			{
				if (_z->_M_left == 0)
					_rightmost = _z->_M_parent;  
				else
					_rightmost = _rbt_node_base::_S_maximum(_x);
			}
		}
		if (_y->_M_color != _s_red) 
		{ 
	 		while (_x != _root && (_x == 0 || _x->_M_color == _s_black))
			{
				if (_x == _x_parent->_M_left) 
				{
					_rbt_node_base* _w = _x_parent->_M_right;
					if (_w->_M_color == _s_red) 
					{
						_w->_M_color = _s_black;
						_x_parent->_M_color = _s_red;
						_rbt_rotate_left(_x_parent, _root);
						_w = _x_parent->_M_right;
					}
					if ((_w->_M_left == 0 || _w->_M_left->_M_color == _s_black) && (_w->_M_right == 0 || _w->_M_right->_M_color == _s_black)) 
					{
						_w->_M_color = _s_red;
						_x = _x_parent;
						_x_parent = _x_parent->_M_parent;
					}
					else 
			 		{
						if (_w->_M_right == 0 || _w->_M_right->_M_color == _s_black) 
						{
							_w->_M_left->_M_color = _s_black;
							_w->_M_color = _s_red;
							_rbt_rotate_right(_w, _root);
							_w = _x_parent->_M_right;
						}
						_w->_M_color = _x_parent->_M_color;
						_x_parent->_M_color = _s_black;
						if (_w->_M_right) 
							_w->_M_right->_M_color = _s_black;
						_rbt_rotate_left(_x_parent, _root);
						break;
					}
				}
				else 
				{	
					_rbt_node_base* _w = _x_parent->_M_left;
					if (_w->_M_color == _s_red) 
					{
						_w->_M_color = _s_black;
						_x_parent->_M_color = _s_red;
						_rbt_rotate_right(_x_parent, _root);
						_w = _x_parent->_M_left;
					}
					if ((_w->_M_right == 0 || _w->_M_right->_M_color == _s_black) && (_w->_M_left == 0 || _w->_M_left->_M_color == _s_black)) 
			 		{
						_w->_M_color = _s_red;
						_x = _x_parent;
						_x_parent = _x_parent->_M_parent;
					} 
					else 
					{
						if (_w->_M_left == 0 || _w->_M_left->_M_color == _s_black) 
						{
							_w->_M_right->_M_color = _s_black;
							_w->_M_color = _s_red;
							_rbt_rotate_left(_w, _root);
							_w = _x_parent->_M_left;
						}
						_w->_M_color = _x_parent->_M_color;
						_x_parent->_M_color = _s_black;
						if (_w->_M_left) 
				 			_w->_M_left->_M_color = _s_black;
						_rbt_rotate_right(_x_parent, _root);
						break;
					}
				}
			}
			if (_x) _x->_M_color = _s_black;
		}
		return (_y);
	}
 
	unsigned int
	_rbt_black_count(const _rbt_node_base* _node, const _rbt_node_base* _root)
	{
		if (_node == 0)
			return (0);
		unsigned int _sum = 0;
		do
		{
			if (_node->_M_color == _s_black) 
				++_sum;
			if (_node == _root) 
				break;
			_node = _node->_M_parent;
		}
		while (1);
			return (_sum);
	}
};

#endif
