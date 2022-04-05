#include "map.hpp"
#include "utils.hpp"

int main()
{
	ft::map<int, char> m;

	m.insert(ft::pair<int, char>(1, 'H'));
	m.insert(ft::pair<int, char>(2, 'E'));
	m.insert(ft::pair<int, char>(0, 'L'));
	m.insert(ft::pair<int, char>(-1, 'L'));
	m.insert(ft::pair<int, char>(10, 'O'));

	m._M_tree.printKey();
	m._M_tree.printVal();
	std::cout << "Is map empty? : " << m.empty() << std::endl;

    return 0;
}