##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	my_putchar.c	\
		my_putstr.c		\
		my_strlen.c		\
		my_getnbr.c


OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean	all
