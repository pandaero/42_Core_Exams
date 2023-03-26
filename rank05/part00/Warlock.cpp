#include "Warlock.hpp"

Warlock::Warlock()
{

}

Warlock::Warlock(const Warlock & other):
	name(other.name),
	title(other.title)
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
