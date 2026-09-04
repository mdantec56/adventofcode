#include "libft.h"

typedef struct s_list
{
	int		x;
	int		y;
	int		z;
	int		index;
	struct s_list	*next;
}		t_list;

typedef struct s_pair
{
	long	distance;
	int	index1;
	int	index2;
}		t_pair;

typedef struct s_circuit
{
	t_list	*head;
	t_list	*tail;
	int	size;
	int	active;
}		t_circuit;

t_list	ft_create_elem(int x, int y, int z, int index)
{
	t_list elem;
	elem.x = x;
	elem.y = y;
	elem.z = z;
	elem.index = index;
	elem.next = NULL;
	return (elem);
}

long	ft_power_2(int n)
{
	return ((long)n * (long)n);
}

long	ft_get_distance(t_list elem1, t_list elem2)
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

int	ft_list_size(t_list *begin_list)
{
	int	count;
	t_list	*elem;
	count = 0;
	elem = begin_list;
	while (elem)
	{
		++count;
		elem = elem->next;
	}
	return (count);
}

int	ft_struct_size(t_list *list)
{
	int	i;
	i = 0;
	while (list[i].x != -1)
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
		list[i] = ft_create_elem(x, y, z, i);
		++i;
	}
	list[i] = ft_create_elem(-1, -1, -1, -1);
	return (list);
}

t_pair	*ft_get_pairs(t_list *list)
{
	int	i;
	int	j;
	int	k;
	int	n;
	long	distance;
	t_pair	*pairs;
	n = ft_struct_size(list);
	pairs = malloc(sizeof(t_pair) * (n * (n - 1) / 2));
	i = 0;
	k = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			distance = ft_get_distance(list[i], list[j]);
			pairs[k].distance = distance;
			pairs[k].index1 = i;
			pairs[k].index2 = j;
			++k;
			++j;
		}
		++i;
	}
	return (pairs);
}

void	ft_swap_pairs(t_pair *pair1, t_pair *pair2)
{
	t_pair temp;
	temp = *pair1;
	*pair1 = *pair2;
	*pair2 = temp;
}

int	ft_partition(t_pair *pairs, int low, int high)
{
	long	pivot;
	int	i;
	int	j;
	pivot = pairs[high].distance;
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (pairs[j].distance < pivot)
		{
			++i;
			ft_swap_pairs(&pairs[i], &pairs[j]);
		}
		++j;
	}
	ft_swap_pairs(&pairs[i + 1], &pairs[high]);
	return (i + 1);
}

void	ft_sort_pairs(t_pair *pairs, int low, int high)
{
	int	pivot_index;
	if (low < high)
	{
		pivot_index = ft_partition(pairs, low, high);
		ft_sort_pairs(pairs, low, pivot_index - 1);
		ft_sort_pairs(pairs, pivot_index + 1, high);
	}
}

t_circuit	*ft_init_circuits(t_list *list, int n)
{
	t_circuit	*circuits;
	int	i;
	circuits = malloc(sizeof(t_circuit) * n);
	i = 0;
	while (i < n)
	{
		circuits[i].head = &list[i];
		circuits[i].tail = &list[i];
		circuits[i].size = 1;
		circuits[i].active = 1;
		++i;
	}
	return (circuits);
}

int	*ft_init_circuit_id(int n)
{
	int	*circuit_id;
	int	i;
	circuit_id = malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		circuit_id[i] = i;
		++i;
	}
	return (circuit_id);
}

void	ft_merge_circuits(t_circuit *circuits, int *circuit_id, int c1, int c2)
{
	t_list	*current;
	circuits[c1].tail->next = circuits[c2].head;
	circuits[c1].tail = circuits[c2].tail;
	circuits[c1].size += circuits[c2].size;
	current = circuits[c2].head;
	while (current)
	{
		circuit_id[current->index] = c1;
		current = current->next;
	}
	circuits[c2].active = 0;
}

int	ft_connect_pairs(t_pair *pairs, int nb_pairs, t_circuit *circuits, int *circuit_id, int limit)
{
	int	i;
	int	c1;
	int	c2;
	i = 0;
	while (i < nb_pairs && i < limit)
	{
		c1 = circuit_id[pairs[i].index1];
		c2 = circuit_id[pairs[i].index2];
		if (c1 != c2)
			ft_merge_circuits(circuits, circuit_id, c1, c2);
		++i;
	}
	return (i);
}

int	ft_top_three_product(t_circuit *circuits, int n)
{
	int	i;
	int	top1;
	int	top2;
	int	top3;
	int	taille;
	top1 = 0;
	top2 = 0;
	top3 = 0;
	i = 0;
	while (i < n)
	{
		if (circuits[i].active)
		{
			taille = circuits[i].size;
			if (taille > top1)
			{
				top3 = top2;
				top2 = top1;
				top1 = taille;
			}
			else if (taille > top2)
			{
				top3 = top2;
				top2 = taille;
			}
			else if (taille > top3)
				top3 = taille;
		}
		++i;
	}
	return (top1 * top2 * top3);
}

int	ft_day8(char *fichier, int limit)
{
	t_list		*list;
	t_pair		*pairs;
	t_circuit	*circuits;
	int		*circuit_id;
	int		n;
	int		nb_pairs;
	int		resultat;
	list = ft_get_structs(fichier);
	n = ft_struct_size(list);
	pairs = ft_get_pairs(list);
	nb_pairs = n * (n - 1) / 2;
	ft_sort_pairs(pairs, 0, nb_pairs - 1);
	circuits = ft_init_circuits(list, n);
	circuit_id = ft_init_circuit_id(n);
	ft_connect_pairs(pairs, nb_pairs, circuits, circuit_id, limit);
	resultat = ft_top_three_product(circuits, n);
	free(list);
	free(pairs);
	free(circuits);
	free(circuit_id);
	return (resultat);
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
	ft_putnbr(ft_day8(fichier, 1000));
	free(fichier);
	return (0);
}
