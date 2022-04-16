/*
** EPITECH PROJECT, 2018
** mapper.c
** File description:
** gestion de la map
*/

#include "../include/my.h"

void	my_printmap(t_line *match)
{
	my_putstars(match->colomn);
	my_putab(match);
	my_putstars(match->colomn);
}

void	my_putstars(int max)
{
	int	line = max * 2;
	int	i = 0;

	for (; i <= line; i += 1)
		my_putchar('*');
	my_putchar('\n');
}

void	my_putspace(int max)
{
	int	i = 0;

	for (; i <= max; i += 1)
		my_putchar(' ');
}

void	my_putab(t_line *match)
{
	int	idx_tab = 0;
	int	idx_line = 0;

	for (; match->map[idx_tab] != NULL; idx_tab += 1, idx_line += 1) {
		my_putchar('*');
		my_putspace(match->colomn - idx_line - 2);
		my_putstr(match->map[idx_tab]);
		my_putspace(match->colomn - idx_line - 2);
		my_putchar('*');
		my_putchar(10);
	}
}
