/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:03:51 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/29 08:44:14 by lchauvet         ###   ########.fr       */
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
	if (this != &fixed)
		this->value = fixed.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream &out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}

bool Fixed::operator< (const Fixed& fixed) const
{
	return (this->value < fixed.getRawBits());
}

bool Fixed::operator> (const Fixed& fixed) const
{
	return (this->value > fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed& fixed) const
{
	return (this->value <= fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed& fixed) const
{
	return (this->value >= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed& fixed) const
{
	return (this->value == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed& fixed) const
{
	return (this->value != fixed.getRawBits());
}

Fixed Fixed::operator+(const Fixed& fixed) const
{
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed& fixed) const
{
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed& fixed) const
{
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed& fixed) const
{
	return Fixed(this->toFloat() / fixed.toFloat());
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

Fixed&		Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

Fixed&		Fixed::max(Fixed& a, Fixed& b)
{
	return (a < b ? b : a);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a < b ? b : a);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

Fixed::~Fixed() {}
