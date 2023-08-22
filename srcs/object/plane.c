#include "minirt.h"

bool	hit_plane(t_ray ray, t_hpl *hit, t_pl pl)
{
	float	denom;
	float	distance;

	denom = vec_dot(ray.dir, pl.dir);
	if (denom < EPSILON)
	{
		distance = vec_dot(vec_sub(pl.pos, ray.ori), pl.dir) / denom;
		if (distance >= 0)
		{
			hit->point = vec_add(ray.ori, vec_scalar(ray.dir, distance)); // closest point of sphere on matrix
			hit->dir = vec_norm(hit->point);
			hit->point = vec_add(hit->point, pl.pos); // move hit point back to the real position
			hit->clr = pl.clr;
			hit->hit = true;
			return (true);
		}
	}
	return (false);
}
