/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:15:22 by pandalaf          #+#    #+#             */
/*   Updated: 2023/04/06 13:17:10 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <string>

# include "ATarget.hpp"

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

		virtual ASpell *	clone() const = 0;

		void	launch(const ATarget &) const;

	protected:
		std::string	name;
		std::string	effects;
};
#endif
