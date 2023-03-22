/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmalassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:02:56 by vmalassi          #+#    #+#             */
/*   Updated: 2023/03/22 21:02:58 by vmalassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	free_buf_content(char *buf, char *content)
{
	free(buf);
	free(content);
}

char	*read_file(int fd)
{
	int		rd;
	char	*content;
	char	*buf;
	char	*tmp;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	rd = 1;
	content = NULL;
	while (rd)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
		{
			free_buf_content(buf, content);
			return (NULL);
		}
		buf[rd] = '\0';
		tmp = ft_strjoin(content, buf);
		free(content);
		content = tmp;
	}
	free(buf);
	return (content);
}

char	*parse(char *file_path)
{
	int		fd;
	char	*file_content;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (MAP_ERROR);
	file_content = read_file(fd);
	if (file_content == NULL)
		return (MAP_ERROR);
	return (file_content);
	free(file_content);
	return (0);
}
