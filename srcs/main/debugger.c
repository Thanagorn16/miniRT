/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:50:18 by tnantaki          #+#    #+#             */
/*   Updated: 2023/08/31 13:50:18 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cmr_post(t_cmr cmr)
{
	printf("Camera position\n");
	printf("x:%f, y:%f, z:%f\n", cmr.post.x, cmr.post.y, cmr.post.z);
}

void	sphere_post(t_sp sp)
{
	printf("Sphere Info\n");
	printf("Post # x:%f, y:%f, z:%f\n", sp.pos.x, sp.pos.y, sp.pos.z);
	printf("Radious : %f\n", sp.radius);
}

void	debug_cor(t_cor cor, char *str)
{
	printf("%s -- x:%f, y:%f, z:%f\n", str, cor.x, cor.y, cor.z);
}

void	debug_rgb(t_rgb rgb, char *str)
{
	printf("%s -- x:%d, y:%d, z:%d\n", str, rgb.r, rgb.g, rgb.b);
}

void	ptr_cor(t_cor cor)
{
	printf("x:%f, y:%f, z:%f", cor.x, cor.y, cor.z);
}

void	test_ray_point(t_ray ray, t_cy* cy, t_sp* sp, t_pl* pl, int mode)
{
	t_hpl	hit;

	hit.distance = FLT_MAX;
	hit.hit = false;
	if (cy)
		hit_cylender(ray, &hit, *cy, mode);
	else if (sp)
		hit_sphere(ray, &hit, *sp, mode);
	else if (pl)
		hit_plane(ray, &hit, *pl, mode);
	debug_cor(hit.point, "hitpoint-");
	debug_cor(hit.dir, "hitdir-");
	printf("distance: %f\n", hit.distance);
}

void	debug_diskey(int keycode)
{
	if (keycode == KEY_UP)
		printf("## Press key up: ##\n");
	else if (keycode == KEY_DOWN)
		printf("## Press key down: ##\n");
	else if (keycode == KEY_LEFT)
		printf("## Press key turn left: ##\n");
	else if (keycode == KEY_RIGHT)
		printf("## Press key turn right: ##\n");
	else if (keycode == KEY_W)
		printf("## Press key forward: ##\n");
	else if (keycode == KEY_S)
		printf("## Press key backward: ##\n");
	else if (keycode == KEY_A)
		printf("## Press key move left: ##\n");
	else if (keycode == KEY_D)
		printf("## Press key move right: ##\n");
	else if (keycode == KEY_Q)
		printf("## Press key move up: ##\n");
	else if (keycode == KEY_E)
		printf("## Press key move down: ##\n");
}