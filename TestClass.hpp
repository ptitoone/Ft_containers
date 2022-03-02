#include <iostream>

class TestClass {
public:
		TestClass();
		TestClass(const TestClass& copy);
		~TestClass();

		std::string
		getName() const;

		void
		setName(std::string name);

		std::string _name;
};
