/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** debut du programme
*/

#include "../include/my.h"

int	main(int argc, char **argv)
{
	t_line	match;

	match.ac = argc;
	if (argc == 3) {
		match.av = my_strcpy(argv[1]);
		match.av_two = my_strcpy(argv[2]);
		match.colomn = my_getnbr(argv[1]);
		match.maxstick = my_getnbr(argv[2]);
	}
	if (gest(&match) == -1)
		return (0);
	else
		return (core(&match));
	return (0);
}

int	core(t_line *match)
{
	match->map = create_map(match);
	my_printmap(match);
	return (my_game(match));
}
