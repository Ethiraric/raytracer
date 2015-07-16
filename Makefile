##
## Makefile for  in /home/sabour_f/github/raytracer
##
## Made by Florian SABOURIN
## Login   <sabour_f@epitech.net>
##
## Started on  Thu Jul 16 19:03:44 2015 Florian SABOURIN
## Last update Thu Jul 16 19:05:55 2015 Florian SABOURIN
##

MAKE		+=	--no-print-directory

all:	raytracer

raytracer:
	@$(MAKE) -C src/main

clean:
	@$(MAKE) -C src/main clean


fclean:
	@$(MAKE) -C src/main fclean

re:	fclean all

.PHONY: all clean fclean re raytracer
