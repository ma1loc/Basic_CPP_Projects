/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:14:20 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/13 15:55:36 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "file_handler.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	return (std::cout << "error: Invalid args provided" << std::endl, 1);

	std::string		to_find;
	std::string		to_replace;
	std::string		file_name;

	file_name = argv[1];
	to_find = argv[2];
	to_replace = argv[3];
	if (to_find.empty() || to_replace.empty())
	{
		std::cout << "error: Your providing an empty args that is not valid." << std::endl;
		return (1);
	}

	std::string		file_content;
	std::string		new_content;
	file_content = open_to_read(file_name);
	new_content = search_and_replace(file_content, to_find, to_replace);
	save_new_content(file_name, new_content);

	return (0);	
}
