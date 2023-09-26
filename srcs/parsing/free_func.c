/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:09:51 by truangsi          #+#    #+#             */
/*   Updated: 2023/09/26 12:06:25 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

size_t	ft_2dstrlen(char **str)
{
	size_t	cw;

	cw = 0;
	while (str[cw])
		cw++;
	return (cw);
}

void	free_2dstr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	free_data(t_rt *rt)
{
	free(rt->pl);
	free(rt->sp);
	free(rt->cy);
	free(rt->tmp);
}

void	free_exit(t_rt *rt, char **set, char *err)
{
	printf("%s: %s", set[0], err);
	free_2dstr(set);
	free_data(rt);
	exit(EXIT_FAILURE);
}
