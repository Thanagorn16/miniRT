#include "minirt.h"

bool	setting_cylender(t_obj *obj)
{
	int	i;

	i = 0;
	while (i < obj->amt.cy)
	{
		obj->cy[i].dir = vec_norm(obj->cy[i].dir);
		obj->cy[i].top = vec_add(obj->cy[i].pos,
			vec_scalar(obj->cy[i].dir, (obj->cy[i].height / 2)));
		obj->cy[i].bot = vec_sub(obj->cy[i].pos,
			vec_scalar(obj->cy[i].dir, (obj->cy[i].height / 2)));
		// debug_cor(obj->cy[i].pos, "pos");
		// debug_cor(obj->cy[i].dir, "dir");
		// debug_cor(obj->cy[i].top, "top");
		// debug_cor(obj->cy[i].bot, "bot");
		// printf("height: %f , width: %f\n", obj->cy[i].height, obj->cy[i].dia);
		i++;
	}
	return (true);
}

bool	setting_plane(t_obj *obj)
{
	int	i;

	i = 0;
	while (i < obj->amt.pl)
	{
		obj->pl[i].dir = vec_norm(obj->pl[i].dir);
		i++;
	}
	return (true);
}

bool	init_object(t_rt *rt, t_obj *obj)
{
	obj->light.clr = ratio_clr(rt->light.clr, rt->light.ratio);
	obj->light.pos = rt->light.pos;
	obj->ambient = ratio_clr(rt->amb.clr, rt->amb.ratio);
	obj->amt = rt->amt;
	obj->sp = rt->sp;
	obj->pl = rt->pl;
	obj->cy = rt->cy;
	setting_cylender(obj);
	setting_plane(obj);
	return (true);
}

void	testing_obj(t_obj obj)
{
	t_ray	ray;
	ray.dir = (t_cor){0,0,-1};
	ray.ori = (t_cor){0,0,10};

	test_ray_point(ray, obj.cy, NULL, NULL, 0);
	// test_ray_point(ray, NULL, obj.sp, NULL, 0);
	exit(0);
}

int	main(int ac, char **av)
{
	t_param	par;
	t_obj	obj;
	t_rt	rt;

	if (parsing(ac, av, &rt))
		return (1);
	init_object(&rt, &obj);
	setting_camera(&par, rt.cam);

	// testing_obj(obj);
	// mlx init
	init_window(&par);
	create_image(&par);

	render_scene(par, &obj);
	printf("Finish raytrace\n");

	mlx_put_image_to_window(par.mlx, par.win, par.img.ptr, 0, 0);
	mlx_hook(par.win, 2, 1L << 0, key_hook, &par);
	mlx_hook(par.win, 17, 0, close_win, &par);
	mlx_loop(par.mlx);
}
