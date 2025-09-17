/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:23:04 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/17 17:23:05 by yanflous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int 				fixed_point;
		static const int	fractional_bit;
	public:
		Fixed();

		Fixed(const int int_nbr);
		Fixed(const float float_nbr);
		float toFloat( void ) const;
		int toInt( void ) const;
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &copy);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		~Fixed();
};

# endif

