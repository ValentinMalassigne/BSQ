#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
//Verifier le nombre d'arguments
//Si arguments fichier donnees => afficher les fichiers
//Si pas d'argument  => entrez un tableau manuellement

char	*read_files(char *file_path)
//Affiche le contenu du fichier en parametre dans la console.
{
	int file_descriptor;
	int	byte_read;
	char *file_content;

	file_content = malloc(4096 * sizeof(char));
	if (!file_content)
		return (0);
	file_descriptor = 0;
	file_descriptor = open(file_path, O_RDONLY);
	if (file_descriptor < 0)
		return (0);
	byte_read = read(file_descriptor, file_content, 4096);
	file_content[byte_read] = '\0';
	return (file_content);
}

void	ft_print(char *path)
//Afficher le tableau /!\ CHANGER LA SORTIE DU ELSE
{
	if(!(read_files(path)))
		write(1, "map error\n", 10);
	else
		printf("%s\n", read_files(path));
}

int	main(int argc, char *argv[])
//afficher les tableaux en parametre demande
{
	char	c;
	int		i;
	if (argc < 2)
	{
		ft_print(NULL);
		return (0);
	}
	c = '\n';
	i = 0;
	while (++i < argc)
	{
		if (i < 1)
			write(1, &c, 1);
		ft_print(argv[i]);
	}
	return 0;
}