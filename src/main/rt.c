/*
** rt.c for  in /home/sabour_f/github/raytracer/src/main
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Fri Jul 17 12:39:18 2015 Florian SABOURIN
** Last update Fri Jul 17 12:39:19 2015 Florian SABOURIN
*/

#include <stdlib.h>
#include <string.h>
#include "raytracer_int.h"

/*
** Create a new raytracer
*/
t_raytracer	*rt_new()
{
  t_raytracer	*ret;

  ret = malloc(sizeof(t_raytracer));
  if (ret)
    {
      memset(ret, 0, sizeof(t_raytracer));
      ret->objlist = objlist_new();
      if (!ret->objlist)
	{
	  rt_delete(ret);
	  return (NULL);
	}
      ret->lightlist = lightlist_new();
      if (!ret->lightlist)
	{
	  rt_delete(ret);
	  return (NULL);
	}
    }
  return (ret);
}

/*
** Delete a previously newed raytracer
*/
void		rt_delete(t_raytracer *rt)
{
  if (rt->objlist)
    objlist_delete(rt->objlist);
  if (rt->lightlist)
    lightlist_delete(rt->lightlist);
  free(rt);
}
