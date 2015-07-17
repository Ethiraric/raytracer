/*
** raytracer.h for  in /home/sabour_f/github/raytracer/include
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Thu Jul 16 19:07:39 2015 Florian SABOURIN
** Last update Thu Jul 16 19:07:49 2015 Florian SABOURIN
*/

#ifndef RAYTRACER_H_
# define RAYTRACER_H_

# ifdef __cplusplus
extern "C"
{
# endif

typedef struct	s_raytracer t_raytracer;

unsigned int	rt_getpixel(unsigned int x, unsigned int y);
int		rt_parse_file(t_raytracer *rt, const char *filename);

# ifdef __cplusplus
}
# endif

#endif /* !RAYTRACER_H_ */
