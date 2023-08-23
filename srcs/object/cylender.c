#include "minirt.h"

static float	discriminant(float a, float b, float c)
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

static bool	closest_cylender(t_ray ray, t_hpl *hit, t_cy cy)
{
	hit->point = vec_add(ray.ori, vec_scalar(ray.dir, hit->distance)); // closest point of sphere on matrix
	hit->dir = vec_norm(hit->point);
	hit->point = vec_add(hit->point, cy.pos); // move hit point back to the real position
	hit->clr = cy.clr;
	hit->ctr = cy.pos;
	hit->hit = true;
	return (true);
}

// m = D|V * t + X|V
// bool	hit_disk(t_ray ray, t_hpl *hit, t_cy cy)
// {
// 	// vec_dot(ray.dir, cy.dir) * t + vec_dot(ray.ori, cy.dir);
// 	float	denom;
// 	float	dis_top;
// 	float	dis_bot;

// 	denom = vec_dot(ray.dir, cy.top);
// 	if ((denom >= 0 && denom < EPSILON) || (denom <= 0 && denom > -EPSILON))
// 		return (false);
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

// static bool	cylender_cap(t_ray ray, t_hpl *hit, t_cy cy)
// {

// 	return (true);
// }

// O is ray origin
// D is ray direction
// X is ray origin - Center point of object
// V is vector of cylender
// r = radius

// a = (D|D) - (D|V)^2
// b = 2 * ((D|X) - (D|V) * (X|V))
// c = X|X - (X|V)^2 - r*r
// t = hit distance
// Because Sphere formular working on x,y,z cartesian, So center will be zero
// That also mean we can't move the sphere, But we can move the camera instead
// Origin is the position of camera
bool	hit_cylender(t_ray ray, t_hpl *hit, t_cy cy)
{
	float	a;
	float	b;
	float	c;
	float	disc;
	float	t_closest;

	ray.ori = vec_sub(ray.ori, cy.pos);
	a = vec_dot(ray.dir, ray.dir) - ft_pow2(vec_dot(ray.dir, cy.dir));
	b = 2 * (vec_dot(ray.dir, ray.ori) - vec_dot(ray.dir, cy.dir)
		* vec_dot(ray.ori, cy.dir));
	c = vec_dot(ray.ori, ray.ori) - ft_pow2(vec_dot(ray.ori, cy.dir)) - ft_pow2(cy.radius);
	disc = discriminant(a, b, c);
	if (disc < 0.0f)
		return (false);
	t_closest = (-b - sqrt(disc)) / (2 * a); // closest distance from camera to sphere
	// if (t_closest < 0)
	// 	t_closest = (-qf.b + sqrt(qf.disc)) / (2 * qf.a);
	if (t_closest > 0.00f && t_closest < hit->distance)
	{
		hit->distance = t_closest;
		closest_cylender(ray, hit, cy);
		return (true);
	}
	return (false);
}
