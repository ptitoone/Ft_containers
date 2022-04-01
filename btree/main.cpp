#include <iostream>

enum color {
	RED,
	BLACK
};

template<typename T>
struct Node {

	typedef T		value_type;
	typedef Node*	pointer;
	typedef short	color_type;

	Node()
	: parent(0), left(0), right(0), color(BLACK), val(value_type())
	{}

	Node(pointer p, pointer l, pointer r, color_type c, value_type v)
	: parent(p), left(l), right(r), color(c), val(v)
	{} 

	Node(Node const& n)
	: parent(n.parent), left(n.left), right(n.right), color(n.color), val(n.val)
	{}

	~Node() {}

	Node const&
	operator=(Node const& n) {
		parent = n.parent;
		left = n.left;
		right = n.right;
		color = n.color;
		val = n.val;
		return (*this);
	}

	pointer		parent;
	pointer		left;
	pointer		right;
	color_type	color;
	value_type	val;

};

template<typename T>
void rotate_left(Node<T> *n)
{
	n->right = n->right->left;
	n->right->parent = n->right;
	n->right->parent->left

	std::cout << "[" << n->right->parent->left->val << "]" << std::endl;
	n->parent = n->right->parent;
	n->right->parent->left = n;
}

int main()
{
	// Creation de 5 noeuds
	Node<int> x;
	Node<int> y;
	Node<int> a;
	Node<int> b;
	Node<int> r;

	x.left = &a;
	x.right = &y;
	x.val = 5;

	y.parent = &x;
	y.left = &b;
	y.right = &r;
	y.val = 7;

	a.parent = &x;
	a.left = 0;
	a.right = 0;
	a.val = 7;

	b.parent = &y;
	b.left = 0;
	b.right = 0;
	b.val = 6;

	r.parent = &y;
	r.left = 0;
	r.right = 0;
	r.val = 8;

	Node<int> *browse = &x;
	while (browse)
	{
		std::cout << browse->val << std::endl;
		browse = browse->right;	
	}

	std::cout << std::endl;

	rotate_left(&x);

	browse = &x;
	while (browse)
	{
		std::cout << browse->val << std::endl;
		browse = browse->right;	
	}
	return (0);
}
