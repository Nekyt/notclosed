/*
** EPITECH PROJECT, 2020
** navy [WSL: Ubuntu]
** File description:
** my_signals
*/
#define _GNU_SOURCE 
#include "../include/my_signals.h"
#include "../include/my.h"
#include <unistd.h>
#include <signal.h> 


int handle = 0;


void id_caller(int s_nb, siginfo_t *info, void *context)
{
    int other_id = info->si_pid;
    handle = other_id;
}

void connect_successful(int s_nb, siginfo_t *info, void *context)
{
    if(info->si_pid == handle)
        handle = -2;
}

void manage_ids(player_t *pl)
{
    struct sigaction sg = {0};
    sg.sa_flags = SA_SIGINFO;
    sigemptyset(&(sg.sa_mask));

    my_putstr("my_pid: \n");
    my_put_nbr(getpid());
    my_putchar('\n');
    if(pl->theirs_pid == 0)
    {
        my_putstr("waiting for enemy connection...\n\n");
        (sg.sa_sigaction) = id_caller;
        sigaction(SIGUSR1, &sg,NULL);
        pause();
        pl->theirs_pid = handle;
        my_putstr("enemy connected\n\n");
        kill(pl->theirs_pid,SIGUSR2);
        pl->order = first;
    } else{
        (sg.sa_sigaction) = connect_successful;
        sigaction(SIGUSR2, &sg, NULL);
        handle = pl->theirs_pid;

        kill(pl->theirs_pid,SIGUSR1);
        pause();
        if(handle == -2)
            my_putstr("successfully connected\n\n");
        else
        {
            my_putstr("error!");
            return;
        }
        pl->order = second;
    }
}

