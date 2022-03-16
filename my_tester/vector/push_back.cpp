#include "../base.hpp"

int main()
{
    
    NAMESPACE::vector<TYPE> empty_vec;
    NAMESPACE::vector<TYPE> full_vec(7, 0);

    for (int i = 0; i < 7 ; i++)
        full_vec[i] = i * 2;

    std::cout << "\t\t===[ Vector push_back() ]===" << std::endl;
    std::cout << std::endl;

    std::cout << "\xF0\x9F\x92\xA1 push_back() on empty vector" << std::endl;
    empty_vec.push_back(10);
    print(empty_vec, "empty_vec");

    std::cout << "\xF0\x9F\x92\xA1--> push_back() on available capacity" << std::endl;
    empty_vec.push_back(11);
    print(empty_vec, "empty_vec");

    std::cout << "\xF0\x9F\x92\xA1--> push_back() on full capacity" << std::endl;
    full_vec.push_back(12);
    print(full_vec, "full_vec");
    
    return (0);
}