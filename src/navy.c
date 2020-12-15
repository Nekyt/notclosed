/*
** EPITECH PROJECT, 2020
** navy.c
** File description:
** navy.c
*/
#include "../include/my.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

void print_pos() { my_putstr("my_positions:\n"); }

void print_ennemy_pos() { my_putstr("ennemy's positions:\n"); }

char **check_size(map_t *map) {
  if (map->tab = malloc(sizeof(char) * 11) == NULL)
    return (1);
}

char **display_map(map_t *map) {
  map->tab = malloc(sizeof(char *) * 11);
  for (int i = 0; i < 10;) {
    if ((map->tab[i] = malloc(sizeof(char) * 18)) == NULL)
      return (NULL);
    ++i;
  }
  map->tab[0] = my_putstr(" |A B C D E F G H\n");
  map->tab[1] = my_putstr("-+---------------\n");
  map->tab[2] = my_putstr("1|. . . . . . . .\n");
  map->tab[3] = my_putstr("2|. . . . . . . .\n");
  map->tab[4] = my_putstr("3|. . . . . . . .\n");
  map->tab[5] = my_putstr("4|. . . . . . . .\n");
  map->tab[6] = my_putstr("5|. . . . . . . .\n");
  map->tab[7] = my_putstr("6|. . . . . . . .\n");
  map->tab[8] = my_putstr("7|. . . . . . . .\n");
  map->tab[9] = my_putstr("8|. . . . . . . .\n");
  return (map->tab);
}

void print_dstar(char **to_print)
{
    for(int i = 0 ; to_print[i] != '\0'; i++)
        my_putstr(to_print[i]);
    my_putstr("\n");
}

entry_data_t get_data(int ac, char **av) {
  int offset = 0;
  int loffset = 0;
  int positions = 0;
  entry_data_t data_got;

  data_got.init_pos = malloc(sizeof(char*) * 5);
  if (ac == 3) {
    data_got.pid = my_getnbr(av[1]);
    offset = offset + 1;
  }
  for(int i = 0; i < 5; i++)
    data_got.init_pos[i] = NULL;
  positions = open(av[1 + offset],O_RDONLY);
  if(errno == ENOENT)
      my_putstr("probleme \n");
  while(read(positions, read_data + loffset, 1) > 0)
    loffset++;
    read_data[loffset  - 1] = '\0';
  my_putstr(read_data);
    close(positions);
}

int main(int ac, char **av) {

    get_data(ac,av);
  map_t *map = malloc(sizeof(map_t));
  char **tab;

  if (check_size(tab) == 1) {
    return (NULL);
  }
  display_map(tab);
}