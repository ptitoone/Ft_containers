#include "../base.hpp"

int main()
{
    NAMESPACE::vector<TYPE> empty_vec;
    NAMESPACE::vector<TYPE> tenths_vec(7, 0);
    
    for (int i = 0; i < 7 ; i++)
        tenths_vec[i] = i * 10;

    std::cout << "\t\t===[ Vector size() ]===" << std::endl;
    std::cout << std::endl;

    PRINT_ACTION("size() on empty vector")
    std::cout << "Size is = " << empty_vec.size() << std::endl;
    
    PRINT_ACTION("size() on populated vector")
    std::cout << "Size is = " << tenths_vec.size() << std::endl;

    return (0);
}