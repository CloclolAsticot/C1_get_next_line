/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:36:02 by csavreux          #+#    #+#             */
/*   Updated: 2024/12/11 18:40:42 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Returns the length of a string.
size_t	ft_strlen(char **str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

// Returns a new line containing : the old line + the characters in the buffer
// up to the end index.
char	*ft_add_buf_to_line(char *line, char *buf, size_t end)
{
	char *newline;
	size_t size_line;
	size_t i;
	
	i = 0;
	size_line = ft_strlen(line);
	newline = malloc((size_line + (end + 1) + 1) * sizeof(char));

	while (line[i])
	{
		newline[i] = line[i];
		i++;
	}
	i = 0;
	while (i <= end)
	{
		newline[size_line + i] = buf[i];
		i++;
	}
	buf[i] = '\0';
	free(line);
	return (newline);
}

// Copies the characters read but not already in a line in the buffer.
void	ft_pending_buf(char *buf, size_t start)
{
	size_t	i;

	i = 0;
	while (buf[start])
	{
		buf[i] = buf[start];
		i++;
		start++;
	}
	buf[i] = '\0';
}

// Returns the number of characters in the buffer needing to be added to
// the current line. If the '\n' character isn't found in the buffer, 
// the length of the buffer is returned (so all the characters are added).
size_t	ft_nbofchar_to_add(char *buf)
{
	size_t	nb;

	nb = 0;
	while (buf[nb])
	{
		if(buf[nb] == '\n')
			return(nb);
		nb++;
	}
	return(nb);
}
