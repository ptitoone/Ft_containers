/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:36:18 by akotzky           #+#    #+#             */
/*   Updated: 2022/02/11 19:29:33 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#if 1
#include "vector.hpp"

void print(const ft::vector<int>& vec)
{
	for (ft::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
}

int main( void )
{
	ft::vector<int> myvector(4, 10);
	ft::vector<int>::iterator it = myvector.begin();

	std::cout << "Is empty : "<< myvector.empty() << std::endl;
	std::cout << *it << std::endl;
	(*it)++;
	std::cout << *it << std::endl;
	it++;
	(*it)++;
	(*it)++;
	std::cout << *it++ << std::endl;
	std::cout << *it << std::endl;
	std::cout << std::endl;
	print(myvector);

	return 0;
}
#else

#include <vector>
#include <iostream>

void print(const std::vector<int>& vec)
{
	for (std::vector<int>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
}

int main( void )
{
	std::vector<int> myvector(4, 10);
	std::vector<int>::iterator it = myvector.begin();

	std::cout << "Is empty : "<< myvector.empty() << std::endl;
	std::cout << *it << std::endl;
	(*it)++;
	std::cout << *it << std::endl;
	it++;
	(*it)++;
	(*it)++;
	std::cout << *it++ << std::endl;
	std::cout << *it << std::endl;
	std::cout << std::endl;
	print(myvector);
	return 0;
}

#endif