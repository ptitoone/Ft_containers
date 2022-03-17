#include "../base.hpp"

int main()
{
    NAMESPACE::vector<TYPE> vec_1(13);
    NAMESPACE::vector<TYPE> vec_2(13, 42);

    std::cout << "\t\t===[ Vector equal operator ]===" << std::endl;
    std::cout << std::endl;

    PRINT_ACTION("Assign vec_1 to vec_2")
    BEFORE
    print(vec_1, "vec_1");
    print(vec_2, "vec_2");
    vec_1 = vec_2;
    AFTER
    print(vec_1, "vec_1");
    print(vec_2, "vec_2");

    return (0);
}