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

float	ft_min(float a, float b)
{
	if (a > b)
		return (b);
	return (a);
}

float	ft_radian(int degree)
{
	return ((float)degree * (M_PI / 180));
}

float	discriminant(float a, float b, float c)
{
	float	num;

	num = ft_pow2(b) - 4 * a * c;
	if (num < 0)
		return (-1);
	else if (num)
		return (num);
	else
		return (0);
}
