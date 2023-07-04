#ifndef MINI_RT
# define MINI_RT

# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct s_ambien
{
	float   ratio;
	int		r;
	int		g;
	int		b;
} t_ambien;

typedef struct s_cam
{
	float	x_pos;
	float	y_pos;
	float	z_pos;
	float	x_dir;
	float	y_dir;
	float	z_dir;
	int		fov;
} t_cam;

typedef struct s_light
{
	float	x_pos;
	float	y_pos;
	float	z_pos;
	float   ratio;
	int		r;
	int		g;
	int		b;
} t_light;

typedef struct s_pl
{
	float	x_pos;
	float	y_pos;
	float	z_pos;
	float	x_dir;
	float	y_dir;
	float	z_dir;
} t_pl;

typedef struct s_sp
{
	float	x_pos;
	float	y_pos;
	float	z_pos;
	float	radius;
	int		r;
	int		g;
	int		b;
} t_sp;

typedef struct s_cy
{
	float	x_pos;
	float	y_pos;
	float	z_pos;
	float	x_dir;
	float	y_dir;
	float	z_dir;
	int		r;
	int		g;
	int		b;
} t_cy;

typedef struct s_rt
{
	t_ambien	ambien;
	t_cam		cam;
	t_light		light;
	t_pl		*pl;
	t_sp		*sp;
	t_cy		*cy;
	int			npl;
	int			nsp;
	int			ncy;
} t_rt;

int	    ft_strcmp(const char *s1, const char *s2);
size_t	ft_2dstrlen(char **str);
void	free_2dstr(char **ptr);

#endif