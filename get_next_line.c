/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:35:34 by csavreux          #+#    #+#             */
/*   Updated: 2024/12/14 02:18:46 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Used if the buffer is empty - reads BUFFER_SIZE bytes in fd and adds it to
// the buffer.
static void	ft_nobuf(ssize_t *nb_read, char *buf, int fd)
{
	*nb_read = read(fd, buf, BUFFER_SIZE);
	buf[*nb_read] = '\0';
}

// Returns a line read from a file descriptor.
char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		nb_read;
	ssize_t		is_eol;

	line = NULL;
	nb_read = 1;
	is_eol = -1;
	while (nb_read != 0 && is_eol == -1)
	{
		if (!buf[0])
			ft_nobuf(&nb_read, buf, fd);
		if (nb_read == -1)
			return (free(line), NULL);
		if (nb_read != 0)
		{
			is_eol = ft_eol_search(buf);
			line = ft_add_buf_to_line(line, buf, is_eol);
			if (!line)
				return (NULL);
			ft_pending_buf(buf, is_eol);
		}
	}
	return (line);
}
