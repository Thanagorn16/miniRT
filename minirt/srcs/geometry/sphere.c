#include "minirt.h"

typedef struct s_quadratic_formula
{
	float	a;
	float	b;
	float	c;
}	t_qf;

float	discriminant(t_qf qf)
{
	float	num;

	num = ft_pow2(qf.b) - 4 * qf.a * qf.c;
	if (num < 0)
		return (-1);
	else if (num)
		return (num);
	else
		return (0);
}

// (dx^2 + dy^2 + dz^2)t^2 + (2(ox * dx + oy * dy))t + (ox^2 + oy^2 - r^2) = 0
// o = ray orignal (position of camera)
// d = ray direction (circle rigion)
// r = radius
// t = hit distance
bool	hit_sph(t_ray *ray, t_sph sph)
{
	t_cor	direc;
	t_cor	origin;
	t_qf	qf;
	float	t_closest;
	float	disc;

	// Because Sphere formular working on x,y,z cartesian, So center will be zero
	// That also mean we can't move the sphere, But we can move the camera instead
	// Origin is the position of camera
	origin = vec_sub(ray->post, sph.post);
	direc = vec_norm(ray->dir);
	qf.a = vec_dot(direc, direc);
	qf.b = 2 * vec_dot(origin, direc);
	qf.c = vec_dot(origin, origin) - ft_pow2(sph.r);
	disc = discriminant(qf);
	if (disc >= 0)
	{
		// float	t_farest = (-b + sqrt(disc)) / (2 * a);
		t_closest = (-qf.b - sqrt(disc)) / (2 * qf.a); // closest distance from camera to sphere
		if (!(ray->hit))
			ray->t_closest = t_closest;
		if (ray->t_closest >= t_closest) // the only one closest object will be see
		{
			ray->hit = true;
			ray->hitpoint = vec_add(origin, vec_scalar(direc, t_closest)); // closest point of sphere on matrix
			ray->clr = sph.clr;
			ray->postobj = sph.post;
		}
		return (true);
	}
	return (false);
}
