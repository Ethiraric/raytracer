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

typedef float t_coor;	// Coordinate type
typedef float t_angle;	// Angle type
typedef t_coor t_radius; // Radius type
typedef t_coor t_dist;	// Distance type
typedef float t_ratio;	// Ratio type
typedef float t_eqtype;	// Equation variable type
typedef unsigned int t_color; // Color type

typedef struct	s_pos
{
  t_coor	x;
  t_coor	y;
  t_coor	z;
}		t_pos;

#define POS_SUBEQ(a, b)	a.x -= b.x; a.y -= b.y; a.z -= b.z;

typedef t_pos t_vec;

typedef struct	s_ray
{
  t_pos		pos;
  t_vec		vec;
}		t_ray;

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

typedef double t_matrix[3][3];

#endif /* !RTTYPES_H */
