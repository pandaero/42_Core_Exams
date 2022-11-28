/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:17:46 by pandalaf          #+#    #+#             */
/*   Updated: 2022/11/28 14:43:37 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

//Function frees a pointer and returns null.
char	*freeptr(char *ptr)
{
	free(ptr);
	return (0);
}

//Function gets the text before a newline character in a file descriptor.
char	*get_next_line(int fd)
{
	int		i;
	int		rd;
	char	buff;
	char	*line;

	i = 0;
	rd = 1;
	line = (char *)malloc(101010 * sizeof(char));
	while (rd > 0)
	{
		rd = read(fd, &buff, BUFFER_SIZE - BUFFER_SIZE + 1);
		if (rd == 0)
			break ;
		line[i] = buff;
		if (buff == '\n')
		{
			line[i + 1] = '\0';
			return (line);
		}
		i++;
	}
	if (rd == -1 || i == 0 || (rd == 0 && line[i - 1] == '\0'))
		return (freeptr(line));
	line[i] = '\0';
	return (line);
}

/*Test (to run, comment out this line only)
//Make a test file titled "hello"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int	fd = open("hello", O_RDONLY);
	char *line = get_next_line(fd);

	while (line != 0)
	{
		printf("Line: %s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
//*/
