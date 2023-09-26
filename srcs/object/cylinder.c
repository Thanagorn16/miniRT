/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:06:32 by tnantaki          #+#    #+#             */
/*   Updated: 2023/09/26 14:06:33 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	closest_disk(t_hpl *hit, t_cy *cy, float denom, float distance)
{
	hit->distance = distance;
	hit->dir = cy->dir;
	if (denom > 0)
		hit->dir = vec_scalar(hit->dir, -1);
	hit->clr = cy->clr;
	hit->hit = true;
	return (true);
}

bool	disk_intersection(t_ray ray, t_hpl *hit, t_cy *cy, int mode)
{
	float	denom;
	float	distance;
	float	distance_bot;
	t_cor	tmp_hitpoint;
	t_cor	pos;

	denom = vec_dot(ray.dir, cy->dir);
	if (ft_abs(denom) < EPSILON)
		return (false);
	pos = cy->top;
	distance = vec_dot(vec_sub(pos, ray.ori), cy->dir) / denom;
	distance_bot = vec_dot(vec_sub(cy->bot, ray.ori), cy->dir) / denom;
	if (distance < 0.00f || (distance_bot > 0.00f && distance_bot < distance))
	{
		distance = distance_bot;
		pos = cy->bot;
	}
	if (distance < 0.00f || distance > hit->distance)
		return (false);
	tmp_hitpoint = vec_add(ray.ori, vec_scalar(ray.dir, distance));
	if (vec_len(vec_sub(tmp_hitpoint, pos)) > cy->radius)
		return (false);
	if (mode)
		return (true);
	return (hit->point = tmp_hitpoint, closest_disk(hit, cy, denom, distance));
}

static bool	closest_cylinder(t_ray ray, t_hpl *hit, t_cy *cy, float distance)
{
	hit->distance = distance;
	hit->point = vec_add(ray.oc, vec_scalar(ray.dir, hit->distance));
	hit->dir = vec_norm(hit->point);
	if (cy->inside)
		hit->dir = vec_scalar(hit->dir, -1);
	hit->point = vec_add(hit->point, cy->pos);
	hit->clr = cy->clr;
	hit->ctr = cy->pos;
	hit->hit = true;
	return (true);
}

// O is ray origin
// D is ray direction
// X is ray origin - Center point of object
// V is vector of cylinder
// r = radius
// m = is a scalar that determines the closest point on the axis to hit point.
// a = (D|D) - (D|V)^2
// b = 2 * ((D|X) - (D|V) * (X|V))
// c = X|X - (X|V)^2 - r*r
// t = hit distance
// m = D|V*t + X|V
bool	hit_cylinder(t_ray ray, t_hpl *hit, t_cy *cy, int mode)
{
	t_fml	fml;
	float	disc;
	float	t_closest;

	cy->inside = false;
	ray.oc = vec_sub(ray.ori, cy->pos);
	fml.a = vec_dot(ray.dir, ray.dir) - ft_pow2(vec_dot(ray.dir, cy->dir));
	fml.b = 2 * (vec_dot(ray.dir, ray.oc) - vec_dot(ray.dir, cy->dir)
			* vec_dot(ray.oc, cy->dir));
	fml.c = vec_dot(ray.oc, ray.oc) - ft_pow2(vec_dot(ray.oc, cy->dir))
		- ft_pow2(cy->radius);
	disc = discriminant(fml.a, fml.b, fml.c);
	if (disc < 0.0f)
		return (false);
	t_closest = (-fml.b - sqrtf(disc)) / (2 * fml.a);
	if (t_closest < 0.00f)
		t_closest = hit_inside(fml, disc, &cy->inside);
	if (t_closest < 0.00f || t_closest > hit->distance)
		return (false);
	cy->m = vec_dot(ray.dir, cy->dir) * t_closest + vec_dot(ray.oc, cy->dir);
	if (ft_abs(cy->m) > cy->height / 2)
		return (false);
	if (mode)
		return (true);
	return (closest_cylinder(ray, hit, cy, t_closest));
}
