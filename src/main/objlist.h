/*
** objlist.h for  in /home/sabour_f/github/raytracer/src/main
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Fri Jul 17 03:09:45 2015 Florian SABOURIN
** Last update Fri Jul 17 03:09:46 2015 Florian SABOURIN
*/

#ifndef OBJLIST_H_
# define OBJLIST_H_

# include <sys/types.h>
# include "objects.h"
# include "light.h"

typedef struct	s_objlist
{
  t_object	**objects;
  size_t	size;
  size_t	allocd;
}		t_objlist;

typedef struct	s_lightlist
{
  t_light	**lights;
  size_t	size;
  size_t	allocd;
}		t_lightlist;

# include "raytracer_int.h"

#endif /* !OBJLIST_H_ */
