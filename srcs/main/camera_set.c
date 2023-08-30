#include "minirt.h"

static bool	camera_set_movement(t_cmr *cmr)
{
	cmr->move[DOLLY] = vec_scalar(cmr->axis.dir, MOVE_CMR_UNIT);
	cmr->move[TRUCK] = vec_scalar(cmr->axis.hor, MOVE_CMR_UNIT);
	cmr->move[PEDESTAL] = vec_scalar(cmr->axis.ver, MOVE_CMR_UNIT);
	return (true);
}

bool	setting_camera(t_param *par, t_cam cam)
{
	t_cmr	cmr;
	t_cor	y_axis; // 2nd para : vector that point up along with y axis

	y_axis = Y_AXIS;
	cmr.post = cam.pos;
	cmr.vp_width = tanf(ft_radian(cam.fov) / 2) * 2; // viewport ratio
	cmr.vp_height = ((float)WD_HEIGHT / (float)WD_WIDTH) * cmr.vp_width; // viewport ratio

	// Change all axis to align with camera coordiate (direction)
	cmr.axis.dir = vec_norm(cam.dir);
	if (cmr.axis.dir.y == -1 || cmr.axis.dir.y == 1)
		y_axis = vec_norm((t_cor){0, 0, 1.00f * cam.dir.y});
	cmr.axis.hor = vec_norm(vec_cross(cmr.axis.dir, y_axis)); // cross right x axis to end point dir
	cmr.axis.ver = vec_norm(vec_cross(cmr.axis.hor, cmr.axis.dir));
	debug_cor(cmr.axis.dir, "axis.dir: ");
	debug_cor(cmr.axis.hor, "axis.hor: ");
	debug_cor(cmr.axis.ver, "axis.ver: ");

	// Camera plane on horizotal and vertical scale as viewport
	cmr.hor = vec_scalar(cmr.axis.hor, cmr.vp_width);
	cmr.ver = vec_scalar(cmr.axis.ver, cmr.vp_height);

	// First projection of camera
	cmr.fpro = cmr.axis.dir;
	cmr.fpro = vec_sub(cmr.axis.dir, vec_scalar(cmr.hor, 0.5));
	cmr.fpro = vec_add(cmr.fpro, vec_scalar(cmr.ver, 0.5));
	camera_set_movement(&cmr);
	par->cmr = cmr;
	return (true);
}

