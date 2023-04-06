/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:20:46 by pandalaf          #+#    #+#             */
/*   Updated: 2023/04/05 21:10:01 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>

#include "SpellBook.hpp"

SpellBook::SpellBook()
{

}

SpellBook::SpellBook(const SpellBook & other)
{
	(void) other;
}

SpellBook::~SpellBook()
{

}

SpellBook &	SpellBook::operator=(const SpellBook & other)
{
	if (this == &other)
		new (this) SpellBook(other);
	return (*this);
}

void	SpellBook::learnSpell(ASpell * spellPtr)
{
	if (std::find(spellNameList.begin(), spellNameList.end(), spellPtr->getName()) == spellNameList.end())
	{
		spellCastList.push_back(spellPtr->clone());
		spellNameList.push_back(spellPtr->getName());
	}
}

void	SpellBook::forgetSpell(const std::string & spellname)
{
	if (std::find(spellNameList.begin(), spellNameList.end(), spellname) != spellNameList.end())
	{
		size_t	index = std::distance(spellNameList.begin(), std::find(spellNameList.begin(), spellNameList.end(), spellname));
		spellNameList.erase(std::find(spellNameList.begin(), spellNameList.end(), spellname));
		std::vector<ASpell *>::iterator	castIt = spellCastList.begin();
		std::advance(castIt, index);
		spellCastList.erase(castIt);
	}
}

ASpell *	SpellBook::createSpell(const std::string & spellname)
{
	if (std::find(spellNameList.begin(), spellNameList.end(), spellname) != spellNameList.end())
	{
		size_t	index = std::distance(spellNameList.begin(), std::find(spellNameList.begin(), spellNameList.end(), spellname));
		std::vector<ASpell *>::iterator	castIt = spellCastList.begin();
		std::advance(castIt, index);
		return ((*castIt)->clone());
	}
	return (NULL);
}
