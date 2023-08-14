#include "minirt.h"

void	get_shape(char **av, t_rt *rt)
{
	char	*tmp;
	char	**elem;

	rt->fd = open(av[1], O_RDONLY);
	if (rt->fd < 0)
		exit(EXIT_FAILURE);
	rt->npl = 0;
	rt->nsp = 0;
	rt->ncy = 0;
	while (1)
	{
		tmp = get_next_line(rt->fd);
		if (!tmp)
			break ;
		elem = ft_split(tmp, ' '); 
		if (ft_strcmp(elem[0], "pl") == 0)
			rt->npl++;
		else if (ft_strcmp(elem[0], "sp") == 0)
			rt->nsp++;
		else if (ft_strcmp(elem[0], "cy") == 0)
			rt->ncy++;
		free(tmp);
	}
	close(rt->fd);
}
