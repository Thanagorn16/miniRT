/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:50:55 by tnantaki          #+#    #+#             */
/*   Updated: 2023/09/18 17:08:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	hit_inside(t_fml fml, float disc, bool *inside)
{
	*inside = true;
	return ((-fml.b + sqrtf(disc)) / (2 * fml.a));
}

bool	hit_plane(t_ray ray, t_hpl *hit, t_pl *pl, int mode)
{
	float	denom;
	float	distance;

	denom = vec_dot(ray.dir, pl->dir);
	if (ft_abs(denom) < EPSILON)
		return (false);
	distance = vec_dot(vec_sub(pl->pos, ray.ori), pl->dir) / denom;
	if (distance < 0.00f || distance > hit->distance)
		return (false);
	if (mode)
		return (true);
	hit->distance = distance;
	hit->point = vec_add(ray.ori, vec_scalar(ray.dir, distance)); // closest point
	hit->dir = pl->dir;
	if (denom > 0) // invert plane dir, Cause plane can see Top and Bot
		hit->dir = vec_scalar(hit->dir, -1);
	hit->clr = pl->clr;
	hit->hit = true;
	return (true);
}
