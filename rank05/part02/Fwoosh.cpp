/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:47:23 by pandalaf          #+#    #+#             */
/*   Updated: 2023/04/06 13:18:07 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"

Fwoosh::Fwoosh()
{
	name = "Fwoosh";
	effects = "fwooshed";
}

Fwoosh::Fwoosh(const Fwoosh & other):
	ASpell()
{
	name = other.name;
	effects = other.effects;
}

Fwoosh::~Fwoosh()
{

}

Fwoosh &	Fwoosh::operator=(const Fwoosh & other)
{
	if (this != &other)
		new (this) Fwoosh(other);
	return (*this);
}

Fwoosh *	Fwoosh::clone() const
{
	return (new Fwoosh());
}
