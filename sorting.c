/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:53:51 by hbettal           #+#    #+#             */
/*   Updated: 2024/03/11 00:50:40 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_sort(t_list *stack)
{
	if (stack->num > stack->next->num)
	{
		ra(&stack);
		if (stack->num < stack->next->num)
			sa(&stack);
	}
}
void    ft_start(t_list *stack)
{
	int mode;

	mode = ft_lstsize(stack);
	if (mode <= 3)
		short_sort(stack);
}

void    sort_check(t_list   *stack)
{
	t_list  *tmp;
	
	tmp = stack;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			ft_start(stack);
		tmp = tmp->next;
	}
}