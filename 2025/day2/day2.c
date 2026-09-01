#include "libft.h"
#include <stdio.h>

int	ft_is_invalid(char *n)
{
	int	i;
	int	len;

	len = ft_strlen(n);
	if (len % 2 == 1)
		return (0);
	i = 0;
	while (i < len / 2)
	{
		if (n[i] != n[len / 2 + i])
			return (0);
		++i;
	}
	return (1);
}

long	*ft_range(long debut, long fin)
{
	long	*tab;
	long	i;

	tab = malloc(sizeof(long) * (fin - debut + 2));
	if (!tab)
		return (NULL);
	i = 0;
	while (i <= fin - debut)
	{
		tab[i] = debut + i;
		++i;
	}
	return (tab);
}

long	ft_day2(char *fichier)
{
	char	*fic;
	char	**rangestr;
	long	i;
	long	j;
	char	**splitted_range;
	long	*range;
	long	res;
	long	debut;
	long	fin;
	long	size;

	fic = ft_get_fichier(fichier);
	rangestr = ft_subsplit(fic, ",");
	res = 0;
	i = 0;
	while (rangestr[i])
	{
		j = 0;
		splitted_range = ft_subsplit(rangestr[i], "-");
		debut = ft_atoi(splitted_range[0]);
		fin = ft_atoi(splitted_range[1]);
		range = ft_range(debut, fin);
		size = fin - debut + 1;
		while (j < size)
		{
			if (ft_is_invalid(ft_itoa(range[j])))
				res += range[j];
			++j;
		}
		free(splitted_range[0]);
		free(splitted_range[1]);
		free(splitted_range);
		free(range);
		free(rangestr[i]);
		++i;
	}
	free(rangestr);
	free(fic);
	return (res);
}

long	main(int argc, char **argv)
{
	char	*fichier;

	if (argc != 2)
	{
		ft_putstr("Nombre d'arguments invalide");
		return (1);
	}
	fichier = argv[1];
	ft_putnbr(ft_day2(fichier));
	return (0);
}
