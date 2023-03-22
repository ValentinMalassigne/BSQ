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
void	init_map(char **map, char *file_content, int lignes, int colonnes);
void	put_str(char *str);
void	solve_file(char *file_path);
void	solve_inputs(void);
char	**remove_filter(int **filtered_map, char *mask, int lignes, int col);
char	**get_biggest_square(char **map, char *mask, int lignes, int colonnes);
char	*ft_strjoin(char *s1, char *s2);
char	*parse(char *file_path);
char	*get_filter(char *file_content);
char	*get_lines_count(char *file_content);
char	**get_biggest_square(char **map, char *mask, int lignes, int colonnes);
char	*get_lines_count(char *file_content);
int		ft_atoi(char *str);
int		**apply_filter(char **map, char *mask, int lignes, int colonnes);
int		ft_strlen(char *str);
int		verif_first_line(char *file_content);
int		length_until_char(char *str, char c);
int		verif_lines_count(char *file_content, int lines_count);
int		verif_lines_length(char *file_content, int lines_length);
int		verif_chars(char *file_content, char *filter);
int		get_lines_length(char *file_content);
int		read_inputs(char ***map, char **first_line);
int		check_inputs(char **map, int lines_count, char *filter);
#endif
