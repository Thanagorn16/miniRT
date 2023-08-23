#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "color.h"
# include "struct_ray.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <float.h>

# if defined(__linux__)
#  include "keycode_linux.h"
# else
#  include "keycode_macos.h"
# endif

# define WD_WIDTH 1500
# define WD_HEIGHT 1000
# define EPSILON 0.0001f
# define BOUNCES 2

bool	hit_object(t_ray ray, t_hpl *payload, t_obj *obj);
t_ray	reflect_ray(t_ray ray, t_hpl *payload, t_light light);
// t_ray	reflect_ray(t_ray ray, t_hpl *payload);
bool	render_scene(t_param par, t_obj *obj);
bool	init_object(t_rt *rt, t_obj *obj);
// Camera
bool	setting_camera(t_param *par, t_cam cam);
// Object
bool	hit_sphere(t_ray ray, t_hpl *hit, t_sp sp);
bool	hit_plane(t_ray ray, t_hpl *hit, t_pl pl);
bool	hit_cylender(t_ray ray, t_hpl *hit, t_cy cy);
// Light
t_rgb	ambient_light(t_rgb clr, t_rgb objclr, t_rgb amb);
t_rgb	point_light(t_rgb clr, t_hpl payload, t_light light);
// bool	shading(t_hitpayload *payload, t_light light);
//Color
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
// Algebra
float	ft_pow2(float num);
float	ft_abs(float num);
float	ft_radius(int degree);
float	ft_min(float a, float b);
// Vector
t_cor	vec_add(t_cor a, t_cor b);
t_cor	vec_sub(t_cor a, t_cor b);
t_cor	vec_scalar(t_cor vec, float t);
float	vec_length(t_cor vec);
t_cor	vec_norm(t_cor vec);
float	vec_dot(t_cor a, t_cor b);
t_cor	vec_cross(t_cor a, t_cor b);

#endif
