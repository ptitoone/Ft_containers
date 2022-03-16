#include "../base.hpp"

int main()
{
    NAMESPACE::vector<TYPE> empty_vec;
    NAMESPACE::vector<TYPE> full_vec(7, 42);
    
    std::cout << "\t\t===[ Vector empty() ]===" << std::endl;
    std::cout << std::endl;

    PRINT_ACTION("empty() on empty vector")
    std::cout << "Vector is empty = " << empty_vec.empty() << std::endl;
    
    PRINT_ACTION("empty() on non-empty vector")
    std::cout << "Vector is empty = " << full_vec.empty() << std::endl;

    return (0);
}