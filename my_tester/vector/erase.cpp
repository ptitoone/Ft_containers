#include "../base.hpp"

int main()
{
    NAMESPACE::vector<TYPE> empty_vec;
    NAMESPACE::vector<TYPE> full_vec(7, 0);
    
    for (int i = 0; i < 7 ; i++)
        full_vec[i] = i * 4;

    std::cout << "\t\t===[ Vector erase() ]===" << std::endl;
    std::cout << std::endl;

    PRINT_SEGV("pop_back() on empty vector causes undefined behaviour")

#ifdef TEST_SEGV
    PRINT_ACTION("erase() by iterator position begin()+2 on empty vector")
    BEFORE
    print(empty_vec, "empty_vec");
    empty_vec.erase(empty_vec.begin()+2);
    print(empty_vec, "empty_vec");
    AFTER
#endif

    PRINT_ACTION("erase() by iterator position begin()+2 on full vector")
    BEFORE
    print(full_vec, "full_vec");
    full_vec.erase(full_vec.begin() + 2);
    AFTER
    print(full_vec, "full_vec");


    PRINT_ACTION("erase() by iterator range [begin()+2, begin()+4) on full vector")
    BEFORE
    print(full_vec, "full_vec");
    full_vec.erase(full_vec.begin() + 2, full_vec.begin() + 4);
    AFTER
    print(full_vec, "full_vec");

    return (0);
}