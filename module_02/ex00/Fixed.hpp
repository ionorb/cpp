/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <yoel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:28:05 by yridgway          #+#    #+#             */
/*   Updated: 2023/04/14 00:46:19 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
class	Fixed
{
	private:
		int					fixed_num;
		static const int	bits = 8;
	
	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed&	operator= (const Fixed& fixed);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
