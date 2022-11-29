/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:16:25 by pandalaf          #+#    #+#             */
/*   Updated: 2022/11/08 12:25:49 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//Function that writes out a given integer.
void	wrt_itoa(int num)
{
	char	ch[10];
	int		i;

	i = 0;
	if (num == 0)
		write(1, "0", 1);
	while (num > 0)
	{
		ch[i] = num % 10 + '0';
		num /= 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &ch[i], 1);
		i--;
	}
}

//Program gives the number of parameters passed to it.
int	main(int argc, char **argv)
{
	if (argv[0])
		wrt_itoa(argc - 1);
	write(1, "\n", 1);
	return (0);
}
