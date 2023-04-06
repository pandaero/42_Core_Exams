/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:55:23 by pandalaf          #+#    #+#             */
/*   Updated: 2023/04/05 17:31:03 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrickWall.hpp"

BrickWall::BrickWall()
{
	type = "Inconspicuous Red-brick Wall";
}

BrickWall::BrickWall(const BrickWall & other):
	ATarget()
{
	type = other.type;
}

BrickWall::~BrickWall()
{

}

BrickWall &	BrickWall::operator=(const BrickWall & other)
{
	if (this != &other)
		new (this) BrickWall(other);
	return (*this);
}

BrickWall *	BrickWall::clone() const
{
	return (new BrickWall());
}
