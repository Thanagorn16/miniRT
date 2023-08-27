#include "minirt.h"

bool	hit_plane(t_ray ray, t_hpl *hit, t_pl pl)
{
	float	denom;
	float	distance;

	denom = vec_dot(ray.dir, pl.dir);
	if ((denom >= 0 && denom < EPSILON) || (denom <= 0 && denom > -EPSILON))
		return (false);
	distance = vec_dot(vec_sub(pl.pos, ray.ori), pl.dir) / denom;
	if (distance < 0.00f || distance > hit->distance)
		return (false);
	hit->distance = distance;
	hit->point = vec_add(ray.ori, vec_scalar(ray.dir, distance)); // closest point
	hit->dir = pl.dir;
	if (denom > 0) // invert plane dir, Cause plane can see Top and Bot
		hit->dir = vec_scalar(hit->dir, -1);
	hit->clr = pl.clr;
	hit->hit = true;
	return (true);
}
