#include "libft.h"

typedef struct s_list
{
	int	x;
	int	y;
	int	z;
}		t_list;

t_list	ft_create_elem(int x, int y, int z)
{
	t_list elem;

	elem.x = x;
	elem.y = y;
	elem.z = z;
	return (elem);
}

int	ft_power_2(int n)
{
	return (n * n);
}

int	ft_get_distance(t_list elem1, t_list elem2)
{
	return (ft_power_2(elem1.x - elem2.x) + ft_power_2(elem1.y - elem2.y) + ft_power_2(elem1.z - elem2.z));
}

char	**ft_get_tab(char *fichier)
{
	char	**tab;

	tab = ft_subsplit(fichier, "\n");
	if (!tab)
		return (NULL);
	return (tab);
}

int	ft_get_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		++i;
	return (i);
}

t_list	*ft_get_structs(char *fichier)
{
	char	**tab;
	t_list	*list;
	char	**line;
	t_list	elem;
	int	i;
	int	x;
	int	y;
	int	z;

	i = 0;
	tab = ft_get_tab(fichier);
	list = malloc(sizeof(elem) * (ft_get_size(tab) + 1));
	while (tab[i])
	{
		line = ft_subsplit(tab[i], ",");
		x = ft_atoi(line[0]);
		y = ft_atoi(line[1]);
		z = ft_atoi(line[2]);
		list[i] = ft_create_elem(x, y, z);
		++i;
	}
	list[i] = ft_create_elem(-1, -1, -1);
	return (list);
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
	//ft_putnbr(ft_day8(fichier));
	free(fichier);
	
	return (0);
}
