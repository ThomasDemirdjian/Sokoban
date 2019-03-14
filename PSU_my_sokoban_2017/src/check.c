/*
** EPITECH PROJECT, 2018
** check
** File description:
** 
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/my.h"

int	check_lenline(char *filename)
{
	int	fd = open(filename, O_RDONLY);
	int	len = get_col(filename);
	int	i = 0;
	char	buffer[1];

	buffer[0] = '0';
	while ((read(fd, buffer, 1)) != 0) {
		if (buffer[0] == '\n' && i == len)
			i = 0;
		else if (i > len)
			return (-1);
		else
			i++;
	}
	return (0);
}
int	check_cara(char *filename)
{
	int	fd = open(filename, O_RDONLY);
	char	buffer[1];

	buffer[0] = '0';
	if (fd == -1) return (-1);
	buffer[0] = '#';
	while ((read(fd, buffer, 1)) != 0) {
		if (buffer[0] != '#' && buffer[0] != ' ' && buffer[0] != 'O'
		 && buffer[0] != 'X' && buffer[0] != '\n' && buffer[0] != 'P')
			return (-1);
		}
	close(fd);
	return (0);
}

int	valid_wall(t_map *map)
{
	int	i = 0;
	int	j = 0;
	int	error = 0;

	while (j != (map->col - 1))
		if (map->map[i][j++] != '#')
			error++;
	while (i != (map->line - 1))
		if (map->map[i++][j] != '#')
			error++;
	i = 0;
	j = 0;
	while (i != (map->line - 1))
		if (map->map[i++][j] != '#')
			error++;
	while (j != (map->col - 1))
		if (map->map[i][j++] != '#')
			error++;
	return (error);
}