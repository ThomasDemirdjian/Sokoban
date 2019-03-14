/*
** EPITECH PROJECT, 2018
** help
** File description:
** 
*/

#include <unistd.h>
#include "../include/my.h"

void	help()
{
	write(1, "USAGE\n\t./my_sokoban map\n", 24);
	write(1, "DESCRIPTION\n\tmap  file representing the", 39);
	write(1, " warehouse map, containing '#' for wall,\n", 41);
	write(1, "\t     'P' for the player, 'X' for boxes ", 40);
	write(1, "and 'O' for storage locations.\n", 32);
}