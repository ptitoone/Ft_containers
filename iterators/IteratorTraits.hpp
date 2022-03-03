#pragma once
#include <iterator>

namespace ft {

		struct input_iterator_tag {};
		struct output_iterator_tag {};
		struct foward_iterator_tag : public input_iterator_tag {};
		struct bidirectional_iterator_tag : public foward_iterator_tag {};
		struct random_access_iterator_tag : public bidirectional_iterator_tag {};

		template <class _Iterator>
		struct iterator_traits {
				typedef typename _Iterator::difference_type difference_type;
				typedef typename _Iterator::value_type value_type;
				typedef typename _Iterator::pointer pointer;
				typedef typename _Iterator::reference reference;
				typedef typename _Iterator::iterator_category iterator_category;
		};

		template <class T>
		struct iterator_traits<T*> {
				typedef ptrdiff_t difference_type;
				typedef T value_type;
				typedef T* pointer;
				typedef T& reference;
				typedef random_access_iterator_tag iterator_category;
		};

		template <class T>
		struct iterator_traits<const T*> {
				typedef ptrdiff_t difference_type;
				typedef T value_type;
				typedef const T* pointer;
				typedef const T& reference;
				typedef random_access_iterator_tag iterator_category;
		};

}