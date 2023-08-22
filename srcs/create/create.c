// ***************************************************************** //
// ---------------- This Part get info from Parsing ---------------- //
// ***************************************************************** //
#include "minirt.h"

t_sp	create_one_sphere(t_cor pos, t_rgb clr, float dia)
{
	t_sp	sp;

	sp.pos = pos;
	sp.clr = clr;
	sp.radius = dia / 2;
	return (sp);
}

t_pl	create_one_plane(t_cor pos, t_cor dir, t_rgb clr)
{
	t_pl	pl;

	pl.pos = pos;
	pl.dir = dir;
	pl.clr = clr;
	return (pl);
}

t_cam	create_camera(void)
{
	t_cam	cam;

	cam.pos.x = 0; // transpose to be center of viewport
	cam.pos.y = 0.2; // transpose to be center of viewport
	cam.pos.z = 7; // step back from viewport 1 unit.
	cam.dir.x = 0; // from parsing
	cam.dir.y = -0.2; // from parsing
	cam.dir.z = -1; // from parsing
	cam.fov = 45;
	return (cam);
}

t_sp	*create_sphere(int *num)
{
	*num = 2;


	t_sp *sp = malloc(sizeof(t_sp) * *num);
	// sp[0] = create_one_sphere((t_cor){0.8,0,-5}, (t_rgb){255,0,255}, 1);
	// sp[1] = create_one_sphere((t_cor){7,0,-5}, (t_rgb){0,0,255}, 10);
	// sp[0] = create_one_sphere((t_cor){0.3,0.3,0.3}, (t_rgb){255,0,255}, 1);
	// sp[1] = create_one_sphere((t_cor){2,-5,0}, (t_rgb){0,255,0}, 10);
	sp[0] = create_one_sphere((t_cor){0,0,0}, (t_rgb){255,0,255}, 1);
	sp[1] = create_one_sphere((t_cor){0,-5.6,0}, (t_rgb){0,0,255}, 10);
	// obj->sp[1] = init_sphere(1, -1, 0, 0.5, BLUE_PIXEL);
	// obj->sp[2] = init_sphere(-1, -0.5, -2, 0.5, GREEN_PIXEL);
	// obj->sp[3] = init_sphere(1, -0.5, -2, 0.5, PURPLE_PIXEL);
	return (sp);
}

t_pl	*create_plane(int *num)
{
	*num = 1;

	t_pl *pl = malloc(sizeof(t_pl) * *num);
	pl[0] = create_one_plane((t_cor){0,-1.2,0}, (t_cor){0,1,0}, (t_rgb){255,255,0});
	return (pl);
}

t_light	create_light(void)
{
	t_light	light;

	light.pos.x = 3;
	light.pos.y = 3;
	light.pos.z = 3;
	light.clr = (t_rgb){255, 255, 255};
	light.ratio = 0.9f;
	return (light);
}

t_ambien	create_ambeint(void)
{
	t_ambien	amb;

	amb.ratio = 0.3;
	amb.clr = (t_rgb){255, 255, 255};
	return (amb);
}

void	create_rt(t_rt *rt)
{
	rt->cam = create_camera();
	rt->light = create_light();
	rt->amb = create_ambeint();
	rt->sp = create_sphere(&rt->amt.sp);
	rt->pl = create_plane(&rt->amt.pl);
}
