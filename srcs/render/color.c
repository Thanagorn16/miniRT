#include "minirt.h"

t_rgb	clamp_clr(t_rgb clr)
{
	if (clr.r > 255)
		clr.r = 255;
	if (clr.g > 255)
		clr.g = 255;
	if (clr.b > 255)
		clr.b = 255;
	return (clr);
}

t_rgb	shade_clr(t_rgb clr, t_rgb shade)
{
	clr.r = (clr.r * shade.r) >> 8;
	clr.g = (clr.g * shade.g) >> 8;
	clr.b = (clr.b * shade.b) >> 8;
	return (clr);
}

t_rgb	add_clr(t_rgb clr, t_rgb add)
{
	clr.r += add.r;
	clr.g += add.g;
	clr.b += add.b;
	return (clr);
}

t_rgb	ratio_clr(t_rgb light, float ratio)
{
	if (ratio < 0)
		ratio = 0;
	light.r *= ratio;
	light.g *= ratio;
	light.b *= ratio;
	return (light);
}

int	rgb_to_clr(t_rgb clr)
{
	clr = clamp_clr(clr);
	return ((clr.r << 16) + (clr.g << 8) + clr.b);
}