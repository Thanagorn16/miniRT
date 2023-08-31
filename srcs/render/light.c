/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:51:11 by tnantaki          #+#    #+#             */
/*   Updated: 2023/08/31 13:51:11 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Ambient light contribute every light of every point in the scene
t_rgb	ambient_light(t_rgb clr, t_rgb objclr, t_rgb amb)
{
	objclr = shade_clr(objclr, amb);
	clr = add_clr(clr, objclr);
	return (clamp_clr(clr));
}

bool	block_object(t_ray ray, t_obj *obj, float distance)
{
	t_hpl	hit;
	int		i;

	hit.distance = distance;
	hit.hit = false;
	i = 0;
	while (i < obj->amt.sp)
	{
		if (hit_sphere(ray, &hit, obj->sp[i++], 1))
			return (true);
	}
	i = 0;
	while (i < obj->amt.pl)
	{
		if (hit_plane(ray, &hit, obj->pl[i++], 1))
			return (true);
	}
	i = 0;
	while (i < obj->amt.cy)
	{
		if (hit_cylender(ray, &hit, obj->cy[i], 1)
			|| disk_intersection(ray, &hit, obj->cy[i++], 1))
			return (true);
	}
	return (false);
}

// Point light will create shade and shadow effect to object
// by using invert light drection dot product with hit point of object
t_rgb	shadowing(t_rgb clr, t_hpl hit, t_obj *obj)
{
	float	shade_ratio;
	float	light_distance;
	t_ray	light;

	light.ori = vec_add(hit.point, vec_scalar(hit.dir, EPSILON));
	light.dir = vec_sub(obj->light.pos, hit.point);
	light.dir = vec_norm(light.dir);
	light_distance = vec_len(vec_sub(light.ori, obj->light.pos));
	if (block_object(light, obj, light_distance))
		return (clr);
	shade_ratio = vec_dot(hit.dir, light.dir);
	hit.clr = shade_clr(hit.clr, obj->light.clr);
	hit.clr = ratio_clr(hit.clr, shade_ratio);
	clr = add_clr(clr, hit.clr);
	return (clamp_clr(clr));
}
