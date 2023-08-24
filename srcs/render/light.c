#include "minirt.h"

// Ambient light contribute every light of every point in the scene
t_rgb	ambient_light(t_rgb clr, t_rgb objclr, t_rgb amb)
{
	objclr = shade_clr(objclr, amb);
	clr = add_clr(clr, objclr);
	return (clamp_clr(clr));
}

// Point light will create shade and shadow effect to object
t_rgb	point_light(t_rgb clr, t_hpl hit, t_light light)
{
	t_cor	lightdir;
	float	shade_ratio;

	lightdir = vec_sub(light.pos, hit.point); // invert light direction
	lightdir = vec_norm(lightdir);
	shade_ratio = vec_dot(hit.dir, lightdir);
	hit.clr = shade_clr(hit.clr, light.clr);
	hit.clr = ratio_clr(hit.clr, shade_ratio);
	clr = add_clr(clr, hit.clr);
	// static int i = 0;
	// if (i++ <= 5)
	// {
	// 	debug_cor(light.pos, "lightpos");
	// 	printf("shade ratio: %f\n", shade_ratio);
	// 	debug_rgb(light.clr, "light");
	// }
	return (clamp_clr(clr));
}

t_ray	reflect_ray(t_ray ray, t_hpl *hit, t_light light)
{
	t_ray	reflect;
	t_cor	diff;

	// Change the hitpoint position a little bit
	// for not reflect to the surface of yourseft.
	reflect.ori = vec_add(hit->point, vec_scalar(hit->dir, EPSILON));
	reflect.dir = vec_scalar(ray.dir, -1); // invert ray direction
	diff = vec_sub(hit->dir, reflect.dir);
	reflect.dir = vec_norm(vec_add(hit->dir, diff));
	return (reflect);
}
