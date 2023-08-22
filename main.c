#include "minirt.h"

void	set_sp(char **set, t_rt *rt)
{
	int	static	i;

	rt->sp[i].pos = set_cor(set[1], set[2], set[3]);
	rt->sp[i].dia = ft_atof(set[4]);
	rt->sp[i].radius = ft_atof(set[4]) / 2;
	rt->sp[i].clr = set_clr(set);
}

void	set_pl(char **set, t_rt *rt)
{
	int	static	i;

	rt->pl[i].pos = set_cor(set[1], set[2], set[3]);
	rt->pl[i].dir = set_cor(set[4], set[5], set[6]);
	rt->pl[i].clr = set_clr(set);
}

void	set_cy(char **set, t_rt *rt)
{
	int	static	i;

	rt->cy[i].pos = set_cor(set[1], set[2], set[3]);
	rt->cy[i].dir = set_cor(set[4], set[5], set[6]);
	rt->cy[i].dia = ft_atof(set[7]);
	rt->cy[i].length = ft_atof(set[8]);
	rt->pl[i].clr = set_clr(set);
}

int	set_elem(char **av, t_rt *rt)
{
	char	*tmp;
	char	**set;

	rt->fd = open(av[1], O_RDONLY);
	int i = 0;
	while (i != 2)
	{
		tmp = get_next_line(rt->fd);
		// printf("%s", tmp);
		set = split2(tmp, ' ', ',');
		if (!set)
			return (EXIT_FAILURE);
		if (ft_strcmp(set[0], "A") == 0)
			set_amb(set, rt);
		if (ft_strcmp(set[0], "C") == 0)
			set_cam(set, rt);
		if (ft_strcmp(set[0], "L") == 0)
			set_light(set, rt);
		if (ft_strcmp(set[0], "sp") == 0)
			set_sp(set, rt);
		if (ft_strcmp(set[0], "pl") == 0)
			set_pl(set, rt);
		if (ft_strcmp(set[0], "cy") == 0)
			set_pl(set, rt);
		// printf("%d\n", rt->amb.rgb.r);
		// printf("%d\n", rt->amb.rgb.g);
		// printf("%d\n", rt->amb.rgb.b);
		// break ;
		i++;
		free(tmp);
	}
	return (EXIT_SUCCESS);
}

int main(int ac, char **av)
{
	char    **name;
	int		len;
	t_rt	rt;
	// char	*aa = "A 0.2 255,255,255";
	// char	**bb;

	if (ac != 2)
		return (EXIT_FAILURE);

	//check input file
	name = ft_split(av[1], '.');
	len = ft_2dstrlen(name) - 1;
	if (ft_strcmp(name[len], "rt") != 0)
		return (EXIT_FAILURE);
	free_2dstr(name);

	// process data
	count_shape(av, &rt);
	alloc_shape(&rt);
	if (set_elem(av, &rt) == 1)
		return (EXIT_FAILURE);
	// printf("%f\n", rt.amb.ratio);
	// exit(0);
	// printf("%d\n", rt.npl);
	// printf("%d\n", rt.nsp);
	// printf("%d\n", rt.ncy);
}