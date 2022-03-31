/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:08:21 by akotzky           #+#    #+#             */
/*   Updated: 2022/03/31 19:37:16 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAP_HPP
# define __MAP_HPP

# include <functional>
# include <memory>
# include "tree.hpp"
# include "utils.hpp"

namespace ft {

    template< typename _Key, typename _Tp, typename _Compare = std::less<_Key>,
        typename _Alloc = std::allocator<std::pair<const _Key, _Tp > > >
    class map {

        public:
            typedef _Key                        key_type;
            typedef _Tp                         mapped_type;
            typedef ft::pair<const _Key, _Tp>   value_type;
            typedef _Compare                    key_compare;
            typedef _Alloc                      allocator_type;
        /// Unshure about need to implement ///
        private:
            typedef typename _Alloc::value_type _Alloc_value_type;

        public:

        class value_compare : public std::binary_function<value_type, value_type, bool>
        {
            private:
                friend class map<_Key, _Tp, _Compare, _Alloc>;

            protected:
                _Comppare comp;
            
            value_compare(_compare c)
            : comp(c) { }

            public:
                bool operator()(value_type const& x, value_type const& y) const {
                    return (comp(x.first, y.first););
                }
        };
        ///////////////////////////////////////

        private:
            typedef typename _Alloc::template rebind<value_type>::other _Pair_alloc_type;
            typedef _Rb_tree<key_type, value_type, _Select1st<value_type>,
                key_compare, _Pair_alloc_type> _Rep_type;
            
            _Rep_type _M_tree;
        
        public:
            typedef typename _Pair_alloc_type::pointer          pointer;
            typedef typename _Pair_alloc_type::const_pointer    const_pointer;
            typedef typename _Pair_alloc_type::reference        reference;
            typedef typename _Pair_alloc_type::const_reference  const_reference;
            typedef typename _Rep_type::iterator                iterator;
            typedef typename _Rep_type::const_iterator          const_iterator;
            typedef typename _Rep_type::size_type               size_type;
            typedef typename _Rep_type::difference_type         difference_type;
            typedef typename _Rep_type::reverse_iterator        reverse_iterator;
            typedef typename _Rep_type::const_reverse_iterator  const_reverse_iterator;

        // CTOR //
        map()
        : _M_t()
        {}

        explicit
        map(key_compare const& comp = key_compare(),
              allocator_type const& alloc = allocator_type())
        : _M_tree(comp, _Pair_alloc_type(alloc))
        {}

        template <class InputIterator>
        map(InputIterator first, InputIterator last, key_compare const& comp = key_compare(),
            allocator_type const& alloc = allocator_type())
        : _M_tree()
        { _M_tree._M_insert_unique(first, last); }

        map(map const& x)
        : _M_tree(c._M_tree)
        {}

        // DTOR //
        ~map() {}

        // ITERATORS //
        iterator
        begin() {
            return(_M_tree.begin(););
        }

        const_iterator
        begin() const {
            return(_M_tree.begin(););
        }

        iterator
        end() {
            return(_M_tree.end(););
        }
        const_iterator
        end() const {
            return(_M_tree.end(););
        }

        reverse_iterator
        rbegin() {
            return(_M_tree.rbegin(););
        }

        const_reverse_iterator
        rbegin() const {
            return(_M_tree.rbegin(););
        }

        reverse_iterator
        rend() {
            return(_M_tree.rend(););
        }

        const_reverse_iterator
        rend() const {
            return(_M_tree.rend(););
        }

        // CAPACITY //
        bool
        empty() const {
            return(_M_tree.empty(););
        }

        size_type
        size() const {
            return(_M_tree.size(););
        }

        size_type
        max_size() const {
            return(_M_tree.max_size(););
        }

        // ELEMENT ACCESS //
        mapped_type&
        operator[] (key_type const& k) {
            iterator it = lower_bound(k);

            if (it == end() || key_comp()(k, *it.first))
                it = insert(it, value_type(k, mapped_type()));
            return(*it.second;);
        }

        // MODIFIERS //
        ft::pair<iterator, bool>
        insert (value_type const& val) {
            return(_M_tree._M_insert_unique(val););
        }

        iterator
        insert (iterator position, value_type const& val) {
            return(_M_tree._M_insert_unique_(position, val));
        }

        template <class InputIterator>
        void
        insert (InputIterator first, InputIterator last) {
            _M_tree._M_insert_unique(first, last);
        }

        void
        erase (iterator position) {
            _M_tree.erase(position);
        }

        size_type
        erase (key_type const& k) {
            return(_M_tree.erase(k););
        }

        void
        erase (iterator first, iterator last) {
            _M_tree.erase(first, last);
        }

        void
        swap (map& x) {
            _M_tree.swap(x._M_tree);
        }

        void
        clear() {
            _M_tree.clear();
        }

        // OBSERVERS //
        key_compare
        key_comp() const {
            return(_M_tree.key_comp(););
        }

        value_compare
        value_comp() const {
            return(_M_tree.value_compare(_M_tree.key_comp()););
        }

        // OPERATIONS //
        iterator
        find (key_type const& k) {
            return(_M_tree.find(k););
        }

        const_iterator
        find (key_type const& k) const {
            return(_M_tree.find(k););
        }

        size_type
        count (key_type const& k) const {
            return(_M_tree.count(););
        }

        iterator
        lower_bound (key_type const& k) {
            return(_M_tree.lower_bound(k););
        }

        const_iterator
        lower_bound (key_type const& k) const {
            return(_M_tree.lower_bound(k););
        }

        iterator
        upper_bound (key_type const& k) {
            return(_M_tree.upper_bound(k););
        }

        const_iterator
        upper_bound (key_type const& k) const {
            return(_M_tree.upper_bound(k););
        }

        pair<const_iterator, const_iterator>
        equal_range (key_type const& k) const {
            return(_M_tree.equal_range(x));
        }

        pair<iterator, iterator>
        equal_range (key_type const& k) {
            return(_M_tree.equal_range(x));
        }

        // ALLOCATOR //
        allocator_type
        get_allocator() const;

        template<typename _K1, typename _T1, typename _C1, typename _A1>
        friend bool
        operator==(map<_K1, _T1, _C1, _A1> const&, map<_K1, _T1, _C1, _A1> const&);

        template<typename _K1, typename _T1, typename _C1, typename _A1>
        friend bool
        operator<(map<_K1, _T1, _C1, _A1> const&, map<_K1, _T1, _C1, _A1> const&);
    };

    template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    inline bool
    operator==( map<_Key, _Tp, _Compare, _Alloc> const& x,
                map<_Key, _Tp, _Compare, _Alloc> const& y) {
        return(x._M_tree == y._M_tree);
    }

    template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    inline bool
    operator<( map<_Key, _Tp, _Compare, _Alloc> const& x,
                map<_Key, _Tp, _Compare, _Alloc> const& y) {
        return(x._M_tree < y._M_tree);
    }

    template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    inline bool
    operator!=( map<_Key, _Tp, _Compare, _Alloc> const& x,
                map<_Key, _Tp, _Compare, _Alloc> const& y) {
        return(!(x == y));
    }

    template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    inline bool
    operator>( map<_Key, _Tp, _Compare, _Alloc> const& x,
                map<_Key, _Tp, _Compare, _Alloc> const& y) {
        return(y < x);
    }
    
    template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    inline bool
    operator<=( map<_Key, _Tp, _Compare, _Alloc> const& x,
                map<_Key, _Tp, _Compare, _Alloc> const& y) {
        return(!(y < x));
    }
    
    template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    inline bool
    operator>=( map<_Key, _Tp, _Compare, _Alloc> const& x,
                map<_Key, _Tp, _Compare, _Alloc> const& y) {
        return(!(x < y));
    }

    template<typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    inline void
    swap(   map<_Key, _Tp, _Compare, _Alloc> const& x,
            map<_Key, _Tp, _Compare, _Alloc> const& y) {
        x.swap(y);
    }
};

#endif