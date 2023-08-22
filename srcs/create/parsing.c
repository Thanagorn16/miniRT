#include "minirt.h"

bool	parsing(t_rt *rt, t_obj *obj)
{
	//number of object
	obj->light.clr = ratio_clr(rt->light.clr, rt->light.ratio);
	obj->light.pos = rt->light.pos;
	obj->ambient = ratio_clr(rt->amb.clr, rt->amb.ratio);
	obj->amt = rt->amt;

	//Sphere
	obj->sp = rt->sp;
	obj->pl = rt->pl;
	debug_rgb(obj->light.clr, "light");

	return (true);
}
