#include "minirt.h"

bool	rotate_object(int keycode, t_slt *slt)
{
	if (!slt->dir)
		return (true);
	if (keycode == KEY_UP || keycode == KEY_DOWN)
	{
		if (keycode == KEY_UP)
			*(slt->dir) = tilt_cmr(*(slt->dir), ROT_DEGREE);
		else
			*(slt->dir) = tilt_cmr(*(slt->dir), -ROT_DEGREE);
	}
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		if (keycode == KEY_LEFT)
			*(slt->dir) = plan_cmr(*(slt->dir), ROT_DEGREE);
		else
			*(slt->dir) = plan_cmr(*(slt->dir), -ROT_DEGREE);
	}
	else
		return (false);
	return (true);
}

bool	move_object(int keycode, t_slt *slt)
{
	if (keycode == KEY_W)
		*(slt->pos) = vec_sub(*(slt->pos), (t_cor){0.0f, 0.0f, MOVE_OBJ_UNIT});
	else if (keycode == KEY_S)
		*(slt->pos) = vec_add(*(slt->pos), (t_cor){0.0f, 0.0f, MOVE_OBJ_UNIT});
	else if (keycode == KEY_D)
		*(slt->pos) = vec_add(*(slt->pos), (t_cor){MOVE_OBJ_UNIT, 0.0f, 0.0f});
	else if (keycode == KEY_A)
		*(slt->pos) = vec_sub(*(slt->pos), (t_cor){MOVE_OBJ_UNIT, 0.0f, 0.0f});
	else if (keycode == KEY_Q)
		*(slt->pos) = vec_add(*(slt->pos), (t_cor){0.0f, MOVE_OBJ_UNIT, 0.0f});
	else if (keycode == KEY_E)
		*(slt->pos) = vec_sub(*(slt->pos), (t_cor){0.0f, MOVE_OBJ_UNIT, 0.0f});
	else
		return (false);
	return (true);
}

bool	match_one(t_slt *slt, t_cor *pos, t_cor *dir, int index)
{
	slt->pos = pos;
	slt->dir = dir;
	slt->index = index;
	if (index == 1)
		printf("Light has seleted\n");
	else if (index == 2)
		printf("Sphere has seleted\n");
	else if (index == 3)
		printf("Plane has seleted\n");
	else if (index == 4)
		printf("Cylender has seleted\n");
	return (true);
}

bool	selete_object(int keycode, t_slt *slt, t_obj *obj)
{
	if (keycode == KEY_ZERO)
		return (slt->index = 0, printf("Camera has seleted\n", true));
	else if (keycode == KEY_ONE && slt->obj[1])
		return (match_one(slt, &(obj->light.pos), NULL, 1));
	else if (keycode == KEY_TWO && slt->obj[2])
		return (match_one(slt, &(obj->sp->pos), NULL, 2));
	else if (keycode == KEY_THREE && slt->obj[3])
		return (match_one(slt, &(obj->pl->pos), &(obj->pl->dir), 3));
	else if (keycode == KEY_FOUR && slt->obj[4])
		return (match_one(slt, &(obj->cy->pos), &(obj->cy->dir), 4));
	return (false);
}
