/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmalassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:39:52 by vmalassi          #+#    #+#             */
/*   Updated: 2023/03/22 17:39:53 by vmalassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	solving(char *file_content, char *filter, int l_count, int l_length)
{
	char	**map;

	map = malloc(l_count * sizeof(char *));
	init_map(map, file_content, l_count, l_length);
	map = get_biggest_square(map, filter, l_count, l_length);
	display_map(map, l_count, l_length);
}

void	solve_file(char *file_path)
{
	
	char	*file_content;
	char	*filter;
	int		lines_count;
	int		lines_length;

	file_content = parse(file_path);
	if(file_content == NULL)
		put_str("map error\n");
	if(verif_first_line(file_content) == 1)
	{
		lines_count = ft_atoi(get_lines_count(file_content));
		if (verif_lines_count(file_content, lines_count) == 1)
		{
			lines_length = get_lines_length(file_content);
			if (verif_lines_length(file_content, lines_length) == 1)
			{
				filter = get_filter(file_content);
				if (verif_chars(file_content, filter) == 1)
				{
					solving(file_content, filter, lines_count, lines_length);
					return ;
				}
			}
		}
	}
	put_str("map error\n");
}
