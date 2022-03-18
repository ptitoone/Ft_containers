#pragma once
#define TYPE int
#if __FT
    #include "../vector.hpp"
    #include "../IteratorTraits.hpp"
    #define NAMESPACE ft
#else
    #include <vector>
    #include <iostream>
    #define NAMESPACE std
#endif

#include "ANSI-color-codes.hpp"
#define PRINT_ACTION(msg) std::cout << "\t\t\xF0\x9F\x92\xA1 " <<  BWHT << msg << RST << std::endl;
#define PRINT_SEGV(msg) std::cout << "\t\t\xF0\x9F\x92\xA3 " <<  RED << msg << RST << std::endl;
#define BEFORE std::cout << "\xE2\x8F\xAA Before" << std::endl;
#define AFTER std::cout << "\xE2\x8F\xA9 After" << std::endl;


void    print(NAMESPACE::vector<TYPE> & vct, std::string const &name);