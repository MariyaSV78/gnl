/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:25:21 by msosnova          #+#    #+#             */
/*   Updated: 2021/07/08 12:25:45 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <stdio.h>

// ft_strchr
int	ft_findend(t_readbuffer r_buff)
{
	while (r_buff.start < r_buff.n)
	{
		if (r_buff.buf[r_buff.start] == '\n')
			return (r_buff.start);
		r_buff.start++;
	}
	return (r_buff.start);
}

//ft_strlen
int	ft_len_line(char *line)
{
	unsigned int	i;

	i = 0;
	if (line == 0)
		return (i);
	while (line[i])
		i++;
	return (i);
}

//ft_strjoin
char	*ft_newline(char *temp_line, char *buf, int start, int end)
{
	int		j;
	char	*line;
	int		len_temp_line;

	if (end == start)
		return (temp_line);
	len_temp_line = ft_len_line(temp_line);
	line = (char *)malloc(sizeof(char) * (end - start + len_temp_line + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (j < len_temp_line)
	{
		line[j] = temp_line[j];
		j++;
	}
	while (start < end)
	{
		line[j] = buf[start];
		j++;
		start++;
	}
	line[j] = '\0';
	free(temp_line);
	return (line);
}
