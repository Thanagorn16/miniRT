#include "minirt.h"

t_cor	tilt_cmr(t_cor old, int degree)
{
	t_cor	new;
	float	radian;
	float	sine;
	float	cosine;

	radian = ft_radian(degree);
	sine = sinf(radian);
	cosine = cosf(radian);
	new.x = old.x;
	new.y = old.y * cosine - old.z * sine;
	new.z = old.y * sine + old.z * cosine;
	new = vec_norm(new);
	return (new);
}

t_cor	plan_cmr(t_cor old, int degree)
{
	t_cor	new;
	float	radian;
	float	sine;
	float	cosine;

	radian = ft_radian(degree);
	sine = sinf(radian);
	cosine = cosf(radian);
	new.y = old.y;
	new.x = old.x * cosine - old.z * sine;
	new.z = old.x * sine + old.z * cosine;
	new = vec_norm(new);
	return (new);
}

bool	rotate_camera(int keycode, t_cmr *cmr)
{
	if (keycode == KEY_UP || keycode == KEY_DOWN)
	{
		if (keycode == KEY_UP)
			cmr->axis.dir = tilt_cmr(cmr->axis.dir, ROT_DEGREE);
		else
			cmr->axis.dir = tilt_cmr(cmr->axis.dir, -ROT_DEGREE);
		cmr->axis.ver = vec_cross(cmr->axis.hor, cmr->axis.dir);
		cmr->ver = vec_scalar(cmr->axis.ver, cmr->vp_height);
	}
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		if (keycode == KEY_LEFT)
			cmr->axis.dir = plan_cmr(cmr->axis.dir, -ROT_DEGREE);
		else
			cmr->axis.dir = plan_cmr(cmr->axis.dir, ROT_DEGREE);
		cmr->axis.hor = vec_cross(cmr->axis.dir, cmr->axis.ver);
		cmr->hor = vec_scalar(cmr->axis.hor, cmr->vp_width);
	}
	else
		return (false);
	cmr->fpro = cmr->axis.dir;
	cmr->fpro = vec_sub(cmr->axis.dir, vec_scalar(cmr->hor, 0.5));
	cmr->fpro = vec_add(cmr->fpro, vec_scalar(cmr->ver, 0.5));
	return (true);
}

bool	move_camera(int keycode, t_cmr *cmr)
{
	if (keycode == KEY_W)
		cmr->post = vec_add(cmr->post, cmr->move[DOLLY]);
	else if (keycode == KEY_S)
		cmr->post = vec_sub(cmr->post, cmr->move[DOLLY]);
	else if (keycode == KEY_D)
		cmr->post = vec_add(cmr->post, cmr->move[TRUCK]);
	else if (keycode == KEY_A)
		cmr->post = vec_sub(cmr->post, cmr->move[TRUCK]);
	else if (keycode == KEY_Q)
		cmr->post = vec_add(cmr->post, cmr->move[PEDESTAL]);
	else if (keycode == KEY_E)
		cmr->post = vec_sub(cmr->post, cmr->move[PEDESTAL]);
	else
		return (false);
	return (true);
}
