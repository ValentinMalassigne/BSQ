/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmalassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:11:45 by vmalassi          #+#    #+#             */
/*   Updated: 2023/03/22 19:11:46 by vmalassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_length(char **map, int lines_count)
{
	int	i;
	int	length;

	i = 1;
	length = ft_strlen(map[0]);
	while (i < lines_count)
	{
		if (ft_strlen(map[i]) != length)
			return (0);
		i++;
	}
	if(length < 2)
		return (0);
	return (1);
}

int check_chars(char **map, int lines_count, char *filter)
{
	int	i;
	int	j;
	int	length;

	i = 0;
	j = 0;
	length = ft_strlen(map[0]);
	while (i < lines_count)
	{
		j = 0;
		while (j < length)
		{
			if(map[i][j] != filter[0] && map[i][j] != filter[1] && map[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_inputs(char **map, int lines_count, char *filter)
{
	if (check_length(map, lines_count) != 1)
		return (0);
	if (check_chars(map, lines_count, filter) != 1)
		return (0);
	return (1);
}
