/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:05:56 by pandalaf          #+#    #+#             */
/*   Updated: 2022/11/28 14:38:50 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

//Function returns the number of digits (including sign) of an integer.
int	numdigs(int num)
{
	int	dg;

	dg = 0;
	if (num == 0)
		dg++;
	if (num < 0)
	{
		num *= -1;
		dg++;
	}
	while (num > 0)
	{
		num /= 10;
		dg++;
	}
	return (dg);
}

//Function performs number to character conversion and writing to string.
static char	*fill(char *str, char *tmp, int num, int i)
{
	int	j;

	j = 0;
	while (num > 0)
	{
		tmp[j] = (num % 10) + '0';
		num /= 10;
		j++;
	}
	if (num == 0)
		j--;
	while (j >= 0)
	{
		str[i] = tmp[j];
		j--;
		i++;
	}
	str[i] = '\0';
	return (str);
}

//Function duplicates a string to a new memory location.
char	*ft_strdup(const char *str)
{
	char	*new;
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	new = (char *)malloc((i + 1) * sizeof(char));
	i = 0;
	while (str[i] != '\0')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = str[i];
	return (new);
}

//Function converts an integer type to a char string containing its value.
char	*ft_itoa(int num)
{
	char	*str;
	char	tmp[10];
	int		i;

	if (num == INT_MIN)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	str = (char *)malloc((numdigs(num) + 1) * sizeof(char));
	i = 0;
	if (num == 0)
	{
		str[0] = '0';
		i++;
	}
	if (num < 0)
	{
		num *= -1;
		str[0] = '-';
		i++;
	}
	str = fill(str, tmp, num, i);
	return (str);
}

/* Test (to run, comment out this line only)
#include <stdio.h>

int	main(void)
{
	int		num = 4532;
	int		neg = -4852;
	char	*zero = ft_itoa(0);
	char	*intg = ft_itoa(num);
	char	*nint = ft_itoa(neg);
	char	*mini = ft_itoa(INT_MIN);
	char	*maxi = ft_itoa(INT_MAX);

	printf("Num: %5d Digs: %2d, Str: %s\n", 0, numdigs(0), zero);
	printf("Num: %5d Digs: %2d, Str: %s\n", num, numdigs(num), intg);
	printf("Num: %5d Digs: %2d, Str: %s\n", neg, numdigs(neg), nint);
	printf("Num: %11d Digs: %2d, Str: %s\n", INT_MAX, numdigs(INT_MAX), maxi);
	printf("Num: %11d Digs: %2d, Str: %s\n", INT_MIN, numdigs(INT_MIN), mini);
	free(zero);
	free(intg);
	free(nint);
	free(mini);
	free(maxi);
	return (0);
}
//*/
