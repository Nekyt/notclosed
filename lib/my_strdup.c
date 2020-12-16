/*
** EPITECH PROJECT, 2020
** strdup1
** File description:
** strdup1
*/

#include "../include/my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int i = my_strlen(src);
    char *str = malloc(sizeof(char) * (i) + 1);
    int k = 0 ;
    for (; k < i; k++) {
        str[k] = src[k];
    }
    str[k] = '\0';

    return (str);
}