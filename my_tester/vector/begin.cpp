#include "../base.hpp"

int main()
{
    NAMESPACE::vector<TYPE> tenths_vec(7, 0);
    NAMESPACE::vector<TYPE>::iterator it = tenths_vec.begin();
    NAMESPACE::vector<TYPE>::iterator ite = tenths_vec.end();

    for (int i = 0; i < 7 ; i++)
        tenths_vec[i] = i * 10;

    std::cout << "\t\t===[ Vector begin() ]===" << std::endl;
    std::cout << std::endl;

    PRINT_ACTION("begin() iterator++ ")
    print(tenths_vec, "tenths_vec");
    for (; it != ite; it++)
        std::cout << "Post increment = " << *it << std::endl;

    return (0);
}