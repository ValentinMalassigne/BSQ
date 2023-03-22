/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_file_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmalassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:43:50 by vmalassi          #+#    #+#             */
/*   Updated: 2023/03/22 17:43:51 by vmalassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	init_map(char **map, char *file_content, int lignes, int colonnes)
{
	int	i;
	int	j;

	i = 0;
	while (*file_content != '\n')
		file_content++;
	file_content++;
	while (i < lignes)
	{
		j = 0;
		map[i] = malloc((colonnes + 1) * sizeof(char));
		while (j < colonnes)
		{
			map[i][j] = *file_content++;
			j++;
		}
		map[i][j] = '\0';
		file_content++;
		i++;
	}
}

char	**get_biggest_square(char **map, char *mask, int lignes, int colonnes)
{
	int		**count_map;
	int		**filtered_map;

	count_map = malloc((lignes + 1) * sizeof(int *));
	filtered_map = apply_filter(map, mask, lignes, colonnes);
	solve(filtered_map, count_map, lignes, colonnes);
	replace_values(filtered_map, count_map, lignes, colonnes);
	map = remove_filter(filtered_map, mask, lignes, colonnes);
	return (map);
}

char	*get_lines_count(char *file_content)
{
	int		i;
	char	*res;

	i = 0;
	while (file_content[i] < 58 && file_content[i] > 47 && file_content[i])
		i++;
	res = malloc((i + 1) * sizeof(char));
	i = 0;
	while (file_content[i] < 58 && file_content[i] > 47 && file_content[i])
	{
		res[i] = file_content[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	get_lines_length(char *file_content)
{
	while (*file_content != '\n' && *file_content)
		file_content++;
	file_content++;
	return (length_until_char(file_content, '\n'));
}
