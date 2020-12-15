/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** my_putstr
*/

#include <unistd.h>
void my_putchar(char c);

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}