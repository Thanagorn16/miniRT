/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:50:59 by tnantaki          #+#    #+#             */
/*   Updated: 2023/09/01 10:28:31 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	closest_sphere(t_ray ray, t_hpl *hit, t_sp *sp, float t_closest)
{
	hit->distance = t_closest;
	hit->point = vec_add(ray.oc, vec_scalar(ray.dir, hit->distance)); // closest point of sphere on matrix
	hit->dir = vec_norm(hit->point);
	hit->point = vec_add(hit->point, sp->pos); // move hit point back to the real position
	hit->clr = sp->clr;
	hit->ctr = sp->pos;
	hit->hit = true;
	return (true);
}

// (dx^2 + dy^2 + dz^2)t^2 + (2(ox * dx + oy * dy))t + (ox^2 + oy^2 - r^2) = 0
// o = ray orignal (position of camera)
// d = ray direction (circle rigion)
// r = radius
// t = hit distance
// Because Sphere formular working on x,y,z cartesian, So center will be zero
// That also mean we can't move the sphere, But we can move the camera instead
// Origin is the position of camera
bool	hit_sphere(t_ray ray, t_hpl *hit, t_sp *sp, int mode)
{
	t_fml	fml;
	float	disc;
	float	t_closest;

	ray.oc = vec_sub(ray.ori, sp->pos);
	fml.a = vec_dot(ray.dir, ray.dir);
	fml.b = 2 * vec_dot(ray.oc, ray.dir);
	fml.c = vec_dot(ray.oc, ray.oc) - ft_pow2(sp->radius);
	disc = discriminant(fml.a, fml.b, fml.c);
	if (disc < 0.0f)
		return (false);
	t_closest = (-fml.b - sqrtf(disc)) / (2 * fml.a); // closest distance from camera to sphere
	if (t_closest < 0) // incase of position of camera are inside the sphere
		t_closest = (-fml.b + sqrtf(disc)) / (2 * fml.a);
	if (t_closest < 0.00f || t_closest > hit->distance)
		return (false);
	if (mode) // To only calculate that hit any object.
		return (true);
	return (closest_sphere(ray, hit, sp, t_closest));
}
