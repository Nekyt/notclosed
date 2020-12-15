/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** my_getnbr
*/

#include <stdio.h>

int my_getnbr(char const *str)
{
    int signe = 1;
    int i = 0;
    int nbr = 0;

    while (str[i] != '\0' && (str[i] == '-' || str[i] == '+')) {
        if (str[i] == '-') {
            signe *= -1;
        }
        ++i;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nbr = nbr * 10;
            nbr = nbr + (str[i] - '0');
            i++;
            if (str[i] < '0' || str[i] > '9') {
                return (nbr * signe);
            }
            continue;
        }
        else if (str[i] < '0' && str[i] > '9')
            return (nbr * signe);
        i++;
    }
    return (nbr * signe);
}
