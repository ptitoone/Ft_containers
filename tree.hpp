#ifndef __TREE_HPP
# define __TREE_HPP

#include "utils.hpp"
#include "IteratorTraits.hpp"

namespace ft {

	enum _RBT_color { _RBT_red = false, _RBT_black = true };

	template<typename _Val>
	struct _RBT_Node {

		//typedef	_RBT_Node<_Val>*	_Link_type;
		typedef _RBT_Node<_Val>* 	_RBT_Node_ptr;
		typedef _RBT_Node const*	_RBT_Node_const_ptr;

		_RBT_color		_M_color;
		_RBT_Node_ptr	_M_parent;
		_RBT_Node_ptr	_M_left;
		_RBT_Node_ptr	_M_right;
		_Val			_M_value;

		static _RBT_Node_ptr
		_S_minimum(_RBT_Node_ptr _root) {
			while (_root->_M_left)
				_root = root->_M_left;
			return (_root);
		}

		static _RBT_Node_const_ptr
		_S_minimum(_RBT_Node_ptr _root) {
			while (_root->_M_left)
				_root = root->_M_left;
			return (_root);
		}

		static _RBT_Node_ptr
		_S_maximum(_RBT_Node_ptr _root) {
			while (_root->_M_right)
				_root = root->_M_right;
			return (_root);
		}

		static _RBT_Node_const_ptr
		_S_maximum(_RBT_Node_ptr _root) {
			while (_root->_M_right)
				_root = root->_M_right;
			return (_root);
		}
	};

//////////// INC DEC ///////////////
/// Can be simplified for MAP case as each key is unique
	template<typename _T>
	static _RBT_Node<_T>*
	_RBT_increment(_RBT_Node<_T>* _x) throw() {
		if (_x->right)
		{
			_x = _x->_M_right;
			while (_x->_M_left)
				_x = _x->_M_left;
		}
		else
		{
			// Y = parent de X
			_RBT_Node<_T>* _y = _x->_M_parent;
			// Tant que X = parent droit de Y
			// on remonte
			while (_x == _y->_M_right)
			{
				// On remonte X a Y
				_x = _y;
				// On remonte Y a Y->parent
				_y = _y->parent;
			}
			if (_x->_M_right != _y)
				_x = _y;
		}
		return (_x);
	}

	template<typename _T>
	static _RBT_Node<_T>*
	_RBT_decrement(_RBT_Node<_T>* _x) throw() {
		//Cant be true in MAP
		if (_x->_M_color = _RBT_red && _x->_M_parent->_M_parent == _x)
			_x = _x->_M_right;
		else if (_x->_M_left)
		{
			_RBT_Node<_T>* _y = _x->_M_left;
			// remonter Y de 1 et descendre le plus a droite possible
			while (_y->_M_right)
				_y = _y->_M_right;
			_x = _y;
		}
		else
		{
			_RBT_Node<_T>* _y = _x->_M_parent;
			while (_x == _y->_M_left)
			{
				_x = _y;
				_y = _y->_M_parent;
			}
			_x = _y;

		}
		return _x;
	}
////////////////////////////////////

	template<typename _T>
	struct _RBT_iterator {

		typedef _T value_type;
		typedef _T&	reference;
		typedef _T*	pointer;

		typedef ft::bidirectional_iterator_tag	iterator_category;
		typedef ptrdiff_t						difference_type;

		typedef _RBT_iterator<_T>					_Self;
//		typedef ft::_RBT_Node<_T>::_RBT_Node_ptr	_Base_ptr;
		typedef ft::_RBT_Node<_T>*					_Link_type;

		_RBT_iterator()
		: _M_node() { }

		explicit
		_RBT_iterator(_Link_type _node)
		: _M_node(_node) { }

		reference
		operator*() const {
			return (_M_node->_M_value);
		}

		pointer
		operator->() const {
			return (&_M_node->_M_value);
		}

		_Self&
		operator++() {

		}

		_Link_type _M_node;
	};
};

#endif