/*
** EPITECH PROJECT, 2020
** my_h
** File description:
** my_h
*/

#ifndef MY_H_
#define MY_H_
#include "maps_manager.h"
typedef struct map_s {
    char **tab;
} map_t;

typedef struct entry_data {
    char **init_pos;
    int pid;
} entry_data_t;

typedef enum ppos { first, second } ppos_t;

typedef struct player {
    char **own;
    char **theirs;
    int own_pid;
    int theirs_pid;
    int score_max;
    int score;
    ppos_t order;
} player_t;

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
void print_pos();
int get_from_char(char letter);
int get_from_num(char num);
void print_ennemy_pos();
int my_getnbr(char const *str);
void my_put_nbr(int nb);
char **display_map(map_t *map);
char *my_strdup(char const *src);
player_t *init_player(char **our_map, ship_t **ships, int op_id);
#endif /* !MY_H_ */
