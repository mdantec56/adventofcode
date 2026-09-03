#include "libft.h"

int	ft_get_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		++i;
	return (i);
}

int	ft_case_is_valid(char **tab, int ligne, int colonne)
{
	if (ligne >= 0 && ligne < ft_get_size(tab) - 1 && colonne >= 0 && colonne < ft_strlen(tab[ligne]) - 1)
		return (1);
	return (0);
}

void	ft_start(char **tab, int ligne, int colonne)
{
	if (tab[ligne][colonne] == 'S' && ft_case_is_valid(tab, ligne + 1, colonne))
		tab[ligne + 1][colonne] = '|';
}

void	ft_puttachyon(char **tab, int ligne, int colonne)
{
	if (tab[ligne][colonne] == '|' && ft_case_is_valid(tab, ligne + 1, colonne) && tab[ligne + 1][colonne] != '^')
		tab[ligne + 1][colonne] = '|';
}

int	ft_putsplit(char **tab, int ligne, int colonne)
{
	int	splitted;

	splitted = 0;
	if (tab[ligne][colonne] == '|' && ft_case_is_valid(tab, ligne + 1, colonne + 1) && tab[ligne + 1][colonne] == '^')
	{
		tab[ligne + 1][colonne + 1] = '|';
		splitted = 1;
	}
	if (tab[ligne][colonne] == '|' && ft_case_is_valid(tab, ligne + 1, colonne - 1) && tab[ligne + 1][colonne] == '^')
	{
		tab[ligne + 1][colonne - 1] = '|';
		splitted = 1;
	}
	return (splitted);
}

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		++i;
	}
	free(tab);
}

int	ft_day7(char *fichier)
{
	char	**tab;
	int	ligne;
	int	colonne;
	int	cpt_split;

	tab = ft_split(fichier, "\n");
	if (!tab)
		return (-1);
	ligne = 0;
	cpt_split = 0;
	while (tab[ligne])
	{
		colonne = 0;
		while (colonne < ft_strlen(tab[ligne]) - 1)
		{
			ft_start(tab, ligne, colonne);
			ft_puttachyon(tab, ligne, colonne);
			cpt_split += ft_putsplit(tab, ligne, colonne);
			++colonne;
		}
		++ligne;
	}
	ft_free(tab);
	return (cpt_split);
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
	ft_putnbr(ft_day7(fichier));
	free(fichier);
	return (0);
}
