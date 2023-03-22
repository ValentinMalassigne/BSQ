/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmalassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:04:37 by vmalassi          #+#    #+#             */
/*   Updated: 2023/03/22 18:04:39 by vmalassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char *read_line(int buff_size)
{
	int		rd;
	char	*content;
	char	*buf;
	char	*tmp;
	buf = malloc(sizeof(char) * buff_size);
	if (!buf)
		return NULL;
	content = NULL;
	rd = read(0, buf, BUFFER_SIZE);
	if (rd == -1)
	{
		free(buf);
		free(content);
		return NULL;
	}
	buf[rd] = '\0';
	tmp = ft_strjoin(content, buf);
	free(content);
	content = tmp;
	free(buf);
	return (content);
}

char	*correct_first_map_line(char *str)
{
	int 	i;
	int		j;
	char	*res;

	i = 0;
	while(str[i]!= '\n' && str[i])
		i++;
	i = i + 1;
	res = malloc (i * sizeof(char));
	j = 0;
	while (j < i - 1)
	{
		res[j] = str[j];
		j++;
	}
	res[j] = '\0';
	free(str);
	return (res);
}

char	**get_map(int lines_count)
{
	char	**map;
	int		i;
	int		length;

	map = malloc(lines_count * sizeof (char *));
	if (!map)
		return (NULL);
	map[0] = read_line(100000);
	map[0] = correct_first_map_line(map[0]);
	length = ft_strlen(map[0]);
	i = 1;
	while (i < lines_count)
		map[i++] = read_line(length + 1);
	return (map);
}

int	read_inputs(char ***map, char **first_line)
{
	int		lines_count;

	*first_line = read_line(100000);
	if (*first_line == NULL)
		return (0);
	if (verif_first_line(*first_line) != 1)
		return (0);
	lines_count = ft_atoi(get_lines_count(*first_line));
	*map = get_map(lines_count);
	if (!*map)
		return (0);
	return (1);
}
