/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:16:10 by lchauvet          #+#    #+#             */
/*   Updated: 2025/01/27 13:57:56 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

void Harl::debug(void)
{
	std::cout << "I’m looking at order #102 like a hawk. Every detail’s under a microscope."\
	" You better believe I know exactly how much cheese is left."\
	" Mess with me, and I’ll catch it." << '\n';
}

void Harl::info(void)
{
	std::cout << "Order #102 is being made right now. I don’t care if you’re ready for it"\
	" or not—it’s happening. Get your act together and deal with it." << '\n';
}

void Harl::warning(void)
{
	std::cout << "Listen up! The cheese for order #102 is about to expire. You’re seriously"\
	" gonna let that happen? Use it or you’ll regret it. This is your final warning." << '\n';
}

void Harl::error(void)
{
	std::cout << "Order #102 is completely screwed. Payment failed."\
	" Do you even know how to fix this? If you don’t sort this out right now,"\
	" you’re losing a customer—and your job might be next." << '\n';
}


void Harl::complain(std::string level)
{
	void	(Harl::*fonctPTR[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	fonctName[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (short i = 0; i < 4; i++)
	{
		if (level == fonctName[i])
			(this->*fonctPTR[i])();
	}
}

Harl::~Harl() {}
