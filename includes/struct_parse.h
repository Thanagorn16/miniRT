/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_parse.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:58:38 by truangsi          #+#    #+#             */
/*   Updated: 2023/09/26 11:58:38 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_PARSE_H
# define STRUCT_PARSE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

# define FAILURE_INFO \
"Invalid information\n"
# define FAILURE_RATIO \
"Ratio must not be less than 0.0 and must not be more than 1.0\n"
# define FAILURE_RGB \
"RGB must not be less than 0 and must not be more than 255\n"
# define FAILURE_VEC \
"Vector must not be less than -1.0 and must not be more than 1.0\n"
# define FAILURE_VEC_0 \
"Vector (x, y, z) must not all be pointed 0 at the beginning\n"
# define FAILURE_FOV \
"FOV must not be less than 0 and must not be more than 180\n"

typedef struct s_cor
{
	float	x;
	float	y;
	float	z;
}	t_cor;

typedef struct s_axis
{
	t_cor	dir;
	t_cor	hor;
	t_cor	ver;
}	t_axis;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_ambien
{
	t_rgb	clr;
	float	ratio;
}	t_ambien;

typedef struct s_cam
{
	t_cor	pos;
	t_cor	dir;
	int		fov;
}	t_cam;

typedef struct s_light
{
	t_cor	pos;
	t_rgb	clr;
	float	ratio;
}	t_light;

typedef struct s_pl
{
	t_axis	axis;
	t_cor	pos;
	t_cor	dir;
	t_rgb	clr;
}	t_pl;

typedef struct s_sp
{
	t_cor	pos;
	t_rgb	clr;
	float	dia;
	float	radius;
	bool	inside;
}	t_sp;

// m = is a scalar
//that determines the closest point on the axis to the hit point.
typedef struct s_cy
{
	t_axis	axis;
	t_cor	pos;
	t_cor	dir;
	t_cor	top;
	t_cor	bot;
	t_rgb	clr;
	float	height;
	float	dia;
	float	radius;
	float	m;
	bool	inside;
}	t_cy;

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
	char		*tmp;
	int			fd;
}	t_rt;

// non shapes
t_cor	set_cor(char *set1, char *set2, char *set3);
t_rgb	set_clr(char **set);
int		set_amb(char **set, t_rt *rt);
int		set_cam(char **set, t_rt *rt);
int		set_light(char **set, t_rt *rt);
// shape(s)
void	count_shape(char **av, t_rt *rt);
void	alloc_shape(t_rt *rt);
int		set_sp(char **set, t_rt *rt);
int		set_pl(char **set, t_rt *rt);
int		set_cy(char **set, t_rt *rt);
// utils
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_2dstrlen(char **str);
void	free_2dstr(char **ptr);
// protection
void	check_identifier(t_rt *rt, char **set);
void	check_alpha(t_rt *rt, char **set);
int		protect_rat_n(t_rt *rt, char **set, int mode);
int		protect_rgb_n(t_rt *rt, char **set, int mode);
int		protect_vec_n(t_rt *rt, char **set);
int		protect_rat_s(t_rt *rt, char **set, int i, int mode);
int		protect_rgb_s(t_rt *rt, char **set, int i, int mode);
int		protect_vec_s(t_rt *rt, char **set, int i, int mode);
// others
int		parsing(int ac, char **av, t_rt *rt);
float	ft_atof(const char *str);
char	**split_data(char const *s, char c1, char c2);
void	free_data(t_rt *rt);
void	free_shape(t_rt *rt);
void	free_exit(t_rt *rt, char **set, char *err);
#endif