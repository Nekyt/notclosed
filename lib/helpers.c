/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-navy-nykyta.kudrya [WSL: Ubuntu]
** File description:
** helpers
*/

#include <stdlib.h>
#include "../include/my.h"


int get_from_char(char letter)
{
    int nb = letter - 'A';
    return (nb);
}

int get_from_num(char num)
{
    int nb = num - '0';
    return (nb);
}

int check_pos(char *at_p)
{
    if (at_p[0] >= 'A' && at_p[0] <= 'H') {
        if (at_p[1] >= '1' && at_p[1] <= '8') {
            return (1);
        }
    }
    return (0);
}

char *convert_to(int to_convert)
{
    char *result = malloc(5);
    int c = 0;
    long copy = to_convert;
    long rem = copy % 2;

    while (copy / 2 != 0 || rem != 0) {
        result[c++] = rem + '0';
        copy = copy / 2;
        rem = copy % 2;
    }
    if (c == 0){
        result[0] = '0';
        result[1] = '\0';
        return (result);
    }
    my_revstr(result);
    my_putstr("log : = ");
    my_putstr(result);
    my_putchar('\n');
    return (result);
}