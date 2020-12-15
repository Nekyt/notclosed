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
    right
} way_t;

typedef struct ship
{
    int start_pos;
    way_t orientation; 
} ship_t;


char **init_player_map(char **empty_map,char **coordinates);
char **init_empty_map();
