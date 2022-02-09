/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <msosnova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:08:04 by msosnova          #+#    #+#             */
/*   Updated: 2021/06/21 14:08:37 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	static t_readbuffer	buff[FD_MAX] = {0};
	int					end;
	char				*line;

	if (BUFFER_SIZE < 0 || fd < 0 || fd == 1 || fd == 2 || fd >= FD_MAX)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (buff[fd].start == 0)
			buff[fd].n = read(fd, buff[fd].buf, BUFFER_SIZE);
		if (buff[fd].n < 0)
			return (NULL);
		if (buff[fd].n == 0)
			return (line);
		end = ft_findend(buff[fd]);
		if (end < buff[fd].n)
		{
			line = ft_newline(line, buff[fd].buf, buff[fd].start, end + 1);
			buff[fd].start = end + 1;
			return (line);
		}
		line = ft_newline(line, buff[fd].buf, buff[fd].start, end);
		buff[fd].start = 0;
	}
}
