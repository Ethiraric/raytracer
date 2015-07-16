##
## Makefile for  in /home/sabour_f/github/raytracer
## 
## Made by Florian SABOURIN
## Login   <sabour_f@epitech.net>
## 
## Started on  Thu Jul 16 19:03:44 2015 Florian SABOURIN
## Last update Thu Jul 16 19:05:55 2015 Florian SABOURIN
##

NAME		=	raytracer
CC		=	gcc
RM		=	@rm -vf
MAKE		+=	--no-print-directory

SRC		=	src/main/main.c

OBJ		=	$(SRC:.c=.o)

CFLAGS = -W -Wall -Wshadow -D_GNU_SOURCE -I -fno-diagnostics-show-caret

%.o:	%.c
	$(CC) -c $(CFLAGS)            -o $@ $^

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
