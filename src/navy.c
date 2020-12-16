/*
** EPITECH PROJECT, 2020
** navy.c
** File description:
** navy.c
*/
#include "../include/my.h"
#include "../include/maps_manager.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>   
#include <unistd.h>

void print_dstar(char **to_print) {
  for (int i = 0; to_print[i] != NULL; i++) {
    my_putstr(to_print[i]);
  }
  my_putstr("\n");
}
void print_player(player_t *pl)
{
    my_putstr("created player max ");
    my_put_nbr(pl->score_max);
    my_putstr("\nscore actual:\n");
    my_put_nbr(pl->score);
    my_putstr("\nour map\n");
    print_dstar(pl->own);
    my_putstr("theirs \n");
    print_dstar(pl->theirs);
}


entry_data_t get_data(int ac, char **av) {
  int offset = 0;
  long unsigned int at_v;
  FILE *positions;
  entry_data_t data_got;
  int k = 0;

  data_got.pid = 0;
  data_got.init_pos = malloc(sizeof(char *) * 5);
  for (int i = 0; i < 5; i++)
    data_got.init_pos[i] = NULL;
  if (ac == 3) {
    data_got.pid = my_getnbr(av[1]);
    offset = offset + 1;
  }
  positions = fopen(av[1 + offset], "r");
  for (; getline(&data_got.init_pos[k], &at_v, positions) > 0; k++);
  data_got.init_pos[k] = NULL;
  fclose(positions);
  return (data_got);
}



player_t *init_player(entry_data_t my_data, ship_t **ships)
{
    player_t *our = malloc(sizeof(player_t));
    int score_max = 0;
    our->own = my_data.init_pos;
    our->theirs = init_empty_map();
    our->score = 0;
    for(int i = 0;ships[i] != NULL; i++)
        score_max += ships[i]->length;
    our->score_max = score_max;
    our->own_pid = getpid();
    if (my_data.pid == 0)
    
    return(our);
}

int main(int ac, char **av) {
  entry_data_t data_got;
  ship_t **ships = NULL;
  player_t *pl = NULL;
  char **map;

  data_got = get_data(ac,av);
  ships = ship_analyzer(data_got.init_pos, 0, NULL);
  map = init_player_map(data_got.init_pos,ships);
  pl = init_player(map, ships);
  print_player(pl);

}