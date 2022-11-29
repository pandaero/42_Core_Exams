/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:55:17 by pandalaf          #+#    #+#             */
/*   Updated: 2022/11/08 10:23:48 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//Function interpretes a string to give the positive integer it contains.
int	small_atoi(const char *str)
{
	int	i;
	int	sum;

	sum = 0;
	i = 0;
	while (str[i] != '\0')
	{
		sum = sum * 10 + (str[i] - '0');
		i++;
	}
	return (sum);
}

//Function takes a positive decimal integer and prints out the hexadecimal.
void	hexprint(int num)
{
	char	ch[8];
	int		tmp;
	int		i;

	if (num == 0)
		write(1, "0", 1);
	i = 0;
	while (num > 0)
	{
		tmp = num % 16;
		if (tmp >= 10 && tmp <= 15)
			ch[i] = (tmp - 10) + 'a';
		else
			ch[i] = tmp + '0';
		num /= 16;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &ch[i], 1);
		i--;
	}
}

//Program takes a positive decimal integer and returns the hexadecimal number.
int	main(int argc, char **argv)
{
	if (argc == 2)
		hexprint(small_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}
