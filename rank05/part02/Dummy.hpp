/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:52:10 by pandalaf          #+#    #+#             */
/*   Updated: 2023/04/06 13:17:19 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMMY_HPP
# define DUMMY_HPP

# include "ATarget.hpp"

class	Dummy: public ATarget
{
	public:
		Dummy();
		Dummy(const Dummy &);
		~Dummy();
		Dummy &	operator=(const Dummy &);

		Dummy *	clone() const;
};
#endif
