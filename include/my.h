/*
** EPITECH PROJECT, 2020
** my_h
** File description:
** my_h
*/

#ifndef MY_H_
#define MY_H_

typedef struct map_s
{
    char **tab;
} map_t;

typedef struct entry_data{
    char **init_pos;
    int pid;
} entry_data_t;
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
void print_pos();
void print_ennemy_pos();
int my_getnbr(char const *str);
void my_put_nbr(int nb);
char **display_map(map_t *map);
char *my_strdup(char const *src);

#endif /* !MY_H_ */
