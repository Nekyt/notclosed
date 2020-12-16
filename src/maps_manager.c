/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-navy-nykyta.kudrya [WSL: Ubuntu]
** File description:
** maps_manager
*/

#include "../include/maps_manager.h"
#include "../include/my.h"
#include <stdlib.h>

char **init_empty_map()
{
    char **empty_map = malloc(sizeof(char *) * 11);

    empty_map[0] = my_strdup(" |A B C D E F G H\n");
    empty_map[1] = my_strdup("-+---------------\n");
    empty_map[2] = my_strdup("1|. . . . . . . .\n");
    empty_map[3] = my_strdup("2|. . . . . . . .\n");
    empty_map[4] = my_strdup("3|. . . . . . . .\n");
    empty_map[5] = my_strdup("4|. . . . . . . .\n");
    empty_map[6] = my_strdup("5|. . . . . . . .\n");
    empty_map[7] = my_strdup("6|. . . . . . . .\n");
    empty_map[8] = my_strdup("7|. . . . . . . .\n");
    empty_map[9] = my_strdup("8|. . . . . . . .\n");
    return (empty_map);
}

way_t determine_dir(ship_t **ships, int index, int end_pos_x, int end_pos_y)
{
    if (end_pos_x != ships[index]->start_pos_x) {
        if (end_pos_x > ships[index]->start_pos_x)
            return (right);
        else if (end_pos_x < ships[index]->start_pos_x)
            return (left);
    } else {
        if (end_pos_y > ships[index]->start_pos_y)
            return (down);
        else if (end_pos_y < ships[index]->start_pos_y)
            return (up);
    }
    return(def);
}

void print_ships(ship_t **ships)
{
    for (int i = 0; ships[i] != NULL; i++) {
        my_putstr("ship no ");
        my_put_nbr(i);
        my_putchar('\n');
        my_putstr("ship length:");
        my_put_nbr(ships[i]->length);
        my_putstr("\nship direction: ");
        my_put_nbr(ships[i]->dir);
        my_putstr("\nship st point\n");
        my_put_nbr(ships[i]->start_pos_x);
        my_putchar(' ');
        my_put_nbr(ships[i]->start_pos_y);
        my_putchar('\n');
    }
}

ship_t **ship_analyzer(char **coordinates, int index, ship_t **ships)
{
    int end_pos_x = get_from_char(coordinates[index][5] + 2);
    int end_pos_y = get_from_num(coordinates[index][6] + 1);

    if (index == 0) {
        ships = malloc(sizeof(ship_t *) * 5);
        ships[4] = NULL;
    }
    ships[index] = malloc(sizeof(ship_t));
    ships[index]->length = get_from_num(coordinates[index][0]);
    ships[index]->start_pos_x = get_from_char(coordinates[index][2] + 2);
    ships[index]->start_pos_y = get_from_num(coordinates[index][3] + 1);
    ships[index]->dir = determine_dir(ships, index, end_pos_x, end_pos_y);
    if (index >= 3)
        return (ships);
    else
        return (ship_analyzer(coordinates, index + 1, ships));
}

char **init_player_map(char **coordinates, int index, char **fulfil)
{
    ship_t **ships = ship_analyzer(coordinates, 0 , NULL);
    ship_t *cur = ships[index];
    print_ships(ships);

}