#include "../base.hpp"

int main()
{
    NAMESPACE::vector<TYPE> empty_vec;
    NAMESPACE::vector<TYPE> full_vec(7, 0);

    for (int i = 0; i < 7 ; i++)
        full_vec[i] = i * 4;

    std::cout << "\t\t===[ Vector pop_back() ]===" << std::endl;
    std::cout << std::endl;

    PRINT_SEGV("pop_back() on empty vector causes undefined behaviour")

#ifdef TEST_SEGV
    PRINT_ACTION("pop_back() on empty vector")
    BEFORE
    print(empty_vec, "empty_vec");
    empty_vec.pop_back();
    print(empty_vec, "empty_vec");
    AFTER
#endif

    PRINT_ACTION("pop_back() on populated vector")
    BEFORE
    print(full_vec, "full_vec");
    full_vec.pop_back();
    AFTER
    print(full_vec, "full_vec");

    return (0);
}