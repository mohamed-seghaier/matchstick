/*
** EPITECH PROJECT, 2018
** game_ai.c
** File description:
** tour de jeu de l'intelligence artificielle
*/

#include "../include/my.h"

void	one_line(t_line *match)
{
	int	i = match->maxstick;
	int	j = assign_line(match);
	int	idx = 0;
	int	k = pipelen(match->map[j]);

	if (pipelen(match->map[j]) > 1) {
		for (; pipelen(match->map[j]) > 1 && i >= 0; k -= 1, i -= 1)
			if (match->map[j][k] == '|') {
				match->map[j][k] = ' ';
				idx += 1;
			}
	}
	else if (pipelen(match->map[j]) == 1) {
		match->map[j][0] = ' ';
	}
	match->ai_line = j;
	match->ai_matches = idx;
	my_printf("AI removed %d match", match->ai_matches);
	my_printf("(es) from line %d\n", (match->ai_line + 1));
	my_printmap(match);
}

void	all_lines(t_line *match)
{
	int	i = 0;
	int	j = 0;
	int	k = match->maxstick;
	int	idx = 0;
	int	pip = 0;

	for (j = 0; match->map[j] != NULL; j += 1) {
		i = (pipelen(match->map[j]) - 1);
		while (i >= 0 && k > 0) {
			if (match->map[j][i] == '|') {
				match->map[j][i] = ' ';
				idx += 1;
				i -= 1;
				k -= 1;
			}
		}
		if (idx != 0)
			break;
	}
	mapline(match, j, idx);
}

void	remove_onlyone(t_line *match)
{
	int	i = 0;
	int	j = 0;
	int	idx = 0;

	for (j = 0; match->map[j] != NULL; j += 1) {
		for (i = 0; match->map[j][i] != 0
			&& pipelen(match->map[j]) != 0; i += 1) {
			if (match->map[j][i] == '|') {
				match->map[j][i] = ' ';
				idx += 1;
			}
		}
	}
	mapline(match, j, idx);
}

void	mapline(t_line *match, int j, int idx)
{
	match->ai_line = j;
	match->ai_matches = idx;
	my_printf("AI removed %d match", match->ai_matches);
	my_printf("(es) from line %d\n", (match->ai_line + 1));
	my_printmap(match);
}
