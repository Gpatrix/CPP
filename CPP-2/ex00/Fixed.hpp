/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:03:40 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/27 15:28:24 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fixed
{
private:
	int					value;
	static const int	bitNb;
public:
	Fixed(void);
	Fixed(const Fixed&);
	Fixed&	operator=(const Fixed&);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};
