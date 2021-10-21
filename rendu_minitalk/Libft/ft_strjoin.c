/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 10:49:06 by lmaujean          #+#    #+#             */
/*   Updated: 2021/03/30 13:36:34 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char s2)
{
	char	*strings;
	size_t	i;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = ft_strlen(s1) + 2;
	strings = ft_calloc(sizeof(char), i);
	i = 0;
	if (strings == 0)
		return (0);
	while (s1[i] != 0)
	{
		strings[i] = s1[i];
		i++;
	}
	strings[i] = s2;
	return (strings);
}
