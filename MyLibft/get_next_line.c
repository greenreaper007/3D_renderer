/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 03:15:37 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/24 05:47:27 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoingnl(char *s1, char *s2)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;

	i = ft_strlengnl(s1);
	j = 0;
	res = (char *)malloc((i + ft_strlengnl(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (s1)
		ft_strcpygnl(res, s1);
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = 0;
	free(s1);
	return (res);
}

int	find_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_reduce(char *line, char *buffer)
{
	int		i;
	int		j;
	char	*res;

	ft_bzerognl(buffer, BUFFER_SIZE);
	i = 0;
	while (line[i] != '\n')
		i++;
	res = ft_callocgnl(i + 2, 1);
	if (!res)
		return (NULL);
	i = 0;
	while (line[i] != '\n')
	{
		res[i] = line[i];
		i++;
	}
	res[i] = line[i];
	j = -1;
	while (line[i++])
		buffer[++j] = line[i];
	return (free(line), res);
}

int	ft_initgnl(char **line, char *buffer, int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (1);
	if (buffer[0] == 0)
		return (1);
	line[0] = ft_strjoingnl(line[0], buffer);
	if (!line[0])
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;

	line = NULL;
	if (buffer[0] == 0)
		read(fd, buffer, BUFFER_SIZE);
	if (ft_initgnl(&line, buffer, fd))
		return (NULL);
	while (!find_newline(line))
	{
		ft_bzerognl(buffer, BUFFER_SIZE);
		if (read(fd, buffer, BUFFER_SIZE) != BUFFER_SIZE)
		{
			line = ft_strjoingnl(line, buffer);
			return (ft_bzerognl(buffer, BUFFER_SIZE), line);
		}
		line = ft_strjoingnl(line, buffer);
		if (!line)
			return (NULL);
	}
	if (!line)
		return (NULL);
	return (line = ft_reduce(line, buffer), line);
}
