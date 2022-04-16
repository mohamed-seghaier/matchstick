/*
** EPITECH PROJECT, 2018
** utils_suite.c
** File description:
** suite de fonctions utilitaires
*/

#include "../include/my.h"

int	pipelen(char *str)
{
	int	i = 0;
	int	idx = 0;

	for (; str[i]; i += 1) {
		idx += str[i] == '|' ? 1 : 0;
	}
	return (idx);
}

int	count_line(t_line *match)
{
	int	i = 0;
	int	j = 0;
	int	idx = 0;

	for (j = 0; match->map[j] != NULL; j += 1) {
		for (i = 0; match->map[j][i] != 0; i += 1) {
			if (match->map[j][i] == '|') {
				idx += 1;
				break;
			}
		}
	}
	return (idx);
}

int	assign_line(t_line *match)
{
	int	i = 0;
	int	j = 0;
	int	idx = 0;

	for (j = 0; match->map[j] != NULL; j += 1) {
		for (i = 0; match->map[j][i] != 0; i += 1) {
			if (match->map[j][i] == '|') {
				idx += 1;
				break;
			}
		}
		if (idx > 0)
			break;
	}
	return (j);

}
