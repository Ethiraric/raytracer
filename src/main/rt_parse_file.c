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
** Fetches the next token, and prints and error message if it is null
*/
#define CHECK_TOKEN(a, b, ...)	a = strtok(NULL, " \n\t"); \
  if (!a) { fprintf(stderr, b, __VA_ARGS__); return (1); }

/*
** Special one for light, need to free the light
*/
#define CHECK_TOKEN_LIGHT(a, b, ...)	a = strtok(NULL, " \n\t"); \
  if (!a) { fprintf(stderr, b, __VA_ARGS__); free(light); return (1); }

/*
** char * -> t_color conversion
** Basically it's hexadecimal string to t_color
*/
static t_color	get_color(char *token)
{
  t_color	res;

  res = 0;
  while (*token)
    {
      res <<= 4;
      if (*token <= 'F' && *token > 'A')
	res += (t_color)(*token - 'A') + 10;
      else if (*token <= '9' && *token >= '0')
	res += (t_color)(*token - '0');
      else
	return (res);
      ++token;
    }
  return (res);
}

/*
** Parses sphere-specific arguments
*/
static int	parse_sphere(t_object *object, unsigned int lineno)
{
  t_sphere	*sphere;
  char		*token;

  sphere = (t_sphere *)(object);
  CHECK_TOKEN(token, "%u: missing sphere-radius\n", lineno);
  sphere->radius = atof(token);
  sphere->collision = &sphere_collision;
  sphere->normal = &sphere_norm;
  return (0);
}

/*
** Parses the base of an object (pos, rotation, ...)
*/
static int	parse_object(t_object *object,
			     int (*fct)(t_object *, unsigned int),
			     unsigned int lineno)
{
  char		*token;

  CHECK_TOKEN(token, "%u: missing pos-x\n", lineno);
  object->pos.x = atof(token);
  CHECK_TOKEN(token, "%u: missing pos-y\n", lineno);
  object->pos.y = atof(token);
  CHECK_TOKEN(token, "%u: missing pos-z\n", lineno);
  object->pos.z = atof(token);
  CHECK_TOKEN(token, "%u: missing alpha angle\n", lineno);
  object->rotat.alpha = atof(token);
  CHECK_TOKEN(token, "%u: missing beta angle\n", lineno);
  object->rotat.beta = atof(token);
  CHECK_TOKEN(token, "%u: missing gamma angle\n", lineno);
  object->rotat.gamma = atof(token);
  CHECK_TOKEN(token, "%u: missing color\n", lineno);
  object->color = get_color(token);
  return (fct(object, lineno));
}

/*
** Parses informations about the eye (i.e. the camera)
*/
static int	parse_eye(t_raytracer *rt, unsigned int lineno)
{
  char		*token;

  CHECK_TOKEN(token, "%u: missing eye pos-x\n", lineno);
  rt->eye.pos.x = atof(token);
  CHECK_TOKEN(token, "%u: missing eye pos-y\n", lineno);
  rt->eye.pos.y = atof(token);
  CHECK_TOKEN(token, "%u: missing eye pos-z\n", lineno);
  rt->eye.pos.z = atof(token);
  CHECK_TOKEN(token, "%u: missing eye alpha angle\n", lineno);
  rt->eye.rotat.alpha = atof(token);
  CHECK_TOKEN(token, "%u: missing eye beta angle\n", lineno);
  rt->eye.rotat.beta = atof(token);
  CHECK_TOKEN(token, "%u: missing eye gamma angle\n", lineno);
  rt->eye.rotat.gamma = atof(token);
  CHECK_TOKEN(token, "%u: missing eye plan distance\n", lineno);
  rt->eye.d = atof(token);
  CHECK_TOKEN(token, "%u: missing eye plan width\n", lineno);
  rt->eye.pw = atof(token);
  CHECK_TOKEN(token, "%u: missing eye plan height\n", lineno);
  rt->eye.ph = atof(token);
  return (0);
}

/*
** Parses informations about the render
*/
static int	parse_render(t_raytracer *rt, unsigned int lineno)
{
  char		*token;

  CHECK_TOKEN(token, "%u: missing render image width\n", lineno);
  rt->render.imgw = (unsigned int)(atoi(token));
  CHECK_TOKEN(token, "%u: missing render image height\n", lineno);
  rt->render.imgh = (unsigned int)(atoi(token));
  return (0);
}

static int	parse_light(t_raytracer *rt, unsigned int lineno)
{
  t_light	*light;
  char		*token;

  light = malloc(sizeof(t_light));
  if (!light)
    {
      perror("malloc");
      return (1);
    }
  CHECK_TOKEN_LIGHT(token, "%u: missing light pos-x\n", lineno);
  light->pos.x = (t_coor)(atoi(token));
  CHECK_TOKEN_LIGHT(token, "%u: missing light pos-y\n", lineno);
  light->pos.y = (t_coor)(atoi(token));
  CHECK_TOKEN_LIGHT(token, "%u: missing light pos-z\n", lineno);
  light->pos.z = (t_coor)(atoi(token));
  CHECK_TOKEN_LIGHT(token, "%u: missing light intensity\n", lineno);
  light->intensity = (t_intens)(atof(token));
  if (light->intensity > (t_intens)(1) || light->intensity < (t_intens)(0))
    {
      fprintf(stderr, "%u: Invalid light intensity\n", lineno);
      return (1);
    }
  CHECK_TOKEN_LIGHT(token, "%u: missing color\n", lineno);
  light->color = get_color(token);
  if (lightlist_push_back(rt->lightlist, light))
    {
      free(light);
      perror("lightlist_push_back");
      return (1);
    }
  return (0);
}

/*
** Returns a zero-initialized object from its name
*/
static t_object	*get_object(const char *name, unsigned int lineno)
{
  /* Contains all object names, their sizes and a parsing function that will
   * fill the object's specific fields */
  static const struct { const char *name; size_t size;
			int (*fct)(t_object *, unsigned int); } matches[] =
  {
    { "sphere", sizeof(t_sphere), &parse_sphere },
    { NULL, 0, NULL }
  };
  unsigned int	i;
  t_object	*obj;

  /* Iterate over all names, allocate and return if names match */
  for (i = 0 ; matches[i].name ; ++i)
    if (!strcasecmp(matches[i].name, name))
      {
	obj = malloc(matches[i].size);
	if (obj)
	  {
	    memset(obj, 0, matches[i].size);
	    if (parse_object(obj, matches[i].fct, lineno))
	      {
		free(obj);
		return (NULL);
	      }
	  }
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
  token = strtok(line, " \n\t");
  if (!token || token[0] == '#')
    return (0);
  if (!strcasecmp(token, "eye"))
    return (parse_eye(rt, lineno));
  if (!strcasecmp(token, "render"))
    return (parse_render(rt, lineno));
  if (!strcasecmp(token, "light"))
    return (parse_light(rt, lineno));
  obj = get_object(token, lineno);
  if (!obj)
    return (1);
  if (objlist_push_back(rt->objlist, obj))
    {
      free(obj);
      perror("objlist_push_back");
      return (1);
    }
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
    {
      perror("fopen");
      return (1);
    }
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
  free(line);
  fclose(file);
  return (0);
}
