/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:03:51 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/28 14:53:51 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->value = 0;
}

Fixed::Fixed(const int nb)
{
	this->value = nb << this->bitNb;
}

Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor called\n";
	this->value = roundf(nb * pow(2, this->bitNb));
}

Fixed::Fixed(const Fixed& fixed)
{
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
	if (this == &fixed)
		return (*this);
	this->value = fixed.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream &out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}

// prefix increment
Fixed& Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

// postfix increment
Fixed Fixed::operator++(int)
{
	Fixed old = *this;
	operator++();
	return old;
}

// prefix decrement
Fixed& Fixed::operator--()
{
	this->value--;
	return *this;
}

// postfix decrement
Fixed Fixed::operator--(int)
{
	Fixed old = *this;
	operator--();
	return old;
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

Fixed::~Fixed() {}
