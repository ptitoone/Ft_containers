#include "../base.hpp"

int main()
{
    NAMESPACE::vector<TYPE> tenths_vec(7, 0);
    
    for (int i = 0; i < 7 ; i++)
        tenths_vec[i] = i * 10;

    std::cout << "\t\t===[ Vector clear() ]===" << std::endl;
    std::cout << std::endl;

    PRINT_ACTION("clear() tenths vector")
    BEFORE
    print(tenths_vec, "tenths_vec");
    tenths_vec.clear();
    AFTER
    print(tenths_vec, "tenths_vec");

    PRINT_ACTION("push_back() new values")
    BEFORE
    print(tenths_vec, "tenths_vec");
    tenths_vec.push_back(42);
    tenths_vec.push_back(420);
    AFTER
    print(tenths_vec, "tenths_vec");

    return (0);
}