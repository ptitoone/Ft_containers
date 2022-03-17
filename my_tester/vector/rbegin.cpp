#include "../base.hpp"

int main()
{
    NAMESPACE::vector<TYPE> tenths_vec(7, 0);
    NAMESPACE::vector<TYPE>::reverse_iterator rit = tenths_vec.rbegin();
    NAMESPACE::vector<TYPE>::reverse_iterator rite = tenths_vec.rend();

    for (int i = 0; i < 7 ; i++)
        tenths_vec[i] = i * 10;

    std::cout << "\t\t===[ Vector rbegin() ]===" << std::endl;
    std::cout << std::endl;

    PRINT_ACTION("rbegin() iterator++ ")
    print(tenths_vec, "tenths_vec");
    for (; rit != rite; rit++)
        std::cout << "Post increment = " << *rit << std::endl;

    return (0);
}