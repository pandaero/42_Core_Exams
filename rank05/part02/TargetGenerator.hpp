/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:35:45 by pandalaf          #+#    #+#             */
/*   Updated: 2023/04/05 20:44:56 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <string>
# include <vector>

# include "ATarget.hpp"

class	TargetGenerator
{
	public:
		TargetGenerator();
		~TargetGenerator();

		void		learnTargetType(ATarget *);
		void		forgetTargetType(const std::string &);
		ATarget *	createTarget(const std::string &);

	private:
		TargetGenerator(const TargetGenerator &);
		TargetGenerator &	operator=(const TargetGenerator &);
		std::vector<ATarget *>		targetList;
		std::vector<std::string>	targetTypeList;
};
#endif
