/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmalassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:30:47 by vmalassi          #+#    #+#             */
/*   Updated: 2023/03/21 19:30:48 by vmalassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	**remove_filter(int **filtered_map, char *mask, int lignes, int col)
{
	int		i;
	int		j;
	char	**map;

	map = malloc(lignes * sizeof(int *));
	i = 0;
	while (i < lignes)
	{
		j = 0;
		map[i] = malloc(col * sizeof(int));
		while (j < col)
		{
			if (filtered_map[i][j] == 0)
				map[i][j] = mask[1];
			else if (filtered_map[i][j] == 1)
				map[i][j] = mask[0];
			else
				map[i][j] = mask[2];
			j++;
		}
		i++;
	}
	return (map);
}

int	**apply_filter(char **map, char *mask, int lignes, int colonnes)
{
	int	i;
	int	j;
	int	**filtered_map;

	filtered_map = malloc(lignes * sizeof(int *));
	i = 0;
	while (i < lignes)
	{
		j = 0;
		filtered_map[i] = malloc(colonnes * sizeof(int));
		while (j < colonnes)
		{
			if (map[i][j] == mask[0])
				filtered_map[i][j] = 1;
			else if (map[i][j] == mask[1])
				filtered_map[i][j] = 0;
			else
				filtered_map[i][j] = 2;
			j++;
		}
		i++;
	}
	return (filtered_map);
}

char	*get_filter(char *file_content)
{
	char	*filter;
	int		i;

	i = 0;
	filter = malloc(4 * sizeof(char));
	while (file_content[i] < 58 && file_content[i] > 47 && file_content[i])
		i++;
	filter[0] = file_content[i++];
	filter[1] = file_content[i++];
	filter[2] = file_content[i++];
	filter[3] = '\0';
	return (filter);
}
