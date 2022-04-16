/*
** EPITECH PROJECT, 2018
** checkpoint.c
** File description:
** check_error
*/

#include "../include/my.h"

int	gest(t_line *match)
{
	int	idx_check = 0;

	for (idx_check = 0; idx_check < 2; idx_check += 1)
		if (my_pretab(idx_check, match) == -1)
			return (-1);
	return (0);
}

int	my_pretab(int i, t_line *match)
{
	ptab_t	check[3];

	check[0] = &check_arguments;
	check[1] = &check_number;
	check[2] = NULL;
	return ((*check[i])(match));
}
