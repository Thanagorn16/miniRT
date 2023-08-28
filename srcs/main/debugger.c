#include "minirt.h"

void	cmr_post(t_cmr cmr)
{
	printf("Camera position\n");
	printf("x:%f, y:%f, z:%f\n", cmr.post.x, cmr.post.y, cmr.post.z);
}

void	sphere_post(t_sp sp)
{
	printf("Sphere Info\n");
	printf("Post # x:%f, y:%f, z:%f\n", sp.pos.x, sp.pos.y, sp.pos.z);
	printf("Radious : %f\n", sp.radius);
}

void	debug_cor(t_cor cor, char *str)
{
	printf("%s -- x:%f, y:%f, z:%f\n", str, cor.x, cor.y, cor.z);
}

void	debug_rgb(t_rgb rgb, char *str)
{
	printf("%s -- x:%d, y:%d, z:%d\n", str, rgb.r, rgb.g, rgb.b);
}

void	ptr_cor(t_cor cor)
{
	printf("x:%f, y:%f, z:%f", cor.x, cor.y, cor.z);
}

void	test_ray_point(t_ray ray, t_cy* cy, t_sp* sp, t_pl* pl, int mode)
{
	t_hpl	hit;

	hit.distance = FLT_MAX;
	hit.hit = false;
	if (cy)
		hit_cylender(ray, &hit, *cy, mode);
	else if (sp)
		hit_sphere(ray, &hit, *sp, mode);
	else if (pl)
		hit_plane(ray, &hit, *pl, mode);
	debug_cor(hit.point, "hitpoint-");
	debug_cor(hit.dir, "hitdir-");
	printf("distance: %f\n", hit.distance);
}