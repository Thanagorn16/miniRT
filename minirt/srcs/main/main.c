#include "minirt.h"

int	render_sphere(t_ray *ray, t_sph *sph, int amt)
{
	t_rgb	rgb;
	int	i;

	i = 0;
	while (i < amt)
	{
		hit_sph(ray, sph[i]);
		i++;
	}
	return (true);
}

bool	render_object(t_ray *ray, t_obj obj)
{
	ray->clr = (t_rgb){0, 0, 0};
	ray->hit = false;
	ray->t_closest = 0;
	if (obj.amt.sph)
		render_sphere(ray, obj.sph, obj.amt.sph);
	if (ray->hit)
		shading(ray, obj.light);
	return (true);
}

bool	gen_ray(t_ray *ray, t_cmr cmr, float x, float y)
{
	ray->dir = vec_add(cmr.fpro, vec_scalar(cmr.hor, (x / WD_WIDTH)));
	ray->dir = vec_sub(ray->dir, vec_scalar(cmr.ver, (y / WD_HEIGHT)));
	return (true);
}

bool	ray_tracing(t_param par, t_obj obj)
{
	t_pix	pix;
	t_ray	ray; // vector ray that point to viewport map to pixel on screen

	pix.y = 0;
	ray.post = par.cmr.post;
	while (pix.y < WD_HEIGHT)
	{
		pix.x = 0;
		while (pix.x < WD_WIDTH)
		{
			gen_ray(&ray, par.cmr, pix.x, pix.y);
			render_object(&ray, obj);	
			pix.clr = rgb_to_clr(ray.clr);
			put_pixel_to_image(&par.img, pix);
			pix.x++;
		}
		pix.y++;
	}
	return (true);
}

int	main(void)
{
	t_param	par;
	t_obj	obj;

	// parse data
	t_rt rt = create_rt();
	parsing(rt, &obj);
	setting_camera(&par, rt.cam);
	// cmr_post(cmr); // debug

	// mlx init
	init_window(&par);
	create_image(&par);

	ray_tracing(par, obj);
	printf("Finish raytrace\n");

	mlx_put_image_to_window(par.mlx, par.win, par.img.ptr, 0, 0);
	mlx_hook(par.win, 2, 1L << 0, key_hook, &par);
	mlx_hook(par.win, 17, 0, close_win, &par);
	mlx_loop(par.mlx);
}
