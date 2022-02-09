/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msosnova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 12:26:48 by msosnova          #+#    #+#             */
/*   Updated: 2021/07/08 12:27:20 by msosnova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# define FD_MAX 1000

typedef struct s_readbuffer
{
	int		start;
	ssize_t	n;
	char	buf[BUFFER_SIZE];
}			t_readbuffer;

char	*get_next_line(int fd);
int		ft_len_line(char *line);
int		ft_findend(t_readbuffer r_buff);
char	*ft_newline(char *temp_line, char *buff, int start, int end);

#endif
