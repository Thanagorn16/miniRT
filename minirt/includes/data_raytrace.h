#ifndef DATA_RAYTRACE_H
# define DATA_RAYTRACE_H

# include <stdbool.h>
# include "parsing.h" // Will update from Prach Man

// Image structure
typedef struct s_image
{
	void	*ptr;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;
// Ambient lightning
typedef struct s_ambient
{
	float	ratio;
	int		clr;
}	t_abt;
// Camera
typedef struct s_cmr
{
	t_cor	post;
	t_cor	fpro;
	t_cor	hor;
	t_cor	ver;
}	t_cmr;
// // Light
// typedef struct s_lht
// {
// 	t_cor	point;
// 	float	bright;
// }	t_lht;
// Pixel
typedef struct s_pix
{
	int	x;
	int	y;
	int	clr;
}	t_pix;
// Amount of object
typedef struct s_amt
{
	int	sph;
}	t_amt;
// // Sphere
typedef struct s_sphere
{
	t_cor	post;
	float	diameter;
	float	r;
	t_rgb	clr;
}	t_sph;
// Object
typedef struct s_obj
{
	t_light	light;
	t_sph	*sph;
	t_amt	amt;
	int		ambient;
}	t_obj;
typedef struct s_ray
{
	t_cor	dir; // Ray direction
	t_cor	post; // Camera Position
	t_rgb	clr; // Color object
	t_cor	hitpoint; // Position of hit surface
	t_cor	postobj; // Position object
	float	t_closest; // distance from cam to object
	bool	hit; // if ray hit on any object it will true;
}	t_ray;
// mlx
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
