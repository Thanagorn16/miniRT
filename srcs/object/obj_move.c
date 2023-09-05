/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:50:49 by tnantaki          #+#    #+#             */
/*   Updated: 2023/08/31 13:50:50 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	rotate_object(int keycode, t_slt *slt)
{
	if (!slt->dir)
		return (false);
	if (keycode == KEY_UP || keycode == KEY_DOWN)
	{
		if (keycode == KEY_UP)
			*(slt->axis) = tilt_dir(*(slt->axis), ROT_DEGREE);
		else
			*(slt->axis) = tilt_dir(*(slt->axis), -ROT_DEGREE);
	}
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		if (keycode == KEY_LEFT)
			*(slt->axis) = plan_dir(*(slt->axis), -ROT_DEGREE);
		else
			*(slt->axis) = plan_dir(*(slt->axis), ROT_DEGREE);
	}
	else
		return (false);
	*(slt->dir) = slt->axis->dir;
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

static bool	match(t_slt *slt, t_cor *pos, t_cor *dir, t_axis *axis)
{
	slt->pos = pos;
	slt->dir = dir;
	slt->axis = axis;
	if (slt->index == 1)
		printf("Light has seleted\n");
	else if (slt->index == 2)
		printf("Sphere has seleted\n");
	else if (slt->index == 3)
		printf("Plane has seleted\n");
	else if (slt->index == 4)
		printf("Cylender has seleted\n");
	return (true);
}

bool	selete_object(int keycode, t_slt *slt, t_obj *obj)
{
	if (keycode == KEY_ZERO)
		return (slt->index = 0, printf("Camera has seleted\n"), true);
	else if (keycode == KEY_ONE && slt->obj[1])
	{
		slt->index = 1;
		return (match(slt, &(obj->light.pos), NULL, NULL));
	}
	else if (keycode == KEY_TWO && slt->obj[2])
	{
		slt->index = 2;
		return (match(slt, &(obj->sp->pos), NULL, NULL));
	}
	else if (keycode == KEY_THREE && slt->obj[3])
	{
		slt->index = 3;
		return (match(slt, &(obj->pl->pos), &(obj->pl->dir), &(obj->pl->axis)));
	}
	else if (keycode == KEY_FOUR && slt->obj[4])
	{
		slt->index = 4;
		return (match(slt, &(obj->cy->pos), &(obj->cy->dir), &(obj->cy->axis)));
	}
	return (false);
}

bool	display_object(t_amt amt, t_slt *slt)
{
	slt->index = 0;
	slt->obj[0] = true;
	slt->obj[1] = true;
	slt->obj[2] = false;
	slt->obj[3] = false;
	slt->obj[4] = false;
	printf("Finish Raytrace\n");
	printf("Number[0] : Camera\nNumber[1] : Light\n");
	if (amt.sp)
	{
		slt->obj[2] = true;
		printf("Number[2] : Sphere\n");
	}
	if (amt.pl)
	{
		slt->obj[3] = true;
		printf("Number[3] : Plane\n");
	}
	if (amt.cy)
	{
		slt->obj[4] = true;
		printf("Number[4] : Cylender\n");
	}
	printf("Press number to selete Object\n");
	return (true);
}
