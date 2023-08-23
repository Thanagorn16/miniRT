#include "minirt.h"

bool	init_object(t_rt *rt, t_obj *obj)
{
	obj->light.clr = ratio_clr(rt->light.clr, rt->light.ratio);
	obj->light.pos = rt->light.pos;
	obj->ambient = ratio_clr(rt->amb.clr, rt->amb.ratio);
	obj->amt = rt->amt;
	obj->sp = rt->sp;
	obj->pl = rt->pl;
	obj->cy = rt->cy;
	return (true);
}

int	main(int ac, char **av)
{
	t_param	par;
	t_obj	obj;
	t_rt	rt;

	if (parsing(ac, av, &rt))
		return (1);
	init_object(&rt, &obj);
	// parse data
	// create_rt(&rt);
	setting_camera(&par, rt.cam);
	// cmr_post(par.cmr); // debug
	debug_cor(obj.sp[0].pos, "sp: ");
	printf("radius: %f\n", obj.sp[0].radius);
	// exit(0);

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
