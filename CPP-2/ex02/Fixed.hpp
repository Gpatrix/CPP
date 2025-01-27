/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:03:40 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/27 17:20:41 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					value;
	static const int	bitNb = 8;
public:
	Fixed(void);
	Fixed(const int);
	Fixed(const float);
	Fixed(const Fixed&);

	Fixed&					operator=(const Fixed&);
	friend std::ostream&	operator<<(std::ostream& flux, const Fixed&);

	Fixed& operator++(void)
	{
		// actual increment takes place here
		return (*this); // return new value by reference
	}

	// postfix increment
	Fixed operator++(int)
	{
		Fixed old = *this; // copy old value
		operator++();  // prefix increment
		return old;    // return old value
	}

	// prefix decrement
	Fixed& operator--()
	{
		// actual decrement takes place here
		return *this; // return new value by reference
	}

	// postfix decrement
	Fixed operator--(int)
	{
		Fixed old = *this; // copy old value
		operator--();  // prefix decrement
		return old;    // return old value
	}

	~Fixed();

	int		toInt(void) const;
	float	toFloat(void) const;

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};
