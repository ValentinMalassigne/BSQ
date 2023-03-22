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

	first_line = NULL;
	map = NULL;
	if (read_inputs(&map, &first_line) != 1)
		put_str("map error\n");
	if (check_inputs(map, ft_atoi(get_lines_count(first_line)),get_filter(first_line)) != 1)
		put_str("map error2\n");
	
		//runProgram
}
