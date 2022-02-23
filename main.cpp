/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:36:18 by akotzky           #+#    #+#             */
/*   Updated: 2022/02/15 15:00:27 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "TestClass.hpp"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"

#if __FT
#		include "vector.hpp"
void
print(const ft::vector<TestClass>& vec) {
		std::cout << std::endl << "Current values in vector:" << std::endl;
		for(ft::vector<TestClass>::const_iterator it = vec.begin(); it != vec.end(); ++it)
#else
#		include <vector>
void
print(const std::vector<TestClass>& vec) {
		std::cout << std::endl << "Current values in vector:" << std::endl;
		for(std::vector<TestClass>::const_iterator it = vec.begin(); it != vec.end(); ++it)
#endif
		{
				std::cout << "[" << *it << "]\t";
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
		myvector.assign(4, TestClass());
		TestClass new_test_class;
		std::cout << "here" << std::endl;
		myvector.reserve(40);
		std::cout << "capacity is " << myvector.capacity() << std::endl;
		std::cout << "size is " << myvector.size() << std::endl;
		print(myvector);

		std::cout << "-------------PUSH BACK----------------" << std::endl;

		myvector.push_back(new_test_class);
		std::cout << "capacity is " << myvector.capacity() << std::endl;
		std::cout << "size is " << myvector.size() << std::endl;
		print(myvector);

	//	myvector.clear();
	return 0;
}
