/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:01:18 by aruzafa-          #+#    #+#             */
/*   Updated: 2022/04/27 10:47:58 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	s_len;
	size_t	i;
	size_t	total_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start > s_len)
		total_len = 0;
	else
		total_len = ft_min(s_len - start, len);
	res = (char *) malloc((total_len + 1) * sizeof(char));
	if (!res)
		return (0);
	i = 0;
	while (i < len && i + start < s_len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = 0;
	return (res);
}
