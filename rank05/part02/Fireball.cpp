/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:47:23 by pandalaf          #+#    #+#             */
/*   Updated: 2023/04/05 17:29:22 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fireball.hpp"

Fireball::Fireball()
{
	name = "Fireball";
	effects = "burnt to a crisp";
}

Fireball::Fireball(const Fireball & other):
	ASpell()
{
	name = other.name;
	effects = other.effects;
}

Fireball::~Fireball()
{

}

Fireball &	Fireball::operator=(const Fireball & other)
{
	if (this != &other)
		new (this) Fireball(other);
	return (*this);
}

Fireball *	Fireball::clone() const
{
	return (new Fireball());
}
