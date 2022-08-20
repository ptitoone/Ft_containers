#ifndef __MAP_HPP
# define __MAP_HPP

#include <functional>
#include "rb_tree.hpp"

namespace ft {

	template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator< ft::pair<const Key, T> > >
	class map
	{
		public:

			typedef Key						key_type;
			typedef T						mapped_type;
			typedef ft::pair<const Key, T>	value_type;
			typedef Compare					key_compare;
			typedef Allocator				allocator_type;

		public:

			class value_compare: public std::binary_function<value_type, value_type, bool>
  			{
  				friend class map<Key, T, Compare, Allocator>;
  				protected:

					Compare comp;

  					value_compare(Compare _c):
					comp(_c)
					{}

  				public:

  					bool
					operator()(const value_type& _x, const value_type& _y) const
					{
						return comp(_x.first, _y.first);
					}
			};

		private:

			template <class _Pair>
			struct _SelectFirst : public std::unary_function<_Pair, typename _Pair::first_type>
			{

				typename _Pair::first_type&	operator()(_Pair& _x) const
				{
					return _x.first;
				}
			 
				const typename _Pair::first_type&
				operator()(const _Pair& _x) const
				{
					return _x.first;
				}

			};

			typedef typename Allocator::template rebind<value_type>::other		_pair_allocator_type;
			typedef	ft::_rbt<key_type, value_type, _SelectFirst<value_type>,
							key_compare, _pair_allocator_type>					_rbt_t;
			_rbt_t																_M_rbt;
		
		public:
			typedef typename _pair_allocator_type::pointer				pointer;
			typedef typename _pair_allocator_type::const_pointer  		const_pointer;
			typedef typename _pair_allocator_type::reference			reference;
			typedef typename _pair_allocator_type::const_reference		const_reference;
			typedef typename _rbt_t::iterator							iterator;
			typedef typename _rbt_t::const_iterator						const_iterator;
			typedef typename _rbt_t::size_type							size_type;
			typedef typename _rbt_t::difference_type					difference_type;
			typedef typename _rbt_t::reverse_iterator					reverse_iterator;
			typedef typename _rbt_t::const_reverse_iterator				const_reverse_iterator;

			map():
			_M_rbt(Compare(), allocator_type())
			{}

			explicit
			map(const Compare& _Comp, const allocator_type& _a = allocator_type()):
			_M_rbt(_Comp, _a)
			{}

			map(const map& _x):
			_M_rbt(_x._M_rbt)
			{}

			template <typename _InputIterator>
			map(_InputIterator _first, _InputIterator _last):
			_M_rbt(Compare(), allocator_type())
			{
				_M_rbt.insert_unique(_first, _last);
			}
 
			template <typename _InputIterator>
			map(_InputIterator _first, _InputIterator _last, const Compare& _Comp,
				const allocator_type& _a = allocator_type()):
			_M_rbt(_Comp, _a)
			{
				_M_rbt.insert_unique(_first, _last);
			}
	 
			map&
			operator=(const map& _x)
			{
				_M_rbt = _x._M_rbt;
				return *this;
			}
	 
			allocator_type
			getAllocatorator() const
			{
				return _M_rbt.getAllocatorator();
			}
	 
			iterator
			begin()
			{
				return _M_rbt.begin();
			}
	 
			const_iterator
			begin() const
			{
				return _M_rbt.begin();
			}
	 
			iterator
			end()
			{
				return _M_rbt.end();
			}
	 
			const_iterator
			end() const
			{
				return _M_rbt.end();
			}
	 
			reverse_iterator
			rbegin()
			{
				return _M_rbt.rbegin();
			}
	 
			const_reverse_iterator
			rbegin() const
			{
				return _M_rbt.rbegin();
			}
	 
			reverse_iterator
			rend()
			{
				return _M_rbt.rend();
			}
	 
			const_reverse_iterator
			rend() const
			{
				return _M_rbt.rend();
			}
	 
			bool
			empty() const
			{
				return _M_rbt.empty();
			}
	 
			size_type
			size() const
			{
				return _M_rbt.size();
			}
	 
			size_type
			max_size() const
			{
				return _M_rbt.max_size();
			}
	 
			mapped_type&
			operator[](const key_type& _K)
			{
				iterator _i = lower_bound(_K);

				if (_i == end() || key_comp()(_K, (*_i).first))
					_i = insert(_i, value_type(_K, mapped_type()));
				return (*_i).second;
			}
	 
			mapped_type&
			at(const key_type& _K)
			{
				iterator _i = lower_bound(_K);
				if (_i == end() || key_comp()(_K, (*_i).first))
					std::range_error("map::at");
				return (*_i).second;
			}
	 
			const mapped_type&
			at(const key_type& _K) const
			{
				const_iterator _i = lower_bound(_K);
				if (_i == end() || key_comp()(_K, (*_i).first))
					std::range_error("map::at");
				return (*_i).second;
			}
	 
			ft::pair<iterator, bool>
			insert(const value_type& _x)
			{
				return _M_rbt.insert_unique(_x);
			}

			iterator
			insert(iterator position, const value_type& _x)
			{
				return _M_rbt.insert_unique(position, _x);
			}
	 
			template <typename _InputIterator>
			void
			insert(_InputIterator _first, _InputIterator _last)
			{
				_M_rbt.insert_unique(_first, _last);
			}
	 
			void
			erase(iterator _position)
			{
				_M_rbt.erase(_position);
			}
	 
			size_type
			erase(const key_type& _x)
			{
				return _M_rbt.erase(_x);
			}

			void
			erase(iterator _first, iterator _last)
			{
				_M_rbt.erase(_first, _last);
			}
	 
			void
			swap(map& _x)
			{
				_M_rbt.swap(_x._M_rbt);
			}
	 
			void
			clear()
			{
				_M_rbt.clear();
			}
	 
			key_compare
			key_comp() const
			{
				return _M_rbt.key_comp();
			}
	 
			value_compare
			value_comp() const
			{
				return value_compare(_M_rbt.key_comp());
			}
	 
			iterator
			find(const key_type& _x)
			{
				return _M_rbt.find(_x);
			}

			const_iterator
			find(const key_type& _x) const
			{
				return _M_rbt.find(_x);
			}
	 
			size_type
			count(const key_type& _x) const
			{
				return _M_rbt.find(_x) == _M_rbt.end() ? 0 : 1;
			}
	 
			iterator
			lower_bound(const key_type& _x)
			{
				return _M_rbt.lower_bound(_x);
			}
	 
			const_iterator
			lower_bound(const key_type& _x) const
			{
				return _M_rbt.lower_bound(_x);
			}
	 
			iterator
			upper_bound(const key_type& _x)
			{
				return _M_rbt.upper_bound(_x);
			}
	 
			const_iterator
			upper_bound(const key_type& _x) const
			{
				return _M_rbt.upper_bound(_x);
			}
	 
			ft::pair<iterator, iterator>
			equal_range(const key_type& _x)
			{
				return _M_rbt.equal_range(_x);
			}
	 
			ft::pair<const_iterator, const_iterator>
			equal_range(const key_type& _x) const
			{
				return _M_rbt.equal_range(_x);
			}
	 
			template <typename K1, typename _T1, typename _c1, typename _a1>
			friend bool	operator== (const map<K1, _T1, _c1, _a1>&,
									 const map<K1, _T1, _c1, _a1>&);
	 
			template <typename K1, typename _T1, typename _c1, typename _a1>
			friend bool	operator< (const map<K1, _T1, _c1, _a1>&,
									const map<K1, _T1, _c1, _a1>&);
	};
 
	template <typename Key, typename T, typename Compare, typename Allocator>
	inline bool	operator==(	const map<Key, T, Compare, Allocator>& _x,
							const map<Key, T, Compare, Allocator>& _y )
	{
		return (_x._M_rbt == _y._M_rbt);
	}
 
	template <typename Key, typename T, typename Compare, typename Allocator>
	inline bool	operator<(	const map<Key, T, Compare, Allocator>& _x,
							const map<Key, T, Compare, Allocator>& _y )
	{
		return (_x._M_rbt < _y._M_rbt);
	}
 
	template <typename Key, typename T, typename Compare, typename Allocator>
	inline bool	operator!=(	const map<Key, T, Compare, Allocator>& _x,
							const map<Key, T, Compare, Allocator>& _y )
	{
		return (!(_x == _y));
	}
 
	template <typename Key, typename T, typename Compare, typename Allocator>
	inline bool	operator>(	const map<Key, T, Compare, Allocator>& _x,
							const map<Key, T, Compare, Allocator>& _y )
	{
		return (_y < _x);
	}
 
	template <typename Key, typename T, typename Compare, typename Allocator>
	inline bool	operator<=(	const map<Key, T, Compare, Allocator>& _x,
							const map<Key, T, Compare, Allocator>& _y )
	{
		return (!(_y < _x));
	}
 
	template <typename Key, typename T, typename Compare, typename Allocator>
	inline bool	operator>=(	const map<Key, T, Compare, Allocator>& _x,
							const map<Key, T, Compare, Allocator>& _y )
	{
		return (!(_x < _y));
	}
 
	template <typename Key, typename T, typename Compare, typename Allocator>
	inline void	swap(	map<Key, T, Compare, Allocator>& _x,
						map<Key, T, Compare, Allocator>& _y )
	{
		_x.swap(_y);
	}
};

#endif
