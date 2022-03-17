#include "../base.hpp"

int main()
{
    NAMESPACE::vector<TYPE> tenths_vec(7, 0);
    NAMESPACE::vector<TYPE>::iterator it = tenths_vec.begin();
    NAMESPACE::vector<TYPE>::iterator ite = tenths_vec.end() - 1;

    for (int i = 0; i < 7 ; i++)
        tenths_vec[i] = i * 10;

    std::cout << "\t\t===[ Vector end() ]===" << std::endl;
    std::cout << std::endl;

    PRINT_ACTION("end() iterator--")
    print(tenths_vec, "tenths_vec");
    for (; ite != it; ite--)
        std::cout << "Post increment = " << *ite << std::endl;

    return (0);
}