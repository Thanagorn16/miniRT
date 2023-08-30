#include "minirt.h"

static bool closest_cylender(t_ray ray, t_hpl *hit, t_cy cy, float t_closest)
{
	hit->distance = t_closest;
	hit->point = vec_add(ray.oc, vec_scalar(ray.dir, hit->distance)); // closest point of sphere on matrix
	hit->dir = vec_norm(hit->point);
	hit->point = vec_add(hit->point, cy.pos); // move hit point back to the real position
	hit->clr = cy.clr;
	hit->ctr = cy.pos;
	hit->hit = true;
	return (true);
}

static bool closest_disk(t_hpl *hit, t_cy cy, float denom, float distance)
{
	hit->distance = distance;
	hit->dir = cy.dir;
	if (denom > 0) // invert plane dir, Cause plane can see Top and Bot
		hit->dir = vec_scalar(hit->dir, -1);
	hit->clr = cy.clr;
	hit->hit = true;
	return (true);
}

bool disk_intersection(t_ray ray, t_hpl *hit, t_cy cy, int mode)
{
	float denom;
	float distance;
	t_cor tmp_hitpoint; // use tmp before calculate vec length ,So in false case hit-point will don't change value
	t_cor pos;

	cy.top = vec_add(cy.pos, vec_scalar(cy.dir, (cy.height / 2)));
	cy.bot = vec_sub(cy.pos, vec_scalar(cy.dir, (cy.height / 2)));
	if (vec_len(vec_sub(ray.ori, cy.top)) < vec_len(vec_sub(ray.ori, cy.bot)))
		pos = cy.top;
	else
		pos = cy.bot;
	denom = vec_dot(ray.dir, cy.dir);
	if (ft_abs(denom) < EPSILON)
		return (false);
	distance = vec_dot(vec_sub(pos, ray.ori), cy.dir) / denom;
	if (distance < 0.00f || distance > hit->distance)
		return (false);
	tmp_hitpoint = vec_add(ray.ori, vec_scalar(ray.dir, distance)); // closest point
	if (vec_len(vec_sub(tmp_hitpoint, pos)) > cy.radius)
		return (false);
	if (mode)
		return (true);
	hit->point = tmp_hitpoint;
	return (closest_disk(hit, cy, denom, distance));
}

// O is ray origin
// D is ray direction
// X is ray origin - Center point of object
// V is vector of cylender
// r = radius
// m = is a scalar that determines the closest point on the axis to the hit point.
// a = (D|D) - (D|V)^2
// b = 2 * ((D|X) - (D|V) * (X|V))
// c = X|X - (X|V)^2 - r*r
// t = hit distance
// m = D|V*t + X|V
bool hit_cylender(t_ray ray, t_hpl *hit, t_cy cy, int mode)
{
	t_fml	fml;
	float	disc;
	float	t_closest;

	ray.oc = vec_sub(ray.ori, cy.pos);
	fml.a = vec_dot(ray.dir, ray.dir) - ft_pow2(vec_dot(ray.dir, cy.dir));
	fml.b = 2 * (vec_dot(ray.dir, ray.oc) - vec_dot(ray.dir, cy.dir)
			* vec_dot(ray.oc, cy.dir));
	fml.c = vec_dot(ray.oc, ray.oc) - ft_pow2(vec_dot(ray.oc, cy.dir))
			- ft_pow2(cy.radius);
	disc = discriminant(fml.a, fml.b, fml.c);
	if (disc < 0.0f)
		return (false);
	t_closest = (-fml.b - sqrt(disc)) / (2 * fml.a); // closest distance from camera to sphere
	if (t_closest < 0.00f || t_closest > hit->distance)
		return (false);
	cy.m = vec_dot(ray.dir, cy.dir) * t_closest + vec_dot(ray.oc, cy.dir);
	if (cy.m > cy.height / 2 || cy.m < -(cy.height / 2)) // if equal maybe hit the edge of plane and it maybe don't saw it
		return (false);
	if (mode)
		return (true);
	return (closest_cylender(ray, hit, cy, t_closest));
}
