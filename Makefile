##
## EPITECH PROJECT, 2020
## NAVY
## File description:
## Makefile
##

SRC	=	src/navy.c

CC			=	gcc

CFLAGS		=	 -Wall -Wextra -pedantic --std=c99 -Llib -lmy -Iinclude -g

OBJS		=	$(SRC:.c=.o)
EXEC 		=	navy

all: ${EXEC}

${EXEC}: ${OBJS}
	$(MAKE) -C lib/my
	${CC}  -o ${EXEC} ${OBJS} ${CFLAGS}

clean:
	rm -f ${OBJS}
	make -C lib/my clean

fclean: clean
	rm -f ${EXEC}
	make -C lib/my fclean

re: fclean all
