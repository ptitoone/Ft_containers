#include "../base.hpp"

int main()
{
    NAMESPACE::vector<TYPE> tenths_vec(7, 0);
    
    for (int i = 0; i < 7 ; i++)
        tenths_vec[i] = i * 10;

    std::cout << "\t\t===[ Vector at() ]===" << std::endl;
    std::cout << std::endl;

    PRINT_ACTION("at() on element at position 2 and position 3")
    print(tenths_vec, "tenths_vec");
    std::cout << "Position 2 = " << tenths_vec.at(2) << std::endl;
    std::cout << "Position 3 = " << tenths_vec.at(3) << std::endl;
    
    PRINT_ACTION("at() on out of range position 15 element")
    try {
        std::cout << "Position 15 = " << tenths_vec.at(15) << std::endl;
    } catch (const std::out_of_range& oor) {
        std::cerr << "Error: " << oor.what() << std::endl;
    }

    return (0);
}