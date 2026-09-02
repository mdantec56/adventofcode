#include "libft.h"

int	ft_get_size(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
		++i;
	return (i);
}

int	ft_get_sizetab(char ***tab)
{
	int	i;

	i = 0;
	while (tab[i])
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

void	ft_free(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		++i;
	}
	free(lines);
}

char	***ft_create_tab(char *fichier)
{
	char	***tab;
	char	**lines;
	int	i;

	lines = ft_get_lines(fichier);
	if (!lines)
		return (NULL);
	tab = malloc(sizeof(char **) * (ft_get_size(lines) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < ft_get_size(lines))
	{
		tab[i] = ft_split(lines[i], " ");
		++i;
	}
	tab[i] = NULL;
	ft_free(lines);
	return (tab);
}

void	ft_free_tab(char ***tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			free(tab[i][j]);
			++j;
		}
		free(tab[i]);
		++i;
	}
	free(tab);
}

long	ft_day6(char *fichier)
{
	long	total;
	long	res_line;
	char	***tab;
	int	colonne;
	int	ligne;
	int	indlastline;
	int	operator;

	tab = ft_create_tab(fichier);
	if (!tab)
		return (-1);
	total = 0;
	colonne = 0;
	indlastline = ft_get_sizetab(tab) - 1;
	while (colonne != ft_get_size(tab[0]))
	{
		if (!ft_strcmp(tab[indlastline][colonne], "*"))
			operator = 1;
		else
			operator = 0;
		ligne = 1;
		res_line = ft_atoi(tab[0][colonne]);
		while (ligne != indlastline)
		{
			if (operator)
				res_line *= ft_atoi(tab[ligne][colonne]);
			else
				res_line += ft_atoi(tab[ligne][colonne]);
			++ligne;
		}
		total += res_line;
		++colonne;
	}
	ft_free_tab(tab);
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
	ft_putnbr(ft_day6(fichier));
	free(fichier);
	return (0);
}
