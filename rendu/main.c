/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmalassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:54:50 by vmalassi          #+#    #+#             */
/*   Updated: 2023/03/21 17:54:52 by vmalassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	init_map(int **map, int lignes, int colonnes)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < lignes)
	{
		j = 0;
		map[i] = malloc(colonnes * sizeof(int));
		while (j < colonnes)
		{
			map[i][j] = 1;
			j++;
		}
		i++;
	}
	map[1][4] = 0;
	map[2][12] = 0;
	map[4][4] = 0;
	map[5][15] = 0;
	map[7][6] = 0;
	map[7][21] = 0;
	map[8][2] = 0;
	map[8][10] = 0;
}

int	main(void)
{
	int	**map;
	int	**count_map;
	int	lignes;
	int	colonnes;
	char *mask;

	mask = "o.x";
	lignes = 9;
	colonnes = 27;
	map = malloc(lignes * sizeof(int *));
	count_map = malloc((lignes + 1) * sizeof(int *));
	init_map(map, lignes, colonnes);
	display_map(map, lignes, colonnes);
	ft_putchar('\n');
	solve(map, count_map, lignes, colonnes);
	display_map(count_map, lignes + 1, colonnes + 1);
	ft_putchar('\n');
	replace_values(map, count_map, lignes, colonnes);
	display_map(map, lignes, colonnes);
	ft_putchar('\n');
	apply_filter(map, mask, lignes, colonnes);
	display_map(map, lignes, colonnes);
}
