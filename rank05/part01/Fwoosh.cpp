#include "Fwoosh.hpp"

Fwoosh::Fwoosh()
{
	setName("Fwoosh");
	setEffects("fwooshed");
}

Fwoosh::Fwoosh(const Fwoosh & other):
	ASpell()
{
	(void) other;
}

Fwoosh::~Fwoosh()
{

}

Fwoosh &	Fwoosh::operator=(const Fwoosh & other)
{
	(void) other;
	return (*this);
}

Fwoosh *	Fwoosh::clone() const
{
	return (new Fwoosh());
}
