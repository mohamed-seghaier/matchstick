/*
** EPITECH PROJECT, 2018
** game.c
** File description:
** le jeu
*/

#include "../include/my.h"

int	my_game(t_line *match)
{
	char	*str = NULL;
	char	**tab = NULL;
	int	idx = 0;

	while (42) {
		idx = player(match);
		if (idx == 8)
			return (0);
		else if (idx == 1)
			return (2);
		idx = 0;
		idx = ai(match);
		if (idx == 8)
			return (0);
		if (idx == 1)
			return (1);
	}
	return (0);
}

int	player(t_line *match)
{
	int	i = 0;

	my_putstr("\nYour turn:\n");
	if (line(match) == 8)
		return (8);
	if (matches(match) == 8)
		return (8);
	remove_pipe(match);
	my_printf("Player removed %d match", match->player_matches);
	my_printf("(es) from line %d\n", (match->player_line + 1));
	my_printmap(match);
	if (victory(2, match) == 0)
		return (1);
	return (0);
}

int	matches(t_line *match)
{
	char	*str = NULL;
	int	idx_alpha = 0;

	my_putstr("Matches: ");
	while ((str = get_next_line(0)) == NULL
	|| (idx_alpha = isnt_matches(str, match)) != 0) {
		if (str == NULL)
			return (8);
		if (line(match) == 8)
			return (8);
		my_putstr("Matches: ");
	}
	return (0);
}

int	ai(t_line *match)
{
	my_printf("\nAI's turn...\n");
	if (count_line(match) == 1)
		one_line(match);
	else if (count_line(match) != 0)
		all_lines(match);
	if (victory(1, match) == 0)
		return (1);
	return (0);
}

int	line(t_line *match)
{
	char	*str = NULL;
	int	idx_alpha = 0;

	my_putstr("Line: ");
	while ((str = get_next_line(0)) == NULL
	|| (idx_alpha = isnt_line(str, match)) != 0) {
		if (str == NULL)
			return (8);
		if (idx_alpha == 1) {
			my_sputstr("Error: invalid input ");
			my_sputstr("(positive number expected)\n");
		}
		my_putstr("Line: ");
	}
	match->player_line = (my_getnbr(str) - 1);
    return (0);
}
