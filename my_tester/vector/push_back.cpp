#include "../base.hpp"

int main()
{
    NAMESPACE::vector<TYPE> empty_vec;
    NAMESPACE::vector<TYPE> full_vec(7, 0);

    for (int i = 0; i < 7 ; i++)
        full_vec[i] = i * 4;

    std::cout << "\t\t===[ Vector push_back() ]===" << std::endl;
    std::cout << std::endl;

    PRINT_ACTION("push_back() on empty vector")
    BEFORE
    print(empty_vec, "empty_vec");
    empty_vec.push_back(10);
    AFTER
    print(empty_vec, "empty_vec");

    PRINT_ACTION("push_back() on available capacity")
    BEFORE
    print(empty_vec, "empty_vec");
    empty_vec.push_back(11);
    AFTER
    print(empty_vec, "empty_vec");

    PRINT_ACTION("push_back() on full capacity")
    BEFORE
    print(full_vec, "full_vec");
    full_vec.push_back(12);
    AFTER
    print(full_vec, "full_vec");
    
    return (0);
}