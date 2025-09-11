/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:14:20 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/11 11:14:21 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	return (std::cout << "invalide args provided" << std::endl, 1);

	std::fstream	in_file;
	std::string		to_find;
	std::string		to_replace;
	std::string		text_file;

	text_file = argv[1];
	to_find = argv[2];
	to_replace = argv[3];
	if (to_find.empty() || to_replace.empty())
	{
		std::cout << "error: Your provinding an empty args that is not valid." << std::endl;
		return (1);
	}

	in_file.open(text_file.c_str(), std::ios::in);
	if (!in_file.is_open())
	{
		std::cout << "failed to open the file" << std::endl;
		return (1);
	}
	std::string file_content;
	getline(in_file, file_content, '\0');
	in_file.close();


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

	std::fstream out_file;
	std::string	new_file;

	new_file = text_file.append(".replace");
	out_file.open(new_file.c_str(), std::ios::out);
	if (!out_file.is_open())
	{
		std::cout << "failed to open the file" << std::endl;
		return (1);
	}
	out_file << new_content;
	out_file.close();

	return (0);	
}
