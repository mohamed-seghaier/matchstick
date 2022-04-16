/*
** EPITECH PROJECT, 2018
** errors_ingame.c
** File description:
** oui
*/

#include "../include/my.h"

int	isnt_line(char *str, t_line *match)
{
	int	i = 0;

	for (i = 0; str[i]; i += 1) {
		if (str[i] < '0' || str[i] > '9')
			return (1);
	}
	if (my_getnbr(str) > my_getnbr(match->av) ||
	my_getnbr(str) < 1) {
		my_sputstr("Error: this line is out of range\n");
		return (2);
	}
	return (0);
}

int	isnt_matches(char *str, t_line *match)
{
	int	i = 0;

	for (i = 0; str[i]; i += 1) {
		if (str[i] < '0' || str[i] > '9')
			return (print_matcherror(1, match));
	}
	match->player_matches = (my_getnbr(str));
	if (match->player_matches > match->maxstick)
		return (print_matcherror(3, match));
	if (match->player_matches > pipelen(match->map[match->player_line]))
		return (print_matcherror(2, match));
	if (match->player_matches == 0)
		return (print_matcherror(4, match));
	return (0);
}

int	print_matcherror(int nb, t_line *match)
{
	if (nb == 1) {
		my_sputstr("Error: invalid input ");
		my_sputstr("(positive number expected)\n");
		return (1);
	}
	else if (nb == 2) {
		my_sputstr("Error: not enough matches on this line\n");
		return (2);
	}
	else
		return (suite_printerror(nb, match));
}

int	suite_printerror(int nb, t_line *match)
{
	if (nb == 3) {
		my_sputstr("Error: you cannot remove more than ");
		my_sputnbr(match->maxstick);
		my_sputstr(" matches per turn\n");
		return (3);
	}
	else if (nb == 4) {
		my_sputstr("Error: you have to remove at least");
		my_sputstr(" one match\n");
		return (4);
	}
    return (0);
}
