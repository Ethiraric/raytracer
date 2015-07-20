/*
** rotations.c for  in /home/sabour_f/github/raytracer/src/main
**
** Made by Florian SABOURIN
** Login   <sabour_f@epitech.net>
**
** Started on  Mon Jul 20 16:56:12 2015 Florian SABOURIN
** Last update Mon Jul 20 16:56:13 2015 Florian SABOURIN
*/

#include <math.h>
#include "raytracer_int.h"
#include "string.h"

static const t_matrix	matrix_identity =
{
  { 1.0f, 0.0f, 0.0f },
  { 0.0f, 1.0f, 0.0f },
  { 0.0f, 0.0f, 1.0f },
};

void		matrix_rotate_x(t_matrix *m, double alpha)
{
  double	vars[5];

  vars[0] = sin((alpha / 180.0f) * M_PI);
  vars[1] = cos((alpha / 180.0f) * M_PI);
  vars[2] = (*m)[0][1];
  vars[3] = (*m)[1][1];
  vars[4] = (*m)[2][1];
  (*m)[0][1] = (*m)[0][1] * vars[1] - (*m)[0][2] * vars[0];
  (*m)[1][1] = (*m)[1][1] * vars[1] - (*m)[1][2] * vars[0];
  (*m)[2][1] = (*m)[2][1] * vars[1] - (*m)[2][2] * vars[0];
  (*m)[0][2] = vars[2] * vars[0] + (*m)[0][2] * vars[1];
  (*m)[1][2] = vars[3] * vars[0] + (*m)[1][2] * vars[1];
  (*m)[2][2] = vars[4] * vars[0] + (*m)[2][2] * vars[1];
}

void		matrix_rotate_y(t_matrix *m, double alpha)
{
  double	vars[5];

  vars[0] = sin((alpha / 180.0f) * M_PI);
  vars[1] = cos((alpha / 180.0f) * M_PI);
  vars[2] = (*m)[0][0];
  vars[3] = (*m)[1][0];
  vars[4] = (*m)[2][0];
  (*m)[0][0] = (*m)[0][0] * vars[1] + (*m)[0][2] * vars[0];
  (*m)[1][0] = (*m)[1][0] * vars[1] + (*m)[1][2] * vars[0];
  (*m)[2][0] = (*m)[2][0] * vars[1] + (*m)[2][2] * vars[0];
  (*m)[0][2] = -vars[2] * vars[0] + (*m)[0][2] * vars[1];
  (*m)[1][2] = -vars[3] * vars[0] + (*m)[1][2] * vars[1];
  (*m)[2][2] = -vars[4] * vars[0] + (*m)[2][2] * vars[1];
}

void		matrix_rotate_z(t_matrix *m, double alpha)
{
  double	vars[5];

  vars[0] = sin((alpha / 180.0f) * M_PI);
  vars[1] = cos((alpha / 180.0f) * M_PI);
  vars[2] = (*m)[0][0];
  vars[3] = (*m)[1][0];
  vars[4] = (*m)[2][0];
  (*m)[0][0] = (*m)[0][0] * vars[1] - (*m)[0][1] * vars[0];
  (*m)[1][0] = (*m)[1][0] * vars[1] - (*m)[1][1] * vars[0];
  (*m)[2][0] = (*m)[2][0] * vars[1] - (*m)[2][1] * vars[0];
  (*m)[0][1] = vars[2] * vars[0] + (*m)[0][1] * vars[1];
  (*m)[1][1] = vars[3] * vars[0] + (*m)[1][1] * vars[1];
  (*m)[2][1] = vars[4] * vars[0] + (*m)[2][1] * vars[1];
}

void		matrix_set_angles(t_matrix *tab, double alpha,
				  double beta, double gamma)
{
  memcpy(tab, &matrix_identity, sizeof(t_matrix));
  matrix_rotate_x(tab, beta);
  matrix_rotate_y(tab, gamma);
  matrix_rotate_z(tab, alpha);
}

void		matrix_set_inv_angles(t_matrix *tab, double alpha,
				      double beta, double gamma)
{
  memcpy(tab, &matrix_identity, sizeof(t_matrix));
  matrix_rotate_z(tab, alpha);
  matrix_rotate_y(tab, gamma);
  matrix_rotate_x(tab, beta);
}

void		matrix_apply(t_matrix *matrix, t_pos *pos)
{
  double	tmpx;
  double	tmpy;

  tmpx = ((*matrix)[0][0] * pos->x +
      (*matrix)[1][0] * pos->y +
      (*matrix)[2][0] * pos->z);
  tmpy = ((*matrix)[0][1] * pos->x +
      (*matrix)[1][1] * pos->y +
      (*matrix)[2][1] * pos->z);
  pos->z = ((*matrix)[0][2] * pos->x +
      (*matrix)[1][2] * pos->y +
      (*matrix)[2][2] * pos->z);
  pos->x = tmpx;
  pos->y = tmpy;
}
