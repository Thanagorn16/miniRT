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

float	vec_len(t_cor vec)
{
	return (sqrt(ft_pow2(vec.x) + ft_pow2(vec.y) + ft_pow2(vec.z)));
}

t_cor	vec_norm(t_cor vec)
{
	float	length;

	length = vec_len(vec);
	vec.x /= length;
	vec.y /= length;
	vec.z /= length;
	return (vec);
}
