/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** 
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <curses.h>

typedef struct s_nbr_box
{
	int	u;
	int	d;
	int	l;
	int	r;
} t_nbr_box;

typedef	struct s_check
{
	int x;
	int o;
	int p;
} t_check;

typedef struct s_pos
{
	int i;
	int j;
} t_pos;

typedef struct s_map
{
	int nbr_box;
	int line;
	int col;
	char **map;
	char **s_map;
} t_map;

#ifndef MY_H_
# define MY_H_

void	help();
void	my_putchar(char);
void	print_map(t_map *map);
void 	get_map(t_map *map, char *);
void	map_alloc(t_map *map);
void	init_check(t_check *check);
void	fill_obj(char *str, t_check *check, t_map *map);
void	get_player(t_map *map, t_pos *pos);
void	save_tab(t_map *map, t_pos *pos, int );
char	*my_strcpy(char *src, char *dest);
int	check_stuck(t_map *map);
int	check_obj(t_map *map);
int	check_end_game(t_map *map);
int	get_line(char *filename);
int	check_lenline(char *filename);
int	check_cara(char *);
int	my_strlen(char *);
int	get_line(char *);
int	get_col(char *);
int	valid_wall(t_map *map);
int	ifmove_u(t_map *map, t_pos *pos);
int	ifmove_d(t_map *map, t_pos *pos);
int	ifmove_l(t_map *map, t_pos *pos);
int	ifmove_r(t_map *map, t_pos *pos);
int	move_u(t_map *map, t_pos *pos, int);
int	move_d(t_map *map, t_pos *pos, int);
int	move_l(t_map *map, t_pos *pos, int);
int	move_r(t_map *map, t_pos *pos, int);
int     orga_game(t_map *map, t_pos *pos);

#endif /* MY_H_ */
