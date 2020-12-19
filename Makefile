##
## EPITECH PROJECT, 2020
## NAVY
## File description:
## Makefile
##

SRC	=	src/navy.c	\
	src/maps_manager.c	\
	src/ship_cptns.c	\
	src/my_signals.c	\
	src/battle_start.c	\
	src/my_att_signals.c

CC			=	gcc

CFLAGS		=	 -Wall -Llib -lmy -Iinclude -g

OBJS		=	$(SRC:.c=.o)
EXEC 		=	navy

all: ${EXEC}

${EXEC}: ${OBJS}
	$(MAKE) -C lib
	${CC}  ${CFLAGS}  -o ${EXEC} ${OBJS} -Llib -lmy

clean:
	rm -f ${OBJS}
	make -C lib clean

fclean: clean
	rm -f ${EXEC}
	make -C lib fclean

re: fclean all
