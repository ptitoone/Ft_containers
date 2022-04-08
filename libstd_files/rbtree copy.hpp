   enum _RBT_color { _RBT_S_red = false, _RBT_S_black = true };
 
   struct _RBT_node_base
   {
     typedef _RBT_node_base* _Base_ptr;
     typedef const _RBT_node_base* _Const_Base_ptr;
 
     _RBT_color		_M_color;
     _Base_ptr		_M_parent;
     _Base_ptr		_M_left;
     _Base_ptr		_M_right;
 
     static _Base_ptr
     _RBT_S_minimum(_Base_ptr _x)
     {
       while (_x->_M_left != 0) _x = _x->_M_left;
       return _x;
     }
 
     static _Const_Base_ptr
     _RBT_S_minimum(_Const_Base_ptr _x)
     {
       while (_x->_M_left != 0) _x = _x->_M_left;
       return _x;
     }
 
     static _Base_ptr
     _RBT_S_maximum(_Base_ptr _x)
     {
       while (_x->_M_right != 0) _x = _x->_M_right;
       return _x;
     }
 
     static _Const_Base_ptr
     _RBT_S_maximum(_Const_Base_ptr _x)
     {
       while (_x->_M_right != 0) _x = _x->_M_right;
       return _x;
     }
   };
 
   template<typename _Val>
     struct _RBT_node : public _RBT_node_base
     {
       typedef _RBT_node<_Val>* _Link_type;
       _Val _M_value_field;
     };
/////////////////// 
   _RBT_node_base*
   _RBT_increment(_RBT_node_base* _x) throw ();
 
   const _RBT_node_base*
   _RBT_increment(const _RBT_node_base* _x) throw ();
 
   _RBT_node_base*
   _RBT_decrement(_RBT_node_base* _x) throw ();
 
   const _RBT_node_base*
   _RBT_decrement(const _RBT_node_base* _x) throw ();
///////////////////
   template<typename _Tp>
     struct _RBT_iterator
     {
       typedef _Tp  value_type;
       typedef _Tp& reference;
       typedef _Tp* pointer;
 
       typedef bidirectional_iterator_tag iterator_category;
       typedef ptrdiff_t                  difference_type;
 
       typedef _RBT_iterator<_Tp>        _Self;
       typedef _RBT_node_base::_Base_ptr _Base_ptr;
       typedef _RBT_node<_Tp>*           _Link_type;
 
       _RBT_iterator()
       : _M_node() { }
 
       explicit
       _RBT_iterator(_Link_type _x)
       : _M_node(_x) { }
 
       reference
       operator*() const
       { return static_cast<_Link_type>(_M_node)->_M_value_field; }
 
       pointer
       operator->() const
       { return std::_addressof(static_cast<_Link_type>
                 (_M_node)->_M_value_field); }
 
       _Self&
       operator++()
       {
     _M_node = _RBT_increment(_M_node);
     return *this;
       }
 
       _Self
       operator++(int)
       {
     _Self _tmp = *this;
     _M_node = _RBT_increment(_M_node);
     return _tmp;
       }
 
       _Self&
       operator--()
       {
     _M_node = _RBT_decrement(_M_node);
     return *this;
       }
 
       _Self
       operator--(int)
       {
     _Self _tmp = *this;
     _M_node = _RBT_decrement(_M_node);
     return _tmp;
       }
 
       bool
       operator==(const _Self& _x) const
       { return _M_node == _x._M_node; }
 
       bool
       operator!=(const _Self& _x) const
       { return _M_node != _x._M_node; }
 
       _Base_ptr _M_node;
   };
 
   template<typename _Tp>
     struct _RBT_const_iterator
     {
       typedef _Tp        value_type;
       typedef const _Tp& reference;
       typedef const _Tp* pointer;
 
       typedef _RBT_iterator<_Tp> iterator;
 
       typedef bidirectional_iterator_tag iterator_category;
       typedef ptrdiff_t                  difference_type;
 
       typedef _RBT_const_iterator<_Tp>        _Self;
       typedef _RBT_node_base::_Const_Base_ptr _Base_ptr;
       typedef const _RBT_node<_Tp>*           _Link_type;
 
       _RBT_const_iterator()
       : _M_node() { }
 
       explicit
       _RBT_const_iterator(_Link_type _x)
       : _M_node(_x) { }
 
       _RBT_const_iterator(const iterator& _it)
       : _M_node(_it._M_node) { }
 
       iterator
       _M_const_cast() const
       { return iterator(static_cast<typename iterator::_Link_type>
             (const_cast<typename iterator::_Base_ptr>(_M_node))); }
 
       reference
       operator*() const
       { return static_cast<_Link_type>(_M_node)->_M_value_field; }
 
       pointer
       operator->() const
       { return std::_addressof(static_cast<_Link_type>
                 (_M_node)->_M_value_field); }
 
       _Self&
       operator++()
       {
     _M_node = _RBT_increment(_M_node);
     return *this;
       }
 
       _Self
       operator++(int)
       {
     _Self _tmp = *this;
     _M_node = _RBT_increment(_M_node);
     return _tmp;
       }
 
       _Self&
       operator--()
       {
     _M_node = _RBT_decrement(_M_node);
     return *this;
       }
 
       _Self
       operator--(int)
       {
     _Self _tmp = *this;
     _M_node = _RBT_decrement(_M_node);
     return _tmp;
       }
 
       bool
       operator==(const _Self& _x) const
       { return _M_node == _x._M_node; }
 
       bool
       operator!=(const _Self& _x) const
       { return _M_node != _x._M_node; }
 
       _Base_ptr _M_node;
     };
 
   template<typename _Val>
     inline bool
     operator==(const _RBT_iterator<_Val>& _x,
                const _RBT_const_iterator<_Val>& _y)
     { return _x._M_node == _y._M_node; }
 
   template<typename _Val>
     inline bool
     operator!=(const _RBT_iterator<_Val>& _x,
                const _RBT_const_iterator<_Val>& _y)
     { return _x._M_node != _y._M_node; }
 
   void
   _RBT_insert_and_rebalance(const bool _insert_left,
                                 _RBT_node_base* _x,
                                 _RBT_node_base* _p,
                                 _RBT_node_base& _header) throw ();
 
   _RBT_node_base*
   _RBT_rebalance_for_erase(_RBT_node_base* const _z,
                    _RBT_node_base& _header) throw ();
 
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc = allocator<_Val> >
     class _RBT
     {
       typedef typename _Alloc::template rebind<_RBT_node<_Val> >::other
               _Node_allocator;
 
     protected:
       typedef _RBT_node_base*       _Base_ptr;
       typedef const _RBT_node_base*     _Const_Base_ptr;
 
     public:
       typedef _Key              key_type;
       typedef _Val              value_type;
       typedef value_type*           pointer;
       typedef const value_type*         const_pointer;
       typedef value_type&           reference;
       typedef const value_type&         const_reference;
       typedef _RBT_node<_Val>*      _Link_type;
       typedef const _RBT_node<_Val>*    _Const_Link_type;
       typedef size_t                size_type;
       typedef ptrdiff_t             difference_type;
       typedef _Alloc                allocator_type;
 
       _Node_allocator&
       _M_get_Node_allocator()
       { return *static_cast<_Node_allocator*>(&this->_M_impl); }
       
       const _Node_allocator&
       _M_get_Node_allocator() const
       { return *static_cast<const _Node_allocator*>(&this->_M_impl); }
 
       allocator_type
       get_allocator() const
       { return allocator_type(_M_get_Node_allocator()); }
 
     protected:
       _Link_type
       _M_get_node()
       { return _M_impl._Node_allocator::allocate(1); }
 
       void
       _M_put_node(_Link_type _p)
       { _M_impl._Node_allocator::deallocate(_p, 1); }
 
       _Link_type
       _M_create_node(const value_type& _x)
       {
     _Link_type _tmp = _M_get_node();
     try
       { get_allocator().construct
           (std::_addressof(_tmp->_M_value_field), _x); }
     catch(...)
       {
         _M_put_node(_tmp);
         _throw_exception_again;
       }
     return _tmp;
       }
 
       void
       _M_destroy_node(_Link_type _p)
       {
     get_allocator().destroy(std::_addressof(_p->_M_value_field));
     _M_put_node(_p);
       }
 
       _Link_type
       _M_clone_node(_Const_Link_type _x)
       {
     _Link_type _tmp = _M_create_node(_x->_M_value_field);
     _tmp->_M_color = _x->_M_color;
     _tmp->_M_left = 0;
     _tmp->_M_right = 0;
     return _tmp;
       }
 
     protected:
       template<typename _Key_compare, 
            bool _Is_pod_comparator = _is_pod(_Key_compare)>
         struct _RBT_impl : public _Node_allocator
         {
       _Key_compare      _M_key_compare;
       _RBT_node_base    _M_header;
       size_type         _M_node_count; // Keeps track of size of tree.
 
       _RBT_impl()
       : _Node_allocator(), _M_key_compare(), _M_header(),
         _M_node_count(0)
       { _M_initialize(); }
 
       _RBT_impl(const _Key_compare& _comp, const _Node_allocator& _a)
       : _Node_allocator(_a), _M_key_compare(_comp), _M_header(),
         _M_node_count(0)
       { _M_initialize(); }
 
     private:
       void
       _M_initialize()
       {
         this->_M_header._M_color = _RBT_S_red;
         this->_M_header._M_parent = 0;
         this->_M_header._M_left = &this->_M_header;
         this->_M_header._M_right = &this->_M_header;
       }     
     };
 
       _RBT_impl<_Compare> _M_impl;
 
     protected:
       _Base_ptr&
       _M_root()
       { return this->_M_impl._M_header._M_parent; }
 
       _Const_Base_ptr
       _M_root() const
       { return this->_M_impl._M_header._M_parent; }
 
       _Base_ptr&
       _M_leftmost()
       { return this->_M_impl._M_header._M_left; }
 
       _Const_Base_ptr
       _M_leftmost() const
       { return this->_M_impl._M_header._M_left; }
 
       _Base_ptr&
       _M_rightmost()
       { return this->_M_impl._M_header._M_right; }
 
       _Const_Base_ptr
       _M_rightmost() const
       { return this->_M_impl._M_header._M_right; }
 
       _Link_type
       _M_begin()
       { return static_cast<_Link_type>(this->_M_impl._M_header._M_parent); }
 
       _Const_Link_type
       _M_begin() const
       {
     return static_cast<_Const_Link_type>
       (this->_M_impl._M_header._M_parent);
       }
 
       _Link_type
       _M_end()
       { return static_cast<_Link_type>(&this->_M_impl._M_header); }
 
       _Const_Link_type
       _M_end() const
       { return static_cast<_Const_Link_type>(&this->_M_impl._M_header); }
 
       static const_reference
       _RBT_S_value(_Const_Link_type _x)
       { return _x->_M_value_field; }
 
       static const _Key&
       _RBT_S_key(_Const_Link_type _x)
       { return _KeyOfValue()(_RBT_S_value(_x)); }
 
       static _Link_type
       _RBT_S_left(_Base_ptr _x)
       { return static_cast<_Link_type>(_x->_M_left); }
 
       static _Const_Link_type
       _RBT_S_left(_Const_Base_ptr _x)
       { return static_cast<_Const_Link_type>(_x->_M_left); }
 
       static _Link_type
       _RBT_S_right(_Base_ptr _x)
       { return static_cast<_Link_type>(_x->_M_right); }
 
       static _Const_Link_type
       _RBT_S_right(_Const_Base_ptr _x)
       { return static_cast<_Const_Link_type>(_x->_M_right); }
 
       static const_reference
       _RBT_S_value(_Const_Base_ptr _x)
       { return static_cast<_Const_Link_type>(_x)->_M_value_field; }
 
       static const _Key&
       _RBT_S_key(_Const_Base_ptr _x)
       { return _KeyOfValue()(_RBT_S_value(_x)); }
 
       static _Base_ptr
       _RBT_S_minimum(_Base_ptr _x)
       { return _RBT_node_base::_RBT_S_minimum(_x); }
 
       static _Const_Base_ptr
       _RBT_S_minimum(_Const_Base_ptr _x)
       { return _RBT_node_base::_RBT_S_minimum(_x); }
 
       static _Base_ptr
       _RBT_S_maximum(_Base_ptr _x)
       { return _RBT_node_base::_RBT_S_maximum(_x); }
 
       static _Const_Base_ptr
       _RBT_S_maximum(_Const_Base_ptr _x)
       { return _RBT_node_base::_RBT_S_maximum(_x); }
 
     public:
       typedef _RBT_iterator<value_type>       iterator;
       typedef _RBT_const_iterator<value_type> const_iterator;
 
       typedef std::reverse_iterator<iterator>       reverse_iterator;
       typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
 
     private:
       ft::pair<_Base_ptr, _Base_ptr>
       _M_get_insert_unique_pos(const key_type& _k);
 
       ft::pair<_Base_ptr, _Base_ptr>
       _M_get_insert_equal_pos(const key_type& _k);
 
       ft::pair<_Base_ptr, _Base_ptr>
       _M_get_insert_hint_unique_pos(const_iterator _pos,
                     const key_type& _k);
 
       ft::pair<_Base_ptr, _Base_ptr>
       _M_get_insert_hint_equal_pos(const_iterator _pos,
                    const key_type& _k);
 
       iterator
       _M_insert_(_Base_ptr _x, _Base_ptr _y,
          const value_type& _v);
 
       iterator
       _M_insert_lower(_Base_ptr _y, const value_type& _v);
 
       iterator
       _M_insert_equal_lower(const value_type& _x);
 
       _Link_type
       _M_copy(_Const_Link_type _x, _Link_type _p);
 
       void
       _M_erase(_Link_type _x);
 
       iterator
       _M_lower_bound(_Link_type _x, _Link_type _y,
              const _Key& _k);
 
       const_iterator
       _M_lower_bound(_Const_Link_type _x, _Const_Link_type _y,
              const _Key& _k) const;
 
       iterator
       _M_upper_bound(_Link_type _x, _Link_type _y,
              const _Key& _k);
 
       const_iterator
       _M_upper_bound(_Const_Link_type _x, _Const_Link_type _y,
              const _Key& _k) const;
 
     public:
       _RBT() { }
 
       _RBT(const _Compare& _comp,
            const allocator_type& _a = allocator_type())
       : _M_impl(_comp, _Node_allocator(_a)) { }
 
       _RBT(const _RBT& _x)
       : _M_impl(_x._M_impl._M_key_compare, _x._M_get_Node_allocator())
       {
     if (_x._M_root() != 0)
       {
         _M_root() = _M_copy(_x._M_begin(), _M_end());
         _M_leftmost() = _RBT_S_minimum(_M_root());
         _M_rightmost() = _RBT_S_maximum(_M_root());
         _M_impl._M_node_count = _x._M_impl._M_node_count;
       }
       }
 
       ~_Rb_tree()
       { _M_erase(_M_begin()); }
 
       _RBT&
       operator=(const _RBT& _x);
 
       // Accessors.
       _Compare
       key_comp() const
       { return _M_impl._M_key_compare; }
 
       iterator
       begin()
       { 
     return iterator(static_cast<_Link_type>
             (this->_M_impl._M_header._M_left));
       }
 
       const_iterator
       begin() const
       { 
     return const_iterator(static_cast<_Const_Link_type>
                   (this->_M_impl._M_header._M_left));
       }
 
       iterator
       end()
       { return iterator(static_cast<_Link_type>(&this->_M_impl._M_header)); }
 
       const_iterator
       end() const
       { 
     return const_iterator(static_cast<_Const_Link_type>
                   (&this->_M_impl._M_header));
       }
 
       reverse_iterator
       rbegin()
       { return reverse_iterator(end()); }
 
       const_reverse_iterator
       rbegin() const
       { return const_reverse_iterator(end()); }
 
       reverse_iterator
       rend()
       { return reverse_iterator(begin()); }
 
       const_reverse_iterator
       rend() const
       { return const_reverse_iterator(begin()); }
 
       bool
       empty() const
       { return _M_impl._M_node_count == 0; }
 
       size_type
       size() const 
       { return _M_impl._M_node_count; }
 
       size_type
       max_size() const
       { return _M_get_Node_allocator().max_size(); }
 
       void
       swap(_Rb_tree& _t);      
 
       // Insert/erase.
       ft::pair<iterator, bool>
       _M_insert_unique(const value_type& _x);
 
       iterator
       _M_insert_equal(const value_type& _x);
 
       iterator
       _M_insert_unique_(const_iterator _position, const value_type& _x);
 
       iterator
       _M_insert_equal_(const_iterator _position, const value_type& _x);
 
       template<typename _InputIterator>
         void
         _M_insert_unique(_InputIterator _first, _InputIterator _last);
 
       template<typename _InputIterator>
         void
         _M_insert_equal(_InputIterator _first, _InputIterator _last);
 
     private:
       void
       _M_erase_aux(const_iterator _position);
 
       void
       _M_erase_aux(const_iterator _first, const_iterator _last);
 
     public:
       void
       erase(iterator _position)
       { _M_erase_aux(_position); }
 
       void
       erase(const_iterator _position)
       { _M_erase_aux(_position); }

       size_type
       erase(const key_type& _x);
 
       void
       erase(iterator _first, iterator _last)
       { _M_erase_aux(_first, _last); }
 
       void
       erase(const_iterator _first, const_iterator _last)
       { _M_erase_aux(_first, _last); }

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
       find(const key_type& _k);
 
       const_iterator
       find(const key_type& _k) const;
 
       size_type
       count(const key_type& _k) const;
 
       iterator
       lower_bound(const key_type& _k)
       { return _M_lower_bound(_M_begin(), _M_end(), _k); }
 
       const_iterator
       lower_bound(const key_type& _k) const
       { return _M_lower_bound(_M_begin(), _M_end(), _k); }
 
       iterator
       upper_bound(const key_type& _k)
       { return _M_upper_bound(_M_begin(), _M_end(), _k); }
 
       const_iterator
       upper_bound(const key_type& _k) const
       { return _M_upper_bound(_M_begin(), _M_end(), _k); }
 
       ft::pair<iterator, iterator>
       equal_range(const key_type& _k);
 
       ft::pair<const_iterator, const_iterator>
       equal_range(const key_type& _k) const;
 
       // Debugging.
       bool
       _rb_verify() const;
     };
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     inline bool
     operator==(const _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>& _x,
            const _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>& _y)
     {
       return _x.size() == _y.size()
          && ft::equal(_x.begin(), _x.end(), _y.begin());
     }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     inline bool
     operator<(const _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>& _x,
           const _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>& _y)
     {
       return ft::lexicographical_compare(_x.begin(), _x.end(), 
                       _y.begin(), _y.end());
     }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     inline bool
     operator!=(const _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>& _x,
            const _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>& _y)
     { return !(_x == _y); }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     inline bool
     operator>(const _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>& _x,
           const _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>& _y)
     { return _y < _x; }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     inline bool
     operator<=(const _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>& _x,
            const _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>& _y)
     { return !(_y < _x); }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     inline bool
     operator>=(const _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>& _x,
            const _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>& _y)
     { return !(_x < _y); }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     inline void
     swap(_RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>& _x,
      _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>& _y)
     { _x.swap(_y); }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>&
     _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
     operator=(const _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>& _x)
     {
       if (this != &_x)
     {
       // Note that _Key may be a constant type.
       clear();
       _M_impl._M_key_compare = _x._M_impl._M_key_compare;
       if (_x._M_root() != 0)
         {
           _M_root() = _M_copy(_x._M_begin(), _M_end());
           _M_leftmost() = _RBT_S_minimum(_M_root());
           _M_rightmost() = _RBT_S_maximum(_M_root());
           _M_impl._M_node_count = _x._M_impl._M_node_count;
         }
     }
       return *this;
     }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     typename _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator
     _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
     _M_insert_(_Base_ptr _x, _Base_ptr _p, const _Val& _v)
     {
       bool _insert_left = (_x != 0 || _p == _M_end()
                 || _M_impl._M_key_compare(_KeyOfValue()(_v),
                               _RBT_S_key(_p)));
 
       _Link_type _z = _M_create_node(_GLIBCXX_FORWARD(_Arg, _v));
 
       _RBT_insert_and_rebalance(_insert_left, _z, _p,
                     this->_M_impl._M_header);
       ++_M_impl._M_node_count;
       return iterator(_z);
     }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     typename _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator
     _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
     _M_insert_lower(_Base_ptr _p, const _Val& _v)
     {
       bool _insert_left = (_p == _M_end()
                 || !_M_impl._M_key_compare(_RBT_S_key(_p),
                                _KeyOfValue()(_v)));
 
       _Link_type _z = _M_create_node(_GLIBCXX_FORWARD(_Arg, _v));
 
       _RBT_insert_and_rebalance(_insert_left, _z, _p,
                     this->_M_impl._M_header);
       ++_M_impl._M_node_count;
       return iterator(_z);
     }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     typename _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator
     _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
     _M_insert_equal_lower(const _Val& _v)
     {
       _Link_type _x = _M_begin();
       _Link_type _y = _M_end();
       while (_x != 0)
     {
       _y = _x;
       _x = !_M_impl._M_key_compare(_RBT_S_key(_x), _KeyOfValue()(_v)) ?
             _RBT_S_left(_x) : _RBT_S_right(_x);
     }
       return _M_insert_lower(_y, _GLIBCXX_FORWARD(_Arg, _v));
     }
 
   template<typename _Key, typename _Val, typename _KoV,
            typename _Compare, typename _Alloc>
     typename _RBT<_Key, _Val, _KoV, _Compare, _Alloc>::_Link_type
     _RBT<_Key, _Val, _KoV, _Compare, _Alloc>::
	 _M_copy(_Const_Link_type _x, _Link_type _p)
     {
       _Link_type _top = _M_clone_node(_x);
       _top->_M_parent = _p;
 
       try
     {
       if (_x->_M_right)
         _top->_M_right = _M_copy(_RBT_S_right(_x), _top);
       _p = _top;
       _x = _RBT_S_left(_x);
 
       while (_x != 0)
         {
           _Link_type _y = _M_clone_node(_x);
           _p->_M_left = _y;
           _y->_M_parent = _p;
           if (_x->_M_right)
         _y->_M_right = _M_copy(_RBT_S_right(_x), _y);
           _p = _y;
           _x = _RBT_S_left(_x);
         }
     }
       catch(...)
     {
       _M_erase(_top);
       _throw_exception_again;
     }
       return _top;
     }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     void
     _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
     _M_erase(_Link_type _x)
     {
       // Erase without rebalancing.
       while (_x != 0)
     {
       _M_erase(_RBT_S_right(_x));
       _Link_type _y = _RBT_S_left(_x);
       _M_destroy_node(_x);
       _x = _y;
     }
     }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     typename _RBT<_Key, _Val, _KeyOfValue,
               _Compare, _Alloc>::iterator
     _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
     _M_lower_bound(_Link_type _x, _Link_type _y,
            const _Key& _k)
     {
       while (_x != 0)
     if (!_M_impl._M_key_compare(_RBT_S_key(_x), _k))
       _y = _x, _x = _RBT_S_left(_x);
     else
       _x = _RBT_S_right(_x);
       return iterator(_y);
     }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     typename _RBT<_Key, _Val, _KeyOfValue,
               _Compare, _Alloc>::const_iterator
     _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
     _M_lower_bound(_Const_Link_type _x, _Const_Link_type _y,
            const _Key& _k) const
     {
       while (_x != 0)
     if (!_M_impl._M_key_compare(_RBT_S_key(_x), _k))
       _y = _x, _x = _RBT_S_left(_x);
     else
       _x = _RBT_S_right(_x);
       return const_iterator(_y);
     }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     typename _RBT<_Key, _Val, _KeyOfValue,
               _Compare, _Alloc>::iterator
     _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
     _M_upper_bound(_Link_type _x, _Link_type _y,
            const _Key& _k)
     {
       while (_x != 0)
     if (_M_impl._M_key_compare(_k, _RBT_S_key(_x)))
       _y = _x, _x = _RBT_S_left(_x);
     else
       _x = _RBT_S_right(_x);
       return iterator(_y);
     }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     typename _RBT<_Key, _Val, _KeyOfValue,
               _Compare, _Alloc>::const_iterator
     _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
     _M_upper_bound(_Const_Link_type _x, _Const_Link_type _y,
            const _Key& _k) const
     {
       while (_x != 0)
     if (_M_impl._M_key_compare(_k, _RBT_S_key(_x)))
       _y = _x, _x = _RBT_S_left(_x);
     else
       _x = _RBT_S_right(_x);
       return const_iterator(_y);
     }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     ft::pair<typename _RBT<_Key, _Val, _KeyOfValue,
                _Compare, _Alloc>::iterator,
      typename _RBT<_Key, _Val, _KeyOfValue,
                _Compare, _Alloc>::iterator>
     _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
     equal_range(const _Key& _k)
     {
       _Link_type _x = _M_begin();
       _Link_type _y = _M_end();
       while (_x != 0)
     {
       if (_M_impl._M_key_compare(_RBT_S_key(_x), _k))
         _x = _RBT_S_right(_x);
       else if (_M_impl._M_key_compare(_k, _RBT_S_key(_x)))
         _y = _x, _x = _RBT_S_left(_x);
       else
         {
           _Link_type _xu(_x), _yu(_y);
           _y = _x, _x = _RBT_S_left(_x);
           _xu = _RBT_S_right(_xu);
           return ft::pair<iterator,
                   iterator>(_M_lower_bound(_x, _y, _k),
                     _M_upper_bound(_xu, _yu, _k));
         }
     }
       return ft::pair<iterator, iterator>(iterator(_y),
                       iterator(_y));
     }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     ft::pair<typename _RBT<_Key, _Val, _KeyOfValue,
                _Compare, _Alloc>::const_iterator,
      typename _RBT<_Key, _Val, _KeyOfValue,
                _Compare, _Alloc>::const_iterator>
     _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
     equal_range(const _Key& _k) const
     {
       _Const_Link_type _x = _M_begin();
       _Const_Link_type _y = _M_end();
       while (_x != 0)
     {
       if (_M_impl._M_key_compare(_RBT_S_key(_x), _k))
         _x = _RBT_S_right(_x);
       else if (_M_impl._M_key_compare(_k, _RBT_S_key(_x)))
         _y = _x, _x = _RBT_S_left(_x);
       else
         {
           _Const_Link_type _xu(_x), _yu(_y);
           _y = _x, _x = _RBT_S_left(_x);
           _xu = _RBT_S_right(_xu);
           return ft::pair<const_iterator,
                   const_iterator>(_M_lower_bound(_x, _y, _k),
                       _M_upper_bound(_xu, _yu, _k));
         }
     }
       return ft::pair<const_iterator, const_iterator>(const_iterator(_y),
                           const_iterator(_y));
     }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     void
     _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
     swap(_Rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>& _t)
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
       // No need to swap header's color as it does not change.
       std::swap(this->_M_impl._M_node_count, _t._M_impl._M_node_count);
       std::swap(this->_M_impl._M_key_compare, _t._M_impl._M_key_compare);
       
       // _GLIBCXX_RESOLVE_LIB_DEFECTS
       // 431. Swapping containers with unequal allocators.
       std::_alloc_swap<_Node_allocator>::
     _RBT_S_do_it(_M_get_Node_allocator(), _t._M_get_Node_allocator());
     }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     ft::pair<typename _RBT<_Key, _Val, _KeyOfValue,
                _Compare, _Alloc>::_Base_ptr,
      typename _RBT<_Key, _Val, _KeyOfValue,
                _Compare, _Alloc>::_Base_ptr>
     _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
     _M_get_insert_unique_pos(const key_type& _k)
     {
       typedef ft::pair<_Base_ptr, _Base_ptr> _Res;
       _Link_type _x = _M_begin();
       _Link_type _y = _M_end();
       bool _comp = true;
       while (_x != 0)
     {
       _y = _x;
       _comp = _M_impl._M_key_compare(_k, _RBT_S_key(_x));
       _x = _comp ? _RBT_S_left(_x) : _RBT_S_right(_x);
     }
       iterator _j = iterator(_y);
       if (_comp)
     {
       if (_j == begin())
         return _Res(_x, _y);
       else
         --_j;
     }
       if (_M_impl._M_key_compare(_RBT_S_key(_j._M_node), _k))
     return _Res(_x, _y);
       return _Res(_j._M_node, 0);
     }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     ft::pair<typename _RBT<_Key, _Val, _KeyOfValue,
                _Compare, _Alloc>::_Base_ptr,
      typename _RBT<_Key, _Val, _KeyOfValue,
                _Compare, _Alloc>::_Base_ptr>
     _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
     _M_get_insert_equal_pos(const key_type& _k)
     {
       typedef ft::pair<_Base_ptr, _Base_ptr> _Res;
       _Link_type _x = _M_begin();
       _Link_type _y = _M_end();
       while (_x != 0)
     {
       _y = _x;
       _x = _M_impl._M_key_compare(_k, _RBT_S_key(_x)) ?
             _RBT_S_left(_x) : _RBT_S_right(_x);
     }
       return _Res(_x, _y);
     }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     ft::pair<typename _RBT<_Key, _Val, _KeyOfValue,
                _Compare, _Alloc>::iterator, bool>
     _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
     _M_insert_unique(const _Val& _v)
     {
       typedef ft::pair<iterator, bool> _Res;
       ft::pair<_Base_ptr, _Base_ptr> _res
     = _M_get_insert_unique_pos(_KeyOfValue()(_v));
 
       if (_res.second)
     return _Res(_M_insert_(_res.first, _res.second,
                    _GLIBCXX_FORWARD(_Arg, _v)),
             true);
 
       return _Res(iterator(static_cast<_Link_type>(_res.first)), false);
     }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     typename _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator
     _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
     _M_insert_equal(const _Val& _v)
     {
       ft::pair<_Base_ptr, _Base_ptr> _res
     = _M_get_insert_equal_pos(_KeyOfValue()(_v));
       return _M_insert_(_res.first, _res.second, _GLIBCXX_FORWARD(_Arg, _v));
     }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     ft::pair<typename _RBT<_Key, _Val, _KeyOfValue,
                _Compare, _Alloc>::_Base_ptr,
          typename _RBT<_Key, _Val, _KeyOfValue,
                _Compare, _Alloc>::_Base_ptr>
     _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
     _M_get_insert_hint_unique_pos(const_iterator _position,
                   const key_type& _k)
     {
       iterator _pos = _position._M_const_cast();
       typedef ft::pair<_Base_ptr, _Base_ptr> _Res;
 
       // end()
       if (_pos._M_node == _M_end())
     {
       if (size() > 0
           && _M_impl._M_key_compare(_RBT_S_key(_M_rightmost()), _k))
         return _Res(0, _M_rightmost());
       else
         return _M_get_insert_unique_pos(_k);
     }
       else if (_M_impl._M_key_compare(_k, _RBT_S_key(_pos._M_node)))
     {
       // First, try before...
       iterator _before = _pos;
       if (_pos._M_node == _M_leftmost()) // begin()
         return _Res(_M_leftmost(), _M_leftmost());
       else if (_M_impl._M_key_compare(_RBT_S_key((--_before)._M_node), _k))
         {
           if (_RBT_S_right(_before._M_node) == 0)
         return _Res(0, _before._M_node);
           else
         return _Res(_pos._M_node, _pos._M_node);
         }
       else
         return _M_get_insert_unique_pos(_k);
     }
       else if (_M_impl._M_key_compare(_RBT_S_key(_pos._M_node), _k))
     {
       // ... then try after.
       iterator _after = _pos;
       if (_pos._M_node == _M_rightmost())
         return _Res(0, _M_rightmost());
       else if (_M_impl._M_key_compare(_k, _RBT_S_key((++_after)._M_node)))
         {
           if (_RBT_S_right(_pos._M_node) == 0)
         return _Res(0, _pos._M_node);
           else
         return _Res(_after._M_node, _after._M_node);
         }
       else
         return _M_get_insert_unique_pos(_k);
     }
       else
     // Equivalent keys.
     return _Res(_pos._M_node, 0);
     }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     typename _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator
     _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
     _M_insert_unique_(const_iterator _position, const _Val& _v)
     {
       ft::pair<_Base_ptr, _Base_ptr> _res
     = _M_get_insert_hint_unique_pos(_position, _KeyOfValue()(_v));
 
       if (_res.second)
     return _M_insert_(_res.first, _res.second,
               _GLIBCXX_FORWARD(_Arg, _v));
       return iterator(static_cast<_Link_type>(_res.first));
     }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
    ft::pair<typename _RBT<_Key, _Val, _KeyOfValue,
                _Compare, _Alloc>::_Base_ptr,
          typename _RBT<_Key, _Val, _KeyOfValue,
                _Compare, _Alloc>::_Base_ptr>
    _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
	_M_get_insert_hint_equal_pos(const_iterator _position, const key_type& _k)
     
       iterator _pos = _position._M_const_cast();
       typedef ft::pair<_Base_ptr, _Base_ptr> _Res;
 
       // end()
    if (_pos._M_node == _M_end())
    {
       if (size() > 0
           && !_M_impl._M_key_compare(_k, _RBT_S_key(_M_rightmost())))
         return _Res(0, _M_rightmost());
       else
         return _M_get_insert_equal_pos(_k);
    }
    else if (!_M_impl._M_key_compare(_RBT_S_key(_pos._M_node), _k))
    {
       iterator _before = _pos;
      	 if (_pos._M_node == _M_leftmost()) // begin()
        	return _Res(_M_leftmost(), _M_leftmost());
       	else if (!_M_impl._M_key_compare(_k, _RBT_S_key((--_before)._M_node)))
        {
        	if (_RBT_S_right(_before._M_node) == 0)
        		return _Res(0, _before._M_node);
        	else
        		return _Res(_pos._M_node, _pos._M_node);
        }
		else
        	return _M_get_insert_equal_pos(_k);
    }
    else
    {
       iterator _after = _pos;
       if (_pos._M_node == _M_rightmost())
         return _Res(0, _M_rightmost());
       else if (!_M_impl._M_key_compare(_RBT_S_key((++_after)._M_node), _k))
         {
           if (_RBT_S_right(_pos._M_node) == 0)
         return _Res(0, _pos._M_node);
           else
         return _Res(_after._M_node, _after._M_node);
         }
       else
         return _Res(0, 0);
    }
    }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     typename _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::iterator
     _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
     _M_insert_equal_(const_iterator _position, const _Val& _v)
     {
       ft::pair<_Base_ptr, _Base_ptr> _res
     = _M_get_insert_hint_equal_pos(_position, _KeyOfValue()(_v));
 
       if (_res.second)
     return _M_insert_(_res.first, _res.second,
               _GLIBCXX_FORWARD(_Arg, _v));
 
       return _M_insert_equal_lower(_GLIBCXX_FORWARD(_Arg, _v));
     }
 
   template<typename _Key, typename _Val, typename _KoV,
            typename _Cmp, typename _Alloc>
     template<class _II>
       void
       _RBT<_Key, _Val, _KoV, _Cmp, _Alloc>::
       _M_insert_unique(_II _first, _II _last)
       {
     for (; _first != _last; ++_first)
       _M_insert_unique_(end(), *_first);
       }
 
   template<typename _Key, typename _Val, typename _KoV,
            typename _Cmp, typename _Alloc>
     template<class _II>
       void
       _RBT<_Key, _Val, _KoV, _Cmp, _Alloc>::
       _M_insert_equal(_II _first, _II _last)
       {
     for (; _first != _last; ++_first)
       _M_insert_equal_(end(), *_first);
       }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     void
     _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
     _M_erase_aux(const_iterator _position)
     {
       _Link_type _y =
     static_cast<_Link_type>(_RBT_rebalance_for_erase
                 (const_cast<_Base_ptr>(_position._M_node),
                  this->_M_impl._M_header));
       _M_destroy_node(_y);
       --_M_impl._M_node_count;
     }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     void
     _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
     _M_erase_aux(const_iterator _first, const_iterator _last)
     {
       if (_first == begin() && _last == end())
     clear();
       else
     while (_first != _last)
       erase(_first++);
     }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     typename _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::size_type
     _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
     erase(const _Key& _x)
     {
       ft::pair<iterator, iterator> _p = equal_range(_x);
       const size_type _old_size = size();
       erase(_p.first, _p.second);
       return _old_size - size();
     }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     void
     _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
     erase(const _Key* _first, const _Key* _last)
     {
       while (_first != _last)
     erase(*_first++);
     }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     typename _RBT<_Key, _Val, _KeyOfValue,
               _Compare, _Alloc>::iterator
     _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
     find(const _Key& _k)
     {
       iterator _j = _M_lower_bound(_M_begin(), _M_end(), _k);
       return (_j == end()
           || _M_impl._M_key_compare(_k,
                     _RBT_S_key(_j._M_node))) ? end() : _j;
     }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     typename _RBT<_Key, _Val, _KeyOfValue,
               _Compare, _Alloc>::const_iterator
     _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
     find(const _Key& _k) const
     {
       const_iterator _j = _M_lower_bound(_M_begin(), _M_end(), _k);
       return (_j == end()
           || _M_impl._M_key_compare(_k, 
                     _RBT_S_key(_j._M_node))) ? end() : _j;
     }
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     typename _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::size_type
     _RBT<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::
     count(const _Key& _k) const
     {
       ft::pair<const_iterator, const_iterator> _p = equal_range(_k);
       const size_type _n = std::distance(_p.first, _p.second);
       return _n;
     }
 
   unsigned int
   _RBT_black_count(const _RBT_node_base* _node,
                        const _RBT_node_base* _root) throw ();
 
   template<typename _Key, typename _Val, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
     bool
     _RBT<_Key,_Val,_KeyOfValue,_Compare,_Alloc>::_rb_verify() const
     {
       if (_M_impl._M_node_count == 0 || begin() == end())
     return _M_impl._M_node_count == 0 && begin() == end()
            && this->_M_impl._M_header._M_left == _M_end()
            && this->_M_impl._M_header._M_right == _M_end();
 
       unsigned int _len = _RBT_black_count(_M_leftmost(), _M_root());
       for (const_iterator _it = begin(); _it != end(); ++_it)
     {
       _Const_Link_type _x = static_cast<_Const_Link_type>(_it._M_node);
       _Const_Link_type _L = _RBT_S_left(_x);
       _Const_Link_type _R = _RBT_S_right(_x);
 
       if (_x->_M_color == _RBT_S_red)
         if ((_L && _L->_M_color == _RBT_S_red)
         || (_R && _R->_M_color == _RBT_S_red))
           return false;
 
       if (_L && _M_impl._M_key_compare(_RBT_S_key(_x), _RBT_S_key(_L)))
         return false;
       if (_R && _M_impl._M_key_compare(_RBT_S_key(_R), _RBT_S_key(_x)))
         return false;
 
       if (!_L && !_R && _RBT_black_count(_x, _M_root()) != _len)
         return false;
     }
 
       if (_M_leftmost() != _RBT_node_base::_RBT_S_minimum(_M_root()))
     return false;
       if (_M_rightmost() != _RBT_node_base::_RBT_S_maximum(_M_root()))
     return false;
       return true;
     }
 
 };