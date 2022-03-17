#include "../base.hpp"

int main()
{
    NAMESPACE::vector<int>  vec_origin(10);

    for (size_t i = 0; i < 10; i++)
          vec_origin.push_back(2);

    NAMESPACE::vector<int> vec_copy(vec_origin);

    std::cout << "\t\t===[ Vector copy constuctor ]===" << std::endl;
    std::cout << std::endl;

    PRINT_ACTION("Print contents of vector")
    print(vec_origin, "vec_origin");
    print(vec_copy, "vec_copy");

    return (0);
}