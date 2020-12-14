/*
** EPITECH PROJECT, 2020
** navy.c
** File description:
** navy.c
*/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include "../include/my.h"

void print_pos()
{
    my_putstr("my_positions:\n");
}

void print_ennemy_pos()
{
    my_putstr("ennemy's positions:\n");
}

char **check_size(map_t *map)
{
    if (map->tab = malloc(sizeof(char) * 11) == NULL)
        return (1);
}

char **display_map(map_t *map)
{
    map->tab = malloc(sizeof(char *) * 11);
    for (int i = 0; i < 10;) {
        if ((map->tab[i] = malloc(sizeof(char) * 18)) == NULL)
        return (NULL);
        ++i;
    }
    map->tab[0] = my_putstr(" |A B C D E F G H\n");
    map->tab[1] = my_putstr("-+---------------\n");
    map->tab[2] = my_putstr("1|. . . . . . . .\n");
    map->tab[3] = my_putstr("2|. . . . . . . .\n");
    map->tab[4] = my_putstr("3|. . . . . . . .\n");
    map->tab[5] = my_putstr("4|. . . . . . . .\n");
    map->tab[6] = my_putstr("5|. . . . . . . .\n");
    map->tab[7] = my_putstr("6|. . . . . . . .\n");
    map->tab[8] = my_putstr("7|. . . . . . . .\n");
    map->tab[9] = my_putstr("8|. . . . . . . .\n");
    return (map->tab);
}


int main()
{
    map_t *map = malloc(sizeof(map_t));
    char **tab;

    if (check_size(tab) == 1) {
    return (NULL);
    }
    display_map(tab);
}