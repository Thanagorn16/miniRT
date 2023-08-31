#include "minirt.h"

static t_axis	calculate_axis(t_cor dir)
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

static bool	setting_cylender(t_cy **cy, int amt)
{
	int		i;
	t_cor	y_axis;

	i = 0;
	y_axis = (t_cor){0, 1.0f, 0};
	while (i < amt)
	{
		(*cy)[i].dir = vec_norm((*cy)[i].dir);
		(*cy)[i].axis = calculate_axis((*cy)[i].dir);
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
	setting_cylender(&obj.cy, obj.amt.cy);
	setting_plane(&obj.pl, obj.amt.pl);
	par->obj = obj;
	return (true);
}
