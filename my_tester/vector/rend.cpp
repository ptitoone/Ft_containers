#include "../base.hpp"

int main()
{
    NAMESPACE::vector<TYPE> tenths_vec(7, 0);
    NAMESPACE::vector<TYPE>::reverse_iterator rit = tenths_vec.rbegin();
    NAMESPACE::vector<TYPE>::reverse_iterator rite = tenths_vec.rend() - 1;
    
    for (int i = 0; i < 7 ; i++)
        tenths_vec[i] = i * 10;

    std::cout << "\t\t===[ Vector rend() ]===" << std::endl;
    std::cout << std::endl;

    PRINT_ACTION("rend()-1 iterator-- ")
    print(tenths_vec, "tenths_vec");
    for (; rite != rit; rite--)
        std::cout << "Post decrement = " << *rite << std::endl;
    
        std::cout << "test = " << rite[2] << std::endl;
    return (0);
}