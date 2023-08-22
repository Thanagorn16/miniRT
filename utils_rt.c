#include "minirt.h"

// count the number of arithmetic shape
void	count_shape(char **av, t_rt *rt)
{
	char	*tmp;
	char	**elem;

	rt->fd = open(av[1], O_RDONLY);
	if (rt->fd < 0)
		exit(EXIT_FAILURE);
	rt->amt.pl = 0;
	rt->amt.sp = 0;
	rt->amt.cy = 0;
	while (1)
	{
		tmp = get_next_line(rt->fd);
		if (!tmp)
			break ;
		elem = ft_split(tmp, ' ');
		if (ft_strcmp(elem[0], "pl") == 0)
			rt->amt.pl++;
		else if (ft_strcmp(elem[0], "sp") == 0)
			rt->amt.sp++;
		else if (ft_strcmp(elem[0], "cy") == 0)
			rt->amt.cy++;
		free(tmp);
	}
	close(rt->fd);
}

// allocate all the shapes in the data
void	alloc_shape(t_rt *rt)
{
	int	i;

	i = 0;
	while (i < rt->amt.pl)
	{
		rt->pl = malloc(sizeof(t_rt) * rt->amt.pl);
		i++;
	}
	i = 0;
	while (i < rt->amt.sp)
	{
		rt->sp = malloc(sizeof(t_rt) * rt->amt.sp);
		i++;
	}
	i = 0;
	while (i < rt->amt.cy)
	{
		rt->cy = malloc(sizeof(t_rt) * rt->amt.cy);
		i++;
	}
}
