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

#if __FT
#		include "vector.hpp"
void
print(const ft::vector<int>& vec) {
		std::cout << std::endl << "Current values in vector:" << std::endl;
		for(ft::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
#else
#		include <vector>
void
print(const std::vector<int>& vec) {
		std::cout << std::endl << "Current values in vector:" << std::endl;
		for(std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
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
		std::cout << "=== FT IMPLEMENTATION RESULT ===" << std::endl;
		ft::vector<int> myvector(4, 10);
		ft::vector<int>::reverse_iterator it = myvector.rbegin();

		ft::vector<int> myvector_copy;
#else
		std::cout << "=== LIBSTD IMPLEMENTATION RESULT ===" << std::endl;
		std::vector<int> myvector(4, 10);
		std::vector<int>::reverse_iterator it = myvector.rbegin();

		std::vector<int> myvector_copy;
#endif
		myvector_copy = myvector;
		print(myvector);
		for(; it != myvector.rend();) {
				std::cout << "Increment iterator value" << std::endl;
				(*it)++;
				std::cout << "value = " << *it << std::endl;
				std::cout << "Increment iterator" << std::endl;
				it++;
		}
		print(myvector);

		return 0;
}
