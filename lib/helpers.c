/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-navy-nykyta.kudrya [WSL: Ubuntu]
** File description:
** helpers
*/

int get_from_char(char letter)
{
    int nb = letter - 'A';
    return(nb);
}

int get_from_num(char num)
{
    int nb = num - '0';
    return(nb);
}
