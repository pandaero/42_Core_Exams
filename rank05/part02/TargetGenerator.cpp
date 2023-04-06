/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:41:38 by pandalaf          #+#    #+#             */
/*   Updated: 2023/04/05 21:10:35 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{

}

TargetGenerator::TargetGenerator(const TargetGenerator & other)
{
	(void) other;
}

TargetGenerator::~TargetGenerator()
{

}

TargetGenerator &	TargetGenerator::operator=(const TargetGenerator & other)
{
	if (this == &other)
		new (this) TargetGenerator(other);
	return (*this);
}

void	TargetGenerator::learnTargetType(ATarget * target)
{
	if (std::find(targetTypeList.begin(), targetTypeList.end(), target->getType()) == targetTypeList.end())
	{
		targetTypeList.push_back(target->getType());
		targetList.push_back(target);
	}
}

void	TargetGenerator::forgetTargetType(const std::string & targetType)
{
	if (std::find(targetTypeList.begin(), targetTypeList.end(), targetType) != targetTypeList.end())
	{
		size_t	index = std::distance(targetTypeList.begin(), std::find(targetTypeList.begin(), targetTypeList.end(), targetType));
		targetTypeList.erase(std::find(targetTypeList.begin(), targetTypeList.end(), targetType));
		std::vector<ATarget *>::iterator	targetIt = targetList.begin();
		std::advance(targetIt, index);
		targetList.erase(targetIt);
	}
}

ATarget *	TargetGenerator::createTarget(const std::string & targetType)
{
	if (std::find(targetTypeList.begin(), targetTypeList.end(), targetType) != targetTypeList.end())
	{
		size_t	index = std::distance(targetTypeList.begin(), std::find(targetTypeList.begin(), targetTypeList.end(), targetType));
		std::vector<ATarget *>::iterator	targetIt = targetList.begin();
		std::advance(targetIt, index);
		return ((*targetIt)->clone());
	}
	return (NULL);
}
