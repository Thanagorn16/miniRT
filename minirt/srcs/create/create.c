// ***************************************************************** //
// ---------------- This Part get info from Parsing ---------------- //
// ***************************************************************** //
#include "minirt.h"

t_sp	create_one_sphere(t_cor cor, t_rgb rgb, float radius)
{
	t_sp	sp;

	sp.cor = cor;
	sp.rgb = rgb;
	sp.radius = radius;
	return (sp);
}

t_cam	create_camera(void)
{
	t_cam	cam;

	cam.pos.x = 0; // transpose to be center of viewport
	cam.pos.y = 0; // transpose to be center of viewport
	cam.pos.z = 3; // step back from viewport 1 unit.
	cam.dir.x = 0; // from parsing
	cam.dir.y = 0; // from parsing
	cam.dir.z = -1; // from parsing
	cam.fov = 45;
	return (cam);
}

t_sp	*create_sphere(int	*nsp)
{
	*nsp = 2;


	t_sp *sp = malloc(sizeof(t_sp) * *nsp);
	sp[0] = create_one_sphere((t_cor){0,0,0}, (t_rgb){255,0,255}, 0.8);
	sp[1] = create_one_sphere((t_cor){0.3,0.3,0.2}, (t_rgb){0,255,0}, 0.5);
	// obj->sp[1] = init_sphere(1, -1, 0, 0.5, BLUE_PIXEL);
	// obj->sp[2] = init_sphere(-1, -0.5, -2, 0.5, GREEN_PIXEL);
	// obj->sp[3] = init_sphere(1, -0.5, -2, 0.5, PURPLE_PIXEL);
	return (sp);
}

t_light	create_light(void)
{
	t_light	light;

	light.pos.x = 0.5;
	light.pos.y = 0.5;
	light.pos.z = 1;
	light.rgb = (t_rgb){255, 255, 255};
	light.ratio = 1.0f;
	return (light);
}

t_ambien	create_ambeint(void)
{
	t_ambien	amb;

	amb.ratio = 0.5;
	amb.rgb = (t_rgb){255, 0, 0};
	return (amb);
}

t_rt	create_rt(void)
{
	t_rt	rt;

	rt.cam = create_camera();
	rt.light = create_light();
	rt.amb = create_ambeint();
	rt.sp = create_sphere(&rt.nsp);
	return (rt);
}
