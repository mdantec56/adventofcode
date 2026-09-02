#include "libft.h"

int	ft_strcmp_nbr(char *number1, char *number2) // n1 > n2 = -1 ; n1 < n2 = 1 ; n1 == n2 = 0
{
	int	i;

	i = 0;
	if (ft_strlen(number1) > ft_strlen(number2))
		return (-1);
	else if (ft_strlen(number1) < ft_strlen(number2))
		return (1);
	while (number1[i] && number2[i])
	{
		if (number1[i] > number2[i])
			return (-1);
		else if (number1[i] < number2[i])
			return (1);
		else
			++i;
	}
	return (0);
}

char	**ft_splitfic(char *fichier)
{
	char	**splitted;

	splitted = ft_subsplit(fichier, "\n\n");
	return (splitted);
}

char	*ft_get_ranges(char *fichier)
{
	return (ft_splitfic(fichier)[0]);
}

char	*ft_get_numbers(char *fichier)
{
	return (ft_splitfic(fichier)[1]);
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
	tab[i] = -1;
	return (tab);
}

long	ft_size_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		++i;
	return (i);
}

long	ft_len_tab(long **tab)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] != -1)
		{
			++count;
			++j;
		}
		++i;
	}
	return (count);
}

typedef struct s_range
{
	long	debut;
	long	fin;
}	t_range;

t_range	*ft_parse_ranges(char *ranges, long *nb_ranges)
{
	char	**split_ranges;
	char	**splitted;
	t_range	*tab;
	int		i;

	split_ranges = ft_subsplit(ranges, "\n");
	if (!split_ranges)
		return (NULL);
	tab = malloc(sizeof(t_range) * (ft_size_tab(split_ranges) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (split_ranges[i])
	{
		splitted = ft_subsplit(split_ranges[i], "-");
		tab[i].debut = ft_atoi(splitted[0]);
		tab[i].fin = ft_atoi(splitted[1]);
		++i;
	}
	*nb_ranges = i;
	return (tab);
}

void	ft_sort_ranges(t_range *tab, long n)
{
	long	i;
	t_range	temp;

	i = 0;
	while (i < n - 1)
	{
		if (tab[i].debut > tab[i + 1].debut)
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			++i;
	}
}

long	ft_day5s2(char *fichier)
{
	char	*ranges;
	t_range	*tab;
	long	nb_ranges;
	long	total;
	long	cur_debut;
	long	cur_fin;
	long	i;

	ranges = ft_get_ranges(fichier);
	tab = ft_parse_ranges(ranges, &nb_ranges);
	if (!tab || nb_ranges == 0)
		return (0);
	ft_sort_ranges(tab, nb_ranges);
	total = 0;
	cur_debut = tab[0].debut;
	cur_fin = tab[0].fin;
	i = 1;
	while (i < nb_ranges)
	{
		if (tab[i].debut <= cur_fin + 1)
		{
			if (tab[i].fin > cur_fin)
				cur_fin = tab[i].fin;
		}
		else
		{
			total += cur_fin - cur_debut + 1;
			cur_debut = tab[i].debut;
			cur_fin = tab[i].fin;
		}
		++i;
	}
	total += cur_fin - cur_debut + 1;
	return (total);
}

int	main(int argc, char **argv)
{
	char	*fichier;
	if (argc != 2)
	{
		ft_putstr("Nombre d'arguments invalide");
		return (1);
	}
	fichier = ft_get_fichier(argv[1]);
	ft_putnbr(ft_day5s2(fichier));
	//ft_putstr(ft_get_ranges(fichier));
	return (0);
}
