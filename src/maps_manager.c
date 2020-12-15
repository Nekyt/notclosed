/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-navy-nykyta.kudrya [WSL: Ubuntu]
** File description:
** maps_manager
*/

#include "../include/maps_manager.h"

char **init_empty_map() {
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
  return(empty_map);
}

ship_t **ship_analyzer(char **coordinates, int index, ship_t **ships_n)
{
    ship_t **ships;

    if(index == 0)
}


char **init_player_map(char **empty_map, char **coordinates)
{

}