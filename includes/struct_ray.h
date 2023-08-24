#ifndef STRUCT_RAY_H
# define STRUCT_RAY_H

# include <stdbool.h>
# include "struct_parse.h"

// Image structure
typedef struct s_image
{
	void	*ptr;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_cmr
{
	t_cor	post;
	t_cor	fpro;
	t_cor	hor;
	t_cor	ver;
}	t_cmr;

typedef struct s_formula
{
	float	a;
	float	b;
	float	c;
}	t_fml;

typedef struct s_pixel
{
	int	x;
	int	y;
	int	clr;
}	t_pix;

typedef struct s_object
{
	t_light	light;
	t_sp	*sp;
	t_pl	*pl;
	t_cy	*cy;
	t_amt	amt;
	t_rgb	ambient;
}	t_obj;

typedef struct s_ray
{
	t_cor	dir; // Ray direction
	t_cor	ori; // Camera Position
	t_cor	oc; // Original Center (ori - obj.pos)
}	t_ray;

typedef struct s_hitpayload
{
	t_cor	ctr;
	t_cor	point;
	t_cor	dir;
	float	distance;
	t_rgb	clr;
	bool	hit;
}	t_hpl;

typedef struct s_param
{
	t_image	img;
	void	*mlx;
	void	*win;
	t_cmr	cmr;
	float	h;
	float	w;
}	t_param;

#endif
