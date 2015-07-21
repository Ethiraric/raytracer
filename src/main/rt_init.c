/*
** rt_init.c for  in /home/sabour_f/github/raytracer/src/main
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Mon Jul 20 23:52:06 2015 Florian SABOURIN
** Last update Mon Jul 20 23:52:07 2015 Florian SABOURIN
*/

#include "raytracer_int.h"

/*
** Initializes fields in the raytracer structure
** Must be called after parsing and before get pixel
*/
int		rt_init(t_raytracer *rt)
{
  unsigned int	i;
  t_object	*obj;

  /* Set matrix and matrix_inv fields of each objects */
  for (i = 0 ; i < objlist_size(rt->objlist) ; ++i)
    {
      obj = objlist_at(rt->objlist, i);
      matrix_set_angles(&obj->matrix, obj->rotat.alpha, obj->rotat.beta,
			obj->rotat.gamma);
      matrix_set_inv_angles(&obj->matrix_inv, obj->rotat.alpha,
			    obj->rotat.beta, obj->rotat.gamma);
    }

  /* Set matrix and matrix_inv fields of the eye */
  matrix_set_angles(&rt->eye.matrix, rt->eye.rotat.alpha, rt->eye.rotat.beta,
		    rt->eye.rotat.gamma);
  matrix_set_inv_angles(&rt->eye.matrix_inv, rt->eye.rotat.alpha,
			rt->eye.rotat.beta, rt->eye.rotat.gamma);
  return (0);
}
