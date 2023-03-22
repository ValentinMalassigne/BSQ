/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmalassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:01:40 by vmalassi          #+#    #+#             */
/*   Updated: 2023/03/22 21:01:42 by vmalassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*res;

	if (!src)
		return (NULL);
	res = malloc(sizeof(char) * (1 + ft_strlen(src)));
	if (!src)
		return (NULL);
	i = -1;
	while (src[++i])
		res[i] = src[i];
	res[i] = '\0';
	return (res);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size)
	{
		while (i < size - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return ((unsigned int)ft_strlen(src));
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	src_len = (unsigned int)ft_strlen(src);
	dest_len = (unsigned int)ft_strlen(dest);
	if (size <= dest_len)
		return (src_len + size);
	i = 0;
	while (src[i] && i + dest_len < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (src_len + dest_len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*res;
	unsigned int	size;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	size = 1 + ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * size);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, size);
	ft_strlcat(res, s2, size);
	return (res);
}
