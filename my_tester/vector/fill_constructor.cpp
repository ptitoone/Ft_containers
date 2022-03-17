#include "../base.hpp"

int main()
{
    NAMESPACE::vector<TYPE> vec(13, 42);

    std::cout << "\t\t===[ Vector fill constuctor ]===" << std::endl;
    std::cout << std::endl;

    PRINT_ACTION("Print contents of vector")
    print(vec, "vec");

    return (0);
}