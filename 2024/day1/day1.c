#include "libft.h"

int	ft_strcmp_nbr(char *n1, char *n2)
{
	int	i;

	if (ft_strlen(n1) > ft_strlen(n2))
		return (1);
	if (ft_strlen(n1) < ft_strlen(n2))
		return (-1);
	i = 0;
	while (n1[i])
	{
		if (n1[i] > n2[i])
			return (1);
		if (n1[i] < n2[i])
			return (-1);
		++i;
	}
	return (0);
}

void	ft_sort_list(char **list)
{
	int	i;
	char	*temp;

	i = 0;
	while (list[i + 1])
	{
		if (ft_strcmp_nbr(list[i], list[i + 1]) > 0)
		{
			temp = list[i];
			list[i] = list[i + 1];
			list[i + 1] = temp;
			i = 0;
		}
		else
			++i;
	}
}

long	ft_abs(long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

long	ft_get_diff(long n1, long n2)
{
	return (ft_abs(n1 - n2));
}

int	ft_get_size(char **list)
{
	int	i;

	i = 0;
	while (list[i])
		++i;
	return (i);
}

char	**ft_get_list(char **lines, int n)
{
	char	**list;
	int	i;

	list = malloc(sizeof(char *) * (ft_get_size(lines) + 1));
	i = 0;
	while (lines[i])
	{
		list[i] = ft_split(lines[i], " ")[n];
		++i;
	}
	list[i] = NULL;
	return (list);
}

long	ft_day1(char *fichier)
{
	int	i;
	char	**lines;
	long	res;
	char	*n1;
	char	*n2;
	char	**list1;
	char	**list2;

	lines = ft_subsplit(fichier, "\n");
	list1 = ft_get_list(lines, 0);
	list2 = ft_get_list(lines, 1);
	ft_sort_list(list1);
	ft_sort_list(list2);
	i = 0;
	res = 0;
	while (lines[i])
	{
		n1 = list1[i];
		n2 = list2[i];
		res += ft_get_diff(ft_atoi(n1), ft_atoi(n2));
		++i;
	}
	return (res);
}

int     main(int argc, char **argv)
{
        char    *fichier;

        if (argc != 2)
        {
                ft_putstr("Nombre d'arguments invalide");
                return (1);
        }
        fichier = ft_get_fichier(argv[1]);
        ft_putnbr(ft_day1(fichier));
        return (0);
}
