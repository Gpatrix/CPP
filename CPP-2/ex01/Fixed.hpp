/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:03:40 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/13 09:05:10 by lchauvet         ###   ########.fr       */
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

	int		toInt(void) const;
	float	toFloat(void) const;

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	
	~Fixed();
};
