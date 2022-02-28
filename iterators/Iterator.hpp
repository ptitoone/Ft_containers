#pragma once
#include <cstddef>

namespace ft {

    template <class T, class Category>
    struct iterator {
        typedef T           value_type;
        typedef ptrdiff_t   difference_type;
        typedef T*          pointer;
        typedef T&          reference;
        typedef Category    iterator_category;
    };
};
