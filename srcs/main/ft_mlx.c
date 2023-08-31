#include "minirt.h"

bool	init_window(t_param *par)
{
	par->mlx = mlx_init();
	if (par->mlx == NULL)
	{
		// free something
		return (false);
	}
	par->win = mlx_new_window(par->mlx, WD_WIDTH, WD_HEIGHT, "miniRT");
	if (par->win == NULL)
	{
		// free something
		free(par->mlx);
		return (false);
	}
	return (true);
}

int	close_win(t_param *par)
{
	mlx_destroy_image(par->mlx, par->img.ptr);
	mlx_destroy_window(par->mlx, par->win);
	free(par->mlx);
	exit (0);
	return (0);
}

bool	create_image(t_param *par)
{
	par->img.ptr = mlx_new_image(par->mlx, WD_WIDTH, WD_HEIGHT);
	if (par->img.ptr == NULL)
	{
		mlx_destroy_window(par->mlx, par->win);
		free(par->mlx);
		return (false);
	}
	par->img.addr = mlx_get_data_addr(par->img.ptr, &par->img.bpp,
			&par->img.line_len, &par->img.endian);
	par->img.bpp /= 8;
	return (true);
}

void	put_pixel_to_image(t_image *img, t_pix pix)
{
	unsigned int	*dst;

	if (pix.x >= 0 && pix.x < WD_WIDTH && pix.y >= 0 && pix.y < WD_HEIGHT)
	{
		dst = img->addr + ((int)pix.y * img->line_len + (int)pix.x * img->bpp);
		*dst = (unsigned int)pix.clr;
	}
}

int	key_hook(int keycode, t_param *par)
{
	int	index;

	index =  par->slt.index;
	if (keycode == KEY_ESC)
		close_win(par);
	else if (selete_object(keycode, &par->slt, &par->obj))
		return (0);
	else if (!index && move_camera(keycode, &par->cmr))
		return (0);
	else if (!index && rotate_camera(keycode, &par->cmr))
		return (0);
	else if (index && move_object(keycode, &par->slt))
		return (0);
	else if (index && rotate_object(keycode, &par->slt))
		return (0);
	return (0);
}
