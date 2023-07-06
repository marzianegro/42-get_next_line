/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:50:40 by mnegro            #+#    #+#             */
/*   Updated: 2023/03/04 16:50:41 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* HEADER FILES */
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* CONSTANTS */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* PROTOTYPES */
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_clean_buftomem(char *buftomem, int i);
int		ft_find_newline(char *buftomem);
char	*ft_free(char **buf);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);

#endif
