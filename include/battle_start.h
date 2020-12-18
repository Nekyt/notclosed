/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-navy-nykyta.kudrya [WSL: Ubuntu]
** File description:
** battle_start
*/

#ifndef BATTLE_START_H_
#define BATTLE_START_H_
void battle_start(player_t *pl);
int won(int test, player_t *pl);
int analyze_hit(coord_t my_coord, player_t *pl);
int lost(int test, player_t *pl);
#endif /* !BATTLE_START_H_ */
