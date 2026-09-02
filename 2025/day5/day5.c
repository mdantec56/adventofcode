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

typedef struct s_range
{
	char	*low;
	char	*high;
}		t_range;

int	ft_day5(char *fichier)
{
	t_range	*ranges;
	char	**split_range;
	int	nb_ranges;
	char	**lines;
	int	i;
	int	j;
	int	fresh;
	char	**numbers;

	lines = ft_subsplit(ft_get_ranges(fichier), "\n");
	numbers = ft_subsplit(ft_get_numbers(fichier), "\n");
	nb_ranges = 0;
	while (lines[nb_ranges])
		++nb_ranges;
	ranges = malloc(sizeof(t_range) * nb_ranges);
	i = 0;
	while (i < nb_ranges)
	{
		split_range = ft_subsplit(lines[i], "-");
		ranges[i].low = split_range[0];
		ranges[i].high = split_range[1];
		free(split_range);
		++i;
	}
	fresh = 0;
	i = 0;
	while (numbers[i])
	{
		j = 0;
		while (j < nb_ranges)
		{	
			if (ft_strcmp_nbr(ranges[j].low, numbers[i]) >= 0
						&& ft_strcmp_nbr(ranges[j].high, numbers[i]) <= 0)
			{
				++fresh;
				j = nb_ranges - 1;
			}
			++j;
		}
		++i;
	}
	return (fresh);
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
	ft_putnbr(ft_day5(fichier));
	return (0);
}
