/*
** EPITECH PROJECT, 2018
** errors.c
** File description:
** gestion d'erreur
*/

#include "../include/my.h"

int	check_number(t_line *match)
{
	if (my_number(match->av) == -1)
		return (-1);
	if (my_number(match->av_two) == -1)
		return (-1);
	if (my_strlen(match->av) > 2)
		return (-1);
	return (0);
}

int	my_number(char *str)
{
	int	i = 0;

	for (i = 0; str[i]; i += 1)
		if (str[i] < 48 || str[i] > 57)
			return (-1);
	return (0);
}

int	check_arguments(t_line *match)
{
	if (match->ac != 3)
		return (-1);
	if (match->colomn < 2 || match->maxstick < 1)
		return (-1);
	return (1);
}
