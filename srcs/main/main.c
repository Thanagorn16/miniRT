/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:50:25 by tnantaki          #+#    #+#             */
/*   Updated: 2023/09/18 13:04:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	t_param	par;
	t_rt	rt;

	// par.start = get_elapse_time(); // framerate
	if (parsing(ac, av, &rt))
		return (1);
	setting_camera(&par, rt.cam);
	setting_object(&par, rt);
	init_window(&par);
	create_image(&par);
	mlx_loop_hook(par.mlx, &render_scene, &par);
	mlx_hook(par.win, 2, 1L << 0, key_hook, &par);
	mlx_hook(par.win, 17, 0, close_win, &par);
	display_object(par.obj.amt, &par.slt);
	mlx_loop(par.mlx);
}
