/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmalassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:47:32 by vmalassi          #+#    #+#             */
/*   Updated: 2023/03/21 17:47:34 by vmalassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

void	display_map(int **map, int lignes, int colonnes)
{
	int	i;
	int	j;

	i = 0;
	while (i < lignes)
	{
		j = 0;
		while (j < colonnes)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	apply_filter(int **map, char* mask, int lignes, int colonnes)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < lignes)
	{
		j = 0;
		while (j < colonnes)
		{
			map[i][j] = mask[map[i][j]];
			j++;
		}
		i++;
	}
}

void	remove_filter(int **map, char* mask, int lignes, int colonnes)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < lignes)
	{
		j = 0;
		while (j < colonnes)
		{
			if(map[i][j] == mask[0])
				map[i][j] = 0;
			else if(map[i][j] == mask[1])
				map[i][j] = 1;
			else
				map[i][j] = 2;
			j++;
		}
		i++;
	}
}
