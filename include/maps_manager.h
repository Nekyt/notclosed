/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-navy-nykyta.kudrya [WSL: Ubuntu]
** File description:
** maps_manager
*/

typedef enum way
{
    up, 
    down, 
    left, 
    right,
    def
} way_t;

typedef struct ship
{
    int start_pos_x;
    int start_pos_y;
    int length;
    way_t dir;
} ship_t;


char **init_player_map(char **coordinates, int index, char **fulfil);
char **init_empty_map();
