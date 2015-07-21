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
# include "rttypes.h"

/*
** Math-related utilities
*/
# define SQR(a)		((a) * (a))
/* The delta from a quadratic equation */
# define EQ2DELTA	SQR(b) - 4 * a * c

inline t_dist	quadratic_dist(t_eqtype a, t_eqtype b, t_eqtype delta);

/*
** Objlist interface
*/
typedef struct s_objlist t_objlist;

t_objlist	*objlist_new();
void		objlist_delete(t_objlist *objlist);
int		objlist_push_back(t_objlist *objlist, t_object *obj);
t_object	*objlist_at(t_objlist *objlist, unsigned int idx);
size_t		objlist_size(t_objlist *objlist);

/*
** Matrix
*/
void		matrix_rotate_x(t_matrix *m, double alpha);
void		matrix_rotate_y(t_matrix *m, double alpha);
void		matrix_rotate_z(t_matrix *m, double alpha);
void		matrix_set_angles(t_matrix *tab, double alpha,
				  double beta, double gamma);
void		matrix_set_inv_angles(t_matrix *tab, double alpha,
				      double beta, double gamma);
void		matrix_apply(t_matrix *matrix, t_pos *pos);

typedef struct	s_render
{
  size_t	imgw;	// Render image width
  size_t	imgh;	// Render image height
}		t_render;

typedef struct	s_eye
{
  t_pos		pos;	// Position of the eye
  t_rotat	rotat;	// Rotation of the eye
  t_matrix	matrix;	// Rotation matrix of the eye
  t_matrix	matrix_inv; // Inverted rotation matrix of the eye
  t_dist	d;	// Distance to the plan
  t_dist	pw;	// Plan width
  t_dist	ph;	// Plan height
}		t_eye;

typedef struct	s_raytracer
{
  t_eye		eye;
  t_render	render;
  t_objlist	*objlist;
}		t_raytracer;

/*
** Datas necessary to the calculation of intersections
*/
typedef struct	s_calcdat
{
  t_pos		eyepos;	// Position of the eye
  t_vec		eyevec;	// Vector of the ray we launch
  t_dist	objdist; // Distance of the nearest object
  t_object	*obj;	// Nearest object
}		t_calcdat;

#endif /* !RAYTRACER_INT_H_ */
