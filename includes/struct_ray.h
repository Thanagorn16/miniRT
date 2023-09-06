/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_ray.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:50:05 by tnantaki          #+#    #+#             */
/*   Updated: 2023/08/31 13:50:06 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_RAY_H
# define STRUCT_RAY_H

# include <stdbool.h>
# include "struct_parse.h"

typedef enum e_cmr_move
{
	DOLLY,
	TRUCK,
	PEDESTAL,
}	t_cmr_move;

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
	t_cor	move[3];
	t_axis	axis;
	t_cor	post;
	t_cor	fpro; //first projection
	t_cor	hor;
	t_cor	ver;
	float	vp_width;
	float	vp_height;
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
	t_rgb	clr;
	float	distance;
	bool	hit;
}	t_hpl;

typedef struct s_selete
{
	t_axis	*axis;
	t_cor	*pos;
	t_cor	*dir;
	bool	obj[5];
	int		index;
}	t_slt;

typedef struct s_param
{
	t_image	img;
	void	*mlx;
	void	*win;
	t_obj	obj;
	t_cmr	cmr;
	t_slt	slt;
	long int	start;
	long int	current;
}	t_param;

#endif
