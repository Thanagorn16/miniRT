#include "minirt.h"

float	ft_pow2(float num)
{
	return (num * num);
}

float	ft_abs(float num)
{
	if (num > 0)
		return (num);
	return (num * -1);
}

float	ft_radius(int degree)
{
	return ((float)degree * (M_PI / 180));
}

int	rgb_to_clr(t_rgb rgb)
{
	return ((rgb.r << 16) + (rgb.g << 8) + rgb.b);
}
