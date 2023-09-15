/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prachman <prachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:52:32 by truangsi          #+#    #+#             */
/*   Updated: 2023/09/15 09:20:01 by prachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}

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
}

void	free_exit(t_rt *rt, char **set, char *identifier, char *err)
{
	free_2dstr(set);
	free_data(rt);
	printf("%s %s", identifier, err);
	exit(EXIT_FAILURE);
}

// void	free_set(t_rt *rt, char **ptr, char *identifier, char *err)
// {
// 	int	i;

// 	i = 0;
// 	while (ptr[i])
// 	{
// 		free(ptr[i]);
// 		i++;
// 	}
// 	free(ptr);
// 	free_data(rt);
// 	printf("%s %s", identifier, err);
// 	exit(EXIT_FAILURE);
// }

// void	free_exit(t_rt *rt, char *identifier, char *err)
// {
// 	free(rt->pl);
// 	free(rt->sp);
// 	free(rt->cy);
// 	printf("%s %s", identifier, err);
// 	exit(EXIT_FAILURE);
// }
