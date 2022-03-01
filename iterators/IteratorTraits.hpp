#pragma once

namespace ft {

    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct foward_iterator_tag {};
    struct bidirectional_iterator_tag {};
    struct random_access_iterator_tag {};

	template <class _type>
	class _has_iterator_typedefs{
		public:
			const bool _value;
			_has_iterator_typedefs()
			:
			{}

		private:
			Void<_type::difference_type> difference_type::value = 0;
			Void<_type::value_type> value_type::value = 0;
			Void<_type::pointer> pointer::value = 0;
			Void<_type::reference> reference::value = 0;
			Void<_type::iterator_category> iterator_category::value = 0;

			const bool _check(void _diff, void _val, void _ptr, void _ref, void _cat) {

			}
	};
	
	template <typename T>
	struct Void { typedef T value; value =  };


    template <class Iterator>
    struct iterator_traits
    {
        typedef typename Iterator::difference_type   difference_type;
        typedef typename Iterator::value_type        value_type;
        typedef typename Iterator::pointer           pointer;
        typedef typename Iterator::reference         reference;
        typedef typename Iterator::iterator_category iterator_category;
    };

    template <class T>
    struct iterator_traits<T*>
    {
        typedef ptrdiff_t                   difference_type;
        typedef T                           value_type;
        typedef T*                          pointer;
        typedef T&                          reference;
        typedef random_access_iterator_tag  iterator_category;
    };

    template <class T>
    struct iterator_traits<const T*>
    {
        typedef ptrdiff_t                   difference_type;
        typedef T                           value_type;
        typedef const T*                    pointer;
        typedef const T&                    reference;
        typedef random_access_iterator_tag  iterator_category;
    };

}