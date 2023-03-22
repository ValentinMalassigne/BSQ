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

int	length_until_char(char *str, char c)
{
	int	length;

	length = 0;
	while (str[length] && str[length]!= c)
		length++;
	return (length);
}

void	test_init_map(char **map, int lignes, int colonnes)
{
	int		i;
	int		j;
	char	obstacle;

	obstacle = 'o';
	i = 0;
	j = 0;
	while (i < lignes)
	{
		j = 0;
		map[i] = malloc(colonnes * sizeof(int));
		while (j < colonnes)
			map[i][j++] = '.';
		i++;
	}
	map[1][4] = obstacle;
	map[2][12] = obstacle;
	map[4][4] = obstacle;
	map[5][15] = obstacle;
	map[7][6] = obstacle;
	map[7][21] = obstacle;
	map[8][2] = obstacle;
	map[8][10] = obstacle;
}

void	init_map(char **map, char *file_content, int lignes, int colonnes)
{
	int	i;
	int	j;
	
	i = 0;
	while(*file_content != '\n')
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
	int 	i;
	char	*res;

	i = 0;
	while(file_content[i] < 58 && file_content[i] > 47 && file_content[i])
		i++;
	res = malloc((i + 1) * sizeof(char));
	i = 0;
	while(file_content[i] < 58 && file_content[i] > 47 && file_content[i])
	{
		res[i] = file_content[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	get_lines_length(char *file_content)
{
	while(*file_content != '\n' && *file_content)
		file_content++;
	file_content++;
	return (length_until_char(file_content , '\n'));
}

int	main(void)
{
	char	**map;
	char	*file_content;
	char	*filter;
	int		lines_count;
	int		lines_length;

	//Faire la recup des parametres pour savoir si on prend files ou inputs	
	
	file_content = parse("test1");
	
	// Faire les verifs sur le file content

	lines_count = ft_atoi(get_lines_count(file_content));

	lines_length = get_lines_length(file_content);
	filter = get_filter(file_content);
	map = malloc(lines_count * sizeof(char *));
	init_map(map, file_content, lines_count, lines_length);
	//test_init_map(map, lines_count, lines_length);
	map = get_biggest_square(map, filter, lines_count, lines_length);
	display_map(map, lines_count, lines_length);
	
	return (0);
}
