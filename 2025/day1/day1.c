#include "libft.h"
#include <stdio.h>

int	ft_day1(char *fic)
{
	char	*fichier;
	char	**fichier_lines;
	int	count;
	int	count_res;
	int	i;
	int	indline;
	int	res;
	char	**line;

	fichier = ft_get_fichier(fic);
	fichier_lines = ft_split(fichier, "\n");
	if (!fichier_lines)
		return (-1);
	i = 0;
	count = 50;
	count_res = 0;
	while (fichier_lines[i])
	{
		indline = 0;
		res = 0;
		if (fichier_lines[i][0] == 'R')
		{
			line = ft_split(fichier_lines[i], "R");
			while (indline < ft_strlen(line[0]))
			{
				res = res * 10 + (line[0][indline] - 48);
				++indline;
			}
			count_res += (count + res) / 100;
			count = (count + res) % 100;
			//count = ((count + res) % 100 + 100) % 100;
			//if (!count)
			//	++count_res;
		}
		else if (fichier_lines[i][0] == 'L')
		{
			line = ft_split(fichier_lines[i], "L");
			while (indline < ft_strlen(line[0]))
			{
				res = res * 10 + (line[0][indline] - 48);
				++indline;
			}
			count_res += (res + ((100 - count) % 100)) / 100;
			count = ((count - res) % 100 + 100) % 100;
			//count = ((count - res) % 100 + 100) % 100;
			//if (!count)
			//	++count_res;
		}
		free(line[0]);
		free(line);
		free(fichier_lines[i]);
		++i;
	}
	free(fichier_lines);
	free(fichier);
	return (count_res);
}

int	main(int argc, char **argv)
{
	char	*fichier;

	if (argc != 2)
	{
		ft_putstr("Nombre d'arguments invalide\n");
		return (1);
	}
	fichier = argv[1];
	ft_putnbr(ft_day1(fichier));
	return (0);
}
