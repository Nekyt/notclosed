/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-navy-nykyta.kudrya [WSL: Ubuntu]
** File description:
** battle_start
*/

#include "../include/my.h"
#include "../include/my_signals.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void print_attack(player_t *pl)
{
    my_putstr("my positions:\n");
    print_dstar(pl->own);
    my_putstr("enemy positions\n");
    print_dstar(pl->theirs);
}

void receive(player_t *pl)
{

}

void attack(player_t *pl)
{
    coord_t att = {0};
    print_attack(pl);
    char *at_p = NULL;
    long unsigned int off = 0;
    my_putstr("attack: ");
    getline(&at_p, &off, stdin);
    while (check_pos(at_p) != 1){
        my_putstr("wrong position\nattack: ");
        at_p = NULL;
        off = 0;
        getline(&at_p, &off, stdin);
    } 
    att.lett = (at_p[0] - 'A' + 1) * 2;
    att.nb = at_p[1] + 1;
}

void battle_start(player_t *pl)
{
    if (pl->order == first) {
        attack(pl);
    } else {
        receive(pl);
    }
}