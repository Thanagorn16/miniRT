#include "minirt.h"

bool	hit_plane(t_ray ray, t_hpl *hit, t_pl pl)
{
	float	denom;
	float	distance;

	denom = vec_dot(ray.dir, pl.dir);
	if ((denom >= 0 && denom < EPSILON) || (denom <= 0 && denom > -EPSILON))
		return (false);
	distance = vec_dot(vec_sub(pl.pos, ray.ori), pl.dir) / denom;
	if (distance >= 0)
	{
		hit->point = vec_add(ray.ori, vec_scalar(ray.dir, distance)); // closest point of sphere on matrix
		hit->point = vec_add(hit->point, ray.ori); // move hit point back to the real position
		hit->dir = vec_norm(pl.dir);
		if (denom > 0)
			hit->dir = vec_scalar(hit->dir, -1);
		hit->clr = pl.clr;
		hit->hit = true;
		return (true);
	}
	return (false);
}
