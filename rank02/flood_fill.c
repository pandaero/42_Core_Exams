/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:26:07 by pandalaf          #+#    #+#             */
/*   Updated: 2022/11/29 01:48:11 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Type describes a point with x and y coordinats.
typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

//Function changes a character based on the neighbouring characters being equal.
void	fill(char **tab, t_point size, t_point point, char ch)
{
	if (point.y < 0 || point.y >= size.y || point.x < 0 || point.x >= size.x)
		return ;
	if (tab[point.y][point.x] != ch)
		return ;
	tab[point.y][point.x] = 'F';
	fill(tab, size, (t_point){point.x - 1, point.y}, ch);
	fill(tab, size, (t_point){point.x + 1, point.y}, ch);
	fill(tab, size, (t_point){point.x, point.y - 1}, ch);
	fill(tab, size, (t_point){point.x, point.y + 1}, ch);
}

//Function takes a table and a starting point. It fills like-points vrt and hrz.
void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

/* Test with cc -Wall -Werror -Wextra flood_fill.c
#include <stdio.h>
#include <stdlib.h>

char	**make_area(char** zone, t_point size)
{
	char	**new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}
	return new;
}

int	main(void)
{
	t_point	size = {8, 5};
	t_point	begin = {7, 4};
	char	*zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};
	char	**area = make_area(zone, size);

	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}
//*/
