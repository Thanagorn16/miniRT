/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:18:24 by truangsi          #+#    #+#             */
/*   Updated: 2023/09/02 13:27:22 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int protect_rat_n(t_rt *rt, int mode)
{
	if (mode == 1)
	{
		if (rt->amb.ratio < 0.0 || rt->amb.ratio > 1.0)
			free_exit(rt, "A:", FAILURE_RATIO);
	}
	else
	{
		if (rt->light.ratio < 0.0 || rt->light.ratio > 1.0)
			free_exit(rt, "L:", FAILURE_RATIO);
	}
	return (EXIT_SUCCESS);
}

int protect_rgb_n(t_rt *rt, int mode)
{
	if (mode == 1)
	{
		if (rt->amb.clr.r < 0 || rt->amb.clr.r > 255 ||
			rt->amb.clr.g < 0 || rt->amb.clr.g > 255 ||
			rt->amb.clr.b < 0 || rt->amb.clr.b > 255)
			free_exit(rt, "A:", FAILURE_RGB);
	}
	else
	{
		if (rt->light.clr.r < 0 || rt->light.clr.r > 255 ||
			rt->light.clr.g < 0 || rt->light.clr.g > 255 ||
			rt->light.clr.b < 0 || rt->light.clr.b > 255)
			free_exit(rt, "L:", FAILURE_RGB);
	}
	return (EXIT_SUCCESS);
}

int protect_vec_n(t_rt *rt)
{
	if (rt->cam.dir.x < -1.0 || rt->cam.dir.x > 1.0 ||
		rt->cam.dir.y < -1.0 || rt->cam.dir.y > 1.0 ||
		rt->cam.dir.z < -1.0 || rt->cam.dir.z > 1.0)
		free_exit(rt, "C:", FAILURE_VEC);
	if (rt->cam.dir.x == 0 && rt->cam.dir.y == 0 && rt->cam.dir.z == 0)
		free_exit(rt, "C:", FAILURE_VEC_0);
	return (EXIT_SUCCESS);
}