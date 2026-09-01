#include "libft.h"

int	ft_get_max(char *str)
{
	int	i;
	char	max;
	int	indmax;

	i = 0;
	max = 0;
	indmax = 0;
	while (str[i])
	{
		if (str[i] > max && i != ft_strlen(str) - 1)
		{
			indmax = i;
			max = str[i];
		}
		++i;
	}
	return (indmax);
}

int	ft_get_max2(char *str, int indmax)
{
	int	i;
	char	max2;
	int	indmax2;

	i = indmax;
	max2 = 0;
	indmax2 = 0;
	while (str[i])
	{
		if (str[i] > max2 && i != indmax)
		{
			indmax2 = i;
			max2 = str[i];
		}
		++i;
	}
	return (indmax2);
}

int	ft_day3(char *fichier)
{
	char	*fic;
	char	**lines;
	int	i;
	int	res;
	int	max;
	int	max2;

	fic = ft_get_fichier(fichier);
	lines = ft_subsplit(fic, "\n");
	i = 0;
	res = 0;
	while (lines[i])
	{
		max = ft_get_max(lines[i]);
		max2 = ft_get_max2(lines[i], max);
		res += ((lines[i][max] - '0') * 10) + lines[i][max2] - '0';
		++i;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	char	*fichier;
	if (argc != 2)
	{
		ft_putstr("Nombre d'arguments invalide");
		return (1);
	}
	fichier = argv[1];
	ft_putnbr(ft_day3(fichier));
	return (0);
}
