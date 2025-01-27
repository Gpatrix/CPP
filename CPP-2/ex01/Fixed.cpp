/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:03:51 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/27 16:54:30 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called\n";
	this->value = 0;
}

Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called\n";
	this->value = nb << this->bitNb;
}

Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor called\n";
	this->value = roundf(nb * pow(2, this->bitNb));
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called\n";
	this->operator=(fixed);
}

int		Fixed::toInt(void) const
{
	return (this->value >> this->bitNb);
}

float	Fixed::toFloat(void) const
{
	return (this->value / pow(2, this->bitNb));
}

int		Fixed::getRawBits(void) const
{
	return (this->value);
}

Fixed&	Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called\n";
	this->value = fixed.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream &out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	this->value = raw;
}

Fixed::~Fixed() 
{
	std::cout << "Destructor called\n";
}
