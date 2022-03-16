#include "../base.hpp"

int main()
{
    NAMESPACE::vector<TYPE> tenths_vec(7, 0);
    
    for (int i = 0; i < 7 ; i++)
        tenths_vec[i] = i * 10;

    std::cout << "\t\t===[ Vector back() ]===" << std::endl;
    std::cout << std::endl;

    PRINT_ACTION("back() on vector")
    print(tenths_vec, "tenths_vec");
    std::cout << "Back element = " << tenths_vec.back() << std::endl;
    
    return (0);
}