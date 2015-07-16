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
#include "raytracer.h"

static void	fill_image(sf::Image &img)
{
  unsigned int	color;

  for (unsigned int i = 0 ; i < img.getSize().x ; ++i)
    for (unsigned int j = 0 ; j < img.getSize().y ; ++j)
      {
	color = rt_getpixel(i, j);
	img.setPixel(i, j, sf::Color((color & 0xFF0000) >> 16,
				     (color & 0xFF00) >> 8,
				     (color & 0xFF)));
      }
}

int		main()
{
  /* Create and fill image */
  sf::RenderWindow	win;
  sf::Image		img;

  win.create(sf::VideoMode(640, 480), "Raytracer");
  img.create(640, 480);
  fill_image(img);

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

  return (0);
}
