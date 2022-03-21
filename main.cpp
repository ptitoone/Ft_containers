#include "vector.hpp"

int main()
{
    ft::vector<int> vec0(10);
    ft::vector<int> vec1(10, 42);
    ft::vector<int>::iterator it;
    ft::vector<int>::iterator ite;
    ft::vector<int> vec3(it, ite);

    return 0;
}