/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:50:25 by tnantaki          #+#    #+#             */
/*   Updated: 2023/09/26 14:25:24 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	t_param	par;

	if (parsing(ac, av, &par.rt))
		return (1);
	setting_camera(&par, par.rt.cam);
	setting_object(&par, par.rt);
	init_window(&par);
	create_image(&par);
	mlx_loop_hook(par.mlx, &render_scene, &par);
	mlx_hook(par.win, 2, 1L << 0, key_hook, &par);
	mlx_hook(par.win, 17, 0, close_win, &par);
	display_object(par.obj.amt, &par.slt);
	mlx_loop(par.mlx);
}
