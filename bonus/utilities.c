/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:44:36 by hbettal           #+#    #+#             */
/*   Updated: 2024/03/20 00:36:59 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	size_t		i;
	size_t		lent;
	char		*dest;

	i = 0;
	lent = ft_strlen(s1);
	dest = (char *)malloc(lent + 1);
	if (dest == NULL)
		return (NULL);
	while (s1[i] != 0)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*all;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	all = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!all)
		return (NULL);
	while (s1[++i])
		all[j++] = s1[i];
	all[j] = ' ';
	j++;
	i = -1;
	while (s2[++i])
		all[j++] = s2[i];
	all[j] = 0;
	free(s1);
	return (all);
}

long	ft_atoi(char *str)
{
	long	sign;
	long	i;
	long	sum;

	i = 0;
	sign = 1;
	sum = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	if (str[i] == '\0' || str[i] < '0' || str[i] > '9')
		(write(2, "Error\n", 6), exit(1));
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			(write(2, "Error\n", 6), exit(1));
		sum *= 10;
		sum += str[i] - '0';
		i++;
	}
	return (sum * sign);
}
