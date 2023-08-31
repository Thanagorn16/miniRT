#include "minirt.h"

int	set_elem(char **av, t_rt *rt)
{
	char	*tmp;
	char	**set;

	rt->fd = open(av[1], O_RDONLY);
	while (1)
	{
		tmp = get_next_line(rt->fd);
		if (!tmp)
			break ;
		set = split2(tmp, ' ', ',');
		if (!set)
			return (EXIT_FAILURE);
		if (ft_strcmp(set[0], "A") == 0)
			if (set_amb(set, rt))
				exit(EXIT_FAILURE);
		if (ft_strcmp(set[0], "C") == 0)
			if (set_cam(set, rt))
				exit(EXIT_FAILURE);
		if (ft_strcmp(set[0], "L") == 0)
			if (set_light(set, rt))
				exit(EXIT_FAILURE);
		if (ft_strcmp(set[0], "sp") == 0)
			if (set_sp(set, rt))
				exit(EXIT_FAILURE);
		if (ft_strcmp(set[0], "pl") == 0)
			if (set_pl(set, rt))
				exit(EXIT_FAILURE);
		if (ft_strcmp(set[0], "cy") == 0)
			if (set_cy(set, rt))
				exit(EXIT_FAILURE);
		free(tmp);
	}
	return (EXIT_SUCCESS);
}

int parsing(int ac, char **av, t_rt *rt)
{
	char	**name;
	int		len;

	if (ac != 2)
		return (EXIT_FAILURE);

	//check input file
	name = ft_split(av[1], '.');
	len = ft_2dstrlen(name) - 1;
	if (ft_strcmp(name[len], "rt") != 0)
		return (EXIT_FAILURE);
	free_2dstr(name);

	// process data
	count_shape(av, rt);
	alloc_shape(rt);
	if (set_elem(av, rt) == 1)
		return (EXIT_FAILURE);

	// check data (remove the comment below to use the function)
	display(rt);
	exit(0);
	return (EXIT_SUCCESS);
}