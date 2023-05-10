/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:10:41 by codespace         #+#    #+#             */
/*   Updated: 2023/05/10 13:27:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP
#include <limits>
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <stdlib.h>
#include <stdint.h>

class Base
{
	public:
		virtual	~Base();
};

class A : public Base
{};

class B : public Base
{};

class C : public Base
{};

#endif
