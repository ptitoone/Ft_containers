#include "../base.hpp"

int main()
{
    NAMESPACE::vector<TYPE> tenths_vec(7, 0);
    
    for (int i = 0; i < 7 ; i++)
        tenths_vec[i] = i * 10;

    std::cout << "\t\t===[ Vector front() ]===" << std::endl;
    std::cout << std::endl;

    PRINT_ACTION("front() on vector")
    print(tenths_vec, "tenths_vec");
    std::cout << "Front element = " << tenths_vec.front() << std::endl;
    
    return (0);
}