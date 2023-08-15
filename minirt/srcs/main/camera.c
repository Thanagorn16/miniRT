#include "minirt.h"

bool	setting_camera(t_param *par, t_cam cam)
{
	t_cor	axis_z; // vector that point to viewport
	t_cor	axis_x; // vector that point along with x axis of viewport
	t_cor	axis_y; // vector that point along with y axis of viewport
	float	vp_width;
	float	vp_height;

	par->cmr.post = cam.pos;
	vp_width = tanf(ft_radius(cam.fov) / 2) * 2; // viewport ratio
	vp_height = ((float)WD_HEIGHT / (float)WD_WIDTH) * vp_width; // viewport ratio
	printf("w:%f h:%f\n", vp_width, vp_height);

	// Change all axis to along with camera coordiate
	axis_z = vec_norm(cam.dir);
	axis_x = vec_cross(axis_z, (t_cor){0, 1.00, 0}); // 2nd para : vector that point up along with y axis
	axis_y = vec_cross(axis_x, axis_z);
	debug_cor(axis_z, "axis_z ");
	debug_cor(axis_x, "axis_x ");
	debug_cor(axis_y, "axis_y ");

	// Camera plane on horizotal and vertical scale as viewport
	par->cmr.hor = vec_scalar(axis_x, vp_width);
	par->cmr.ver = vec_scalar(axis_y, vp_height);
	debug_cor(par->cmr.hor, "cmr_hor ");
	debug_cor(par->cmr.ver, "cmr_ver ");

	// First projection of camera
	par->cmr.fpro = vec_scalar(vec_scalar(par->cmr.hor, 0.5), -1);
	debug_cor(par->cmr.fpro, "fpro ver1 ");
	par->cmr.fpro = vec_add(par->cmr.fpro, vec_scalar(par->cmr.ver, 0.5));
	debug_cor(par->cmr.fpro, "fpro ver2 ");
	par->cmr.fpro = vec_add(par->cmr.fpro, axis_z);
	debug_cor(par->cmr.fpro, "fpro ver3 ");
	return (true);
}
