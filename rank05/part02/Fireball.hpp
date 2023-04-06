/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:07:52 by pandalaf          #+#    #+#             */
/*   Updated: 2023/04/06 13:17:23 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIREBALL_HPP
# define FIREBALL_HPP

# include "ASpell.hpp"

class	Fireball:	public	ASpell
{
	public:
		Fireball();
		Fireball(const Fireball &);
		~Fireball();
		Fireball &	operator=(const Fireball &);

		Fireball *	clone() const;
};
#endif
