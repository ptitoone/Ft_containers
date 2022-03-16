#include "../base.hpp"

int main()
{
    NAMESPACE::vector<TYPE> tenths_vec(7, 0);
    
    for (int i = 0; i < 7 ; i++)
        tenths_vec[i] = i * 10;

    std::cout << "\t\t===[ Vector reserve() ]===" << std::endl;
    std::cout << std::endl;

    PRINT_ACTION("reserve() smaller new capacity than actual capacity")
    BEFORE
    print(tenths_vec, "tenths_vec");
    tenths_vec.reserve(2);
    AFTER
    print(tenths_vec, "tenths_vec");

    PRINT_ACTION("reserve() bigger new capacity than actual capacity")
    BEFORE
    print(tenths_vec, "tenths_vec");
    tenths_vec.reserve(40);
    AFTER
    print(tenths_vec, "tenths_vec");

    PRINT_ACTION("reserve() bigger new capacity than max_size")
    BEFORE
    print(tenths_vec, "tenths_vec");
    try {
        tenths_vec.reserve(tenths_vec.max_size() + 1);
        AFTER
        print(tenths_vec, "tenths_vec");
    } catch (std::length_error &le) {
        std::cout << "Error: " << le.what() << std::endl;
    }

    return (0);
}