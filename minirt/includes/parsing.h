// ***************************************************************** //
// ------------------------ Prach Structure ------------------------ //
// ***************************************************************** //

#ifndef PARSING_H
# define PARSING_H

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
	float   ratio;
	t_rgb	rgb;
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
	float   ratio;
	t_rgb	rgb;
} t_light;

typedef struct s_pl
{
	t_cor	cor;
	t_rgb	rgb;
} t_pl;

typedef struct s_sp
{
	t_cor	cor;
	float	radius;
	t_rgb	rgb;
} t_sp;

typedef struct s_cy
{
	t_cor	cor;
	float	length;
	float	dia;
	t_rgb	rgb;
} t_cy;

typedef struct s_rt
{
	t_ambien	amb;
	t_cam		cam;
	t_light		light;
	t_pl		*pl;
	t_sp		*sp;
	t_cy		*cy;
	int			npl;
	int			nsp;
	int			ncy;
	int			fd;
} t_rt;

// Create random
t_rt	create_rt(void);

#endif
