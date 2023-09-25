// ********************************************************** //
// ------------------ This Part Just Testing ---------------- //
// ********************************************************** //

#include "minirt.h"

void	circle(t_image *img)
{
	float	radius = 300;
	float	h = WD_HEIGHT / 2;
	float	w = WD_WIDTH / 2;
	float	cx = -400;
	float	cy = +400;

	for (int y = 0; y < WD_HEIGHT; y++)
	{
		for (int x = 0; x < WD_WIDTH; x++)
		{
			if (pow(x - w - cx, 2) + pow(h - y - cy, 2) <= pow(radius, 2))
			{
				t_pix pix = {x, y, RED_PIXEL};
				put_pixel_to_image(img, pix);
			}
		}
	}
}

int	convert2rgb(t_cor vec)
{
	int	clr;
	int	r = 0;
	int	g = 0;
	int b = 0;

	vec = vec_add(vec_scalar(vec, 0.5), (t_cor){0.5, 0.5, 0.5});
	if (vec.x > 0)
		r = (int)(vec.x * 255);
	if (vec.y > 0)
		g = (int)(vec.y * 255);
	if (vec.z > 0)
		b = (int)(vec.z * 255);
	clr = (r << 16) | (g << 8) | b;
	return (clr);
}

t_axis	test_rotate(t_axis old, int degree)
{
	t_axis	new;
	float	radian;
	float	sine;
	float	cosine;

	radian = ft_radian(degree);
	sine = sinf(radian);
	cosine = cosf(radian);
	new.hor = old.hor;
	// new.y = old.y * cosine - old.z * sine;
	new.ver = vec_sub(vec_scalar(old.ver, cosine), vec_scalar(old.dir, sine));
	// new.z = old.y * sine + old.z * cosine;
	new.dir = vec_add(vec_scalar(old.ver, sine), vec_scalar(old.dir, cosine));
	debug_cor(new.dir, "axis.dir: ");
	debug_cor(new.hor, "axis.hor: ");
	debug_cor(new.ver, "axis.ver: ");
	return (new);
}

// Change the hitpoint position a little bit
// for not reflect to the surface of yourseft.
t_ray reflect_ray(t_ray ray, t_hpl *hit, t_light light)
{
	t_ray	reflect;
	t_cor	diff;

	reflect.ori = vec_add(hit->point, vec_scalar(hit->dir, EPSILON));
	reflect.dir = vec_scalar(ray.dir, -1); // invert ray direction
	diff = vec_sub(hit->dir, reflect.dir);
	reflect.dir = vec_norm(vec_add(hit->dir, diff));
	return (reflect);
}