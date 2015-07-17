/*
** raytracer_int.h for  in /home/sabour_f/github/raytracer/src/main
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Fri Jul 17 02:45:00 2015 Florian SABOURIN
** Last update Fri Jul 17 02:45:00 2015 Florian SABOURIN
*/

#ifndef RAYTRACER_INT_H_
# define RAYTRACER_INT_H_

# include <sys/types.h>
# include "objects.h"

typedef struct s_objlist t_objlist;

t_objlist	*objlist_new();
void		objlist_delete(t_objlist *objlist);
int		objlist_push_back(t_objlist *objlist, t_object *obj);
t_object	*objlist_at(t_objlist *objlist, unsigned int idx);
size_t		objlist_size(t_objlist *objlist);

typedef struct	s_raytracer
{
  t_objlist	*objlist;
}		t_raytracer;

#endif /* !RAYTRACER_INT_H_ */
