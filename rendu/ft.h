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

# define MAX_LINES
# define BUFFER_SIZE
# define MIN(A, B)

# include <stdlib.h>
# include <unistd.h>

typedef struct str_point
{
	int	i;
	int	j;
	int	value;
}t_point;

t_point	find_max_value(int **count_map, int lignes, int colonnes);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	display_map(int **map, int lignes, int colonnes);
void	init_count_map(int **count_map, int lignes, int colonnes);
void	fill_count_map(int **count_map, int ligne, int colonne, int map_value);
void	solve(int **map, int **count_map, int lignes, int colonnes);
void	replace_values(int **map, int **count_map, int lignes, int colonnes);
void	apply_filter(int **map, char* mask, int lignes, int colonnes);
int		ft_strlen(char *str);
#endif
