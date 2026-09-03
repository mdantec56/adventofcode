#include "libft.h"

int	ft_get_nb_current(char **tab, int ligne, int colonne)
{
	int	count;

	count = 0;
	if (colonne - 1 >= 0)
	{
		if (tab[ligne][colonne - 1] == '@')
			++count;
	}
	if (colonne + 1 < ft_strlen(tab[ligne]))
	{
		if (tab[ligne][colonne + 1] == '@')
			++count;
	}
	return (count);
}

int	ft_get_nb_high(char **tab, int ligne, int colonne)
{
	int	count;

	count = 0;
	if (ligne - 1 >= 0)
	{
		if (colonne - 1 >= 0)
		{
			if (tab[ligne - 1][colonne - 1] == '@')
				++count;
		}
		if (colonne + 1 < ft_strlen(tab[ligne - 1]))
		{
			if (tab[ligne - 1][colonne + 1] == '@')
				++count;
		}
		if (tab[ligne - 1][colonne] == '@')
			++count;
	}
	return (count);
}

int	ft_get_nb_low(char **tab, int ligne, int colonne)
{
	int	count;

	count = 0;
	if (tab[ligne + 1])
	{
		if (colonne - 1 >= 0)
		{
			if (tab[ligne + 1][colonne - 1] == '@')
				++count;
		}
		if (colonne + 1 < ft_strlen(tab[ligne + 1]))
		{
			if (tab[ligne + 1][colonne + 1] == '@')
				++count;
		}
		if (tab[ligne + 1][colonne] == '@')
			++count;
	}
	return (count);
}


int	ft_get_nb_voisins(char **tab, int ligne, int colonne)
{
	int	count;

	count = 0;
	count += ft_get_nb_current(tab, ligne, colonne);
	count += ft_get_nb_high(tab, ligne, colonne);
	count += ft_get_nb_low(tab, ligne, colonne);
	return (count);
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

int	day4(char *fichier)
{
	int	cptrolls;
	int	ligne;
	int	colonne;
	char	**tab;
	int	cpt; // s2

	tab = ft_subsplit(fichier, "\n");
	ligne = 0;
	ligne = 0;
	cptrolls = 0;
	while (tab[ligne])
	{
		colonne = 0;
		cpt = 0; // s2
		while (tab[ligne][colonne])
		{
			if (tab[ligne][colonne] == '@' && ft_get_nb_voisins(tab, ligne, colonne) < 4)
			{
				tab[ligne][colonne] = '.'; // s2
				++cpt; // s2
				++cptrolls;
			}
			++colonne;
		}
		++ligne;
		if (cpt) // s2
			ligne = 0; // s2
	}
	ft_free(tab);
	return (cptrolls);
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
	ft_putnbr(day4(fichier));
	free(fichier);
	return (0);
}
