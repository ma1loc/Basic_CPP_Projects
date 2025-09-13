/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:57:08 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/13 15:57:09 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "file_handler.hpp"

std::string open_to_read(const std::string &text_file)
{
	std::fstream	file;

	file.open(text_file.c_str(), std::ios::in);
	if (!file.is_open())
	{
		std::cout << "error: Failed to open the file" << std::endl;
		exit(1);
	}
	std::string file_content;
	getline(file, file_content, '\0');
	file.close();
	return (file_content);
}

std::string	search_and_replace(
	std::string &file_content,std::string &to_find, std::string &to_replace)
{
	size_t i;

	i = 0;
	std::string new_content;
	while (i < file_content.length())
	{
		if (file_content.compare(i, to_find.length(), to_find) == 0)
		{
			new_content += to_replace;
			i += to_find.length();
		}
		else
		{
			new_content += file_content[i];
			i++;
		}
	}	
	return (new_content);
}

void	save_new_content(std::string &file_name, std::string &new_content)
{
	std::fstream w_file;
	std::string new_file_name;

	new_file_name = file_name.append(".replace");
	w_file.open(new_file_name.c_str(), std::ios::out);
	if (!w_file.is_open())
	{
		std::cout << "error: Failed to open the file" << std::endl;
		exit(1);
	}
	w_file << new_content;
	w_file.close();
}