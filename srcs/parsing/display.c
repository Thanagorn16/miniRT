#include "struct_parse.h"

void	display(t_rt *rt)
{
	// check elem
	printf("\nAMB\n");
	printf("amb ratio: %f\n", rt->amb.ratio);
	printf("amb r: %d\n", rt->amb.clr.r);
	printf("amb g: %d\n", rt->amb.clr.g);
	printf("amb b: %d\n", rt->amb.clr.b);

	printf("\nCAM\n");
	printf("pos x: %f\n", rt->cam.pos.x);
	printf("pos y: %f\n", rt->cam.pos.y);
	printf("pos z: %f\n", rt->cam.pos.z);
	printf("dir x: %f\n", rt->cam.dir.x);
	printf("dir y: %f\n", rt->cam.dir.y);
	printf("dir z: %f\n", rt->cam.dir.z);
	printf("fov: %d\n", rt->cam.fov);

	printf("\nLIGHT\n");
	printf("pos x: %f\n", rt->light.pos.x);
	printf("pos y: %f\n", rt->light.pos.y);
	printf("pos z: %f\n", rt->light.pos.z);
	printf("light ratio: %f\n", rt->light.ratio);
	printf("light r: %d\n", rt->light.clr.r);
	printf("light g: %d\n", rt->light.clr.g);
	printf("light b: %d\n", rt->light.clr.b);

	printf("\nPL\n");
	printf("amt: %d\n", rt->amt.pl);
	printf("pos x: %f\n", rt->pl[1].pos.x);
	printf("pos y: %f\n", rt->pl[0].pos.y);
	printf("pos z: %f\n", rt->pl[0].pos.z);
	printf("dir x: %f\n", rt->pl[0].dir.x);
	printf("dir y: %f\n", rt->pl[0].dir.y);
	printf("dir z: %f\n", rt->pl[0].dir.z);
	printf("pl r: %d\n", rt->pl[0].clr.r);
	printf("pl g: %d\n", rt->pl[0].clr.g);
	printf("pl b: %d\n", rt->pl[0].clr.b);

	printf("\nSP\n");
	printf("amt: %d\n", rt->amt.sp);
	printf("pos x: %f\n", rt->sp[0].pos.x);
	printf("pos y: %f\n", rt->sp[0].pos.y);
	printf("pos z: %f\n", rt->sp[0].pos.z);
	printf("diameter: %f\n", rt->sp[0].dia);
	printf("radius: %f\n", rt->sp[0].radius);
	printf("sp r: %d\n", rt->sp[0].clr.r);
	printf("sp g: %d\n", rt->sp[0].clr.g);
	printf("sp b: %d\n", rt->sp[0].clr.b);

	printf("\nCY\n");
	printf("amt: %d\n", rt->amt.cy);
	printf("pos x: %f\n", rt->cy[0].pos.x);
	printf("pos y: %f\n", rt->cy[0].pos.y);
	printf("pos z: %f\n", rt->cy[0].pos.z);
	printf("dir x: %f\n", rt->cy[0].dir.x);
	printf("dir y: %f\n", rt->cy[0].dir.y);
	printf("dir z: %f\n", rt->cy[0].dir.z);
	printf("diameter: %f\n", rt->cy[0].dia);
	printf("radius: %f\n", rt->cy[0].radius);
	printf("length: %f\n", rt->cy[0].length);
	printf("cy r: %d\n", rt->cy[0].clr.r);
	printf("cy g: %d\n", rt->cy[0].clr.g);
	printf("cy b: %d\n", rt->cy[0].clr.b);

}