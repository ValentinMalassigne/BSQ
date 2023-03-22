#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "ft.h"
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] > '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
		if (res > 2147483647)
			return (-1);
	}
	return (res);
}
char	*read_files(char *file_path)
{
	int file_descriptor;
	int	byte_read;
	char *file_content;

	file_content = malloc(4096 * sizeof(char));
	if (!file_content)
		return (0);
	file_descriptor = 0;
	file_descriptor = open(file_path, O_RDONLY);
	if (file_descriptor < -1)
		return (0);
	byte_read = read(file_descriptor, file_content, 4096);
	close(file_descriptor);
	file_content[byte_read] = '\0';
	return (file_content);
}

char **init_matrix(int rows, int cols)
{
	char **map;
	int i;

	map = malloc(rows * sizeof(int *));
	if (map == NULL)
	{
		ft_putstr("map error");
		return NULL;
	}
	i = 0;
	while (i < rows)
	{
		map[i] = malloc(cols * sizeof(int));
		if (map[i] == NULL)
		{
			ft_putstr("map error");
			while (i > 0)
			{
				i--;
				free(map[i]);
				map[i] = NULL;
			}
			free(map);
			map = NULL;
			return NULL;
		}
		i++;
	}
	return (map);
}

char **read_matrix(char **map, int rows, int cols)
{
    int i = 0;
    int j = 0;
    
    while (i < rows)
    {
        j = 0;
        while (j < cols)
        {
            read(STDIN_FILENO, &map[i][j], sizeof(char));
            j++;
        }
        i++;
    }

    i = 0;
    while (i < rows)
    {
        j = 0;
        while (j < cols)
        {
            write(STDOUT_FILENO, &map[i][j], sizeof(char));
            write(STDOUT_FILENO, " ", 1);
            j++;
        }
        write(STDOUT_FILENO, "\n", 1);
        i++;
    }

    return map;
}

void	ft_print(char *path)
{
	if(!(read_files(path)))
		ft_putstr("map error");
	else
		ft_putstr(read_files(path));
}

int main(int argc, char *argv[])
{

	int i;

	if(argc < 2)
	{
		int row = 5;
		int col = 5;
		char **matrix = init_matrix(row, col);
		if (matrix == NULL)
		{
			ft_putstr("NOPE\n");
		}
		else
			ft_putstr("CHECK\n");
		ft_putstr("Please enter the arguments you wish to pass : ");
		read_matrix(matrix, row, col);
		return (0);
	}
	else
	{
		i = 0;
		
		while(++i < argc)
		{
			if (i > 1)
				write(1, "\n", 1);
			ft_print(argv[i]);
		}
	}
}