#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell()
{

}

ASpell::ASpell(const ASpell & other):
	name(other.name),
	effects(other.effects)
{

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

ASpell::ASpell(const std::string & nameSet, const std::string & effectsSet):
	name(nameSet),
	effects(effectsSet)
{

}

const std::string &	ASpell::getName() const
{
	return (name);
}

const std::string &	ASpell::getEffects() const
{
	return (effects);
}

void	ASpell::setName(const std::string & nameSet)
{
	name = nameSet;
}

void	ASpell::setEffects(const std::string & effectsSet)
{
	effects = effectsSet;
}

void	ASpell::launch(const ATarget & target)
{
	target.getHitBySpell(*this);
}
