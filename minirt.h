#ifndef STRUCT_PARSE_H
# define STRUCT_PARSE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_cor
{
	float	x;
	float	y;
	float	z;
} t_cor;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
} t_rgb;

typedef struct s_ambien
{
	t_rgb	clr;
	float	ratio;
} t_ambien;

typedef struct s_cam
{
	t_cor	pos;
	t_cor	dir;
	int		fov;
} t_cam;

typedef struct s_light
{
	t_cor	pos;
	t_rgb	clr;
	float	ratio; //brightness
} t_light;

typedef struct s_pl
{
	t_cor	pos;
	t_cor	dir;
	t_rgb	clr;
} t_pl;

typedef struct s_sp
{
	t_cor	pos;
	t_rgb	clr;
	float	dia;
	float	radius;
} t_sp;

typedef struct s_cy
{
	t_cor	pos;
	t_cor	dir;
	t_rgb	clr;
	float	length;
	float	dia;
} t_cy;

// Amount of object
typedef struct s_amt
{
	int	sp;
	int	pl;
	int	cy;
}	t_amt;

typedef struct s_rt
{
	t_ambien	amb;
	t_cam		cam;
	t_light		light;
	t_pl		*pl;
	t_sp		*sp;
	t_cy		*cy;
	t_amt		amt;
	int			fd;
} t_rt;

float	ft_atof(const char *str);
// Create random
void	create_rt(t_rt *rt);
// non shapes
t_cor	set_cor(char *set1, char *set2, char *set3);
t_rgb	set_clr(char **set);
void	set_amb(char **set, t_rt *rt);
void	set_cam(char **set, t_rt *rt);
void	set_light(char **set, t_rt *rt);
// shape(s)
void	count_shape(char **av, t_rt *rt);
void	alloc_shape(t_rt *rt);

#endif