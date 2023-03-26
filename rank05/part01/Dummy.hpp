#ifndef Dummy_HPP
# define Dummy_HPP

# include "ASpell.hpp"
# include "ATarget.hpp"

class	Dummy: public ATarget
{
	public:
		Dummy();
		Dummy(const Dummy &);
		~Dummy();
		Dummy &	operator=(const Dummy &);

		Dummy *	clone();
};
#endif
