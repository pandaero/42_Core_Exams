/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:52:10 by pandalaf          #+#    #+#             */
/*   Updated: 2023/04/06 13:17:16 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRICKWALL_HPP
# define BRICKWALL_HPP

# include "ATarget.hpp"

class	BrickWall: public ATarget
{
	public:
		BrickWall();
		BrickWall(const BrickWall &);
		~BrickWall();
		BrickWall &	operator=(const BrickWall &);

		BrickWall *	clone() const;
};
#endif
