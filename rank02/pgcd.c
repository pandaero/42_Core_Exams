/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:30:36 by pandalaf          #+#    #+#             */
/*   Updated: 2022/11/07 15:04:28 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

//Function obtains the valid denominators of an integer and stores in array.
int	*denoms(int num)
{
	int	den;
	int	*list;
	int	i;

	i = 0;
	den = 1;
	while (den <= num)
	{
		if (num % den == 0)
			i++;
		den++;
	}
	list = (int *)malloc((i + 1) * sizeof(int));
	i = 0;
	den = 1;
	while (den <= num)
	{
		if (num % den == 0)
			list[i++] = den;
		den++;
	}
	list[i + 1] = 0;
	return (list);
}

//Function returns the highest common value between two integer arrays.
int	common(int *arr1, int *arr2)
{
	int	max;
	int	i;
	int	j;

	max = 0;
	i = 0;
	while (arr1[i] != 0)
	{
		j = 0;
		while (arr2[j] != 0)
		{
			if (arr1[i] == arr2[j] && arr1[i] > max)
				max = arr1[i];
			j++;
		}
		i++;
	}
	return (max);
}

//Program displays the largest common denominator between two integers.
int	main(int argc, char **argv)
{
	int	*dens1;
	int	*dens2;

	if (argc == 3)
	{
		dens1 = denoms(atoi(argv[1]));
		dens2 = denoms(atoi(argv[2]));
		printf("%d", common(dens1, dens2));
		free(dens1);
		free(dens2);
	}
	printf("\n");
	return (0);
}
