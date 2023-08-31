#include "minirt.h"

int	set_amb(char **set, t_rt *rt)
{
	int static	i;

	if (i > 0)
		return (EXIT_FAILURE);
	rt->amb.ratio = ft_atof(set[1]);
	if (protect_rat_n(rt, 1))
		exit(EXIT_FAILURE);
	rt->amb.clr = set_clr(set);
	if (protect_rgb_n(rt, 1))
		exit (EXIT_FAILURE);
	i++;
	return (EXIT_SUCCESS);
}

int	set_cam(char **set, t_rt *rt)
{
	int static	i;

	if (i > 0)
		return (EXIT_FAILURE);
	rt->cam.pos = set_cor(set[1], set[2], set[3]);
	rt->cam.dir = set_cor(set[4], set[5], set[6]);
	if (protect_vec_n(rt))
		exit(EXIT_FAILURE);
	rt->cam.fov = atoi(set[7]);
	if (rt->cam.fov < 0 || rt->cam.fov > 180)
		return (printf("C: " FAILURE_FOV), 1);
	i++;
	return (EXIT_SUCCESS);
}

int	set_light(char **set, t_rt *rt)
{
	int static	i;

	if (i > 0)
		return (EXIT_FAILURE);
	rt->light.pos = set_cor(set[1], set[2], set[3]);
	rt->light.ratio = ft_atof(set[4]);
	if (protect_rat_n(rt, 2))
		exit(EXIT_FAILURE);
	rt->light.clr = set_clr(set);
	if (protect_rgb_n(rt, 2))
		exit(EXIT_FAILURE);
	i++;
	return (EXIT_SUCCESS);
}