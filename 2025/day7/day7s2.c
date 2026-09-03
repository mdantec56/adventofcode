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
	if (ligne >= 0 && ligne < ft_get_size(tab) && colonne >= 0 && colonne < ft_strlen(tab[ligne]))
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

void	ft_putsplit(char **tab, int ligne, int colonne)
{
	if (tab[ligne][colonne] == '|' && ft_case_is_valid(tab, ligne + 1, colonne + 1) && tab[ligne + 1][colonne] == '^')
		tab[ligne + 1][colonne + 1] = '|';
	if (tab[ligne][colonne] == '|' && ft_case_is_valid(tab, ligne + 1, colonne - 1) && tab[ligne + 1][colonne] == '^')
		tab[ligne + 1][colonne - 1] = '|';
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

char	**ft_create_tachyon(char *fichier)
{
	char	**tab;
	int	ligne;
	int	colonne;

	tab = ft_split(fichier, "\n");
	if (!tab)
		return (NULL);
	ligne = 0;
	while (tab[ligne])
	{
		colonne = 0;
		while (colonne < ft_strlen(tab[ligne]))
		{
			ft_start(tab, ligne, colonne);
			ft_puttachyon(tab, ligne, colonne);
			ft_putsplit(tab, ligne, colonne);
			++colonne;
		}
		++ligne;
	}
	return (tab);
}

long long	**ft_create_memo(int size_l, int size_c)
{
	long long	**tab;
	int	i;
	int	j;

	tab = malloc(sizeof(long long *) * (size_l + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size_l)
	{
		j = 0;
		tab[i] = malloc(sizeof(long long) * (size_c + 1));
		while (j < size_c)
		{
			tab[i][j] = -1;
			++j;
		}
		++i;
	}
	tab[i] = NULL;
	return (tab);
}

long long	ft_count(char **tab, long long **memo, int ligne, int colonne)
{
	long long count;

	count = 0;
	if (memo[ligne][colonne] != -1)
		return (memo[ligne][colonne]);
	if (!ft_case_is_valid(tab, ligne + 1, colonne))
	{
		memo[ligne][colonne] = 1;
		return (1);
	}
	if (tab[ligne + 1][colonne] == '^')
	{
		if (ft_case_is_valid(tab, ligne + 1, colonne - 1))
			count += ft_count(tab, memo, ligne + 1, colonne - 1);
		if (ft_case_is_valid(tab, ligne + 1, colonne + 1))
			count += ft_count(tab, memo, ligne + 1, colonne + 1);
	}
	else
		count = ft_count(tab, memo, ligne + 1, colonne);
	memo[ligne][colonne] = count;
	return (count);
}
long long	ft_day7s2(char *fichier)
{
	char	**tab;
	int	ligne;
	int	colonne;
	long long	cpt_timeline;
	long long	**memo;

	tab = ft_create_tachyon(fichier);
	if (!tab)
		return (-1);
	ligne = 0;
	cpt_timeline = 0;
	memo = ft_create_memo(ft_get_size(tab), ft_strlen(tab[0]));
	if (!memo)
		return (-1);
	while (tab[ligne])
	{
		colonne = 0;
		while (tab[ligne][colonne])
		{
			if (tab[ligne][colonne] == 'S')
				cpt_timeline += ft_count(tab, memo, ligne, colonne);
			++colonne;
		}
		++ligne;
	}
	return (cpt_timeline);
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
	ft_putnbr(ft_day7s2(fichier));
	free(fichier);
	return (0);
}
