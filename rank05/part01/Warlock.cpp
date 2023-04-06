/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:39:40 by pandalaf          #+#    #+#             */
/*   Updated: 2023/04/05 18:12:34 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>

#include "Warlock.hpp"

Warlock::Warlock()
{

}

Warlock::Warlock(const Warlock & other)
{
	name = other.name;
	title = other.title;
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!" << std::endl;
}

Warlock &	Warlock::operator=(const Warlock & other)
{
	if (this != &other)
		new (this) Warlock(other);
	return (*this);
}

Warlock::Warlock(const std::string & warname, const std::string & wartitle):
	name(warname),
	title(wartitle)
{
	std::cout << name << ": This looks like another boring day." << std::endl;
}

const std::string &	Warlock::getName() const
{
	return (name);
}

const std::string &	Warlock::getTitle() const
{
	return (title);
}

void	Warlock::setTitle(const std::string & wartitle)
{
	title = wartitle;
}

void	Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell * spell)
{
	if (std::find(spellCastList.begin(), spellCastList.end(), spell) == spellCastList.end())
	{
		spellCastList.push_back(spell);
		spellNameList.push_back(spell->getName());
	}
}

void	Warlock::forgetSpell(std::string spellname)
{
	if (std::find(spellNameList.begin(), spellNameList.end(), spellname) != spellNameList.end())
	{
		spellNameList.erase(std::find(spellNameList.begin(), spellNameList.end(), spellname));
		size_t	index = std::distance(spellNameList.begin(), std::find(spellNameList.begin(), spellNameList.end(), spellname));
		std::vector<ASpell *>::iterator	castIt = spellCastList.begin();
		std::advance(castIt, index);
		spellCastList.erase(castIt);
	}
}

void	Warlock::launchSpell(std::string spellname, const ATarget & target)
{
	if (std::find(spellNameList.begin(), spellNameList.end(), spellname) != spellNameList.end())
		spellCastList[std::distance(spellNameList.begin(), std::find(spellNameList.begin(), spellNameList.end(), spellname))]->launch(target);
}
