/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:56:58 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/11 16:12:57 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "losers.hpp"

bool	get_content (std::string& content, char* filename)
{
	std::ifstream	InFile;
	char		c;

	InFile.open(filename, std::ios::in);
	if (!InFile.is_open())
	{
		std::cout << ERROR_OPEN_FILE << " \'" << filename << "\'\n";
		return (EXIT_FAILURE);
	}
	while (!InFile.eof())
	{
		InFile >> std::noskipws >> c;
		content += c;
	}
	InFile.close();
	return (EXIT_SUCCESS);
}

void	find_and_replace(std::string& content, std::string s1, std::string s2)
{
	std::size_t	pos = 0;
	
	while (pos != content.npos)
	{
		pos = content.find(s1, pos);
		if (pos != content.npos)
		{
			content.erase(pos, s1.length());
			content.insert(pos, s2);
			pos += s2.length();
		}
	}
}

bool	copie_content(std::string& content, std::string filename)
{
	std::ofstream	OutFile;

	OutFile.open((filename + ".replace").c_str(), std::ios::out | std::ios::trunc);
	if (!OutFile.is_open())
	{
		std::cout << ERROR_OPEN_FILE << " \'" << filename + ".replace" << "\'\n";
		return (EXIT_FAILURE);
	}
	OutFile << content;
	OutFile.close();
	return (EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
	std::string		content;

	if (argc != 4
		|| argv[1][0] == '\0'
		|| argv[2][0] == '\0'
		|| argv[3][0] == '\0')
	{
		std::cout << ERROR_ARGS << '\n';
		return (EXIT_FAILURE);
	}

	if (get_content(content, argv[1]))
		return (EXIT_FAILURE);
	find_and_replace(content, argv[2], argv[3]);
	copie_content(content, argv[1]);
	return (EXIT_SUCCESS);
}
