/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 00:49:50 by tnantaki          #+#    #+#             */
/*   Updated: 2023/08/31 14:22:20 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "color.h"
# include "struct_ray.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# if defined(__linux__)
#  include "keycode_linux.h"
# else
#  include "keycode_macos.h"
# endif

# define WD_WIDTH 1280
# define WD_HEIGHT 720

# define FLT_MAX 3.4028234664e+38
# define EPSILON 0.001f

# define ROT_DEGREE 5
# define MOVE_CMR_UNIT 0.5
# define MOVE_OBJ_UNIT 0.2
# define BOUNCES 2

// Raytrace
bool	hit_object(t_ray ray, t_hpl *payload, t_obj *obj);
t_ray	reflect_ray(t_ray ray, t_hpl *payload, t_light light);
int		render_scene(t_param *par);
// Camera
bool	setting_camera(t_param *par, t_cam cam);
bool	move_camera(int keycode, t_cmr *cmr);
bool	rotate_camera(int keycode, t_cmr *cmr);
// Object
bool	display_object(t_amt amt, t_slt *slt);
bool	setting_object(t_param *par, t_rt rt);
bool	selete_object(int keycode, t_slt *slt, t_obj *obj);
bool	move_object(int keycode, t_slt *slt);
bool	rotate_object(int keycode, t_slt *slt);
bool	hit_sphere(t_ray ray, t_hpl *hit, t_sp sp, int mode);
bool	hit_plane(t_ray ray, t_hpl *hit, t_pl pl, int mode);
bool	hit_cylender(t_ray ray, t_hpl *hit, t_cy cy, int mode);
bool	disk_intersection(t_ray ray, t_hpl *hit, t_cy cy, int mode);
// Light
t_rgb	ambient_light(t_rgb clr, t_rgb objclr, t_rgb amb);
t_rgb	shadowing(t_rgb	clr, t_hpl hit, t_obj *obj);
// Color
t_rgb	clamp_clr(t_rgb clr);
t_rgb	add_clr(t_rgb clr, t_rgb add);
t_rgb	shade_clr(t_rgb clr, t_rgb shade);
t_rgb	ratio_clr(t_rgb light, float ratio);
int		rgb_to_clr(t_rgb clr);
// mlx
bool	init_window(t_param *par);
int		close_win(t_param *par);
bool	create_image(t_param *par);
void	put_pixel_to_image(t_image *img, t_pix pix);
int		key_hook(int keycode, t_param *par);
// Debugger
void	cmr_post(t_cmr cmr);
void	sphere_post(t_sp sp);
void	debug_cor(t_cor cor, char *str);
void	debug_rgb(t_rgb rgb, char *str);
void	test_ray_point(t_ray ray, t_cy *cy, t_sp *sp, t_pl *pl, int mode);
void	debug_diskey(int keycode);
// Algebra
float	ft_pow2(float num);
float	ft_abs(float num);
float	ft_radian(int degree);
float	ft_min(float a, float b);
float	discriminant(float a, float b, float c);
// Vector
t_cor	vec_add(t_cor a, t_cor b);
t_cor	vec_sub(t_cor a, t_cor b);
t_cor	vec_scalar(t_cor vec, float t);
float	vec_len(t_cor vec);
t_cor	vec_norm(t_cor vec);
float	vec_dot(t_cor a, t_cor b);
t_cor	vec_cross(t_cor a, t_cor b);
t_axis	calculate_axis(t_cor dir);
t_axis	tilt_dir(t_axis old, int degree);
t_axis	plan_dir(t_axis old, int degree);
t_axis	plan_catesian_dir(t_axis old, int degree);

#endif
