/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:26:45 by pandalaf          #+#    #+#             */
/*   Updated: 2023/04/06 13:17:05 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <string>

# include "ASpell.hpp"

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

		virtual ATarget *	clone() const = 0;

		void	getHitBySpell(const ASpell &) const;

	protected:
		std::string	type;
};
#endif
