/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:36:02 by csavreux          #+#    #+#             */
/*   Updated: 2024/12/14 02:19:47 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// Returns the length of a string.
static size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

// Returns a new line containing : the old line + the characters in the buffer
// up to the end index. Copies all the buffer in the line if end == -1.
char	*ft_add_buf_to_line(char *line, char *buf, ssize_t end)
{
	char	*newline;
	size_t	size_line;
	ssize_t	i;

	i = -1;
	size_line = 0;
	if (ft_strlen(line) != 0)
		size_line = ft_strlen(line);
	if (end == -1)
		end = ft_strlen(buf) - 1;
	newline = malloc((size_line + (end + 1) + 1) * sizeof(char));
	if (!newline)
	{
		buf[0] = '\0';
		return (free(line), NULL);
	}
	while ((size_line != 0) && line[++i])
		newline[i] = line[i];
	i = -1;
	if (end == -1)
		end = ft_strlen(buf) - 1;
	while (++i <= end)
		newline[size_line + i] = buf[i];
	newline[size_line + i] = '\0';
	return (free(line), newline);
}

// Copies the characters read but not already in a line in the buffer.
void	ft_pending_buf(char *buf, ssize_t start)
{
	size_t	i;

	i = 0;
	while ((start != -1) && buf[start + 1])
	{
		buf[i] = buf[start + 1];
		i++;
		start++;
	}
	buf[i] = '\0';
}

// Returns the number of characters in the buffer needing to be added to
// the current line. If the '\n' character isn't found in the buffer,
// -1 is returned.
ssize_t	ft_eol_search(char *buf)
{
	size_t	nb;

	nb = 0;
	while (buf[nb])
	{
		if (buf[nb] == '\n')
			return (nb);
		nb++;
	}
	return (-1);
}
