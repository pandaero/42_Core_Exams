#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <string>
# include <iostream>

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

	private:
		Warlock();
		Warlock &	operator=(const Warlock &);

		std::string	name;
		std::string	title;
};
#endif
