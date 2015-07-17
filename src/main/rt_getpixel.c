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
#include "raytracer.h"

unsigned int	rt_getpixel(unsigned int x, unsigned int y)
{
  (void)(x);
  (void)(y);
  return (rand());
}
