/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:36:18 by akotzky           #+#    #+#             */
/*   Updated: 2022/03/15 19:14:28 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "TestClass.hpp"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#include <iostream>
#include <iterator>
#include <typeinfo>
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
		ft::vector<TestClass> myvector1;
#else
		std::cout << YEL << std::endl;
		std::cout << "=== LIBSTD IMPLEMENTATION RESULT ===" << std::endl;
		std::vector<TestClass> myvector;
		std::vector<TestClass> myvector1;
#endif
		TestClass new_test_class0;
		TestClass new_test_class1;
		TestClass new_test_class2;
		TestClass new_test_class3;
		TestClass new_test_class4;
		TestClass new_test_class5;

		TestClass new_test_class6;
		TestClass new_test_class7;
		TestClass new_test_class8;
		TestClass new_test_class9;
		TestClass new_test_class10;
		TestClass new_test_class11;

		new_test_class0.setName("aa");
		new_test_class1.setName("bb");
		new_test_class2.setName("cc");
		new_test_class3.setName("dd");
		new_test_class4.setName("ee");
		new_test_class5.setName("ff");

		new_test_class6.setName("00");
		new_test_class7.setName("11");
		new_test_class8.setName("22");
		new_test_class9.setName("33");
		new_test_class10.setName("44");
		new_test_class11.setName("55");
        std::cout << "reserve" << std::endl;
//    	myvector.reserve(40);

		myvector.push_back(new_test_class0);
		myvector.push_back(new_test_class1);
		myvector.push_back(new_test_class2);
		myvector.push_back(new_test_class3);
		myvector.push_back(new_test_class4);
		myvector.push_back(new_test_class5);

		myvector1.push_back(new_test_class6);
		myvector1.push_back(new_test_class7);
		myvector1.push_back(new_test_class8);
		myvector1.push_back(new_test_class9);
		myvector1.push_back(new_test_class10);
		myvector1.push_back(new_test_class11);
		print(myvector);
		print(myvector1);
	    myvector1.assign(myvector.begin(), myvector.begin() + 3);
		print(myvector);
		print(myvector1);

	//	myvector.clear();
	return 0;
}
