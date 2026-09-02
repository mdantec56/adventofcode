#include "libft.h"

int	ft_get_size(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
		++i;
	return (i);
}

char	**ft_get_lines(char *fichier)
{
	char	**lines;

	lines = ft_subsplit(fichier, "\n");
	if (!lines)
		return (NULL);
	return (lines);
}

char	*ft_get_numbers(char **tab, int colonne)
{
	int	ligne;
	char	*number;
	char	*temp;
	int	size;
	int	j;
	int	last_line;

	ligne = 0;
	number = malloc(sizeof(char) * 1);
	last_line = ft_get_size(tab) - 1;
	number[size] = '\0';
	while (ligne < last_line)
	{
		if (ft_isdigit(tab[ligne][colonne]))
		{
			j = 0;
			temp = number;
			number = malloc(sizeof(char) * 1 + size);
			while (temp[j])
			{
				number[j] = temp[j];
				++j;
			}
			number[j] = tab[ligne][colonne];
			number[j + 1] = '\0';
		}
		++ligne;
	}
	number[ligne] = '\0';
	return (number);
}

long	ft_day6s2(char *fichier)
{
	long	total;
	long	res_line;
	char	**tab;
	char	**signes;
	int	colonne;
	int	ligne;
	int	indlastline;
	int	operator;
	char	*number;
	int	colonnecalc;

	tab = ft_get_lines(fichier);
	if (!tab)
		return (-1);
	total = 0;
	colonne = 0;
	indlastline = ft_get_size(tab) - 1;
	colonnecalc = 0;
	signes = ft_split(tab[indlastline], " ");
	while (colonne != ft_strlen(tab[0]))
	{
		if (!ft_strcmp(signes[colonnecalc], "*"))
		{
			operator = 1;
			res_line = 1;
		}
		else
		{
			operator = 0;
			res_line = 0;
		}
		number = ft_get_numbers(tab, colonne);
		if (number[0] != '\0')
		{
			while (number[0] != '\0')
			{
				if (operator)
					res_line *= ft_atoi(number);
				else
					res_line += ft_atoi(number);
				++colonne;
				number = ft_get_numbers(tab, colonne);
			}
			++colonnecalc;
			total += res_line;
		}
		else
			++colonne;
	}
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
	ft_putnbr(ft_day6s2(fichier));
	return (0);
}
