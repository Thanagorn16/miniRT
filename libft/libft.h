/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prachman <prachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:36:45 by truangsi          #+#    #+#             */
/*   Updated: 2023/07/04 13:19:10 by prachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_split
{
	int		count;
	int		slot;
	size_t	i;
}	t_split;

void		double_free(char **arr);
int			ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *str);

#endif