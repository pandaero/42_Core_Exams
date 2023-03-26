#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <string>
# include <iostream>

class	ASpell;

class	ATarget
{
	public:
		ATarget();
		ATarget(const ATarget &);
		virtual	~ATarget();
		ATarget &	operator=(const ATarget &);

		ATarget(const std::string &);

		const std::string &	getType() const;

		void	getHitBySpell(const ASpell &) const;

		virtual ATarget *	clone() = 0;

	private:
		std::string	type;
};
#endif
