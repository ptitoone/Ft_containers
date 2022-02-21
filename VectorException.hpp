/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorException.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotzky <akotzky@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 21:49:14 by akotzky           #+#    #+#             */
/*   Updated: 2022/02/15 12:48:53 by akotzky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <exception>

class VectorException 
{
    public:
        class OutOfMemoryException : std::exception {
            public:
                const char* what() throw();
        };
};
