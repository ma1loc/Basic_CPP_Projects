/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:57:06 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/13 15:57:07 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FILE_HANDLER_HPP
# define FILE_HANDLER_HPP

# include <iostream>
# include <fstream>
# include <cstdlib>


std::string open_to_read(const std::string &text_file);
std::string	search_and_replace(
	std::string &file_content,std::string &to_find,
	std::string &to_replace);
void	save_new_content(std::string &file_name,
	std::string &new_content);

# endif