#include "vector.hpp"

int main()
{
    ft::vector<int> vec(10, 42);
    ft::vector<int>::iterator it;
    ft::vector<int>::iterator ite;
    ft::vector<int> vecr(it, ite);

    return 0;
}