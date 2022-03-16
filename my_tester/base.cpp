#include "base.hpp"

void    print(NAMESPACE::vector<TYPE> & vct, std::string const &name)
{
    NAMESPACE::vector<TYPE>::iterator it = vct.begin();
    NAMESPACE::vector<TYPE>::iterator ite = vct.end();

    std::cout << GRN << "[[" << name << "]]" << RST << std::endl;
    std::cout << "Size is: " << vct.size() << std::endl;
    std::cout << "Capacity is: " << vct.capacity() << std::endl;
    std::cout << "Content is: " << std::endl;
    std::cout << "\t|POS\t|VAL" << std::endl;
    std::cout << "\t|\t|" << std::endl;
    for (size_t i = 0; it != ite; it++)
        std::cout << "\t[" << i++ << "]\t|-> " << *it << std::endl;
    std::cout << GRN << "==============================" << RST << std::endl << std::endl;
}