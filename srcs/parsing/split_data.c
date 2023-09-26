/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:20:30 by truangsi          #+#    #+#             */
/*   Updated: 2023/09/26 11:21:29 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	ft_countword(char const *s, char c1, char c2)
{
	int	i;
	int	cw;

	i = 0;
	cw = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == c1 || s[i] == c2
				|| s[i] == '\t' || s[i] == '\n'))
			i++;
		while (s[i] && (s[i] != c1 && s[i] != c2
				&& s[i] != '\t' && s[i] != '\n'))
		{
			i++;
			if (s[i] == c1 || s[i] == c2 || s[i] == '\t'
				|| s[i] == '\n' || s[i] == '\0')
				cw++;
		}
	}
	return (cw);
}

static char	*ft_malloc_word(const char *str, char c1, char c2, int *start)
{
	char	*word;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (str[*start] == c1 || str[*start] == c2
		|| str[*start] == '\t' || str[*start] == '\n')
		*start += 1;
	while (str[*start + len] != c1 && str[*start + len] != c2
		&& str[*start + len] != '\0')
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[*start + i];
		i++;
	}
	*start += len;
	word[i] = '\0';
	return (word);
}

static char	**ft_freeword(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
	return (NULL);
}

char	**split_data(char const *s, char c1, char c2)
{
	char	**split;
	int		cw;
	int		i;
	int		start;

	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	cw = ft_countword(s, c1, c2);
	split = (char **)malloc(sizeof(char *) * (cw + 1));
	if (!split)
		return (NULL);
	while (i < cw)
	{
		split[i] = ft_malloc_word(s, c1, c2, &start);
		if (!split[i])
			return (ft_freeword(split, i));
		i++;
	}
	split[i] = NULL;
	return (split);
}
