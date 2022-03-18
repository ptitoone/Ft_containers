#include "../base.hpp"

int main()
{
    NAMESPACE::vector<TYPE> tenths_vec(7, 0);
    
    for (int i = 0; i < 7 ; i++)
        tenths_vec[i] = i * 10;

    std::cout << "\t\t===[ Vector resize() ]===" << std::endl;
    std::cout << std::endl;

    PRINT_ACTION("resize() on full vector to smaller size")
    BEFORE
    print(tenths_vec, "tenths_vec");
    tenths_vec.resize(4);
    AFTER
    print(tenths_vec, "tenths_vec");
    
    PRINT_ACTION("resize() on non-full vector to bigger size and val unspecified")
    BEFORE
    print(tenths_vec, "tenths_vec");
    tenths_vec.resize(6);
    AFTER
    print(tenths_vec, "tenths_vec");
  
    PRINT_ACTION("resize() on non-full vector to bigger size and val specified")
    BEFORE
    print(tenths_vec, "tenths_vec");
    tenths_vec.resize(7, 42);
    AFTER
    print(tenths_vec, "tenths_vec");
    
    PRINT_ACTION("resize() on full vector to bigger capacity and val specified")
    BEFORE
    print(tenths_vec, "tenths_vec");
    tenths_vec.resize(15, 420);
    AFTER
    print(tenths_vec, "tenths_vec");

    return (0);
}