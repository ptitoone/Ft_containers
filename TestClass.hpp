#include <iostream>

class TestClass {

public:
    TestClass() {}

    ~TestClass() {
        std::cout << "Test class destructor called: " << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, TestClass const& rval)
    {
        std::cout << "xx";
        return (os);
    }

};
