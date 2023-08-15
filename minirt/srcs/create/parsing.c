#include "minirt.h"

t_sph	*parse_sp(t_sp *sp, int amt)
{
	t_sph	*sph;
	int		i;

	sph = malloc(sizeof(t_sph) * amt);
	if (!sph)
		return (NULL);
	i = 0;
	while (i < amt)
	{
		sph[i].post  = sp[i].cor;
		sph[i].clr = sp[i].rgb;
		sph[i].r = sp[i].radius / 2;
		i++;
	}
	return (sph);
}

bool	parsing(t_rt rt, t_obj *obj)
{
	//number of object
	obj->light = rt.light;
	obj->amt.sph = rt.nsp;
	obj->ambient = ambient_light(rt.amb);

	//Sphere
	obj->sph = parse_sp(rt.sp, rt.nsp);
	debug_cor(obj->light.pos, "Post light :");
	debug_rgb(obj->light.rgb, "rgb light :");

	return (true);
}
