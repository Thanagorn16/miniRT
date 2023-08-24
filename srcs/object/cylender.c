#include "minirt.h"

static bool	closest_cylender(t_ray ray, t_hpl *hit, t_cy cy, float t_closest)
{
	hit->distance = t_closest;
	hit->point = vec_add(ray.ori, vec_scalar(ray.dir, hit->distance)); // closest point of sphere on matrix
	hit->dir = vec_norm(hit->point);
	hit->point = vec_add(hit->point, cy.pos); // move hit point back to the real position
	hit->clr = cy.clr;
	hit->ctr = cy.pos;
	hit->hit = true;
	return (true);
}

static bool	cylender_cap(t_ray ray, t_hpl *hit, t_cy cy, float t_closest)
{
	return (false); // Test
	float	denom;
	float	distance;

	if (cy.m > 0)
		cy.pos = cy.top;
	else
		cy.pos = cy.bot;
	denom = vec_dot(ray.dir, cy.dir);
	if ((denom >= 0 && denom < EPSILON) || (denom <= 0 && denom > -EPSILON))
		return (false);
	distance = vec_dot(vec_sub(cy.pos, ray.ori), cy.dir) / denom;
	if (distance > 0.00f && distance < hit->distance)
	{
		hit->point = vec_add(ray.ori, vec_scalar(ray.dir, distance)); // closest point of sphere on matrix
		hit->point = vec_add(hit->point, ray.ori); // move hit point back to the real position
		hit->dir = vec_norm(cy.dir);
		if (denom > 0)
			hit->dir = vec_scalar(hit->dir, -1);
		hit->clr = cy.clr;
		hit->hit = true;
		// if ()
		// 	return (true);
		return (false);
	}
	return (false);
}

// bool	hit_disk(t_ray ray, t_hpl *hit, t_cy cy)
// {
// 	// vec_dot(ray.dir, cy.dir) * t + vec_dot(ray.ori, cy.dir);
// 	float	dis_top;
// 	float	dis_bot;

// 	dis_top = vec_dot(vec_sub(cy.top, ray.ori), cy.dir) / denom;
// 	denom = vec_dot(ray.dir, cy.bot);
// 	if ((denom >= 0 && denom < EPSILON) || (denom <= 0 && denom > -EPSILON))
// 		return (false);
// 	dis_bot = vec_dot(vec_sub(cy.bot, ray.ori), cy.dir) / denom;
// 	hit->distance = ft_min(dis_top, dis_bot);

// // 		hit->point = vec_add(ray.ori, vec_scalar(ray.dir, distance)); // closest point of sphere on matrix
// // 		hit->point = vec_add(hit->point, ray.ori); // move hit point back to the real position
// // 		hit->dir = vec_norm(pl.dir);
// // 		if (denom > 0)
// // 			hit->dir = vec_scalar(hit->dir, -1);
// // 		hit->clr = pl.clr;
// // 		hit->hit = true;
// // 		return (true);
// 	}
// 	return (false);
// }

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
bool	hit_cylender(t_ray ray, t_hpl *hit, t_cy cy)
{
	t_fml	fml;
	float	disc;
	float	t_closest;

	ray.ori = vec_sub(ray.ori, cy.pos);
	fml.a = vec_dot(ray.dir, ray.dir) - ft_pow2(vec_dot(ray.dir, cy.dir));
	fml.b = 2 * (vec_dot(ray.dir, ray.ori) - vec_dot(ray.dir, cy.dir)
		* vec_dot(ray.ori, cy.dir));
	fml.c = vec_dot(ray.ori, ray.ori) - ft_pow2(vec_dot(ray.ori, cy.dir)) - ft_pow2(cy.radius);
	disc = discriminant(fml.a, fml.b, fml.c);
	if (disc < 0.0f)
		return (false);
	t_closest = (-fml.b - sqrt(disc)) / (2 * fml.a); // closest distance from camera to sphere
	// if (t_closest < 0)
	// 	t_closest = (-qf.b + sqrt(qf.disc)) / (2 * qf.a);
	if (t_closest > 0.00f && t_closest < hit->distance)
	{
		cy.m = vec_dot(ray.dir, cy.dir) * t_closest + vec_dot(ray.ori, cy.dir);
		if (cy.m > cy.height / 2 || cy.m < -(cy.height / 2))
			return (cylender_cap(ray, hit, cy, t_closest));
		return (closest_cylender(ray, hit, cy, t_closest));
	}
	return (false);
}
