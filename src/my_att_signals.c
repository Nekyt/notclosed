/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-navy-nykyta.kudrya [WSL: Ubuntu]
** File description:
** my_att_signals
*/

#define _GNU_SOURCE
#include "../include/my.h"
#include "../include/my_signals.h"
#include "../include/maps_manager.h"
#include "../include/battle_start.h"
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

void determine_success(int num)
{
    if (num == SIGUSR1) {
        handle = 0;
    } else if (num == SIGUSR2) {
        handle = 1;
    }
}

void att_helper(coord_t *act, player_t *pl)
{

}

int attack_other_pl(coord_t act, player_t *pl)
{
    struct sigaction sg1 = {0};
    (sg1.sa_handler) = determine_success;
    sigaction(SIGUSR1, &sg1, NULL);
    sigaction(SIGUSR2, &sg1, NULL);
    for (int i = 0; i < act.lett; i++) {
        kill(pl->theirs_pid, SIGUSR1);
            usleep(5);
    }
    pause();
    for (int i = 0; i < act.nb; i++) {
        kill(pl->theirs_pid, SIGUSR1);
            usleep(5);
    }
    pause();
   // my_putstr("not you!\n");
    return(won(handle, pl, act));
}

void receive_handle(int num)
{
    handle = handle + 1;
}

void r_helper(player_t *pl, struct timespec *tc, coord_t *received)
{
    handle = 0;
    tc->tv_nsec = 10000000;
    pause();
    while (nanosleep(tc, tc) < 0);
    received->lett = handle;
    tc->tv_sec = 0;
    tc->tv_nsec = 10000000;
    handle = 0;
    kill(pl->theirs_pid, SIGUSR1);

    while (nanosleep(tc, tc) < 0);
    received->nb = handle;
}

int receive_attack(player_t *pl)
{
    struct timespec tc = {0};
    coord_t received = {0};
    struct sigaction sg = {0};

    (sg.sa_handler) = receive_handle;
    sigaction(SIGUSR1, &sg, NULL);
    r_helper(pl, &tc, &received);
    (sg.sa_handler) = determine_success;
    sigaction(SIGUSR1, &sg, NULL);
    sigaction(SIGUSR2, &sg, NULL);
     if(analyze_hit(received, pl) == 1)
          kill(pl->theirs_pid, SIGUSR2);
     else
         kill(pl->theirs_pid, SIGUSR1);
    pause();
      //  my_putstr("am\n");

    return (lost(handle, pl));
}