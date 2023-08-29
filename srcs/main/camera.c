#include "minirt.h"

bool	camera_set_movement(t_cmr *cmr)
{
	cmr->move[DOLLY] = vec_scalar(cmr->axis.z, MOVE_UNIT);
	cmr->move[TRUCK] = vec_scalar(cmr->axis.x, MOVE_UNIT);
	cmr->move[PEDESTAL] = vec_scalar(cmr->axis.y, MOVE_UNIT);
	return (true);
}

bool	setting_camera(t_param *par, t_cam cam)
{
	t_cmr	cmr;
	t_cor	axis_y; // 2nd para : vector that point up along with y axis

	axis_y = (t_cor){0, 1.00, 0};
	cmr.post = cam.pos;
	cmr.vp_width = tanf(ft_radian(cam.fov) / 2) * 2; // viewport ratio
	cmr.vp_height = ((float)WD_HEIGHT / (float)WD_WIDTH) * cmr.vp_width; // viewport ratio

	// Change all axis to align with camera coordiate (direction)
	cmr.axis.z = vec_norm(cam.dir);
	cmr.axis.x = vec_norm(vec_cross(cmr.axis.z, axis_y)); // cross right x axis to end point dir
	cmr.axis.y = vec_norm(vec_cross(cmr.axis.x, cmr.axis.z));
	debug_cor(cmr.axis.z, "axis.z: ");
	debug_cor(cmr.axis.x, "axis.x: ");
	debug_cor(cmr.axis.y, "axis.y: ");

	// Camera plane on horizotal and vertical scale as viewport
	cmr.hor = vec_scalar(cmr.axis.x, cmr.vp_width);
	cmr.ver = vec_scalar(cmr.axis.y, cmr.vp_height);

	// First projection of camera
	cmr.fpro = cmr.axis.z;
	debug_cor(cmr.fpro, "cam dir: ");
	cmr.fpro = vec_sub(cmr.axis.z, vec_scalar(cmr.hor, 0.5));
	cmr.fpro = vec_add(cmr.fpro, vec_scalar(cmr.ver, 0.5));
	camera_set_movement(&cmr);
	par->cmr = cmr;
	debug_cor(cmr.fpro, "dir: ");
	return (true);
}

