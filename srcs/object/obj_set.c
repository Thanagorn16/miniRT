/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:50:52 by tnantaki          #+#    #+#             */
/*   Updated: 2023/09/18 17:22:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	cy_position(t_cy **cy, int amt)
{
	t_cor	half_pos;
	int		i;

	i = 0;
	while (i < amt)
	{
		half_pos = vec_scalar((*cy)[i].dir, ((*cy)[i].height / 2));
		(*cy)[i].top = vec_add((*cy)[i].pos, half_pos);
		(*cy)[i].bot = vec_sub((*cy)[i].pos, half_pos);
		i++;
	}
	return (true);
}

static bool	setting_cylinder(t_cy **cy, int amt)
{
	int		i;

	i = 0;
	while (i < amt)
	{
		(*cy)[i].dir = vec_norm((*cy)[i].dir);
		(*cy)[i].axis = calculate_axis((*cy)[i].dir);
		(*cy)[i].inside = false;
		i++;
	}
	return (true);
}

static bool	setting_plane(t_pl **pl, int amt)
{
	int	i;

	i = 0;
	while (i < amt)
	{
		(*pl)[i].dir = vec_norm((*pl)[i].dir);
		(*pl)[i].axis = calculate_axis((*pl)[i].dir);
		i++;
	}
	return (true);
}

bool	setting_object(t_param *par, t_rt rt)
{
	t_obj	obj;

	obj.light.clr = ratio_clr(rt.light.clr, rt.light.ratio);
	obj.light.pos = rt.light.pos;
	obj.ambient = ratio_clr(rt.amb.clr, rt.amb.ratio);
	obj.amt = rt.amt;
	obj.sp = rt.sp;
	obj.pl = rt.pl;
	obj.cy = rt.cy;
	setting_cylinder(&obj.cy, obj.amt.cy);
	setting_plane(&obj.pl, obj.amt.pl);
	par->obj = obj;
	return (true);
}
