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
