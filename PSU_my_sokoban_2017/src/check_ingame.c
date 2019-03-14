/*
** EPITECH PROJECT, 2018
** check_ingame
** File description:
** 
*/

#include "../include/my.h"

void	init_box(t_nbr_box *box)
{
	box->u = 0;
	box->d = 0;
	box->l = 0;
	box->r = 0;
}

int	check_wall(t_nbr_box *box)
{
	if (box->u == 1 && box->l == 1)
		return (-1);
	else if (box->u == 1 && box->r == 1)
		return (-1);
	else if (box->d == 1 && box->l == 1)
		return (-1);
	else if (box->d == 1 && box->r == 1)
		return (-1);
	else
		return (0);
}

int	check_pos_box(t_map *map, int i, int j)
{
	t_nbr_box	*box = malloc(sizeof(struct s_nbr_box));

	init_box(box);
	if (map->map[i + 1][j] == '#')
		box->d = 1;
	if (map->map[i - 1][j] == '#')
		box->u = 1;
	if (map->map[i][j - 1] == '#')
		box->l = 1;
	if (map->map[i][j + 1] == '#')
		box->r = 1;
	if (check_wall(box) == -1)
		return (-1);
	return (0);
}

int	check_stuck(t_map *map)
{
	int	i = 0;
	int	j = 0;
	int	check = 0;
	int	nbr_check = 0;

	while (i != map->line) {
		if (map->map[i][j] == 'X')
			check = check_pos_box(map, i, j);
		if (check == -1)
			nbr_check++;
		check = 0;
		j++;
		if (j == map->col) {
			j = 0;
			i++;
		}
	}
	if (nbr_check == map->nbr_box)
		return (-1);
	return (0);
}

int	check_end_game(t_map *map)
{
	int	box = 0;
	int	x = 0;
	int	y = 0;

	while (x != map->line) {
		while (y != map->col) {
			if (map->map[x][y] == 'O')
				box++;
			else if (map->map[x][y] == 'P' &&
			map->s_map[x][y] == 'O')
				box++;
			y++;
		}
		y = 0;
		x++;
	}
	return (box);
}