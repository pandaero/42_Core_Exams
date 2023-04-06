/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:33:43 by pandalaf          #+#    #+#             */
/*   Updated: 2023/04/06 13:11:09 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <string>
# include <vector>

# include "ASpell.hpp"

class	Warlock
{
	public:
		~Warlock();
		Warlock &	operator=(const Warlock &);
	
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
		Warlock(const Warlock &);

		std::string	name;
		std::string	title;
		std::vector<std::string>	spellNameList;
		std::vector<ASpell *>		spellCastList;
};
#endif
