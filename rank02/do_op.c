/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:06:40 by pandalaf          #+#    #+#             */
/*   Updated: 2022/11/08 12:12:30 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

//Program is a basic 5-operation calculator.
int	main(int argc, char **argv)
{
	int	res;

	if (argc == 4)
	{
		if (argv[2][0] == '+')
			res = atoi(argv[1]) + atoi(argv[3]);
		if (argv[2][0] == '-')
			res = atoi(argv[1]) - atoi(argv[3]);
		if (argv[2][0] == '*')
			res = atoi(argv[1]) * atoi(argv[3]);
		if (argv[2][0] == '/')
			res = atoi(argv[1]) / atoi(argv[3]);
		if (argv[2][0] == '%')
			res = atoi(argv[1]) % atoi(argv[3]);
		printf("%d", res);
	}
	printf("\n");
	return (0);
}
