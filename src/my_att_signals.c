/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-navy-nykyta.kudrya [WSL: Ubuntu]
** File description:
** my_att_signals
*/

#include "../include/my.h"
#include "../include/my_signals.h"
#include "../include/maps_manager.h"
#include <stdlib.h>
#include <unistd.h>


void attack_other_pl(coord_t act, player_t *pl)
{
    act.lett = convert_to(act.lett);
    act.nb = convert_to(act.nb);

    for(int i = 0; act.lett[i] != '\0')
}