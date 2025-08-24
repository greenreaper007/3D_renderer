/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:50:53 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/24 05:47:31 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlengnl(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_callocgnl(unsigned nmeb, unsigned size)
{
	void	*ptr;

	if (nmeb == 0 || size == 0)
		return (ptr = (void *)malloc(nmeb * size), ptr);
	ptr = (void *)malloc(nmeb * size);
	if (!ptr)
		return (NULL);
	ft_bzerognl(ptr, nmeb * size);
	return (ptr);
}

void	ft_bzerognl(void *s, unsigned int n)
{
	unsigned int	i;
	char			*ptr;

	ptr = (char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

char	*ft_reallocgnl(char *str)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i])
		i++;
	res = ft_callocgnl(BUFFER_SIZE + i + 1, 1);
	if (!res)
		return (NULL);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	free(str);
	return (res);
}

char	*ft_strcpygnl(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
