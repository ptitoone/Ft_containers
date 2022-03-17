#include "../base.hpp"

int main()
{
    NAMESPACE::vector<TYPE> vec_origin;
    NAMESPACE::vector<TYPE> vec_copy;

    std::cout << "\t\t===[ Vector copy constuctor ]===" << std::endl;
    std::cout << std::endl;

    PRINT_ACTION("Print contents of vector")
    print(vec_origin, "vec_origin");
    print(vec_copy, "vec_copy");

    return (0);
}