/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-navy-nykyta.kudrya [WSL: Ubuntu]
** File description:
** ship_cptns
*/
#include <stdlib.h>
#include "../include/my.h"
#include "../include/maps_manager.h"

void ship_is_left(char **map, ship_t *to_put)
{
    int n_x = to_put->start_pos_x;
    int n_y = to_put->start_pos_y;

    for(int i = 0; i < to_put->length; i++)
    {
        map[n_y][n_x - i * 2] = to_put->length + '0';
    }
}

void ship_is_right(char **map, ship_t *to_put)
{
    int n_x = to_put->start_pos_x;
    int n_y = to_put->start_pos_y;

    for(int i = 0; i < to_put->length; i++)
    {
        map[n_y][n_x + i * 2] = to_put->length + '0';
    }
}

void ship_is_down(char **map, ship_t *to_put)
{
    int n_x = to_put->start_pos_x;
    int n_y = to_put->start_pos_y;
    
    for(int i = 0; i < to_put->length; i++)
    {
        map[n_y + i][n_x] = to_put->length + '0';
    }
}

void ship_is_up(char **map, ship_t *to_put)
{
    int n_x = to_put->start_pos_x;
    int n_y = to_put->start_pos_y;

    for(int i = 0; i < to_put->length; i++)
    {
        map[n_y - i][n_x] = to_put->length + '0';
    }
}