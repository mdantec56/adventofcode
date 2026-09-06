#include "libft.h"

long	ft_day2(char *fichier)
{
	char	**lines;
	int	i;
	int	j;
	char	**numbers;
	long	cpt;
	long	croissant;
	long	decroissant;


	lines = ft_split(fichier, "\n");
	i = 0;
	j = 0;
	cpt = 0;
	while (lines[i])
	{
		numbers = ft_split(lines[i], " ");
		croissant = 0;
		decroissant = 0;
		j = 0;
		while (numbers[j + 1])
		{
			if (ft_atoi(numbers[j]) - ft_atoi(numbers[j + 1]) <= 3
					&& ft_atoi(numbers[j]) - ft_atoi(numbers[j + 1]) > 0)
				++decroissant;
			if (ft_atoi(numbers[j + 1]) - ft_atoi(numbers[j]) <= 3
					&& ft_atoi(numbers[j + 1]) - ft_atoi(numbers[j]) > 0)
				++croissant;
			++j;
		}
		if (decroissant == j || croissant == j)
			++cpt;
		++i;
	}
	return (cpt);
}

int	main(int argc, char **argv)
{
	char	*fichier;

	if (argc != 2)
	{
		ft_putstr("Nombre d'arguments invalide.\n");
		return (1);
	}
	fichier = ft_get_fichier(argv[1]);
	ft_putnbr(ft_day2(fichier));
	return (0);
}
