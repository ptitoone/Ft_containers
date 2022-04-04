/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:57:56 by akotzky           #+#    #+#             */
/*   Updated: 2022/04/04 22:17:11 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TREE_HPP
# define __TREE_HPP

//
#include <iostream>
//

#include "utils.hpp"
#include <cstddef>

namespace ft {

	template<typename T>
	struct _B_tree_node {

		typedef T				value_type;
		typedef _B_tree_node*	pointer;
		
		_B_tree_node(value_type const& val)
		: value(val), left(0), right(0)
		{}

		_B_tree_node<T> const&
		operator=(_B_tree_node const& rhs) {
			left = rhs.left;
			right = rhs.right;
			value = value_type(rhs.value->first, rhs.value->second);
			return (*this);
		}

		pointer		left;
		pointer		right;
		value_type	value;
	};

	template <typename _Key, typename _Pair, typename _Compare, typename _Alloc>
	class _B_tree {

		public:
			typedef _Key						key_type;
			typedef _Pair						value_type;
			typedef _Compare					key_compare;
			typedef	_Alloc						allocator_type;
			typedef	_B_tree_node<value_type> 	node_type;

			typedef std::allocator<node_type>	node_allocator;

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
					_Pair *pr = allocator_type().allocate(1);
					allocator_type().construct(pr, val);
					_M_root = node_allocator().allocate(1);
					node_allocator().construct(_M_root, node_type(val));
				}
				else
				{
					node_type* browse = _M_root;
					int i = 0;
					while (browse)
					{
						std::cout << "LOOP" << i++ << std::endl;
						if (browse->value.first < val.first)
						{
							std::cout << "left" << std::endl;
							browse = browse->left;
						}
						else
						{
							std::cout << "right" << std::endl;
							browse = browse->right;
						}
					}
					_Pair *pr = allocator_type().allocate(1);
					allocator_type().construct(pr, val);
					browse = node_allocator().allocate(1);
					node_allocator().construct(browse, node_type(val));
				}
			}

			void
			printKey() const {
				node_type *browse = _M_root;
				while (browse)
				{
					std::cout << "browse = " << browse << std::endl; 
					std::cout << "Key = " << browse->value.first << std::endl; 
					browse = browse->right;
				}
			}

			void
			printVal() const {
				std::cout << "Val = " << _M_root->value.second << std::endl; 

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

#endif