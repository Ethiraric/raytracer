/*
** objects.h for  in /home/sabour_f/github/raytracer/include
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Fri Jul 17 02:51:32 2015 Florian SABOURIN
** Last update Fri Jul 17 02:51:32 2015 Florian SABOURIN
*/

#ifndef OBJECTS_H_
# define OBJECTS_H_

# include "rttypes.h"

typedef struct	s_object
{
  t_rotat	rotat;
  t_pos		pos;
}		t_object;

typedef struct	s_sphere
{
  t_object;
  t_radius	radius;
}		t_sphere;

#endif /* !OBJECTS_H_ */
