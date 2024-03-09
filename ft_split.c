/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:54:07 by hbettal           #+#    #+#             */
/*   Updated: 2024/03/09 21:45:21 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *s, int c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while(s[i] == ' ' || s[i] == '\0')
	{
		if (s[i] == '\0')
			(write(2, "error\n", 7),exit(1));
		i++;
	}
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static void	*free_memory(char **strs, int i)
{
	while (i--)
		free(strs[i]);
	free(strs);
	return (NULL);
}

static char	**strs_split(char **strs, char *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		strs[i] = ft_substr(s, 0, len);
		if (!strs[i])
			return (free_memory(strs, i));
		s += len;
		i++;
	}
	strs[i] = NULL;
	return (strs);
}

char	**ft_split(char *s, char c)
{
	char	**strs;

	if (!*s)
		(write(2,"error\n",7),exit(1));
	strs = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	return (strs_split(strs, s, c));
}
