/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:03:40 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/28 15:09:11 by lchauvet         ###   ########.fr       */
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

	Fixed&	operator=(const Fixed&);

	bool operator< (const Fixed& fixed) const;
	bool operator> (const Fixed& fixed) const;
	bool operator<=(const Fixed& fixed) const;
	bool operator>=(const Fixed& fixed) const;
	bool operator==(const Fixed& fixed) const;
	bool operator!=(const Fixed& fixed) const;

	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);
	~Fixed();

	int		toInt(void) const;
	float	toFloat(void) const;

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

	std::ostream&	operator<<(std::ostream& flux, const Fixed&);
