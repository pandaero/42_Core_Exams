/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:40:48 by pandalaf          #+#    #+#             */
/*   Updated: 2023/04/06 13:17:27 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FWOOSH_HPP
# define FWOOSH_HPP

# include "ASpell.hpp"

class	Fwoosh: public ASpell
{
	public:
		Fwoosh();
		Fwoosh(const Fwoosh &);
		~Fwoosh();
		Fwoosh &	operator=(const Fwoosh &);

		Fwoosh *	clone() const;
};
#endif
