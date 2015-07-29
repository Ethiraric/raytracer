/*
** light.h for  in /home/sabour_f/github/raytracer/include
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Mon Jul 27 21:28:19 2015 Florian SABOURIN
** Last update Mon Jul 27 21:28:20 2015 Florian SABOURIN
*/

#ifndef LIGHT_H_
# define LIGHT_H_

# include "rttypes.h"

/*
** The light structure
** Intensity MUST be between 0 and 1
*/
typedef struct	s_light
{
  t_pos		pos;
  t_intens	intensity;
  t_color	color;
  t_subcolor	r;
  t_subcolor	g;
  t_subcolor	b;
}		t_light;

#endif /* !LIGHT_H_ */
