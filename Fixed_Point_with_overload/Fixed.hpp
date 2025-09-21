/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanflous <yanflous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:23:04 by yanflous          #+#    #+#             */
/*   Updated: 2025/09/22 09:39:25 by yanflous         ###   ########.fr       */
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

		bool operator>(const Fixed &copy) const;
		bool operator<(const Fixed &copy) const;
		bool operator>=(const Fixed &copy) const;
		bool operator<=(const Fixed &copy) const;
		bool operator==(const Fixed &copy) const;
		bool operator!=(const Fixed &copy) const;

		Fixed operator+(const Fixed &copy) const;
		Fixed operator-(const Fixed &copy) const;
		Fixed operator*(const Fixed &copy) const;
		Fixed operator/(const Fixed &copy) const;

		// >>> pre inc
		Fixed &operator++();
		Fixed &operator--();

		// >>> post inc
		Fixed operator++(int);
		Fixed operator--(int);

		
		static Fixed &min(Fixed &f1, Fixed &f2);
		static const Fixed &min(const Fixed &f1, const Fixed &f2);

		static Fixed &max(Fixed &f1, Fixed &f2);
		static const Fixed &max(const Fixed &f1, const Fixed &f2);
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		~Fixed();
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

# endif

