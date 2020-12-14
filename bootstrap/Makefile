##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	my_put_nbr.c	\
		my_putchar.c	\
		my_putstr.c		\
		process_info.c

OBJ	=	$(SRC:.c=.o)

NAME    =	process_info

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -g -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f$(NAME)

re:	flcean all
