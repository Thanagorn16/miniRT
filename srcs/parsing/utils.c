/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:52:32 by truangsi          #+#    #+#             */
/*   Updated: 2023/09/25 11:30:17 by truangsi         ###   ########.fr       */
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
	printf("%s %s", set[0], err);
	free_2dstr(set);
	free_data(rt);
	exit(EXIT_FAILURE);
}

// void	free_exit(t_rt *rt, char **set, char *identifier, char *err)
// {
// 	free_2dstr(set);
// 	free_data(rt);
// 	printf("%s %s", identifier, err);
// 	exit(EXIT_FAILURE);
// }


int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}

void	check_identifier(t_rt *rt, char **set)
{
	int	cn;

	cn = 0;
	if (ft_strcmp(set[0], "A") == 0)
		cn++;
	else if (ft_strcmp(set[0], "C") == 0)
		cn++;
	else if (ft_strcmp(set[0], "L") == 0)
        cn++;
	else if (ft_strcmp(set[0], "pl") == 0)
		cn++;
	else if (ft_strcmp(set[0], "sp") == 0)
		cn++;
	else if (ft_strcmp(set[0], "cy") == 0)
		cn++;
	else if (set[0][0] == '#')
		cn++;
	if (cn == 0)
	{
		printf("Invalid identifier");
		free_2dstr(set);
		free_data(rt);
		exit(EXIT_FAILURE);
	}
}

void	check_alpha(t_rt *rt, char **set)
{
	int	i;
	int	j;

	check_identifier(rt, set);
	i = 1;
	while (set[i])
	{
		j = 0;
		if (set[0][0] == '#')
			break;
		while (set[i][j])
		{
			if ((set[i][j] >= 'A' && set[i][j] <= 'Z') ||
				(set[i][j] >= 'a' && set[i][j] <= 'z'))
			{
				printf("here: %s\n", set[0]);
				printf("here: %c\n", set[0][0]);
				free_2dstr(set);
				free_data(rt);
				printf("Error: Information besides indentifiers must be number only");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
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
