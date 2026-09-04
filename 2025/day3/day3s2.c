#include "libft.h"

char	*ft_get_biggest(char *number)
{
	char	*biggest;
	int	len_number;
	int	len_biggest;
	int	i;
	int	indmax;
	char	max_nb;
	int	start;

	len_number = ft_strlen(number);
	biggest = malloc(sizeof(char) * (12 + 1));
	len_biggest = 0;
	start = 0;
	while (len_biggest < 12)
	{
		indmax = start;
		max_nb = number[start];
		i = start + 1;
		while (i <= len_number - (12 - len_biggest))
		{
			if (number[i] > max_nb)
			{
				max_nb = number[i];
				indmax = i;
			}
			++i;
		}
		biggest[len_biggest] = max_nb;
		start = indmax + 1;
		++len_biggest;
	}
	biggest[len_biggest] = '\0';
	return (biggest);
}

long	ft_day3(char *fichier)
{
	char	**numbers;
	int	i;
	long	res;

	numbers = ft_subsplit(ft_get_fichier(fichier), "\n");
	i = 0;
	res = 0;
	while (numbers[i])
	{
		res += ft_atoi(ft_get_biggest(numbers[i]));
		++i;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	char    *fichier;
	if (argc != 2)
	{
		ft_putstr("Nombre d'arguments invalide");
		return (1);
	}
	fichier = argv[1];
	ft_putnbr(ft_day3(fichier));
	return (0);
}
