/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:51:15 by tnantaki          #+#    #+#             */
/*   Updated: 2023/09/18 17:09:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Generate ray direction that shooting to all pixel
t_ray	gen_ray(t_cmr cmr, float x, float y)
{
	t_ray	ray;

	ray.ori = cmr.post;
	ray.dir = vec_add(cmr.fpro, vec_scalar(cmr.hor, (x / WD_WIDTH)));
	ray.dir = vec_sub(ray.dir, vec_scalar(cmr.ver, (y / WD_HEIGHT)));
	ray.dir = vec_norm(ray.dir);
	return (ray);
}

bool	hit_object(t_ray ray, t_hpl *hit, t_obj *obj)
{
	int	i;

	hit->distance = FLT_MAX;
	hit->hit = false;
	i = 0;
	while (i < obj->amt.sp)
		hit_sphere(ray, hit, &obj->sp[i++], 0);
	i = 0;
	while (i < obj->amt.pl)
		hit_plane(ray, hit, &obj->pl[i++], 0);
	i = 0;
	while (i < obj->amt.cy)
	{
		hit_cylinder(ray, hit, &obj->cy[i], 0);
		disk_intersection(ray, hit, &obj->cy[i++], 0);
	}
	if (!hit->hit)
		return (hit->distance = -1.00f, false);
	return (true);
}

static int	ray_tracing(t_ray ray, t_obj *obj)
{
	t_hpl	hit;
	t_rgb	clr;
	t_rgb	tmp;
	float	mul;

	mul = 1.0f;
	clr = (t_rgb){0, 0, 0};
	tmp = (t_rgb){0, 0, 0};
	hit_object(ray, &hit, obj);
	if (hit.distance < 0)
		return (rgb_to_clr(obj->ambient));
	tmp = ambient_light(clr, hit.clr, obj->ambient);
	tmp = shadowing(tmp, hit, obj);
	clr = add_clr(clr, ratio_clr(tmp, mul));
	return (rgb_to_clr(clr));
}

// ray that point to viewport map to pixel on screen
int	render_scene(t_param *par)
{
	t_pix	pix;
	t_ray	ray;

	pix.y = 0;
	if (par->obj.amt.cy)
		cy_position(&par->obj.cy, par->obj.amt.cy);
	while (pix.y < WD_HEIGHT)
	{
		pix.x = 0;
		while (pix.x < WD_WIDTH)
		{
			ray = gen_ray(par->cmr, pix.x, pix.y);
			pix.clr = ray_tracing(ray, &par->obj);
			put_pixel_to_image(&par->img, pix);
			pix.x++;
		}
		pix.y++;
	}
	mlx_put_image_to_window(par->mlx, par->win, par->img.ptr, 0, 0);
	// par->current = get_elapse_time(); // framerate
	// printf("Frame rate : %ld ms\n", (par->current - par->start)/ 1000); // framerate
	// par->start = par->current; // framerate
	return (true);
}
