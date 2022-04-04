/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:57:56 by akotzky           #+#    #+#             */
/*   Updated: 2022/04/04 16:53:36 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

namespace ft {

	template<typename T>
	struct _B_tree_node {

		typedef T				value_type;
		typedef _B_tree_node*	pointer;
		
		_B_tree_node(value_type val)
		: value(val), left(0), right(0)
		{}

		pointer		left;
		pointer		right;
		value_type	value;
	};

	template <typename _Key, typename _Pair, typename _Compare, typename _Alloc>
	class _B_tree {

		public:
			typedef  _Key						key_type;
			typedef  _Pair						value_type;
			typedef  _Compare					key_compare;
			typedef	 _Alloc						allocator_type;
			typedef	_B_tree_node<value_type> 	node_type;

//            typedef _B_tree_iterator<pointer>				iterator;
//            typedef _B_tree_const_iterator<const_pointer>	const_iterator;
            typedef size_t									size_type;
            typedef ptrdiff_t								difference_type;
//            typedef ft::ReverseIterator<iterator>			reverse_iterator;
//            typedef ft::ReverseIterator<const_iterator>		const_reverse_iterator;

			node_type*	_M_root;

			_B_tree()
			: _M_root(0)
			{}

			_B_tree(_B_tree const& copy)
			{
				// INSERT postfix, infix,  ??? 
			}

			/*ft::pair<iterator, bool>*/
			void
			_M_insert_unique(value_type const& val) {

				if (!_M_root)
				{
					value_type* tmp = allocator_type().allocate(1);
					allocator_type().construct(tmp, val);
					*_M_root = node_type(*tmp);
				}
			}
	};
};
/*

// Increment / add
RB_tree_increment();
const RB_tree_increment();

// Increment / add
RB_tree_decrement();
const RB_tree_decrement();

// Iterators
struct RB_tree_iterator {};
struct RB_tree_const_iterator {};

// Operator overloads for iterators
operator==();
operator!=();

// Out of scope function definitions
RB_tree_insert_and_rebalance();
RB_tree_rebalance_for_erase();


// Operator overloads for trees
operator==();
operator!=();
operator<();
operator<=();
operator>();
operator>=();
operator=();

// Function overloads
swap();
*/