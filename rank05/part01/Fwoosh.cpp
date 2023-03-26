#include "Fwoosh.hpp"

Fwoosh::Fwoosh()
{
	setName("Fwoosh");
	setEffects("fwooshed");
}

Fwoosh::Fwoosh(const Fwoosh & other)
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

Fwoosh *	Fwoosh::clone()
{
	return (new Fwoosh());
}
