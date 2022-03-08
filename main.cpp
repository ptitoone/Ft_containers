/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:36:18 by akotzky           #+#    #+#             */
/*   Updated: 2022/02/23 21:47:16 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "TestClass.hpp"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#include <iostream>     // std::cout
#include <iterator>     // std::iterator_traits
#include <typeinfo>     // typeid
#include "./iterators/IteratorTraits.hpp"

#if __FT
#include "vector.hpp"
void
print(const ft::vector<TestClass>& vec) {
		std::cout << "capacity is " << vec.capacity() << std::endl;
		std::cout << "size is " << vec.size() << std::endl;
		std::cout << std::endl << "Current values in vector:" << std::endl;
		for(ft::vector<TestClass>::const_iterator it = vec.begin(); it != vec.end(); ++it)
#else
#include <vector>
void
print(const std::vector<TestClass>& vec) {
		std::cout << "capacity is " << vec.capacity() << std::endl;
		std::cout << "size is " << vec.size() << std::endl;
		std::cout << std::endl << "Current values in vector:" << std::endl;
		for(std::vector<TestClass>::const_iterator it = vec.begin(); it != vec.end(); ++it)
#endif
		{
				std::cout << "[" << it->getName() << "]\t";
		}
		std::cout << std::endl;
		std::cout << "|\t|\t|\t|" << std::endl;
		std::cout << "0\t1\t2\t3" << std::endl;
		std::cout << std::endl;
}

int
main(void) {
#if __FT
		std::cout << GRN << std::endl;
		std::cout << "=== FT IMPLEMENTATION RESULT ===" << std::endl;
		ft::vector<TestClass> myvector;
#else
		std::cout << YEL << std::endl;
		std::cout << "=== LIBSTD IMPLEMENTATION RESULT ===" << std::endl;
		std::vector<TestClass> myvector;
#endif
		TestClass new_test_class0;
		TestClass new_test_class1;
		TestClass new_test_class2;
		TestClass new_test_class3;
		TestClass new_test_class4;
		TestClass new_test_class5;

		new_test_class0.setName("aa");
		new_test_class1.setName("bb");
		new_test_class2.setName("cc");
		new_test_class3.setName("dd");
		new_test_class4.setName("ee");
		new_test_class5.setName("ff");
//        std::cout << "reserve" << std::endl;
//		myvector.reserve(40);

		myvector.push_back(new_test_class0);
		myvector.push_back(new_test_class1);
		myvector.push_back(new_test_class2);
		myvector.push_back(new_test_class3);
		myvector.push_back(new_test_class4);
		myvector.push_back(new_test_class5);
        return 0;
		print(myvector);

        std::cout << "erase" << std::endl;
#if __FT
    ft::vector<TestClass>::iterator it;
#else
    std::vector<TestClass>::iterator it;
#endif

		it = myvector.erase(myvector.begin() + 1, myvector.begin() + 3);
        
        std::cout << "Print returned iter from erase : " << it->getName() << std::endl;
		print(myvector);

	//	myvector.clear();
	return 0;
}
