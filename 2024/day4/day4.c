#include "libft.h"

int	ft_get_size(char **tab)
{
	int	i;

	while (tab[i])
		++i;
	return (i);
}

int	ft_case_isvalid(char **tab, int ligne, int colonne)
{
	if (ligne >= 0 && ligne < ft_get_size(tab) && colonne >= 0 && colonne < ft_strlen(tab[ligne]))
		return (1);
	return (0);
}

long	ft_get_diagonal(char **tab, int ligne, int colonne)
{
	long	cpt;

	cpt = 0;
	if (tab[ligne][colonne] == 'X'
                        && (ft_case_isvalid(tab, ligne + 1, colonne + 1) && tab[ligne + 1][colonne + 1] == 'M')
                        && (ft_case_isvalid(tab, ligne + 2, colonne + 2) && tab[ligne + 2][colonne + 2] == 'A')
                        && (ft_case_isvalid(tab, ligne + 3, colonne + 3) && tab[ligne + 3][colonne + 3] == 'S'))
                ++cpt;
	if (tab[ligne][colonne] == 'X'
                        && (ft_case_isvalid(tab, ligne - 1, colonne + 1) && tab[ligne - 1][colonne + 1] == 'M')
                        && (ft_case_isvalid(tab, ligne - 2, colonne + 2) && tab[ligne - 2][colonne + 2] == 'A')
                        && (ft_case_isvalid(tab, ligne - 3, colonne + 3) && tab[ligne - 3][colonne + 3] == 'S'))
                ++cpt;
	if (tab[ligne][colonne] == 'X'
                        && (ft_case_isvalid(tab, ligne + 1, colonne - 1) && tab[ligne + 1][colonne - 1] == 'M')
                        && (ft_case_isvalid(tab, ligne + 2, colonne - 2) && tab[ligne + 2][colonne - 2] == 'A')
                        && (ft_case_isvalid(tab, ligne + 3, colonne - 3) && tab[ligne + 3][colonne - 3] == 'S'))
                ++cpt;
	if (tab[ligne][colonne] == 'X'
                        && (ft_case_isvalid(tab, ligne - 1, colonne - 1) && tab[ligne - 1][colonne - 1] == 'M')
                        && (ft_case_isvalid(tab, ligne - 2, colonne - 2) && tab[ligne - 2][colonne - 2] == 'A')
                        && (ft_case_isvalid(tab, ligne - 3, colonne - 3) && tab[ligne - 3][colonne - 3] == 'S'))
                ++cpt;
	return (cpt);
}

long	ft_get_axe(char **tab, int ligne, int colonne)
{
	long	cpt;

	cpt = 0;
	if (tab[ligne][colonne] == 'X'
			&& (ft_case_isvalid(tab, ligne, colonne + 1) && tab[ligne][colonne + 1] == 'M')
			&& (ft_case_isvalid(tab, ligne, colonne + 2) && tab[ligne][colonne + 2] == 'A')
			&& (ft_case_isvalid(tab, ligne, colonne + 3) && tab[ligne][colonne + 3] == 'S'))
		++cpt;
	if (tab[ligne][colonne] == 'X'
                        && (ft_case_isvalid(tab, ligne, colonne - 1) && tab[ligne][colonne - 1] == 'M')
                        && (ft_case_isvalid(tab, ligne, colonne - 2) && tab[ligne][colonne - 2] == 'A')
                        && (ft_case_isvalid(tab, ligne, colonne - 3) && tab[ligne][colonne - 3] == 'S'))
                ++cpt;
	if (tab[ligne][colonne] == 'X'
                        && (ft_case_isvalid(tab, ligne + 1, colonne) && tab[ligne + 1][colonne] == 'M')
                        && (ft_case_isvalid(tab, ligne + 2, colonne) && tab[ligne + 2][colonne] == 'A')
                        && (ft_case_isvalid(tab, ligne + 3, colonne) && tab[ligne + 3][colonne] == 'S'))
                ++cpt;
	if (tab[ligne][colonne] == 'X'
                        && (ft_case_isvalid(tab, ligne - 1, colonne) && tab[ligne - 1][colonne] == 'M')
                        && (ft_case_isvalid(tab, ligne - 2, colonne) && tab[ligne - 2][colonne] == 'A')
                        && (ft_case_isvalid(tab, ligne - 3, colonne) && tab[ligne - 3][colonne] == 'S'))
                ++cpt;
	return (cpt);
}

long	ft_day4(char *fichier)
{
	char	**tab;
	long	cpt;
	int	ligne;
	int	colonne;

	tab = ft_split(fichier, "\n");
	cpt = 0;
	ligne = 0;
	while (tab[ligne])
	{
		colonne = 0;
		while (tab[ligne][colonne])
		{
			cpt += ft_get_diagonal(tab, ligne, colonne);
			cpt += ft_get_axe(tab, ligne, colonne);
			++colonne;
		}
		++ligne;
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
	ft_putnbr(ft_day4(fichier));
	return (0);
}
