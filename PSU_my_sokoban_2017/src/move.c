/*
** EPITECH PROJECT, 2018
** move
** File description:
** 
*/

#include "../include/my.h"

int	move_u(t_map *map, t_pos *pos, int mod)
{
	if (map->s_map[pos->i][pos->j] == 'O')
		map->map[pos->i][pos->j] = 'O';
	else
		map->map[pos->i][pos->j] = ' ';
	pos->i -= 1;
	map->map[pos->i][pos->j] = 'P';
	if (mod == 1)
		map->map[pos->i - 1][pos->j] = 'X';
	return (0);
}

int	move_d(t_map *map, t_pos *pos, int mod)
{
	if (map->s_map[pos->i][pos->j] == 'O')
		map->map[pos->i][pos->j] = 'O';
	else
		map->map[pos->i][pos->j] = ' ';
	pos->i += 1;
	map->map[pos->i][pos->j] = 'P';
	if (mod == 1)
		map->map[pos->i + 1][pos->j] = 'X';
	return (0);
}

int	move_l(t_map *map, t_pos *pos, int mod)
{
	if (map->s_map[pos->i][pos->j] == 'O')
		map->map[pos->i][pos->j] = 'O';
	else
		map->map[pos->i][pos->j] = ' ';
	pos->j -= 1;
	map->map[pos->i][pos->j] = 'P';
	if (mod == 1)
		map->map[pos->i][pos->j - 1] = 'X';
	return (0);
}

int	move_r(t_map *map, t_pos *pos, int mod)
{
	if (map->s_map[pos->i][pos->j] == 'O')
		map->map[pos->i][pos->j] = 'O';
	else
		map->map[pos->i][pos->j] = ' ';
	pos->j += 1;
	map->map[pos->i][pos->j] = 'P';
	if (mod == 1)
		map->map[pos->i][pos->j + 1] = 'X';
	return (0);
}