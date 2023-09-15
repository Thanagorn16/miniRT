/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prachman <prachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 08:38:16 by prachman          #+#    #+#             */
/*   Updated: 2023/09/15 09:39:48 by prachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	set_sp(char **set, t_rt *rt)
{
	int	static	i;

	if (ft_2dstrlen(set) != 8)
		free_exit(rt, set, "SP:", FAILURE_INFO);
	rt->sp[i].pos = set_cor(set[1], set[2], set[3]);
	rt->sp[i].dia = ft_atof(set[4]);
	rt->sp[i].radius = ft_atof(set[4]) / 2;
	rt->sp[i].clr = set_clr(set);
	protect_rgb_s(rt, set, i, 1);
	i++;
	return (EXIT_SUCCESS);
}

int	set_pl(char **set, t_rt *rt)
{
	int	static	i;

	if (ft_2dstrlen(set) != 10)
		free_exit(rt, set, "PL:", FAILURE_INFO);
	rt->pl[i].pos = set_cor(set[1], set[2], set[3]);
	rt->pl[i].dir = set_cor(set[4], set[5], set[6]);
	protect_vec_s(rt, set, i, 1);
	rt->pl[i].clr = set_clr(set);
	protect_rgb_s(rt, set, i, 2);
	i++;
	return (EXIT_SUCCESS);
}

int	set_cy(char **set, t_rt *rt)
{
	int	static	i;

	if (ft_2dstrlen(set) != 12)
		free_exit(rt, set, "CY:", FAILURE_INFO);
	rt->cy[i].pos = set_cor(set[1], set[2], set[3]);
	rt->cy[i].dir = set_cor(set[4], set[5], set[6]);
	protect_vec_s(rt, set, i, 2);
	rt->cy[i].dia = ft_atof(set[7]);
	rt->cy[i].radius = ft_atof(set[7]) / 2;
	rt->cy[i].height = ft_atof(set[8]);
	rt->cy[i].clr = set_clr(set);
	protect_rgb_s(rt, set, i, 3);
	i++;
	return (EXIT_SUCCESS);
}