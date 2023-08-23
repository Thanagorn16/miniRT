#include "minirt.h"

bool	init_object(t_rt *rt, t_obj *obj)
{
	//light
	obj->light.clr = ratio_clr(rt->light.clr, rt->light.ratio);
	obj->light.pos = rt->light.pos;
	//ambient
	obj->ambient = ratio_clr(rt->amb.clr, rt->amb.ratio);
	//amount object
	obj->amt = rt->amt;
	//object
	obj->sp = rt->sp;
	obj->pl = rt->pl;
	obj->cy = rt->cy;

	return (true);
}
