/*
** main.cpp for  in /home/sabour_f/github/raytracer/src/main
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Thu Jul 16 19:06:09 2015 Florian SABOURIN
** Last update Thu Jul 16 19:06:26 2015 Florian SABOURIN
*/

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "raytracer.h"

static void	fill_image(sf::Image &img, t_raytracer *rt)
{
  unsigned int	color;

  color = 0;
  for (unsigned int i = 0 ; i < img.getSize().x ; ++i)
    for (unsigned int j = 0 ; j < img.getSize().y ; ++j)
      {
	color = rt_getpixel(rt, i, j);
	img.setPixel(i, j, sf::Color((color & 0xFF0000) >> 16,
				     (color & 0xFF00) >> 8,
				     (color & 0xFF)));
      }
  rt_getpixel(rt, 320, 240);
}

int		main(int argc, char **argv)
{
  /* Create and fill image */
  sf::RenderWindow	win;
  t_raytracer		*rt;
  sf::Image		img;

  if (argc != 2)
    {
      fprintf(stderr, "Usage : %s scene_file\n", *argv);
      return (1);
    }

  /* Initialize the raytracer structure */
  rt = rt_new();
  if (!rt)
    {
      perror("rt_new");
      return (1);
    }
  if (rt_parse_file(rt, argv[1]) || rt_init(rt))
    {
      rt_delete(rt);
      return (1);
    }

  win.create(sf::VideoMode(640, 480), "Raytracer");
  img.create(640, 480);
  fill_image(img, rt);

  /* Create texture and sprite*/
  sf::Texture		tx;
  sf::Sprite		sprite;

  tx.loadFromImage(img);
  sprite.setTexture(tx);
  sprite.setPosition(0, 0);
  win.draw(sprite);
  win.display();

  /* Main event loop */
  sf::Event		event;

  while (win.isOpen())
    {
      if (!win.waitEvent(event))
	continue ;
      if (event.type == sf::Event::Closed)
	win.close();
      else if (event.type == sf::Event::KeyReleased &&
	       (event.key.code == sf::Keyboard::Q ||
		event.key.code == sf::Keyboard::Escape))
	win.close();
      win.draw(sprite);
      win.display();
    }

  /* Deallocate resources */
  rt_delete(rt);

  return (0);
}
