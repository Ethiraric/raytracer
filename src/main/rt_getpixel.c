/*
** rt_getpixel.c for  in /home/sabour_f/github/raytracer/src/main
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Thu Jul 16 19:21:17 2015 Florian SABOURIN
** Last update Thu Jul 16 19:21:18 2015 Florian SABOURIN
*/

#include <stdlib.h>
#include <string.h>
#include "raytracer_int.h"

/*
** Sets the "eye", i.e. the pos and vector of the ray we cast
*/
static void	set_eye(t_calcdat *dat, t_raytracer *rt, unsigned int x,
			unsigned int y)
{
  t_ratio	ratiox;
  t_ratio	ratioy;

  /* We consider our eye is not rotated and loks towards positive Z
   * The distance to the plan is d, its width pw and its height ph
   * We search the point on the plan we will cast the ray to
   * We compute the ratio between the coordinate and the width/height, and
   * substract 0.5 because the center of the plan is the center of the
   * screen
   * Note that since the screen coordinates' Y axis goes down, we must multiply
   * the ratio by -1
   * We then apply rotation to the vector */
  ratiox = (t_ratio)(x) / (t_ratio)(rt->render.imgw) - (t_ratio)0.5;
  ratioy = -((t_ratio)(y) / (t_ratio)(rt->render.imgh) - (t_ratio)0.5);
  dat->eyevec.x = ratiox * rt->eye.pw;
  dat->eyevec.y = ratioy * rt->eye.ph;
  dat->eyevec.z = rt->eye.d;
  matrix_apply(&rt->eye.matrix, &dat->eyevec);
  dat->eyepos = rt->eye.pos;
}

/*
** Sets the ray correctly to be thrown to the object
*/
static void	do_collision(t_calcdat *dat, t_object *obj)
{
  t_dist	dist;
  t_ray		ray;

  /* Make the object the new origin */
  ray.pos = dat->eyepos;
  POS_SUBEQ(ray.pos, obj->pos);

  /* Rotate the object correctly */
  matrix_apply(&obj->matrix_inv, &ray.pos);
  ray.vec = dat->eyevec;
  matrix_apply(&obj->matrix_inv, &ray.vec);
  dist = obj->collision(obj, &ray);
  if ((dist > (t_dist)(0)) &&
      (!dat->obj || dist < dat->objdist))
    {
      dat->obj = obj;
      dat->objdist = dist;
      dat->objray = ray;
    }
}

/*
** Sets the obj and objdist fields of the dat stucture
*/
static void	get_collision(t_calcdat *dat, t_raytracer *rt)
{
  unsigned int	max;
  unsigned int	i;
  t_object	*obj;

  max = objlist_size(rt->objlist);
  dat->objdist = -1;
  for (i = 0 ; i < max ; ++i)
    {
      obj = objlist_at(rt->objlist, i);
      do_collision(dat, obj);
    }
}

/*
** Gets the color of the pixel at given coordinates
*/
unsigned int	rt_getpixel(t_raytracer *rt, unsigned int x, unsigned int y)
{
  t_calcdat	dat;

  if (!lightlist_size(rt->lightlist))
    return (0);
  memset(&dat, 0, sizeof(t_calcdat));
  set_eye(&dat, rt, x, y);
  get_collision(&dat, rt);
  if (dat.obj)
    {
      apply_lights(rt->lightlist, &dat);
      return (dat.pixelcolor);
    }
  return (0);
}
