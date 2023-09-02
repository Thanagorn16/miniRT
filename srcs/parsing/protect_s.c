/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:04:56 by truangsi          #+#    #+#             */
/*   Updated: 2023/09/02 11:06:33 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_parse.h"

int	protect_rgb_s(t_rt *rt, int i, int mode)
{
	if (mode == 1)
	{
		if (rt->sp[i].clr.r < 0 || rt->sp[i].clr.r > 255 ||
			rt->sp[i].clr.g < 0 || rt->sp[i].clr.g > 255 ||
			rt->sp[i].clr.b < 0 || rt->sp[i].clr.b > 255)
			return (printf("SP: " FAILURE_RGB), EXIT_FAILURE);
	}
	else if (mode == 2)
	{
		if (rt->pl[i].clr.r < 0 || rt->pl[i].clr.r > 255 ||
			rt->pl[i].clr.g < 0 || rt->pl[i].clr.g > 255 ||
			rt->pl[i].clr.b < 0 || rt->pl[i].clr.b > 255)
			return (printf("PL: " FAILURE_RGB), EXIT_FAILURE);
	}
	else
	{
		if (rt->cy[i].clr.r < 0 || rt->cy[i].clr.r > 255 ||
			rt->cy[i].clr.g < 0 || rt->cy[i].clr.g > 255 ||
			rt->cy[i].clr.b < 0 || rt->cy[i].clr.b > 255)
			return (printf("CY: " FAILURE_RGB), EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int		protect_vec_s(t_rt *rt, int i, int mode)
{
	if (mode == 1)
	{
		if (rt->pl[i].dir.x < -1.0 || rt->pl[i].dir.x > 1.0 ||
			rt->pl[i].dir.y < -1.0 || rt->pl[i].dir.y > 1.0 ||
			rt->pl[i].dir.z < -1.0 || rt->pl[i].dir.z > 1.0)
			return (printf("PL: " FAILURE_VEC), EXIT_FAILURE);
		if (rt->pl[i].dir.x == 0 && rt->pl[i].dir.y == 0 && rt->pl[i].dir.z == 0)
			return (printf("PL: " FAILURE_VEC_0), EXIT_FAILURE);
	}
	else
	{
		if (rt->cy[i].dir.x < -1.0 || rt->cy[i].dir.x > 1.0 ||
			rt->cy[i].dir.y < -1.0 || rt->cy[i].dir.y > 1.0 ||
			rt->cy[i].dir.z < -1.0 || rt->cy[i].dir.z > 1.0)
			return (printf("CY: " FAILURE_VEC), EXIT_FAILURE);
		if (rt->cy[i].dir.x == 0 && rt->cy[i].dir.y == 0 && rt->cy[i].dir.z == 0)
			return (printf("CY: " FAILURE_VEC_0), EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}