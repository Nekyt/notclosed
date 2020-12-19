/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-navy-nykyta.kudrya [WSL: Ubuntu]
** File description:
** battle_start
*/

#include "../include/my.h"
#include "../include/my_signals.h"
#include "../include/battle_start.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void print_dispo(player_t *pl)
{
    my_putstr("my positions:\n");
    print_dstar(pl->own);
    my_putstr("enemy positions\n");
    print_dstar(pl->theirs);
}

int receive(player_t *pl)
{
    int r = 0;
    my_putstr("waiting for enemy's attack...\n");
    r = receive_attack(pl);
    my_putchar('\n');
    return(r);
}

int attack(player_t *pl)
{
    coord_t att = {0};
    char *at_p = NULL;
    long unsigned int off = 0;
    int r = 0;
    my_putstr("attack: ");
    getline(&at_p, &off, stdin);
    while (check_pos(at_p) != 1) {
        my_putstr("wrong position\nattack: ");
        at_p = NULL;
        off = 0;
        getline(&at_p, &off, stdin);
    }
    att.lett = at_p[0] - 'A' + 1;
    att.nb = at_p[1] - '0';
    r = attack_other_pl(att,pl);
    my_putchar('\n');
    return(r);
}

int won(int test, player_t *pl, coord_t act)
{
    act.lett = (act.lett + 1) * 2;
    act.nb = act.nb + 1;
    if (test == 1) {
        pl->score = pl->score + 1;
            pl->theirs[act.nb][act.lett] = 'x';
        if (pl->score == pl->score_max) {
            kill(pl->theirs_pid, SIGUSR1);
            my_putstr("I won");
            return (1);
        } else{
            kill(pl->theirs_pid, SIGUSR2);
        }
    } else{
        pl->theirs[act.nb][act.lett] = 'o';
        kill(pl->theirs_pid, SIGUSR2);
    }
    my_putstr("was at end");
  //  fflush(stdin);
    return (0);
}

int lost(int test, player_t *pl)
{
    if(test == 0){
        my_putstr("Enemy won\n");
        return (1);
    }
    else
        return (0);
}
void battle_start(player_t *pl)
{
    fight_manager(pl);
}

int analyze_hit(coord_t my_coord, player_t *pl)
{
    display_coord(&my_coord);
        my_putstr("\n");
    my_put_nbr(my_coord.lett);
    my_putstr("\n");
    my_put_nbr(my_coord.nb);
    my_putstr("\n");
    my_coord.lett = (my_coord.lett + 1) * 2;
    my_coord.nb = (my_coord.nb) + 1;

    if(is_num(pl->own[my_coord.nb][my_coord.lett]))
    {
        pl->own[my_coord.lett][my_coord.nb] = 'x';
        my_putstr(" hit\n");
        return (1);
    }
    else
    {
        pl->own[my_coord.lett][my_coord.nb] = 'o';
        my_putstr(" missed\n");
    }
    return (0);
}

int fight_manager(player_t *pl)
{
    if(pl->order == first)
    {
        do{
            print_dispo(pl);
        }
        while(attack(pl) == 0 && receive(pl) == 0);
    }
    else
    {
        do{
        print_dispo(pl);
        } while (receive(pl) == 0 && attack(pl) == 0);
    }
    my_putstr("exited manager...\n");
}