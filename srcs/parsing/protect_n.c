/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:18:24 by truangsi          #+#    #+#             */
/*   Updated: 2023/09/02 11:14:46 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_parse.h"

int	protect_rat_n(t_rt *rt, int mode)
{
	if (mode == 1)
	{
		if (rt->amb.ratio < 0.0 || rt->amb.ratio > 1.0)
			return (printf("A: " FAILURE_RATIO), 1);
	}
	else
	{
		if (rt->light.ratio < 0.0 || rt->light.ratio > 1.0)
			return (printf("L: " FAILURE_RATIO), 1);
	}
	return (EXIT_SUCCESS);
}

int	protect_rgb_n(t_rt *rt, int mode)
{
	if (mode == 1)
	{
		if (rt->amb.clr.r < 0 || rt->amb.clr.r > 255 ||
			rt->amb.clr.g < 0 || rt->amb.clr.g > 255 ||
			rt->amb.clr.b < 0 || rt->amb.clr.b > 255)
			return (printf("A: " FAILURE_RGB), EXIT_FAILURE);
	}
	else
	{
		if (rt->light.clr.r < 0 || rt->light.clr.r > 255 ||
			rt->light.clr.g < 0 || rt->light.clr.g > 255 ||
			rt->light.clr.b < 0 || rt->light.clr.b > 255)
			return (printf("L: " FAILURE_RGB), EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	protect_vec_n(t_rt *rt)
{
	if (rt->cam.dir.x < -1.0 || rt->cam.dir.x > 1.0 ||
		rt->cam.dir.y < -1.0 || rt->cam.dir.y > 1.0 ||
		rt->cam.dir.z < -1.0 || rt->cam.dir.z > 1.0)
		return (printf("C: " FAILURE_VEC), EXIT_FAILURE);
	if (rt->cam.dir.x == 0 && rt->cam.dir.y == 0 && rt->cam.dir.z == 0)
		return (printf("C: " FAILURE_VEC_0), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}