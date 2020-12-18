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

void received_attack(int pid, siginfo_t *information, void *my_context)
{
}


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
    
    if(pl->theirs_pid == 0)
    {
        (sg.sa_sigaction) = id_caller;
        sigaction(SIGUSR1, &sg,NULL);
        my_putstr("waiting for bananas!\n");
        my_put_nbr(pl->own_pid);
        pause();
        pl->theirs_pid = handle;
        my_putstr("\nconnection established! theirs pid = ");
        my_put_nbr(pl->theirs_pid);
        my_putstr("\n");
        kill(pl->theirs_pid,SIGUSR2);
        pl->order = first;
    } else{
        (sg.sa_sigaction) = connect_successful;
        sigaction(SIGUSR2, &sg, NULL);
        handle = pl->theirs_pid;
        my_putstr("signaling ...\n");
        my_put_nbr(getpid());
        kill(pl->theirs_pid,SIGUSR1);
        pause();
        if(handle == -2)
            my_putstr("connection returned!\n");
        else
        {
            my_putstr("error! ");
            return;
        }
        my_putstr("my id was: ");
        my_put_nbr(getpid());
        my_putchar('\n');
        pl->order = second;
    }


}

