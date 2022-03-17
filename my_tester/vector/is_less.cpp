#include "../base.hpp"

int main()
{
    NAMESPACE::vector<int> vec_1(13, 42);
    NAMESPACE::vector<int> vec_2(13, 42);

    vec_2[11] = 0;

    std::cout << "\t\t===[ Vector less operator ]===" << std::endl;
    std::cout << std::endl;

    PRINT_ACTION("vec_1 < vec_2")
    print(vec_1, "vec_1");
    print(vec_2, "vec_2");
    std::cout << "Result: " << (vec_1 < vec_2) << std::endl;

    return (0);
}