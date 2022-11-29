/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:40:16 by pandalaf          #+#    #+#             */
/*   Updated: 2022/11/07 20:52:52 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//Program takes an input string and repeats the alphabetical chars accordingly.
int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	num;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i] != '\0')
		{
			num = 1;
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				num = argv[1][i] - 'a' + 1;
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				num = argv[1][i] - 'A' + 1;
			j = 0;
			while (j < num)
			{
				write(1, &argv[1][i], 1);
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
