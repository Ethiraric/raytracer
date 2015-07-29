/*
** apply_lights.c for  in /home/sabour_f/github/raytracer/src/main
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Tue Jul 28 17:29:49 2015 Florian SABOURIN
** Last update Tue Jul 28 17:29:49 2015 Florian SABOURIN
*/

#include <stdbool.h>
#include <math.h>
#include "raytracer_int.h"

/*
** Checks if there is an object between the light and the object
** Returns true if there is, false otherwise
*/
static bool	light_is_obstructed(t_light *light, t_pos *ipos)
{
  // TODO
  return (false);
}

/*
** Calculate the cosine between the incoming ray and the normal of the object
** at the intersection
** This will be a multiplying factor for the light colors
*/
static void	apply_cos(t_calcdat *dat, t_light *light, t_pos *ipos,
			  t_rgbcolor *rgb)
{
  t_ratio	cosval;
  t_ratio	dot;
  /* Norm of the vectors */
  t_dist	v1dst;
  t_dist	v2dst;
  /* Vector from the intersection to the light */
  t_vec		lighttoi;
  t_vec		normal;
  /* Position of the intersection, rotated and translated for the object */
  t_pos		objipos;

  lighttoi.x = light->pos.x - ipos->x;
  lighttoi.y = light->pos.y - ipos->y;
  lighttoi.z = light->pos.z - ipos->z;
  objipos.x = dat->objray.pos.x + dat->objray.vec.x * dat->objdist;
  objipos.y = dat->objray.pos.y + dat->objray.vec.y * dat->objdist;
  objipos.z = dat->objray.pos.z + dat->objray.vec.z * dat->objdist;
  dat->obj->normal(dat->obj, &objipos, &normal);
  dot = lighttoi.x * normal.x + lighttoi.y * normal.y + lighttoi.z * normal.z;
  v1dst = sqrt(SQR(lighttoi.x) + SQR(lighttoi.y) + SQR(lighttoi.z));
  v2dst = sqrt(SQR(normal.x) + SQR(normal.y) + SQR(normal.z));
  cosval = dot / (v1dst * v2dst);
  rgb->r = light->r * cosval;
  rgb->g = light->g * cosval;
  rgb->b = light->b * cosval;
}

/*
** Apply the light
*/
void		apply_lights(t_lightlist *lightlist, t_calcdat *dat)
{
  unsigned int	i;
  unsigned int	max;
  t_colorcalc	r;
  t_colorcalc	g;
  t_colorcalc	b;
  t_rgbcolor	lightcolor;
  t_light	*light;
  t_pos		ipos;

  r = 0;
  g = 0;
  b = 0;
  ipos.x = dat->eyepos.x + dat->eyevec.x * dat->objdist;
  ipos.y = dat->eyepos.y + dat->eyevec.y * dat->objdist;
  ipos.z = dat->eyepos.z + dat->eyevec.z * dat->objdist;
  max = lightlist_size(lightlist);
  for (i = 0 ; i < max ; ++i)
    {
      light = lightlist_at(lightlist, i);
      if (!light_is_obstructed(light, &ipos))
	{
	  apply_cos(dat, light, &dat->objray.vec, &lightcolor);
	  r += lightcolor.r;
	  g += lightcolor.g;
	  b += lightcolor.b;
	}
    }
  r = (r * dat->obj->r) / (max * SUBCOLOR_MAX);
  g = (g * dat->obj->g) / (max * SUBCOLOR_MAX);
  b = (b * dat->obj->b) / (max * SUBCOLOR_MAX);
  dat->pixelcolor = (r << 16) | (g << 8) | b;
}
