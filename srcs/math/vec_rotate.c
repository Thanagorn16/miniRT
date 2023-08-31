/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:50:41 by tnantaki          #+#    #+#             */
/*   Updated: 2023/08/31 14:21:36 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

 // y_axis : vector that point up along with y axis
t_axis	calculate_axis(t_cor dir)
{
	t_axis	axis;
	t_cor	y_axis;

	y_axis = (t_cor){0, 1.0f, 0};
	axis.dir = dir;
	if (dir.y == -1 || dir.y == 1)
		y_axis = vec_norm((t_cor){0, 0, 1.0f * dir.y});
	axis.hor = vec_norm(vec_cross(axis.dir, y_axis));
	axis.ver = vec_norm(vec_cross(axis.hor, axis.dir));
	return (axis);
}

// Rotate round the x axis
t_axis	tilt_dir(t_axis old, int degree)
{
	t_axis	new;
	float	radian;
	float	sine;
	float	cosine;

	radian = ft_radian(degree);
	sine = sinf(radian);
	cosine = cosf(radian);
	new.hor = old.hor;
	new.ver = vec_sub(vec_scalar(old.ver, cosine), vec_scalar(old.dir, sine));
	new.dir = vec_add(vec_scalar(old.ver, sine), vec_scalar(old.dir, cosine));
	return (new);
}

// Rotate round the y axis
t_axis	plan_dir(t_axis old, int degree)
{
	t_axis	new;
	float	radian;
	float	sine;
	float	cosine;

	radian = ft_radian(degree);
	sine = sinf(radian);
	cosine = cosf(radian);
	new.ver = old.ver;
	new.hor = vec_sub(vec_scalar(old.hor, cosine), vec_scalar(old.dir, sine));
	new.dir = vec_add(vec_scalar(old.hor, sine), vec_scalar(old.dir, cosine));
	return (new);
}

// Only Rotate round the y system coordinate axis
t_axis	plan_catesian_dir(t_axis old, int degree)
{
	t_axis	new;
	t_cor	cor;
	float	radian;
	float	sine;
	float	cosine;

	radian = ft_radian(degree);
	sine = sinf(radian);
	cosine = cosf(radian);
	cor.y = old.dir.y;
	cor.x = old.dir.x * cosine - old.dir.z * sine;
	cor.z = old.dir.x * sine + old.dir.z * cosine;
	new.dir = vec_norm(cor);
	cor = (t_cor){0, 1.0f, 0};
	if (new.dir.y == -1 || new.dir.y == 1)
		cor = vec_norm((t_cor){0, 0, 1.0f * new.dir.y});
	new.hor = vec_norm(vec_cross(new.dir, cor));
	new.ver = vec_norm(vec_cross(new.hor, new.dir));
	return (new);
}
