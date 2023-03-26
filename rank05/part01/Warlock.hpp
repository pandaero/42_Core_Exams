#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include "ASpell.hpp"
# include "ATarget.hpp"

# include <vector>

class	Warlock
{
	public:
		Warlock(const Warlock &);
		~Warlock();

		Warlock(const std::string &, const std::string &);

		const std::string &	getName() const;
		const std::string &	getTitle() const;

		void	setTitle(const std::string &);

		void	introduce() const;

		void	learnSpell(ASpell *);
		void	forgetSpell(std::string);
		void	launchSpell(std::string, const ATarget &);

	private:
		Warlock();
		Warlock &	operator=(const Warlock &);

		std::string				name;
		std::string				title;
		std::vector<ASpell *>	spells;
};
#endif
