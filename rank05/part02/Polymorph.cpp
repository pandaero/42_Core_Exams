/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:47:23 by pandalaf          #+#    #+#             */
/*   Updated: 2023/04/05 17:29:22 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorph.hpp"

Polymorph::Polymorph()
{
	name = "Polymorph";
	effects = "turned into a critter";
}

Polymorph::Polymorph(const Polymorph & other):
	ASpell()
{
	name = other.name;
	effects = other.effects;
}

Polymorph::~Polymorph()
{

}

Polymorph &	Polymorph::operator=(const Polymorph & other)
{
	if (this != &other)
		new (this) Polymorph(other);
	return (*this);
}

Polymorph *	Polymorph::clone() const
{
	return (new Polymorph());
}
