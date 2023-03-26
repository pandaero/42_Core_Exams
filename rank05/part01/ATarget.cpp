#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget()
{

}

ATarget::ATarget(const ATarget & other):
	type(other.type)
{

}

ATarget::~ATarget()
{

}

ATarget &	ATarget::operator=(const ATarget & other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

ATarget::ATarget(const std::string & typeSet):
	type(typeSet)
{

}

const std::string &	ATarget::getType() const
{
	return (type);
}

void	ATarget::getHitBySpell(const ASpell & spell) const
{
	std::cout << type + " has been " + spell.getEffects() + '!' << std::endl;
}
