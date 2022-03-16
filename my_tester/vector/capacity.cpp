#include "../base.hpp"

int main()
{
    NAMESPACE::vector<TYPE> empty_vec;
    NAMESPACE::vector<TYPE> tenths_vec(7, 0);
    
    for (int i = 0; i < 7 ; i++)
        tenths_vec[i] = i * 10;

    std::cout << "\t\t===[ Vector capacity() ]===" << std::endl;
    std::cout << std::endl;

    PRINT_ACTION("capacity() on empty vector")
    std::cout << "Capacity is = " << empty_vec.capacity() << std::endl;
    
    PRINT_ACTION("capacity() on populated vector")
    std::cout << "Capacity is = " << tenths_vec.capacity() << std::endl;

    return (0);
}