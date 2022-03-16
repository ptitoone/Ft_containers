#pragma once
#define TYPE int
#if __FT
    #include "../vector.hpp"
    #include "../iterators/IteratorTraits.hpp"
    #define NAMESPACE ft
#else
    #include <vector>
    #include <iostream>
    #define NAMESPACE std
#endif

void    print(NAMESPACE::vector<TYPE> & vct, std::string const &name);