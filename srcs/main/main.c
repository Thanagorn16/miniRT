#include "minirt.h"

int	main(void)
{
	t_param	par;
	t_obj	obj;
	t_rt	rt;

	// parse data
	create_rt(&rt);
	parsing(&rt, &obj);
	setting_camera(&par, rt.cam);
	// cmr_post(cmr); // debug

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
