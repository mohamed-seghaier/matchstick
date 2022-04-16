/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef	_MY_H_
#define	_MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>

typedef	struct	s_line	{
	int	maxstick;
	int	colomn;
	char	*av;
	char	*av_two;
	int	ac;
	char	**map;
	int	player_line;
	int	player_matches;
	int	ai_line;
	int	ai_matches;
}	t_line;

typedef	int	(*ptab_t)	(t_line *);

void	my_printmap(t_line *);
void	my_putstars(int);
void	my_putspace(int);
void	my_putab(t_line *);
void	my_putnbr(int);
void	my_putstr(char *);
void	my_putchar(char);
void	my_printf(char *, ...);
void	my_ptab(int, va_list(ap));
void	flag_s(va_list ap);
void	flag_d(va_list ap);
void	flag_c(va_list ap);
void	my_sputchar(char);
void	my_sputstr(char *);
void	my_sputnbr(int);
void	my_memset(char *, int, int);
void	remove_pipe(t_line *);
void	one_line(t_line *);
void	all_lines(t_line *);
void	remove_onlyone(t_line *);
void	mapline(t_line *, int, int);
char	*remplitab(char *, int);
char	*my_strcpy(char *);
char	**create_map(t_line *);
int	check_number(t_line *);
int	main(int, char **);
int	core(t_line *);
int	gest(t_line *);
int	my_pretab(int, t_line *);
int	checkflag(char);
int	my_strlen(char *);
int	my_number(char *);
int	check_arguments(t_line *);
int	my_getnbr(char *);
int	my_game(t_line *);
int	isnt_line(char *, t_line *);
int	isnt_matches(char *, t_line *);
int	line(t_line *);
int	matches(t_line *);
int	ai(t_line *);
int	player(t_line *);
int	pipelen(char *);
int	victory(int, t_line *);
int	victory_player(t_line *);
int	victory_ai(t_line *);
int	print_matcherror(int, t_line *);
int	suite_printerror(int, t_line *);
int	count_line(t_line *);
int	assign_line(t_line *);
char	*get_next_line(int);
char	*my_strcat(char *, char *);

#endif	/*!MY_H_*/
