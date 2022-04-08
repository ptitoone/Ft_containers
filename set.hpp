#ifndef __SET_H
# define __SET_H

#include <functional>
#include "rb_tree.hpp"

namespace ft
{
	template< class _key, class _compare = std::less<_key>, class _alloc = std::allocator<_key> >
	class set
	{
		public:
			typedef _key		key_type;
			typedef _key		value_type;
			typedef _compare	key_compare;
			typedef _compare	value_compare;
		private:
			template<typename T>
			struct _identity : public std::unary_function<T, T>
			{
				T&	operator()( T& _src ) const { return _src; }
			
				const T&	operator()( const T& _src ) const { return _src; }
			};

			typedef	ft::_rbt<key_type, value_type, _identity<value_type>, key_compare, _alloc>	_rbt_t;
			_rbt_t																				_M_rbt;

		public:
			typedef typename _alloc::pointer												pointer;
			typedef typename _alloc::const_pointer											const_pointer;
			typedef typename _alloc::reference												reference;
			typedef typename _alloc::const_reference										const_reference;

			typedef typename _rbt_t::const_iterator											iterator;
			typedef typename _rbt_t::const_iterator											const_iterator;
			typedef typename _rbt_t::const_reverse_iterator									reverse_iterator;
			typedef typename _rbt_t::const_reverse_iterator									const_reverse_iterator;
			typedef typename _rbt_t::size_type												size_type;
			typedef typename _rbt_t::difference_type										difference_type;
			typedef typename _rbt_t::allocator_type											allocator_type;
						set( void ): _M_rbt( _compare(), allocator_type() ) {}
			explicit	set( const _compare& _comp, const allocator_type& _allocate = allocator_type() ): _M_rbt( _comp, _allocate ) {}

			template<class _InputIterator>
												set( _InputIterator _first, _InputIterator _last ):
												_M_rbt( _compare(), allocator_type() )
												{ _M_rbt.insert_unique( _first, _last ); }
			template<class _InputIterator>
												set( _InputIterator _first, _InputIterator _last, const _compare& _comp, const allocator_type& _allocate = allocator_type() ):
												_M_rbt( _comp, _allocate )
												{ _M_rbt.insert_unique( _first, _last ); }
												set( const set<_key, _compare, _alloc>& _src ): _M_rbt( _src._M_rbt ) { }
			ft::set<_key, _compare, _alloc>&	operator=( const set<_key, _compare, _alloc>& _src )
												{
													_M_rbt = _src._M_rbt;
													return *this;
												}
			key_compare							key_comp() const { return _M_rbt.key_comp(); }
			value_compare						value_comp() const { return _M_rbt.key_comp(); }
			allocator_type						get_allocator() const { return _M_rbt.get_allocator(); }
			iterator							begin() const { return _M_rbt.begin(); }
			iterator							end() const { return _M_rbt.end(); }
			reverse_iterator					rbegin() const { return _M_rbt.rbegin(); }
			reverse_iterator					rend() const { return _M_rbt.rend(); }
			bool								empty() const { return _M_rbt.empty(); }
			size_type							size() const { return _M_rbt.size(); }
			size_type							max_size() const { return _M_rbt.max_size(); }
			void								swap( set<_key,_compare,_alloc>& _src ) { _M_rbt.swap( _src._M_rbt ); }
			pair<iterator, bool>				insert( const value_type& _x )
												{
													pair<typename _rbt_t::iterator, bool> _p = _M_rbt.insert_unique( _x );
													return pair<iterator, bool>( _p.first, _p.second );
												}
			iterator							insert( iterator _position, const value_type& _x )
												{
													typedef typename _rbt_t::iterator _rbt_t;
													return _M_rbt.insert_unique( ( _rbt_t& ) _position, _x );
												}
												template<class _InputIterator>
			void								insert( _InputIterator _first, _InputIterator _last ) { _M_rbt.insert_unique( _first, _last ); }
			void								erase( iterator _position )
												{
													typedef typename _rbt_t::iterator _rbt_t;
													_M_rbt.erase( ( _rbt_t& )_position );
												}
 			size_type							erase( const key_type& _x ) { return _M_rbt.erase( _x ); }
 			void								erase( iterator _first, iterator _last )
												{
													typedef typename _rbt_t::iterator _rbt_t;
													_M_rbt.erase( ( _rbt_t& )_first, ( _rbt_t& )_last );
												}
			void								clear() { _M_rbt.clear(); }
			size_type							count( const key_type& _x ) const { return _M_rbt.find( _x ) == _M_rbt.end() ? 0 : 1; }
			iterator							find( const key_type& _x ) { return _M_rbt.find( _x ); }
			const_iterator						find( const key_type& _x ) const { return _M_rbt.find( _x ); }
			iterator							lower_bound( const key_type& _x ) { return _M_rbt.lower_bound( _x ); }
			const_iterator						lower_bound( const key_type& _x ) const { return _M_rbt.lower_bound( _x ); }
			iterator							upper_bound( const key_type& _x ) { return _M_rbt.upper_bound( _x ); }
			const_iterator						upper_bound( const key_type& _x ) const	{ return _M_rbt.upper_bound( _x ); }
			pair<iterator,iterator>				equal_range( const key_type& _x ) { return _M_rbt.equal_range( _x ); }
			pair<const_iterator,const_iterator>	equal_range( const key_type& _x ) const { return _M_rbt.equal_range( _x ); }
			template<class _key1, class _compare1, class _alloc1>
			friend bool							operator== ( const set<_key1,_compare1,_alloc1>&, const set<_key1,_compare1,_alloc1>& );
			template<class _key1, class _compare1, class _alloc1>
			friend bool							operator< ( const set<_key1,_compare1,_alloc1>&, const set<_key1,_compare1,_alloc1>& );
	};

	template<class _key, class _compare, class _alloc>
	inline bool										operator==( const set<_key,_compare,_alloc>& _x, const set<_key,_compare,_alloc>& _y )
													{ return _x._M_rbt == _y._M_rbt; }
	template<class _key, class _compare, class _alloc>
	inline bool										operator<( const set<_key,_compare,_alloc>& _x, const set<_key,_compare,_alloc>& _y )
													{ return _x._M_rbt < _y._M_rbt; }
	template<class _key, class _compare, class _alloc>
	inline bool										operator!=( const set<_key,_compare,_alloc>& _x, const set<_key,_compare,_alloc>& _y )
													{ return !( _x == _y ); }
	template<class _key, class _compare, class _alloc>
	inline bool										operator>( const set<_key,_compare,_alloc>& _x, const set<_key,_compare,_alloc>& _y )
													{ return _y < _x; }
	template<class _key, class _compare, class _alloc>
	inline bool										operator<=( const set<_key,_compare,_alloc>& _x, const set<_key,_compare,_alloc>& _y )
													{ return !( _y < _x ); }
	template<class _key, class _compare, class _alloc>
	inline bool										operator>=( const set<_key,_compare,_alloc>& _x, const set<_key,_compare,_alloc>& _y )
													{ return !( _x < _y ); }
	template<class _key, class _compare, class _alloc>
	inline void										swap( set<_key,_compare,_alloc>& _x, set<_key,_compare,_alloc>& _y )
													{ _x.swap( _y ); }

};

#endif