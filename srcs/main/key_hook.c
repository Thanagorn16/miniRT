#include "minirt.h"

bool	move_cmr(int keycode, t_cmr *cmr)
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
	new.x = old.x * cosine - old.z * sine;
	new.y = old.y;
	new.z = old.x * sine + old.z * cosine;
	new = vec_norm(new);
	return (new);
}

bool	rotate_cmr(int keycode, t_cmr *cmr)
{
	if (keycode == KEY_UP || keycode == KEY_DOWN)
	{
		if (keycode == KEY_UP)
			cmr->axis.z = tilt_cmr(cmr->axis.z, ROT_DEGREE);
		else
			cmr->axis.z = tilt_cmr(cmr->axis.z, -ROT_DEGREE);
		cmr->axis.y = vec_cross(cmr->axis.x, cmr->axis.z);
		cmr->ver = vec_scalar(cmr->axis.y, cmr->vp_height);
	}
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		if (keycode == KEY_LEFT)
			cmr->axis.z = plan_cmr(cmr->axis.z, -ROT_DEGREE);
		else
			cmr->axis.z = plan_cmr(cmr->axis.z, ROT_DEGREE);
		cmr->axis.x = vec_cross(cmr->axis.z, cmr->axis.y);
		cmr->hor = vec_scalar(cmr->axis.x, cmr->vp_width);
	}
	else
		return (false);
	cmr->fpro = cmr->axis.z;
	cmr->fpro = vec_sub(cmr->axis.z, vec_scalar(cmr->hor, 0.5));
	cmr->fpro = vec_add(cmr->fpro, vec_scalar(cmr->ver, 0.5));
	return (true);
}

int	key_hook(int keycode, t_param *par)
{
	if (keycode == KEY_ESC)
		close_win(par);
	else if (move_cmr(keycode, &par->cmr))
		return (0);
	else if (rotate_cmr(keycode, &par->cmr))
		return (0);
	return (0);
}
