#include "../base.hpp"

int main()
{
    NAMESPACE::vector<TYPE> tenths_vec(7, 0);
    
    for (int i = 0; i < 7 ; i++)
        tenths_vec[i] = i * 10;

    std::cout << "\t\t===[ Vector access operator [] ]===" << std::endl;
    std::cout << std::endl;

    PRINT_ACTION("Access operator position 2 position 3")
    print(tenths_vec, "tenths_vec");
    std::cout << "Position 2 = " << tenths_vec[2] << std::endl;
    std::cout << "Position 3 = " << tenths_vec[3] << std::endl;

    return (0);
}