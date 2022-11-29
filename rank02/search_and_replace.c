/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:48:56 by pandalaf          #+#    #+#             */
/*   Updated: 2022/11/08 12:05:38 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

//Program takes a string and a letter to be replaced by another letter.
int	main(int argc, char **argv)
{
	int	i;

	if (argc == 4 && argv[2][1] == '\0' && argv[3][1] == '\0')
	{
		i = 0;
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] == argv[2][0])
				write(1, &argv[3][0], 1);
			else
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
