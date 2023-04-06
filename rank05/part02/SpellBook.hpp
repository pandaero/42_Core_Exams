/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:16:52 by pandalaf          #+#    #+#             */
/*   Updated: 2023/04/05 19:30:38 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <string>
# include <vector>

# include "ASpell.hpp"

class	SpellBook
{
	public:
		SpellBook();
		~SpellBook();

		void		learnSpell(ASpell *);
		void		forgetSpell(const std::string &);
		ASpell *	createSpell(const std::string &);

	private:
		SpellBook(const SpellBook &);
		SpellBook &	operator=(const SpellBook &);

		std::vector<ASpell *>		spellCastList;
		std::vector<std::string>	spellNameList;
};
#endif
