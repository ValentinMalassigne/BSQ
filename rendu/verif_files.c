/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmalassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:36:14 by vmalassi          #+#    #+#             */
/*   Updated: 2023/03/22 16:36:16 by vmalassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_duplicates(char *file_content, int length)
{
	int	i;
	int	j;

	i = 0;
	while (i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if (file_content[i] == file_content[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	verif_first_line(char *file_content)
{
	int	i;
	int	j;
	int	lines_count;

	i = 0;
	while ('0' <= file_content[i] && file_content[i] <= '9' && file_content[i])
		i++;
	j = i;
	while (32 <= file_content[j] && file_content[j] <= 126)
		j++;
	if ((j - i) != 3)
		return (0);
	if (check_duplicates((file_content + i), j - i) == 0)
		return (0);
	lines_count = ft_atoi(get_lines_count(file_content));
	if (lines_count == 0)
		return (0);
	return (1);
}

int	verif_lines_count(char *file_content, int lines_count)
{
	int	count;
	int	i;

	i = 0;
	count = -1;
	while (file_content[i])
		if (file_content[i++] == '\n')
			count ++;
	if (count != lines_count)
		return (0);
	return (1);
}

int	verif_lines_length(char *file_content, int lines_length)
{
	int	count;

	count = -1;
	while (*file_content != '\n' && *file_content)
		file_content++;
	file_content++;
	while (*file_content)
	{
		count++;
		if (*file_content++ == '\n')
		{
			if (count != lines_length)
				return (0);
			count = -1;
		}
	}
	if (lines_length < 1)
		return (0);
	return (1);
}

int	verif_chars(char *file_content, char *filter)
{
	while (*file_content != '\n' && *file_content)
		file_content++;
	file_content++;
	while (*file_content)
	{
		if (*file_content != filter[0] && *file_content != filter[1]
			&& *file_content != '\n')
			return (0);
		file_content++;
	}
	return (1);
}
