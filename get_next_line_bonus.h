/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:36:15 by csavreux          #+#    #+#             */
/*   Updated: 2024/12/14 02:18:10 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef NB_FD
#  define NB_FD 1023
# endif

# if NB_FD < 0 || NB_FD >= 1024
#  error NB_FD must be >= 0 and < 1024
# endif

# if BUFFER_SIZE <= 0
#  error BUFFER_SIZE must be > 0
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

char	*ft_add_buf_to_line(char *line, char *buf, ssize_t end);

void	ft_pending_buf(char *buf, ssize_t start);

ssize_t	ft_eol_search(char *buf);

#endif
