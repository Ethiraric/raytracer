/*
** objlist.c for  in /home/sabour_f/github/raytracer/src/main
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Fri Jul 17 03:02:44 2015 Florian SABOURIN
** Last update Fri Jul 17 03:02:44 2015 Florian SABOURIN
*/

#include <stdlib.h>
#include <string.h>
#include "objlist.h"

/*
** Reallocate the objects field so it can contain at least size elements
*/
static int	objlist_realloc(t_objlist *objlist, size_t size)
{
  t_object	**tmp;

  tmp = realloc(objlist->objects, size * sizeof(t_object *));
  if (!tmp)
    return (1);
  objlist->objects = tmp;
  objlist->allocd = size;
  return (0);
}

/*
** Create a new objlist
*/
t_objlist	*objlist_new()
{
  t_objlist	*ret;

  ret = malloc(sizeof(t_objlist));
  if (ret)
    memset(ret, 0, sizeof(t_objlist));
  return (ret);
}

/*
** Delete a previously newed objlist
** Objects contained in the objlist will be freed
*/
void		objlist_delete(t_objlist *objlist)
{
  unsigned int	i;

  if (objlist->objects)
    {
      for (i = 0 ; i < objlist->size ; ++i)
	free(objlist->objects[i]);
      free(objlist->objects);
    }
  free(objlist);
}

/*
** Add a previously mallocd object to the objlist
*/
int		objlist_push_back(t_objlist *objlist, t_object *obj)
{
  if (objlist->size >= objlist->allocd)
    if (objlist_realloc(objlist, objlist->size + 10))
      return (1);
  objlist->objects[objlist->size] = obj;
  ++objlist->size;
  return (0);
}

/*
** Returns the idx-th element in the objlist
** Does not check if idx is out-of-range
*/
t_object	*objlist_at(t_objlist *objlist, unsigned int idx)
{
  return (objlist->objects[idx]);
}

/*
** Returns the number of objects contained in the objlist
*/
size_t		objlist_size(t_objlist *objlist)
{
  return (objlist->size);
}
