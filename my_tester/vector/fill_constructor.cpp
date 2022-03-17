#include "../base.hpp"

int main()
{
    NAMESPACE::vector<TYPE> vec_fill_def(13);
    NAMESPACE::vector<TYPE> vec_fill_spec(13, 42);

    std::cout << "\t\t===[ Vector fill constuctor ]===" << std::endl;
    std::cout << std::endl;

    PRINT_ACTION("Construct by fill with default value")
    print(vec_fill_def, "vec_fill_def");
    PRINT_ACTION("Construct by fill with specified 42 value")
    print(vec_fill_spec, "vec_fill_spec");

    return (0);
}