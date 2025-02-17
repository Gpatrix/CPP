/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchauvet <lchauvet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:39:06 by lchauvet          #+#    #+#             */
/*   Updated: 2025/02/17 10:44:10 by lchauvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "AForm.hpp"

#define ASCII_TREE \
"⡦⠀⠰⣇⠐⠀⠀⠀⢏⠀⢀⠃⠀⠀⠀⠤⠀⡒⢰⢊⡇⢰⠀⡣⢐⡆⢀⠂⡄⢀⢚⠠⠌⡰⢘⡄⠀⢰⠀⡐⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⡷⠀⢘⠦⡠⠀⠀⠀⢈⡆⠸⡄⣺⣝⢰⣟⠀⢩⢶⡸⡀⢆⢧⡱⢂⠘⣨⠁⠏⣀⡍⢆⡤⠁⠚⢠⣡⠂⠰⡁⠇⠐⠀⢂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⣯⡱⢸⣃⠤⣁⠀⠀⡀⠏⠰⣽⡿⢎⢻⣯⠃⣼⢣⡜⣱⢈⡿⡐⢧⣶⣽⠀⡖⣭⢂⡽⢶⢃⡖⢫⠳⣬⡱⢹⠀⢌⠰⠀⠄⠀⠀⠀⢠⠃⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⢣⠟⡶⢉⠆⡥⠀⣆⠈⡜⢀⠟⣃⠈⣜⣾⣓⣯⢧⢽⣣⢞⡽⢁⢺⡝⣏⢳⣏⠗⣸⡟⠡⢢⠝⡞⣻⠽⢓⠡⠎⠘⢠⠁⠨⠀⠀⢀⠂⡄⠣⠀⠦⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⣷⣯⡗⡩⠂⠵⡱⢸⠁⣶⠩⢶⠀⠹⠀⣈⠸⣌⠿⣮⡽⢎⣽⣣⢏⣎⣷⠞⣾⢷⡼⣿⠐⣏⠚⢥⣏⡰⠀⢂⡄⠚⢠⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⣿⣿⡝⠀⡄⠡⠹⣌⠆⠙⡇⠃⢯⠦⠀⠠⠘⢈⠂⠳⡌⣂⠾⡍⣞⡼⣻⠜⣿⡧⢻⡝⠣⣘⢯⢶⡣⢀⡌⠃⠔⡠⠈⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀\n\
⣿⣿⠃⠀⠅⠠⢑⠺⠇⠀⠀⠀⠀⠐⠀⠀⠀⠀⠀⠁⠐⠉⠀⠃⢈⡗⢿⣹⡟⠷⢨⠿⣅⠺⢯⠷⣁⠀⠨⠙⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⣿⣽⡃⠀⢈⠀⢂⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⡞⢻⡏⢦⢱⣯⠐⡇⢬⠃⠔⡠⠆⢁⠂⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⣿⣖⠣⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⢸⣏⢺⠽⡃⣝⢪⡜⢂⠁⠄⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⣿⠞⡁⠀⠀⠀⠀⠀⡀⠾⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢢⣷⢚⢈⡱⡌⢢⠛⡁⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⡯⣞⠰⠀⠀⠀⠀⠀⠁⠀⠀⢠⠄⠀⠀⠀⠲⣶⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣙⠧⢀⡦⢍⠳⢂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⢤⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⡻⠌⠀⠀⠀⠀⠀⢀⡀⠂⠀⢹⣮⣔⣀⣀⢠⡝⠣⢠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠌⡆⣞⠘⡆⡥⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⡄⡄⡀⣤⢎⡥⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⢀⠀⠀⠀⠀⠀⠂⠀⠀⡀⠈⠙⠂⠁⠊⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠤⣓⢬⢆⡿⣐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠘⠉⠙⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⣀⠂⠈⠀⣄⠀⠀⠀⠀⡐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠍⣲⡍⢯⣘⡷⣥⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡔⢀⠀\n\
⠀⠂⢄⠀⠲⠀⠃⡀⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡙⢦⣹⡟⣻⢶⡍⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠄⠀⠀⠀⡀⠀\n\
⠄⡰⠈⠀⢰⠀⡖⢡⠞⢀⠁⠒⠀⠀⠀⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡄⣸⢦⡹⡷⢯⣽⢻⡝⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠃⠈⠀⠀⠀\n\
⢠⣃⡇⢠⠛⣀⠀⠁⠈⠀⡄⠀⡀⣄⠠⠄⢀⡰⠀⠤⠐⢠⠰⢈⡄⢚⠰⣹⡏⣶⢻⣭⠟⣬⢻⡔⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠠⠸⠄⠈⠀⠀⣀⠈⡄⢯⠁⠀⠜⠧⠀⠀⡄⣃⠩⡔⣹⠂⡱⠤⣋⠤⠇⢹⣧⡻⣜⣾⣳⡈⢇⠧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⢐⡂⠀⠊⠀⠁⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⢀⣀⠀⡄⢲⠁⡞⡀⠂⠄⠠⢉⡄⠀⣱⠃⢤⣛⡷⡘⠤⠙⠰⠀⠘⡂⠼⢀⡻⡼⢣⢓⡯⠈⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠤⣘⠀⢰⠀⠀⠆⠈⠀⠀⠀⠀⠠⠀⠀⠀⠀⠀\n\
⡔⢪⢸⠳⣄⡻⢄⠇⣠⢣⢌⡱⢊⡔⢈⣷⠏⣆⢻⠆⡙⠎⠀⠀⠀⠈⠀⠰⢈⣷⠰⣤⢃⡳⢄⠧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⡈⠐⠀⠰⠰⣀⠁⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠱⢯⣼⣆⡟⣧⠈⠘⡀⡀⠀⠆⡁⣌⠸⢋⡐⠈⡁⠂⠀⠁⠀⠀⠀⠐⠀⢁⢨⢇⡏⢀⠿⡀⠃⠘⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡐⠈⠀⠀⠀⠂⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⡘⢶⡸⣿⡞⡭⠃⡝⡀⠛⡄⠘⠏⠰⠈⠀⠉⠀⠀⠀⠀⠀⠀⠀⠀⠈⢀⠐⡚⠌⢢⢽⡂⢐⡀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠈⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠈⡆⢡⣜⠂⣵⠂⡔⣃⠀⡌⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⡇⡎⡄⣡⠂⡌⢣⣜⣶⡏⣀⠀⣌⡁⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⢦⡀⠰⣈⠂⡡⠀⠡⠙⠤⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠀⢿⣱⠂⢀⠃⠀⣰⣎⣿⡼⠆⠉⠀⢬⢳⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⢫⡔⡡⠦⢡⠃⡙⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠁⡬⠁⠁⠊⢄⠳⣼⣟⣾⣳⢂⢀⡀⠌⢣⢈⢂⠀⠀⢀⠀⠀⠀⠀⠀⡀⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⢦⡙⠆⠹⡐⠀⠐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⡇⢰⡀⠙⢦⢃⣾⠟⡰⣹⢯⠜⠲⡘⢣⠎⠰⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠣⢌⠠⠀⠠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠀⠀⠀⠀⠀⠈⠀⠀⠀⠈⠘⠉⠷⢣⢟⡃⠦⠱⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀\n\
⡁⠌⠐⠠⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠠⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠄⡀⠀⠄⠀⠀⠀⠀⠀⠀⠀⡀⠀⠄⠀⠀⡁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠀⠀⠀⠀⠀⠀\n\
⠂⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠌⡀⠐⡀⠐⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠀⠅⡀⢇⠈⡷⠀⢠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡰⡀⢘⡤⢣⡁⠠⠃⣂⠐⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠀⠅⡀⢂⡞⠁⢼⠀⠅⣨⢃⠐⠀⡧⠀⣆⠠⠀⢀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠂⠰⡀⠠⣆⠈⠀⣵⠀⡜⠩⢀⡞⠒⢤⡃⠁⠀⠀⡰⡄⠀⠀⠀⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⢀⠀⡀⠄⠐⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⠀⠀⠁⠒⢍⠲⡂⢹⡆⢰⣐⣆⣧⢆⣸⣆⡀⢦⠀⡥⢎⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠂⡄⢰⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠈⠁⠚⠁⠋⠊⠐⠛⠁⠂⠡⠘⠊⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠰⠀⠇⢀⠠⠀⢐⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠤⠄⠠⠄⠀⠀⠈⠀⣀⠀⠀⠀⠀⠀⠀⠀⠠⠄⠀⠀⢀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠄⠚⠤⢆⡀⠀⠠⠄⠀⠰⠀⠀⠀⠀⢁⠂⠀⠀⠀⡃⢀⢲⡀⢂⡔⢀⡐⢦⠸⡀⢰⠀⡄⢾⠀⢆⠆⠀⢀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⡄⠀⠀⠀⠘⠀⠀⠂⠀⠈⠀⠏⠀⠀⠀⢈⠂⠀⠀⠀⠂⢅⠪⠌⣅⠘⠶⡸⣄⡞⣀⠇⢉⠒⡌⠸⢂⠠⢂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠀⠀⠀⠐⠄⢀⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⠀⠐⠉⠙⠞⠀⠈⠀⠑⠂⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
⠈⡀⠈⠀⠀⠊⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\
"
class ShrubberyCreationForm: public AForm
{
	private:
		const std::string target;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm&);

		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm&);

		void	execute(const Bureaucrat&);

		class CreateFileException: public std::exception
		{
			private:
				mutable std::string _target;

			public:
				CreateFileException(const std::string target);
				const char* what() const throw();
				~CreateFileException(void) throw();
		};

		~ShrubberyCreationForm(void);
};
