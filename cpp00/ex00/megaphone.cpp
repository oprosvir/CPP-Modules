/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 23:40:37 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/05 22:17:45 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			std::string arg = argv[i];
			for (size_t j = 0; j < arg.size(); ++j)
				arg[j] = std::toupper(arg[j]);
			std::cout << arg;
		}
		std::cout << std::endl;
	}
	return 0;
}
