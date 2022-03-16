#include "../base.hpp"

int main()
{
    NAMESPACE::vector<int> empty_vec;
    NAMESPACE::vector<std::string> str_vec(7, "foo");
    
    std::cout << "\t\t===[ Vector max_size() ]===" << std::endl;
    std::cout << std::endl;

    PRINT_ACTION("max_size() on empty int vector")
    std::cout << "Max size is = " << empty_vec.max_size() << std::endl;
    
    PRINT_ACTION("max_size() on empty std::string vector")
    std::cout << "Max size is = " << str_vec.max_size() << std::endl;

    return (0);
}