#include "Dummy.hpp"

Dummy::Dummy(): ATarget("Target Practice Dummy")
{

}

Dummy::Dummy(const Dummy & other)
{
	(void) other;
}

Dummy::~Dummy()
{

}

Dummy &	Dummy::operator=(const Dummy & other)
{
	(void) other;
	return (*this);
}

Dummy *	Dummy::clone()
{
	return (new Dummy());
}
