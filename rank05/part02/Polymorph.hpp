/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:07:52 by pandalaf          #+#    #+#             */
/*   Updated: 2023/04/05 19:09:50 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP

# include "ASpell.hpp"

class	Polymorph:	public	ASpell
{
	public:
		Polymorph();
		Polymorph(const Polymorph &);
		~Polymorph();
		Polymorph &	operator=(const Polymorph &);

		Polymorph *	clone() const;
};
#endif
