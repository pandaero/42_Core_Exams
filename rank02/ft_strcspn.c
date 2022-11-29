/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:58:59 by pandalaf          #+#    #+#             */
/*   Updated: 2022/11/29 01:49:35 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

//Function gets the length of string until character from second string appears.
size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (reject[j] != '\0')
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

/* Test with: cc -Wall -Werror -Wextra ft_strcspn.c
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "Hell0";
	char	rej[] = "012345";

	printf("Original\n");
	printf("Str: %s, Rej: %s, Out: %ld\n", str, rej, strcspn(str, rej));
	printf("Own\n");
	printf("Str: %s, Rej: %s, Out: %ld\n", str, rej, ft_strcspn(str, rej));
	return (0);
}
//*/
