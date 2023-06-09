#ifndef FT_H
# define FT_H

# define MAX_LINES	
# define BUFFER_SIZE	
# define MIN(A, B)	

typedef struct str_point
{
	int	i;
	int	j;
	int value;
}t_point;

typedef struct str_map
{
	char	*content;
	char	*matrix;
	char	empty;
	char	full;
	char	obs;
	t_point	size;
}t_map;

typedef struct str_square
{
	t_point	coords;
	int	size;
}t_square;

#endif
