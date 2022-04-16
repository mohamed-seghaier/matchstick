/*
** EPITECH PROJECT, 2018
** epitech
** File description:
** gestion de la victoire
*/

#include "../include/my.h"

int	victory(int nb, t_line *match)
{
	if (nb == 1)
		return (victory_player(match));
	else if (nb == 2)
		return (victory_ai(match));
	return (0);
}

int	victory_player(t_line *match)
{
	int	idx_stick = 0;
	int	i = 0;
	int	j = 0;

	for (; match->map[j] != NULL; j += 1) {
		for (i = 0; match->map[j][i]; i += 1) {
			if (match->map[j][i] == '|')
				idx_stick += 1;
		}
	}
	if (idx_stick == 0) {
		my_putstr("I lost... snif... but I'll get you next time!!\n");
		return (0);
	}
	return (1);
}

int	victory_ai(t_line *match)
{
	int	idx_stick = 0;
	int	i = 0;
	int	j = 0;

	for (; match->map[j] != NULL; j += 1) {
		for (i = 0; match->map[j][i]; i += 1) {
			if (match->map[j][i] == '|')
				idx_stick += 1;
		}
	}
	if (idx_stick == 0) {
		my_putstr("You lost, too bad...\n");
		return (0);
	}
	return (2);
}
