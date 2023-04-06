/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:55:23 by pandalaf          #+#    #+#             */
/*   Updated: 2023/04/06 13:17:52 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp"

Dummy::Dummy()
{
	type = "Target Practice Dummy";
}

Dummy::Dummy(const Dummy & other):
	ATarget()
{
	type = other.type;
}

Dummy::~Dummy()
{

}

Dummy &	Dummy::operator=(const Dummy & other)
{
	if (this != &other)
		new (this) Dummy(other);
	return (*this);
}

Dummy *	Dummy::clone() const
{
	return (new Dummy());
}
