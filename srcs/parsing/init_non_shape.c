/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_non_shape.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prachman <prachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:42:13 by truangsi          #+#    #+#             */
/*   Updated: 2023/09/14 12:34:45 by prachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


int	set_amb(char **set, t_rt *rt)
{
	int static	i;

	// printf("here: %zu\n", ft_2dstrlen(set));
	if (ft_2dstrlen(set) != 5)
		free_exit(rt, "A:", FAILURE_INFO);
	// exit(0);
	if (i > 0)
		free_exit(rt, "A:", "must not be more than 1");
	rt->amb.ratio = ft_atof(set[1]);
	protect_rat_n(rt, 1);
	rt->amb.clr = set_clr(set);
	protect_rgb_n(rt, 1);
	i++;
	return (EXIT_SUCCESS);
}

int	set_cam(char **set, t_rt *rt)
{
	int static	i;

	// if (ft_2dstrlen(set) != 8)
	// 	free_exit(rt, "C:", FAILURE_INFO);
	if (i > 0)
		return (EXIT_FAILURE);
	rt->cam.pos = set_cor(set[1], set[2], set[3]);
	rt->cam.dir = set_cor(set[4], set[5], set[6]);
	protect_vec_n(rt);
	rt->cam.fov = atoi(set[7]);
	if (rt->cam.fov < 0 || rt->cam.fov > 180)
		free_exit(rt, "C:", FAILURE_FOV);
	i++;
	return (EXIT_SUCCESS);
}

int	set_light(char **set, t_rt *rt)
{
	int static	i;

	if (i > 0)
		return (EXIT_FAILURE);
	rt->light.pos = set_cor(set[1], set[2], set[3]);
	rt->light.ratio = ft_atof(set[4]);
	protect_rat_n(rt, 2);
	rt->light.clr = set_clr(set);
	protect_rgb_n(rt, 2);
	i++;
	return (EXIT_SUCCESS);
}