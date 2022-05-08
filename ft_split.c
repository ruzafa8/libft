/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruzafa- <aruzafa-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:01:50 by aruzafa-          #+#    #+#             */
/*   Updated: 2022/05/08 15:22:52 by aruzafa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_num_words(char const *s, char c)
{
	int	num;

	num = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (*s == c)
		{
			num++;
			while (*s && *s == c)
				s++;
			if (!*s)
				return (num);
		}
		else
			s++;
	}
	return (num + 1);
}

static size_t	ft_len_next_word(char const *s, char c, size_t *start)
{
	size_t	len;

	len = 0;
	while (s[*start] && s[*start] == c)
		(*start)++;
	while (s[*start + len] && s[*start + len] != c)
		len++;
	return (len);
}

static char	**ft_delete(char **res, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (0);
}

static char	*ft_compute(char const *s, char c, size_t *s_index, int *delete)
{
	char	*word;
	size_t	len_word;

	len_word = ft_len_next_word(s, c, s_index);
	if (len_word > 0)
	{
		word = ft_substr(s, *s_index, len_word);
		*s_index += len_word;
		if (!word)
		{
			*delete = 1;
			return (0);
		}
		return (word);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	num_w;
	char	**res;
	size_t	word;
	size_t	s_index;
	int		delete;

	if (!s)
		return (0);
	num_w = ft_num_words(s, c);
	res = (char **) ft_calloc(num_w + 1, sizeof(char *));
	if (!res)
		return (0);
	word = 0;
	s_index = 0;
	delete = 0;
	while (word < num_w)
	{
		res[word] = ft_compute(s, c, &s_index, &delete);
		if (delete)
			return (ft_delete(res, word));
		word++;
	}
	return (res);
}
