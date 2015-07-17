/*
** rttypes.h for  in /home/sabour_f/github/raytracer/include
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Fri Jul 17 02:51:40 2015 Florian SABOURIN
** Last update Fri Jul 17 02:51:41 2015 Florian SABOURIN
*/

#ifndef RTTYPES_H
# define RTTYPES_H

typedef float t_coor;
typedef float t_angle;
typedef t_coor t_radius;
typedef t_coor t_dist;

typedef struct	s_pos
{
  t_coor	x;
  t_coor	y;
  t_coor	z;
}		t_pos;

/*
** Rotations :
** - alpha : X axis towards Y axis (around Z axis)
** - beta : Z axis towards X axis (around Y axis)
** - gamma : Y axis towards Z axis (around X axis)
*/
typedef struct	s_rotat
{
  t_angle	alpha;
  t_angle	beta;
  t_angle	gamma;
}		t_rotat;

#endif /* !RTTYPES_H */
