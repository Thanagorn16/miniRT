#include "struct_parse.h"

void	set_amb(char **set, t_rt *rt)
{
	// printf("atf: %f\n", ft_atof(set[1]));
	// rt->amb.ratio = atof(set[1]);
	rt->amb.ratio = ft_atof(set[1]);
	rt->amb.clr = set_clr(set);
}

void	set_cam(char **set, t_rt *rt)
{
	rt->cam.pos = set_cor(set[1], set[2], set[3]);
	rt->cam.dir = set_cor(set[4], set[5], set[6]);
	rt->cam.fov = atoi(set[7]);
}

void	set_light(char **set, t_rt *rt)
{
	rt->light.pos = set_cor(set[1], set[2], set[3]);
	rt->light.ratio = ft_atof(set[4]);
	rt->light.clr = set_clr(set);
}