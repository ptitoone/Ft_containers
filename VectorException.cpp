/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorException.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 21:49:02 by akotzky           #+#    #+#             */
/*   Updated: 2022/02/14 21:49:10 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VectorException.hpp"

const char*
VectorException::OutOfMemoryException::what() throw() {
    return ("Error: Not enough memory available");
}