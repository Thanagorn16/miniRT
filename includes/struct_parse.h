// ***************************************************************** //
// ------------------------ Prach Structure ------------------------ //
// ***************************************************************** //

#ifndef STRUCT_PARSE_H
# define STRUCT_PARSE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

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

// m = is a scalar that determines the closest point on the axis to the hit point.
typedef struct s_cy
{
	t_cor	pos;
	t_cor	dir;
	t_cor	top;
	t_cor	bot;
	t_rgb	clr;
	float	length; // height
	float	dia;
	float	radius;
	float	m;
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

int parsing(int ac, char **av, t_rt *rt);

float	ft_atof(const char *str);
char	**split2(char const *s, char c1, char c2);
void	display(t_rt *rt);
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
void	set_sp(char **set, t_rt *rt);
void	set_pl(char **set, t_rt *rt);
void	set_cy(char **set, t_rt *rt);
// utils
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_2dstrlen(char **str);
void	free_2dstr(char **ptr);

#endif