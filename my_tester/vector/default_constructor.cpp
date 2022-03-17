#include "../base.hpp"

int main()
{
    NAMESPACE::vector<TYPE> vec;

    std::cout << "\t\t===[ Vector default constuctor ]===" << std::endl;
    std::cout << std::endl;

    PRINT_ACTION("Print contents of vector")
    print(vec, "vec");

    return (0);
}