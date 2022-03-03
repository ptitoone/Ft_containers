#pragma once

#include "NormalIterator.hpp"

namespace ft {

		template <class T>
		class VectorIterator : public NormalIterator<T> {

		public:
            typedef typename ft::NormalIterator<T>::difference_type difference_type;
            typedef typename ft::NormalIterator<T>::value_type value_type;
            typedef typename ft::NormalIterator<T>::pointer pointer;
            typedef typename ft::NormalIterator<T>::reference reference;
            typedef typename ft::NormalIterator<T>::iterator_category iterator_category;

		};

};