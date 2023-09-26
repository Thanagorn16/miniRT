/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:42:17 by truangsi          #+#    #+#             */
/*   Updated: 2023/09/26 14:30:49 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	process_elem(t_rt *rt, char **set)
{
	if (ft_strcmp(rt->tmp, "\n") != 0)
	{
		check_alpha(rt, set);
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
			set_cy(set, rt);
	}
}

int	set_elem(char **av, t_rt *rt)
{
	char	**set;

	rt->fd = open(av[1], O_RDONLY);
	while (1)
	{
		rt->tmp = get_next_line(rt->fd);
		if (!rt->tmp)
			break ;
		set = split_data(rt->tmp, ' ', ',');
		if (!set)
			return (free_data(rt), exit(EXIT_FAILURE), 1);
		process_elem(rt, set);
		free(rt->tmp);
		free_2dstr(set);
	}
	close(rt->fd);
	return (EXIT_SUCCESS);
}

int	parsing(int ac, char **av, t_rt *rt)
{
	char	**name;
	int		len;

	if (ac != 2)
		return (EXIT_FAILURE);
	name = ft_split(av[1], '.');
	if (!name)
		exit(EXIT_FAILURE);
	len = ft_2dstrlen(name) - 1;
	if (len != 1)
		return (free_2dstr(name), exit(EXIT_FAILURE), 1);
	if (ft_strcmp(name[len], "rt") != 0)
		return (free_2dstr(name), exit(EXIT_FAILURE), 1);
	free_2dstr(name);
	count_shape(av, rt);
	alloc_shape(rt);
	if (set_elem(av, rt) == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
