##
## Makefile for  in /home/sabour_f/github/raytracer
##
## Made by Florian SABOURIN
## Login   <sabour_f@epitech.net>
##
## Started on  Thu Jul 16 19:03:44 2015 Florian SABOURIN
## Last update Thu Jul 16 19:05:55 2015 Florian SABOURIN
##

NAME		=	../../raytracer
CC		=	gcc
CXX		=	g++
RM		=	@rm -vf
MAKE		+=	--no-print-directory

SRCXX		=	main.cpp
SRC		=	rt_getpixel.c
SRC		+=	objlist.c
SRC		+=	rt_parse_file.c
SRC		+=	rt.c

OBJ		=	$(SRC:.c=.o) $(SRCXX:.cpp=.o)

CFLAGS		=	-W -Wall -Wshadow -D_GNU_SOURCE -I../../include -fno-diagnostics-show-caret -fms-extensions
CXXFLAGS	=	-W -Wall -Wshadow -D_GNU_SOURCE -I../../include -fno-diagnostics-show-caret -fms-extensions
LDFLAGS		=	-lsfml-window -lsfml-graphics -lsfml-system

%.o:	%.c
	$(CC) -c $(CFLAGS)            -o $@ $^

%.o:	%.cpp
	$(CXX) -c $(CXXFLAGS)            -o $@ $^

$(NAME):	$(OBJ)
	$(CXX) $(OBJ) -o $(NAME) $(LDFLAGS)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
