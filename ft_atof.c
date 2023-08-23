/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:08:46 by truangsi          #+#    #+#             */
/*   Updated: 2023/08/23 14:55:53 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	ft_atof(const char *str)
{
	float	temp;
	float	fraction;
	int	nev;
	int	i;

	i = 0;
	nev = 0;
	temp = 0;
	fraction = 0.1;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		nev = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		temp = (temp * 10) + (str[i++] - '0');
	if (str[i] == '.')
	{
		i++;
		while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		{
			temp = temp + (str[i++] - '0') * fraction;
			fraction *= 0.1;
		}
	}
	if (nev == 1)
		return (-temp);
	return (temp);
}
