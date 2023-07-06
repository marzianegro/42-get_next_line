/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:51:05 by mnegro            #+#    #+#             */
/*   Updated: 2023/03/04 16:51:06 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_copy_to_new(char **buftomem);
void	ft_read_from_fd(int fd, char **buftomem);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

char	*ft_copy_to_new(char **buftomem)
{
	int		i;
	char	*newline;

	i = 0;
	while ((*buftomem)[i] != '\n' && (*buftomem)[i] != '\0')
		i++;
	newline = (char *)ft_calloc(i + 2, sizeof(char));
	if (!newline)
		return (NULL);
	i = -1;
	while ((*buftomem)[++i] != '\n' && (*buftomem)[i] != '\0')
		newline[i] = (*buftomem)[i];
	if ((*buftomem)[i] == '\n')
	{
		newline[i] = (*buftomem)[i];
		i++;
	}
	if ((*buftomem)[i] == '\0')
		ft_free(buftomem);
	else
		*buftomem = ft_clean_buftomem(*buftomem, i);
	newline[i] = '\0';
	if (i == 0)
		ft_free(&newline);
	return (newline);
}

void	ft_read_from_fd(int fd, char **buftomem)
{
	int				byteread;
	char			*buf;

	byteread = 1;
	while (byteread > 0 && ft_find_newline(*buftomem))
	{
		buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buf)
			return ;
		byteread = read(fd, buf, BUFFER_SIZE);
		*buftomem = ft_strjoin(*buftomem, buf);
		ft_free(&buf);
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)ft_calloc(ft_strlen(s1) + (ft_strlen(s2) + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	ft_free(&s1);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buftomem;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (ft_free(&buftomem));
	ft_read_from_fd(fd, &buftomem);
	if (!buftomem)
		return (NULL);
	line = ft_copy_to_new(&buftomem);
	if (!line)
		return (NULL);
	return (line);
}
