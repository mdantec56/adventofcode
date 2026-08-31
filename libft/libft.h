#ifndef LIBFT_H
#define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	ft_islow(char c);
int	ft_isup(char c);
int	ft_isalpha(char c);
int	ft_isdigit(char c);
int	ft_isalnum(char c);
int	ft_isascii(char c);
int	ft_isprint(char c);
void	ft_tolower(char c);
void	ft_toupper(char c);

void	ft_putchar(char c);
void	ft_putnbr(int nbr);
void	ft_putstr(char *str);

int	ft_strlen(char *str);

char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, unsigned int n);
int	ft_strcmp(char *s1, char *s2);
int	ft_strncmp(char *s1, char *s2);
int	ft_atoi(char *str);
char	*ft_itoa(int nbr);

char	*ft_strdup(char *src);
char	**ft_split(char *src, char *charset);
char	*ft_strjoin(char **srcs, char *sep);

char	*ft_get_fichier(char *fichier);

#endif
