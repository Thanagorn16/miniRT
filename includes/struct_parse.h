// ***************************************************************** //
// ------------------------ Prach Structure ------------------------ //
// ***************************************************************** //

#ifndef STRUCT_PARSE_H
# define STRUCT_PARSE_H

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
	float	ratio;
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

// Create random
void	create_rt(t_rt *rt);

#endif
