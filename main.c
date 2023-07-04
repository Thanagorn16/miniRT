#include "minirt.h"

void	get_max_shape(int file, t_rt *rt)
{
	char	*tmp;
	char	**elem;

	rt->npl = 0;
	rt->nsp = 0;
	rt->ncy = 0;
	while (1)
	{
		tmp = get_next_line(file);
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
}

int main(int ac, char **av)
{
	char    **name;
	// char	*tmp;
	int		len;
	int		file;
	t_rt	rt;

	if (ac != 2)
		exit(EXIT_FAILURE);
	name = ft_split(av[1], '.');
	len = ft_2dstrlen(name) - 1;
	if (ft_strcmp(name[len], "rt") != 0)
		exit(EXIT_FAILURE);
	free_2dstr(name);
	file = open(av[1], O_RDONLY);
	get_max_shape(file, &rt);
	// printf("%d\n", rt.npl);
	// printf("%d\n", rt.nsp);
	// printf("%d\n", rt.ncy);
}