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

t_hpl	miss(void)
{
	t_hpl	hit;

	hit.distance = -1.00f;
	return (hit);
}

bool	hit_object(t_ray ray, t_hpl *hit, t_obj *obj)
{
	int	i;

	hit->distance = FLT_MAX;
	hit->hit = false;
	i = 0;
	while (i < obj->amt.sp)
		hit_sphere(ray, hit, obj->sp[i++]);
	i = 0;
	while (i < obj->amt.pl)
		hit_plane(ray, hit, obj->pl[i++]);
	i = 0;
	while (i < obj->amt.cy)
		hit_cylender(ray, hit, obj->cy[i++]);
	if (!hit->hit)
		return (hit->distance = -1.00f, false);
	return (true);
}

static int	ray_tracing(t_ray ray, t_obj *obj)
{
	t_hpl	hit;
	t_rgb	clr = {0,0,0};
	t_rgb	tmp = {0,0,0};
	float	mul = 1.0f;
	t_rgb	sky_clr = {0,0,0};

	for (int i = 0; i < 1; i++)
	{
		hit_object(ray, &hit, obj);
		if (hit.distance < 0)
		{
			clr = add_clr(clr, sky_clr);
			break ;
		}
		tmp = ambient_light(clr, hit.clr, obj->ambient);
		tmp = point_light(tmp, hit, obj->light);
		clr = add_clr(clr, ratio_clr(tmp, mul));
		mul *= 0.7f;
		// ray = reflect_ray(ray, &hit, obj->light);
	}
	// if (!shadowing(&hit, obj, obj.light))
	// 	return (0);
	return (rgb_to_clr(clr));
}

bool	render_scene(t_param par, t_obj *obj)
{
	t_pix		pix;
	t_ray		ray; // vector ray that point to viewport map to pixel on screen

	pix.y = 0;
	while (pix.y < WD_HEIGHT)
	{
		pix.x = 0;
		while (pix.x < WD_WIDTH)
		{
			ray = gen_ray(par.cmr, pix.x, pix.y);
			pix.clr = ray_tracing(ray, obj);	
			put_pixel_to_image(&par.img, pix);
			pix.x++;
		}
		pix.y++;
	}
	return (true);
}
