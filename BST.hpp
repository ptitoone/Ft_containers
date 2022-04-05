/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:57:56 by akotzky           #+#    #+#             */
/*   Updated: 2022/04/05 13:13:01 by akotzky          ###   ########.fr       */
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
		typedef T*				value_type_pointer;
		typedef _B_tree_node*	node_pointer;
		
		_B_tree_node()
		: value(0), left(0), right(0)
		{}

		_B_tree_node<T> const&
		operator=(_B_tree_node const& rhs) {
			left = rhs.left;
			right = rhs.right;
			value = rhs.value;
			return (*this);
		}

		node_pointer		left;
		node_pointer		right;
		value_type_pointer	value;
	};

	template <typename _Key, typename _Pair, typename _Compare, typename _Alloc>
	class _B_tree {

		public:
			typedef _Key						key_type;
			typedef _Pair						value_type;
			typedef _Compare					key_compare;
			typedef	_Alloc						allocator_type;
			typedef	_B_tree_node<value_type> 	node_type;
			typedef node_type*					node_type_pointer;

			typedef std::allocator<node_type>	node_allocator;

//            typedef _B_tree_iterator<pointer>				iterator;
//            typedef _B_tree_const_iterator<const_pointer>	const_iterator;
            typedef size_t									size_type;
            typedef ptrdiff_t								difference_type;
//            typedef ft::ReverseIterator<iterator>			reverse_iterator;
//            typedef ft::ReverseIterator<const_iterator>		const_reverse_iterator;

			node_type_pointer	_M_root;

			_B_tree()
			: _M_root(0)
			{}

			_B_tree(_B_tree const& copy)
			{
				// INSERT postfix, infix,  ??? 
			}

			void
			_M_build_node(node_type *&dst, value_type const& val) {
					dst = node_allocator().allocate(1);
					node_allocator().construct(dst, node_type());
					dst->value = allocator_type().allocate(1);
					allocator_type().construct(dst->value, val);
			}

        // ITERATORS //
	//        iterator
	//        begin() {
	//            return(_M_tree.begin(););
	//        }

	//        const_iterator
	//        begin() const {
	//            return(_M_tree.begin(););
	//        }

	//        iterator
	//        end() {
	//            return(_M_tree.end(););
	//        }
	//        const_iterator
	//        end() const {
	//            return(_M_tree.end(););
	//        }

	//        reverse_iterator
	//        rbegin() {
	//            return(_M_tree.rbegin(););
	//        }

	//        const_reverse_iterator
	//        rbegin() const {
	//            return(_M_tree.rbegin(););
	//        }

	//        reverse_iterator
	//        rend() {
	//            return(_M_tree.rend(););
	//        }

	//        const_reverse_iterator
	//        rend() const {
	//            return(_M_tree.rend(););
	//        }

			// CAPACITY //
			bool
			empty() const {
				return(_M_root);
			}

//			size_type
//			size() const {
//				return(_M_tree.size(););
//			}

//			size_type
//			max_size() const {
//				return(_M_tree.max_size(););
//			}

			/*ft::pair<iterator, bool>*/
			void
			_M_insert_unique(value_type const& val) {

				if (!_M_root)
					_M_build_node(_M_root, val);
				else
				{
					node_type *browse = _M_root;
					while (browse)
					{
						if (val.first < browse->value->first)
						{
							if (!browse->left)
							{
								_M_build_node(browse->left, val);
								break ;
							}
							else
								browse = browse->left;
						}
						else
						{
							if (!browse->right)
							{
								_M_build_node(browse->right, val);
								break ;
							}
							else
								browse = browse->right;
						}
					}
				}
			}

			void
			printKey() const {
				node_type *browse = _M_root;
				while (browse)
				{
					std::cout << "Key = " << browse->value->first << std::endl; 
					browse = browse->left;
				}
			}

			void
			printVal() const {
				node_type *browse = _M_root;
				while (browse)
				{
					std::cout << "Val = " << _M_root->value->second << std::endl; 
					browse = browse->left;
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

#endif