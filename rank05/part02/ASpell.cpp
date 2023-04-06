/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:19:49 by pandalaf          #+#    #+#             */
/*   Updated: 2023/04/05 17:21:00 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell()
{

}

ASpell::ASpell(const ASpell & other)
{
	name = other.name;
	effects = other.effects;
}

ASpell::~ASpell()
{

}

ASpell &	ASpell::operator=(const ASpell & other)
{
	if (this != &other)
	{
		name = other.name;
		effects = other.effects;
	}
	return (*this);
}

ASpell::ASpell(const std::string & spellname, const std::string & spelleffects):
	name(spellname),
	effects(spelleffects)
{
	
}

const std::string &	ASpell::getName() const
{
	return (name);
}

const std::string & ASpell::getEffects() const
{
	return (effects);
}

void	ASpell::launch(const ATarget & spelltarget) const
{
	spelltarget.getHitBySpell(*this);
}
