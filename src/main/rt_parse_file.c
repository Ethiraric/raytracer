/*
** rt_parse_file.c for  in /home/sabour_f/github/raytracer/src/main
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Fri Jul 17 03:02:06 2015 Florian SABOURIN
** Last update Fri Jul 17 03:02:07 2015 Florian SABOURIN
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "raytracer_int.h"

/*
** Returns a zero-initialized object from its name
*/
static t_object	*get_object(const char *name, unsigned int lineno)
{
  /* Contains all object names and their sizes */
  static const struct { const char *name; size_t size; } matches[] =
  {
    { "sphere", sizeof(t_sphere) },
    { NULL, 0 }
  };
  unsigned int	i;
  t_object	*obj;

  /* Iterate over all names, allocate and return if names match */
  for (i = 0 ; matches[i].name ; ++i)
    if (!strcasecmp(matches[i].name, name))
      {
	obj = malloc(matches[i].size);
	if (obj)
	  memset(obj, 0, matches[i].size);
	else
	  perror("malloc");
	return (obj);
      }
  fprintf(stderr, "%u: Unknown object: %s\n", lineno, name);
  return (NULL);
}

/*
** Parses a single line (i.e. object) of the file
*/
static int	parse_line(t_raytracer *rt, char *line, unsigned int lineno)
{
  t_object	*obj;
  char		*token;

  /* Check first token, should be the name of the object */
  token = strtok(line, " ");
  if (!token || token[0] == '#')
    return (0);
  obj = get_object(token, lineno);
  if (!obj)
    return (1);
  if (objlist_push_back(rt->objlist, obj))
    {
      free(obj);
      perror("objlist_push_back");
      return (1);
    }
  /* Here should be the arguments (position, rotation...) */
  return (0);
}

/*
** Adds objects from the file to the scene of the raytracer
** Upon error in the middle of the file, the scene is partially loaded
** This may result in unexpected results
*/
int		rt_parse_file(t_raytracer *rt, const char *filename)
{
  unsigned int	lineno;
  size_t	size;
  FILE		*file;
  char		*line;

  file = fopen(filename, "r");
  if (!file)
    return (1);
  size = 0;
  line = NULL;
  lineno = 1;

  /* Parse file line by line. lineno enables more precise error messages */
  while (getline(&line, &size, file) != -1)
    {
      if (parse_line(rt, line, lineno))
	{
	  free(line);
	  fclose(file);
	  return (1);
	}
      ++lineno;
    }
  fclose(file);
  return (0);
}
