#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <string>

class	ATarget;

class	ASpell
{
	public:
		ASpell();
		ASpell(const ASpell &);
		virtual	~ASpell();
		ASpell &	operator=(const ASpell &);

		ASpell(const std::string &, const std::string &);

		const std::string &	getName() const;
		const std::string &	getEffects() const;

		void	setName(const std::string &);
		void	setEffects(const std::string &);

		void	launch(const ATarget &);

		virtual ASpell *	clone() const = 0;

	private:
		std::string	name;
		std::string	effects;
};
#endif
