/*
** EPITECH PROJECT, 2018
** get_map
** File description:
** 
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/my.h"

int	get_line(char *filename)
{
	int	fd = open(filename, O_RDONLY);
	int	nb = 0;
	char	buffer[1];

	buffer[0] = '0';
	while (read(fd, &buffer, 1) != 0) {
		if (buffer[0] == '\n')
			nb++;
	}
	close(fd);
	if (buffer[0] == '\n')
		return (nb);
	return (nb + 1);
}

int	get_col(char *filename)
{
	int	i = 0;
	int	fd = open(filename, O_RDONLY);
	char	buffer[1];

	buffer[0] = '0';
	while (buffer[0] != '\n') {
		read(fd, &buffer, 1);
		i++;
	}
	close(fd);
	return (i - 1);
}

void	map_alloc(t_map *map)
{
	int	i = 0;

	map->map = malloc(sizeof(char *) * map->line);
	map->s_map = malloc(sizeof(char *) * map->line);
	while (i != map->line) {
		map->map[i] = malloc(sizeof(char) * map->col);
		map->s_map[i++] = malloc(sizeof(char) * map->col);
	}
}

void 	fill_map(t_map *map, char *filename)
{
	int	i = 0;
	int	fd = open(filename, O_RDONLY);

	while (i != map->line) {
		read(fd, map->map[i], (map->col + 1));
		map->map[i][map->col] = '\0';
		i++;
	}
}

void 	get_map(t_map *map, char *filename)
{
	map->line = get_line(filename);
	map->col = get_col(filename);
	map_alloc(map);
	fill_map(map, filename);
}