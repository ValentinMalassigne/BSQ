/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmalassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:56:18 by vmalassi          #+#    #+#             */
/*   Updated: 2023/03/22 18:56:20 by vmalassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	solve_inputs()
{
	char	*first_line;
	char	**map;
	char	*filter;
	int		lines_count;
	int		lines_length;

	first_line = NULL;
	map = NULL;
	if (read_inputs(&map, &first_line) != 1)
	{
		put_str("map error1\n");
		return ;
	}
	lines_count = ft_atoi(get_lines_count(first_line));
	filter = get_filter(first_line);
	if (check_inputs(map, lines_count, filter) != 1)
	{
		put_str("map error2\n");
		return ;
	}
	lines_length = length_until_char(map[0], '\n');
	map = get_biggest_square(map, filter, lines_count, lines_length);
	display_map(map, lines_count, lines_length);
}
