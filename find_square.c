#include <stdio.h>
#include <stdlib.h>

void	display_map(int **map, int lignes, int colonnes)
{
	int i = 0;
	int j = 0;
	while(i < lignes)
	{
		j = 0;
		while (j < colonnes)
		{
			printf("%d",map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	init_count_map(int **count_map, int lignes, int colonnes)
{
	int i = 0;
	int j;

	while(i < lignes+1)
	{
		count_map[i] = malloc((colonnes +1) * sizeof(int));
		j = 0;
		while (j < colonnes + 1)
			count_map[0][j++] = 0;
		i++;
	}
}

void	fill_count_map(int **count_map, int ligne, int colonne, int map_value)
{
	int min;

	min = count_map[ligne][colonne];
	if(min > count_map[ligne + 1][colonne])
		min = count_map[ligne + 1][colonne];
	if(min > count_map[ligne][colonne + 1])
		min = count_map[ligne][colonne + 1];
	if(map_value == 0)
		count_map[ligne + 1][colonne + 1] = 0;
	else
		count_map[ligne + 1][colonne + 1] = min + map_value;
}

void	traitement(int **map, int **count_map, int lignes, int colonnes)
{
	int i;
	int j;

	i = 0;
	init_count_map(count_map, lignes, colonnes);
	while (i < lignes)
	{
		j = 0;
		while (j < colonnes)
		{
			fill_count_map(count_map, i, j, map[i][j]);
			j++;
		}
		i++;
	}
}

void	init_map(int **map, int lignes, int colonnes)
{
	int i = 0;
	int j = 0;
	
	while(i < lignes)
	{
		j = 0;
		map[i] = malloc(colonnes * sizeof(int));
		while (j < colonnes)
		{
			map[i][j] = 1;
			j++;
		}
		i++;
	}
	map[1][4] = 0;
	map[2][12] = 0;
	map[4][4] = 0;
	map[5][15] = 0;
	map[7][6] = 0;
	map[7][21] = 0;
	map[8][2] = 0;
	map[8][10] = 0;
}

int	main()
{
	int **map;
	int **count_map;
	int lignes = 9;
	int colonnes = 27;

	map = malloc(lignes * sizeof(int *));
	count_map = malloc((lignes+1) * sizeof(int *));
	init_map(map, lignes, colonnes);
	display_map(map, lignes, colonnes);
	traitement(map, count_map, lignes, colonnes);
	printf("\n\n");
	display_map(count_map, lignes+1, colonnes+1);
}
