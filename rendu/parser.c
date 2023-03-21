#include "ft.h"

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
			free(buf);
			free(content);
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
//	add file_content parsing here
//
//	if (parse_file(dict, file_content) == 1)
//		return (ERROR_DICT);
	free(file_content);
	return (0);
}
