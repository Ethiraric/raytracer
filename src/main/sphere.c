/*
** sphere.c for  in /home/sabour_f/github/raytracer/src/main
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Tue Jul 21 00:43:40 2015 Florian SABOURIN
** Last update Tue Jul 21 00:43:40 2015 Florian SABOURIN
*/

#include "raytracer_int.h"

/*
** Returns the distance at which the collisions (if any) are
*/
t_dist		sphere_collision(t_object *obj, t_ray *ray)
{
  t_eqtype	a;
  t_eqtype	b;
  t_eqtype	c;
  t_sphere	*sphere;

  sphere = (t_sphere *)(obj);
  a = SQR(ray->vec.x) + SQR(ray->vec.y) + SQR(ray->vec.z);
  b = ray->vec.x * ray->pos.x + ray->vec.y * ray->pos.y +
      ray->vec.z * ray->pos.z;
  b *= 2;
  c = SQR(ray->pos.x) + SQR(ray->pos.y) + SQR(ray->pos.z) -
      SQR(sphere->radius);
  return (quadratic_dist(a, b, EQ2DELTA));
}

/*
** Fills norm with the normal vector at given intersection
*/
void		sphere_norm(t_object *obj, t_pos *ipos, t_vec *norm)
{
  (void)(obj);
  *norm = *ipos;
}
