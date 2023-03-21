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

void	display_map(char **map, int lignes, int colonnes)
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

void	display_number_map(int **map, int lignes, int colonnes)
{
	int	i;
	int	j;

	i = 0;
	while (i < lignes)
	{
		j = 0;
		while (j < colonnes)
		{
			ft_putchar(map[i][j] + '0');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
		if (res > 2147483647)
			return (-1);
	}
	return (res);
}
