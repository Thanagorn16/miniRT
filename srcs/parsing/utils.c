/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 12:52:32 by truangsi          #+#    #+#             */
/*   Updated: 2023/09/26 11:13:33 by truangsi         ###   ########.fr       */
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
			break ;
		while (set[i][j])
		{
			if ((set[i][j] >= 'A' && set[i][j] <= 'Z') ||
				(set[i][j] >= 'a' && set[i][j] <= 'z'))
			{
				free_2dstr(set);
				free_data(rt);
				printf("Error: Info besides indentifiers must be number only");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}
