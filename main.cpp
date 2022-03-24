#include "vector.hpp"

int main()
{
    ft::vector<std::string> vec1(10, "Hello");

	vec1.assign(42, "James BOND");

    return 0;
}