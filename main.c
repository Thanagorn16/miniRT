#include "minirt.h"

void	set_amb(char **set, t_rt *rt)
{
	int	len;

	rt->amb.ratio = atof(set[1]);
	len = ft_2dstrlen(set);
	rt->amb.rgb.r = atoi(set[len - 3]);
	rt->amb.rgb.g = atoi(set[len - 2]);
	rt->amb.rgb.b = atoi(set[len - 1]);
}

t_cor set_cor(char *set1, char *set2, char *set3)
{
	t_cor	cor;

	cor.x = atof(set1);
	cor.y = atof(set2);
	cor.z = atof(set3);
	return (cor);
}

void	set_cam(char **set, t_rt *rt)
{
	rt->cam.pos = set_cor(set[1], set[2], set[3]);
	rt->cam.dir = set_cor(set[4], set[5], set[6]);
	// rt->cam.pos.x = atof(set[1]);
	// rt->cam.pos.y = atof(set[2]);
	// rt->cam.pos.z = atof(set[3]);
	// rt->cam.dir.x = atof(set[4]);
	// rt->cam.dir.y = atof(set[5]);
	// rt->cam.dir.z = atof(set[6]);
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
	rt->amb.rgb.r = atoi(set[len - 3]);
	rt->amb.rgb.g = atoi(set[len - 2]);
	rt->amb.rgb.b = atoi(set[len - 1]);
}

int	init_elem(char **av, t_rt *rt)
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
	name = ft_split(av[1], '.');
	len = ft_2dstrlen(name) - 1;
	if (ft_strcmp(name[len], "rt") != 0)
		return (EXIT_FAILURE);
	free_2dstr(name);
	get_shape(av, &rt);
	if (init_elem(av, &rt) == 1)
		return (EXIT_FAILURE);
	// printf("%f\n", rt.amb.ratio);
	// exit(0);
	// printf("%d\n", rt.npl);
	// printf("%d\n", rt.nsp);
	// printf("%d\n", rt.ncy);
}