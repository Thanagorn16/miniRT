#include "minirt.h"

t_rgb	relative_ambient(t_rgb clr, t_rgb amb)
{
	clr.r = (clr.r * amb.r) >> 0x10;
	clr.g = (clr.g * amb.g) >> 0x10;
	clr.b = (clr.b * amb.b) >> 0x10;
	return (clr);
}

static t_rgb	shade_clr(t_rgb clr, float shade)
{
	clr.r *= shade;
	clr.g *= shade;
	clr.b *= shade;
	return (clr);
}

bool	shading(t_ray *ray, t_light light)
{
	static int i = 0;
	t_cor	lightdir;
	t_cor	hitdir;
	float	shade;

	light.pos = vec_sub(light.pos, ray->postobj); // move light post instead of move obj
	lightdir = vec_norm(light.pos);
	if (i++ == 0)
	{
		printf("-----------------------------------------------\n");
		debug_cor(light.pos, "light pos: ");
		debug_cor(lightdir, "light dir: ");
	}
	hitdir = vec_norm(ray->hitpoint); // We don't have to subtract because Center of object is 0, 0, 0
	shade = vec_dot(lightdir, hitdir);
	if (shade < 0)
		ray->clr = (t_rgb){0, 0, 0};
	ray->clr = shade_clr(ray->clr, shade);
	return (true);
}
