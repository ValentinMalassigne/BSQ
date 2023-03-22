/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmalassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:52:24 by vmalassi          #+#    #+#             */
/*   Updated: 2023/03/21 17:52:26 by vmalassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	init_count_map(int **count_map, int lignes, int colonnes)
{
	int	i;
	int	j;

	i = 0;
	while (i < lignes + 1)
	{
		count_map[i] = malloc((colonnes + 1) * sizeof(int));
		j = 0;
		while (j < colonnes + 1)
			count_map[i][j++] = 0;
		i++;
	}
}

void	fill_count_map(int **count_map, int ligne, int colonne, int map_value)
{
	int	min;

	min = count_map[ligne][colonne];
	if (min > count_map[ligne + 1][colonne])
		min = count_map[ligne + 1][colonne];
	if (min > count_map[ligne][colonne + 1])
		min = count_map[ligne][colonne + 1];
	if (map_value == 0)
		count_map[ligne + 1][colonne + 1] = 0;
	else
		count_map[ligne + 1][colonne + 1] = min + map_value;
}

void	solve(int **map, int **count_map, int lignes, int colonnes)
{
	int	i;
	int	j;

	i = 0;
	init_count_map(count_map, lignes, colonnes);
	while (i < lignes)
	{
		j = 0;
		while (j < colonnes)
		{
			fill_count_map(count_map, i, j, map[i][j]);
			j++;
		}
		i++;
	}
}

t_point	find_max_value(int **count_map, int lignes, int colonnes)
{
	int		i;
	int		j;
	t_point	point;

	i = 0;
	point.value = 0;
	while (i < lignes + 1)
	{
		j = 0;
		while (j < colonnes + 1)
		{
			if (count_map[i][j] > point.value)
			{
				point.value = count_map[i][j];
				point.i = i - 1;
				point.j = j - 1;
			}
			j++;
		}
		i++;
	}
	return (point);
}

void	replace_values(int **map, int **count_map, int lignes, int colonnes)
{
	int		i;
	int		j;
	t_point	point;

	i = 1;
	point = find_max_value(count_map, lignes, colonnes);
	while (point.i - point.value + i <= point.i)
	{
		j = 1;
		while (point.j - point.value + j <= point.j)
		{
			map[point.i - point.value + i][point.j - point.value + j] = 2;
			j++;
		}
		i++;
	}
}
