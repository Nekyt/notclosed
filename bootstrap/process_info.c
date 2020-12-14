/*
** EPITECH PROJECT, 2020
** PROCESS_INFO
** File description:
** PROCESS_INFO
*/
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int pid = getpid();
    int ppid = getppid();
    int pgid = getpgid(pid);

    my_putstr("PID : ");
    my_put_nbr(pid);
    my_putstr("\n");
    my_putstr("PPID : ");
    my_put_nbr(ppid);
    my_putstr("\n");
    my_putstr("PGID : ");
    my_put_nbr(pgid);
    my_putstr("\n");
}
