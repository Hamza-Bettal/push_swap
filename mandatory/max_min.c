/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:18:36 by hbettal           #+#    #+#             */
/*   Updated: 2024/03/19 22:26:08 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*higher_num(t_list *stack)
{
	t_list	*tmp;
	t_list	*higher;

	tmp = stack;
	higher = tmp;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->num > higher->num)
			higher = tmp;
	}
	return (higher);
}

t_list	*second_higher_num(t_list *stack)
{
	int		sec;
	t_list	*tmp;
	t_list	*higher;

	tmp = stack;
	higher = higher_num(stack);
	sec = higher->index - 1;
	while (tmp)
	{
		if (tmp->index == sec)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int	position_finder(t_list *stack, int w)
{
	t_list	*tmp;
	t_list	*high;
	int		i;

	high = higher_num(stack);
	tmp = stack;
	i = 0;
	while (tmp)
	{
		if (tmp->index == high->index - w)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_list	*lower_num(t_list *stack)
{
	t_list	*tmp;
	t_list	*higher;

	tmp = stack;
	higher = tmp;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->num < higher->num)
			higher = tmp;
	}
	return (higher);
}

int	lower_pos(t_list *stack, int index)
{
	t_list	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		if (tmp->index == index)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}
