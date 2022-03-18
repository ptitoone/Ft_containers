#pragma once
#include <iterator>

namespace ft {

		typedef std::input_iterator_tag input_iterator_tag;
		typedef std::output_iterator_tag output_iterator_tag;
		typedef std::forward_iterator_tag forward_iterator_tag;
		typedef std::bidirectional_iterator_tag bidirectional_iterator_tag;
		typedef std::random_access_iterator_tag random_access_iterator_tag;

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
