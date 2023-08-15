#include "minirt.h"

int	ambient_light(t_ambien amb)
{
	t_rgb	clr;

	clr.r = (amb.rgb.r * amb.ratio);
	clr.r = (amb.rgb.g * amb.ratio);
	clr.r = (amb.rgb.b * amb.ratio);
	return (rgb_to_clr(clr));
}