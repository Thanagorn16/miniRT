#include "minirt.h"

void	cmr_post(t_cmr cmr)
{
	printf("Camera position\n");
	printf("x:%f, y:%f, z:%f\n", cmr.post.x, cmr.post.y, cmr.post.z);
}

void	sphere_post(t_sph sph)
{
	printf("Sphere Info\n");
	printf("Post # x:%f, y:%f, z:%f\n", sph.post.x, sph.post.y, sph.post.z);
	printf("Radious : %f\n", sph.r);
}

void	debug_cor(t_cor cor, char *str)
{
	printf("%s -- x:%f, y:%f, z:%f\n", str, cor.x, cor.y, cor.z);
}

void	debug_rgb(t_rgb rgb, char *str)
{
	printf("%s -- x:%d, y:%d, z:%d\n", str, rgb.r, rgb.g, rgb.b);
}