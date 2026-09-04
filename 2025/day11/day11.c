#include "libft.h"

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
