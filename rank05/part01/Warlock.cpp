#include "Warlock.hpp"

#include <iterator>
#include <algorithm>

Warlock::Warlock()
{

}

Warlock::Warlock(const Warlock & other):
	name(other.name),
	title(other.title),
	spells(other.spells)
{

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

Warlock::Warlock(const std::string & nameSet, const std::string & titleSet):
	name(nameSet),
	title(titleSet)
{
	std::cout << name << ": This looks like another boring day." << std::endl;
}

void	Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

const std::string &	Warlock::getName() const
{
	return (name);
}

const std::string &	Warlock::getTitle() const
{
	return (title);
}

void	Warlock::setTitle(const std::string & titleSet)
{
	title = titleSet;
}
#include <iostream>
void	Warlock::learnSpell(ASpell * spell)
{
	if (find(spells.begin(), spells.end(), spell) == spells.end())
		spells.push_back(spell);
}

void	Warlock::forgetSpell(std::string spellName)
{
	for (size_t i = 0; i < spells.size(); ++i)
	{
		if (spells[i]->getName() == spellName)
		{
			std::vector<ASpell *>::iterator	start = spells.begin();
			std::advance(start, i);
			spells.erase(start);
		}
	}
}

void	Warlock::launchSpell(std::string spellName, const ATarget & target)
{
	for (size_t i = 0; i < spells.size(); ++i)
	{
		if (spells[i]->getName() == spellName)
			target.getHitBySpell(*spells[i]);
	}
}
