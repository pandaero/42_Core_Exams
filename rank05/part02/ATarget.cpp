/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:31:46 by pandalaf          #+#    #+#             */
/*   Updated: 2023/04/05 17:21:40 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ATarget.hpp"

ATarget::ATarget()
{

}

ATarget::ATarget(const ATarget & other)
{
	type = other.type;
}

ATarget::~ATarget()
{

}

ATarget &	ATarget::operator=(const ATarget & other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

ATarget::ATarget(const std::string & targettype):
	type(targettype)
{

}

const std::string & ATarget::getType() const
{
	return (type);
}

void	ATarget::getHitBySpell(const ASpell & spellcast) const
{
	std::cout << type << " has been " << spellcast.getEffects() << "!" << std::endl;
}
