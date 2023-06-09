/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmalassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:46:02 by vmalassi          #+#    #+#             */
/*   Updated: 2023/03/22 21:46:05 by vmalassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	free_char_map_content(char **map, int lines_count)
{
	int	i;

	i = 0;
	while (i < lines_count)
		free(map[i++]);
}

void	free_char_map_and_content(char **map, int lines_count)
{
	free_char_map_content(map, lines_count);
	free(map);
}

void	free_int_map_content(int **map, int lines_count)
{
	int	i;

	i = 0;
	while (i < lines_count)
		free(map[i++]);
}

void	free_int_map_and_content(int **map, int lines_count)
{
	free_int_map_content(map, lines_count);
	free(map);
}
