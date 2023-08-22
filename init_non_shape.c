#include "minirt.h"

t_cor set_cor(char *set1, char *set2, char *set3)
{
	t_cor	cor;

	cor.x = ft_atof(set1);
	cor.y = ft_atof(set2);
	cor.z = ft_atof(set3);
	return (cor);
}

t_rgb	set_clr(char **set)
{
	t_rgb	clr;
	int		len;

	len = ft_2dstrlen(set);
	clr.r = atoi(set[len - 3]);
	clr.g = atoi(set[len - 2]);
	clr.b = atoi(set[len - 1]);
	return (clr);
}

void	set_amb(char **set, t_rt *rt)
{
	int	len;

	rt->amb.ratio = atof(set[1]);
	rt->amb.clr = set_clr(set);
	// len = ft_2dstrlen(set);
	// rt->amb.clr.r = atoi(set[len - 3]);
	// rt->amb.clr.g = atoi(set[len - 2]);
	// rt->amb.clr.b = atoi(set[len - 1]);
}

void	set_cam(char **set, t_rt *rt)
{
	rt->cam.pos = set_cor(set[1], set[2], set[3]);
	rt->cam.dir = set_cor(set[4], set[5], set[6]);
	rt->cam.fov = atoi(set[7]);
}

void	set_light(char **set, t_rt *rt)
{
	int	len;

	rt->light.pos.x = atof(set[1]);
	rt->light.pos.y = atof(set[2]);
	rt->light.pos.z = atof(set[3]);
	rt->light.ratio = atof(set[4]);
	len = ft_2dstrlen(set);
	rt->amb.clr.r = atoi(set[len - 3]);
	rt->amb.clr.g = atoi(set[len - 2]);
	rt->amb.clr.b = atoi(set[len - 1]);
}