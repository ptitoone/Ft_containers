#include "../base.hpp"

int main()
{
    NAMESPACE::vector<TYPE> empty_vec;
    NAMESPACE::vector<TYPE> tenths_vec(7, 0);
    NAMESPACE::vector<TYPE> hundreads_vec(7, 0);
    
    for (int i = 0; i < 7 ; i++)
    {
        tenths_vec[i] = i * 10;
        hundreads_vec[i] = i * 100;
    }

    std::cout << "\t\t===[ Vector swap() ]===" << std::endl;
    std::cout << std::endl;

    PRINT_SEGV("swap() causes undefined behaviour if allocator traits can't\n\t\t   propagate or allocators dont compare equal")

#ifdef TEST_SEGV
    NAMESPACE::vector<std::string> str_vec(5, "test");
    PRINT_ACTION("swap() vector of type int with vector of type string")
    BEFORE
    print(str_vec, "str_vec");
    print(tenths_vec, "tenths_vec");
    tenths_vec.swap(str_vec);
    print(str_vec, "str_vec");
    print(tenths_vec, "tenths_vec");
    AFTER

#else
    PRINT_ACTION("swap() tenths and hundreads vectors")
    BEFORE
    print(tenths_vec, "tenths_vec");
    print(hundreads_vec, "hundreads_vec");
    tenths_vec.swap(hundreads_vec);
    AFTER
    print(tenths_vec, "tenths_vec");
    print(hundreads_vec, "hundreads_vec");

    PRINT_ACTION("swap() altered tenths and empty vectors")
    BEFORE
    print(tenths_vec, "tenths_vec");
    print(empty_vec, "empty_vec");
    tenths_vec.swap(empty_vec);
    AFTER
    print(tenths_vec, "tenths_vec");
    print(empty_vec, "empty_vec");

#endif

    return (0);
}