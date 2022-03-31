/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:08:21 by akotzky           #+#    #+#             */
/*   Updated: 2022/03/31 15:59:07 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <functional>
#include <memory>
#include "tree.hpp"

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
        explicit map(const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type()) {

        }

        template <class InputIterator>
        map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type()) {

        }

        map(map const& x) {

        }

        // DTOR //
        ~map() {

        }

        // ITERATORS //
        iterator begin();
        const_iterator begin() const;

        iterator end();
        const_iterator end() const;

        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;

        reverse_iterator rend();
        const_reverse_iterator rend() const;

        // CAPACITY //
        bool empty() const;
        size_type size() const;

        size_type max_size() const;

        // ELEMENT ACCESS //
        mapped_type& operator[] (const key_type& k);

        // MODIFIERS //
        pair<iterator,bool>
        insert (const value_type& val);

        iterator
        insert (iterator position, const value_type& val);

        template <class InputIterator>
        void
        insert (InputIterator first, InputIterator last);

        void
        erase (iterator position);

        size_type
        erase (const key_type& k);

        void
        erase (iterator first, iterator last);

        void swap (map& x);

        void clear();

        // OBSERVERS //
        key_compare key_comp() const;

        value_compare value_comp() const;

        // OPERATIONS //
        iterator
        find (const key_type& k);

        const_iterator
        find (const key_type& k) const;

        size_type
        count (const key_type& k) const;

        iterator
        lower_bound (const key_type& k);

        const_iterator
        lower_bound (const key_type& k) const;

        iterator
        upper_bound (const key_type& k);

        const_iterator
        upper_bound (const key_type& k) const;

        pair<const_iterator,const_iterator>
        equal_range (const key_type& k) const;

        pair<iterator,iterator>
        equal_range (const key_type& k);

        // ALLOCATOR //
        allocator_type
        get_allocator() const;
    };
};