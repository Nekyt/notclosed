/*
** EPITECH PROJECT, 2020
** navy.c
** File description:
** navy.c
*/
#include "../include/my.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void print_dstar(char **to_print) {
  for (int i = 0; to_print[i] != NULL; i++) {
    my_putstr(to_print[i]);
  }
  my_putstr("\n");
}

char **init_empty_map() {
    char **empty_map = malloc(sizeof(char*) * 11);
    
  (" |A B C D E F G H\n");
  ("-+---------------\n");
  ("1|. . . . . . . .\n");
  ("2|. . . . . . . .\n");
  ("3|. . . . . . . .\n");
  ("4|. . . . . . . .\n");
  ("5|. . . . . . . .\n");
  ("6|. . . . . . . .\n");
  ("7|. . . . . . . .\n");
  ("8|. . . . . . . .\n");
}

char **init_player_map(char **p_data) {}

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
  for (; getline(&data_got.init_pos[k], &at_v, positions) > 0; k++)
    ;
  data_got.init_pos[k] = NULL;
  fclose(positions);
  return (data_got);
}

int main(int ac, char **av) {
  entry_data_t data_got = get_data(ac, av);
  my_putstr("data read:\n pid:");
  my_put_nbr(data_got.pid);
  my_putchar('\n');
  print_dstar(data_got.init_pos);
}