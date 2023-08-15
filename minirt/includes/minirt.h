#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "libft.h"
# include "color.h"
# include "data_raytrace.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# if defined(__linux__)
#  include "keycode_linux.h"
# else
#  include "keycode_macos.h"
# endif

# define WD_WIDTH 1500
# define WD_HEIGHT 1000

bool	parsing(t_rt rt, t_obj *obj);
// Ambient
int		ambient_light(t_ambien amb);
// Camera
bool	setting_camera(t_param *par, t_cam cam);
// Sphere
bool	hit_sph(t_ray *ray, t_sph sph);
// Light
t_rgb	relative_ambient(t_rgb clr, t_rgb amb);
bool	shading(t_ray *ray, t_light light);
// mlx
bool	init_window(t_param *par);
int		close_win(t_param *par);
bool	create_image(t_param *par);
void	put_pixel_to_image(t_image *img, t_pix pix);
int		key_hook(int keycode, t_param *par);
// Debugger
void	cmr_post(t_cmr cmr);
void	sphere_post(t_sph sph);
void	debug_cor(t_cor cor, char *str);
void	debug_rgb(t_rgb rgb, char *str);
// Algebra
float	ft_pow2(float num);
float	ft_abs(float num);
float	ft_radius(int degree);
int		rgb_to_clr(t_rgb rgb);
// Vector
t_cor	vec_add(t_cor a, t_cor b);
t_cor	vec_sub(t_cor a, t_cor b);
t_cor	vec_scalar(t_cor vec, float t);
t_cor	vec_norm(t_cor vec);
float	vec_dot(t_cor a, t_cor b);
t_cor	vec_cross(t_cor a, t_cor b);

#endif
