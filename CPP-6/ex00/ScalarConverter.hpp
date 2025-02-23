/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:52:07 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/23 15:52:11 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <climits>
#include <float.h>
#include <iomanip>
#include <iostream>

#define IMPOSSIBLE		"impossible"
#define NON_DISPLAYABLE	"Non displayable"

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter&);
		ScalarConverter &operator=(const ScalarConverter&);

	public:
		static void convert(std::string);
		~ScalarConverter(void);
};
