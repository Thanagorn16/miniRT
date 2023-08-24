#include "minirt.h"

void	set_sp(char **set, t_rt *rt)
{
	int	static	i;

	rt->sp[i].pos = set_cor(set[1], set[2], set[3]);
	rt->sp[i].dia = ft_atof(set[4]);
	rt->sp[i].radius = ft_atof(set[4]) / 2;
	rt->sp[i].clr = set_clr(set);
	i++;
}

void	set_pl(char **set, t_rt *rt)
{
	int	static	i;

	rt->pl[i].pos = set_cor(set[1], set[2], set[3]);
	rt->pl[i].dir = set_cor(set[4], set[5], set[6]);
	rt->pl[i].clr = set_clr(set);
	i++;
}

void	set_cy(char **set, t_rt *rt)
{
	int	static	i;

	rt->cy[i].pos = set_cor(set[1], set[2], set[3]);
	rt->cy[i].dir = set_cor(set[4], set[5], set[6]);
	rt->cy[i].dia = ft_atof(set[7]);
	rt->cy[i].radius = ft_atof(set[7]) / 2;
	rt->cy[i].height = ft_atof(set[8]);
	rt->cy[i].clr = set_clr(set);
	i++;
}