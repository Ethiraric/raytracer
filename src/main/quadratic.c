/*
** quadratic.c for  in /home/sabour_f/github/raytracer/src/main
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Tue Jul 21 21:35:18 2015 Florian SABOURIN
** Last update Tue Jul 21 21:35:18 2015 Florian SABOURIN
*/

#include <math.h>
#include "rttypes.h"

/*
** Returns the lowest positive root of a quadratic equation
** If there is no, return a negative number
*/
inline t_dist	quadratic_dist(t_eqtype a, t_eqtype b, t_eqtype delta)
{
  if (delta < 0)
    return (-1);

  t_eqtype	sqroot;
  t_eqtype	res;

  sqroot = sqrt(delta);
  res = (-b - sqroot) / ((t_eqtype)(2) * a);
  if (res < 0)
    return (res + sqroot / a);
  return (res);
}
