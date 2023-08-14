#ifndef MINI_RT
# define MINI_RT

# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

# define DIR 1

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

int	    ft_strcmp(const char *s1, const char *s2);
size_t	ft_2dstrlen(char **str);
void	free_2dstr(char **ptr);
char	**split2(char const *s, char c1, char c2);
float	ft_atof(const char *str);
void	get_shape(char **av, t_rt *rt);
void	set_rgb(char **set, t_rt *rt);
void	set_amb(char **set, t_rt *rt);
// void	set_cor(char **set, t_rt *rt, int mode);

#endif