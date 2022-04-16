/*
** EPITECH PROJECT, 2018
** mapping.c
** File description:
** creation et gestion de la map
*/

#include "../include/my.h"

char	**create_map(t_line *match)
{
	int	idx_tab = 0;
	int	idx_line = 1;
	char	**tab;

	if ((tab = malloc(sizeof(char *) * match->colomn)) == NULL)
		return (NULL);
	for (; idx_tab <= (match->colomn - 1); idx_tab += 1) {
		tab[idx_tab] = remplitab(tab[idx_tab], idx_line);
		idx_line += 2;
	}
	tab[idx_tab] = NULL;
	return (tab);
}

char	*remplitab(char *str, int limit)
{
	int	i = 0;

	if ((str = malloc(sizeof(char) * (limit + 1))) == NULL)
		return (NULL);
	for (; i <= limit - 1; i += 1)
		str[i] = '|';
	str[i] = 0;
	return (str);
}

void	remove_pipe(t_line *match)
{
	int	i = match->player_matches;
	int	j = pipelen(match->map[match->player_line]);
	int	k = match->player_line;

	for (; j >= 0 && i >= 0; j -= 1, i -= 1)
		if (match->map[k][j] == '|')
			match->map[k][j] = ' ';
}
