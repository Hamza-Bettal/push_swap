/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:45:55 by hbettal           #+#    #+#             */
/*   Updated: 2024/03/19 22:57:37 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

void	double_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

char	*get_str(t_var	var, int ac, char **av)
{
	while (++var.i < ac)
	{
		var.tmp = var.str;
		var.str = ft_strjoin(var.str, av[var.i]);
	}
	return (var.str);
}

int	last_chunk(t_list *stack, int chunk)
{
	t_list	*tmp;
	t_list	*last;
	int		i;

	tmp = stack;
	i = 0;
	while (tmp->next)
	{
		if (tmp->index <= chunk)
			last = tmp;
		tmp = tmp->next;
	}
	while (last)
	{
		i++;
		last = last->next;
	}
	return (i);
}

int	first_chunk(t_list *stack, int chunk)
{
	t_list	*tmp;
	t_list	*first;
	int		i;

	tmp = stack;
	i = 0;
	while (tmp->next)
	{
		if (tmp->index <= chunk)
		{
			first = tmp;
			break ;
		}
		i++;
		tmp = tmp->next;
	}
	return (i);
}
