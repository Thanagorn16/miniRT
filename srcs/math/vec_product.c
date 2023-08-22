#include "minirt.h"

float	vec_dot(t_cor a, t_cor b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_cor	vec_cross(t_cor a, t_cor b)
{
	t_cor	vec;

	vec.x = a.y * b.z - a.z * b.y;
	vec.y = a.z * b.x - a.x * b.z;
	vec.z = a.x * b.y - a.y * b.x;
	return (vec);
}
