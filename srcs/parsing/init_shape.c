#include "minirt.h"

int	set_sp(char **set, t_rt *rt)
{
	int	static	i;

	rt->sp[i].pos = set_cor(set[1], set[2], set[3]);
	rt->sp[i].dia = ft_atof(set[4]);
	rt->sp[i].radius = ft_atof(set[4]) / 2;
	rt->sp[i].clr = set_clr(set);
	if (rt->sp[i].clr.r < 0 || rt->sp[i].clr.r > 255)
		return (printf("SP: " FAILURE_RGB), 1);
	if (rt->sp[i].clr.g < 0 || rt->sp[i].clr.g > 255)
		return (printf("SP: " FAILURE_RGB), 1);
	if (rt->sp[i].clr.b < 0 || rt->sp[i].clr.b > 255)
		return (printf("SP: " FAILURE_RGB), 1);
	i++;
	return (EXIT_SUCCESS);
}

int	set_pl(char **set, t_rt *rt)
{
	int	static	i;

	rt->pl[i].pos = set_cor(set[1], set[2], set[3]);
	rt->pl[i].dir = set_cor(set[4], set[5], set[6]);
	if (rt->pl[i].dir.x < -1.0 || rt->pl[i].dir.x > 1.0)
		return (printf("PL: " FAILURE_VEC), 1);
	if (rt->pl[i].dir.y < -1.0 || rt->pl[i].dir.y > 1.0)
		return (printf("PL: " FAILURE_VEC), 1);
	if (rt->pl[i].dir.z < -1.0 || rt->pl[i].dir.z > 1.0)
		return (printf("PL: " FAILURE_VEC), 1);
	rt->pl[i].clr = set_clr(set);
	if (rt->pl[i].clr.r < 0 || rt->pl[i].clr.r > 255)
		return (printf("SP: " FAILURE_RGB), 1);
	if (rt->pl[i].clr.g < 0 || rt->pl[i].clr.g > 255)
		return (printf("SP: " FAILURE_RGB), 1);
	if (rt->pl[i].clr.b < 0 || rt->pl[i].clr.b > 255)
		return (printf("SP: " FAILURE_RGB), 1);
	i++;
	return (EXIT_SUCCESS);
}

int	set_cy(char **set, t_rt *rt)
{
	int	static	i;

	rt->cy[i].pos = set_cor(set[1], set[2], set[3]);
	rt->cy[i].dir = set_cor(set[4], set[5], set[6]);
	if (rt->cy[i].dir.x < -1.0 || rt->cy[i].dir.x > 1.0)
		return (printf("CY: " FAILURE_VEC), 1);
	if (rt->cy[i].dir.y < -1.0 || rt->cy[i].dir.y > 1.0)
		return (printf("CY: " FAILURE_VEC), 1);
	if (rt->cy[i].dir.z < -1.0 || rt->cy[i].dir.z > 1.0)
		return (printf("CY: " FAILURE_VEC), 1);
	rt->cy[i].dia = ft_atof(set[7]);
	rt->cy[i].radius = ft_atof(set[7]) / 2;
	rt->cy[i].height = ft_atof(set[8]);
	rt->cy[i].clr = set_clr(set);
	if (rt->cy[i].clr.r < 0 || rt->cy[i].clr.r > 255)
		return (printf("CY: " FAILURE_RGB), 1);
	if (rt->cy[i].clr.g < 0 || rt->cy[i].clr.g > 255)
		return (printf("CY: " FAILURE_RGB), 1);
	if (rt->cy[i].clr.b < 0 || rt->cy[i].clr.b > 255)
		return (printf("CY: " FAILURE_RGB), 1);
	i++;
	return (EXIT_SUCCESS);
}