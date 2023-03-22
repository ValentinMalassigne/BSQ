/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmalassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:01:32 by vmalassi          #+#    #+#             */
/*   Updated: 2023/03/21 18:01:33 by vmalassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define BUFFER_SIZE 4096
# define MAP_ERROR "map error\n"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct str_point
{
	int	i;
	int	j;
	int	value;
}t_point;

t_point	find_max_value(int **count_map, int lignes, int colonnes);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	display_map(char **map, int lignes, int colonnes);
void	display_number_map(int **map, int lignes, int colonnes);
void	init_count_map(int **count_map, int lignes, int colonnes);
void	fill_count_map(int **count_map, int ligne, int colonne, int map_value);
void	solve(int **map, int **count_map, int lignes, int colonnes);
void	replace_values(int **map, int **count_map, int lignes, int colonnes);
char	**remove_filter(int **filtered_map, char *mask, int lignes, int col);
char	**get_biggest_square(char **map, char *mask, int lignes, int colonnes);
char	*ft_strjoin(char *s1, char *s2);
char	*parse(char *file_path);
char	*get_filter(char *file_content);
int		ft_atoi(char *str);
int		**apply_filter(char **map, char *mask, int lignes, int colonnes);
int		ft_strlen(char *str);

#endif
