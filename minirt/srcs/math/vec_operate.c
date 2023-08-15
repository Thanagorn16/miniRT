#include "minirt.h"

t_cor	vec_add(t_cor a, t_cor b)
{
	t_cor	vec;

	vec.x = a.x + b.x;
	vec.y = a.y + b.y;
	vec.z = a.z + b.z;
	return (vec);
}

t_cor	vec_sub(t_cor a, t_cor b)
{
	t_cor	vec;

	vec.x = a.x - b.x;
	vec.y = a.y - b.y;
	vec.z = a.z - b.z;
	return (vec);
}

t_cor	vec_scalar(t_cor vec, float t)
{
	vec.x *= t;
	vec.y *= t;
	vec.z *= t;
	return (vec);
}

t_cor	vec_norm(t_cor vec)
{
	float	vec_length;

	vec_length = sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
	vec.x /= vec_length;
	vec.y /= vec_length;
	vec.z /= vec_length;
	return (vec);
}
