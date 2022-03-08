#include "TestClass.hpp"

TestClass::TestClass()
: _name("xx") {
}

TestClass::TestClass(const TestClass& copy)
: _name(copy.getName()) {
		std::cout << "Copy constructor called: " << std::endl;
}

TestClass::~TestClass() {
	    std::cout << "Test class destructor called: " << std::endl;
}

std::string
TestClass::getName() const {
		return (this->_name);
}

void
TestClass::setName(std::string name) {
		this->_name = name;
}
