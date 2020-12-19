/*
** EPITECH PROJECT, 2020
** navy [WSL: Ubuntu]
** File description:
** my_signals
*/

#include "my.h"
#ifndef MY_SIGNALS_H_
#define MY_SIGNALS_H_
extern int handle;
void manage_ids(player_t *pl);
int receive_attack(player_t *pl);
int attack_other_pl(coord_t act, player_t *pl);
#endif /* !MY_SIGNALS_H_ */
