#include "minirt.h"

int	set_amb(char **set, t_rt *rt)
{
	int static	i;

	if (i > 0)
		return (EXIT_FAILURE);
	rt->amb.ratio = ft_atof(set[1]);
	if (rt->amb.ratio < 0.0 || rt->amb.ratio > 1.0)
		return (printf("A: " FAILURE_RATIO), 1);
	rt->amb.clr = set_clr(set);
	if (rt->amb.clr.r < 0 || rt->amb.clr.r > 255)
		return (printf("A: " FAILURE_RATIO), 1);
	if (rt->amb.clr.g < 0 || rt->amb.clr.g > 255)
		return (printf("A: " FAILURE_RATIO), 1);
	if (rt->amb.clr.b < 0 || rt->amb.clr.b > 255)
		return (printf("A: " FAILURE_RATIO), 1);
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
	if (rt->cam.dir.x < -1.0 || rt->cam.dir.x > 1.0)
		return (printf("C: " FAILURE_VEC), 1);
	if (rt->cam.dir.y < -1.0 || rt->cam.dir.y > 1.0)
		return (printf("C: " FAILURE_VEC), 1);
	if (rt->cam.dir.z < -1.0 || rt->cam.dir.z > 1.0)
		return (printf("C: " FAILURE_VEC), 1);
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
	if (rt->light.ratio < 0.0 || rt->light.ratio > 1.0)
		return (printf("L: " FAILURE_RATIO), 1);
	rt->light.clr = set_clr(set);
	if (rt->light.clr.r < 0 || rt->light.clr.r > 255)
		return (printf("L: " FAILURE_RGB), 1);
	if (rt->light.clr.g < 0 || rt->light.clr.g > 255)
		return (printf("L: " FAILURE_RGB), 1);
	if (rt->light.clr.b < 0 || rt->light.clr.b > 255)
		return (printf("L: " FAILURE_RGB), 1);
	i++;
	return (EXIT_SUCCESS);
}