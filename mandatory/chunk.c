/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:52:16 by hbettal           #+#    #+#             */
/*   Updated: 2024/03/19 23:06:52 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_chunk(t_list *stack_a, t_list *stack_b)
{
	int		mid;
	int		position;

	while (stack_b)
	{
		while (stack_b != higher_num(stack_b))
		{
			mid = ft_lstsize(stack_b) / 2;
			position = position_finder(stack_b, 0);
			if (stack_b == second_higher_num(stack_b))
				push(&stack_b, &stack_a, 'a');
			if (position <= mid)
				rotate(&stack_b, 'b');
			else
				reverse_rotate(&stack_b, 'b');
		}
		push(&stack_b, &stack_a, 'a');
		if (stack_a->next && stack_a->index > stack_a->next->index)
			swap(&stack_a, 'a');
	}
	ft_lstclear(&stack_a);
}

void	chunk(t_list *stack_a, t_list *stack_b, int div)
{
	t_var	var;

	var.i = 0;
	var.origin_chunk = ft_lstsize(stack_a) / div;
	var.chunk = var.origin_chunk;
	var.midchunk = var.chunk / 2;
	while (stack_a)
	{
		while (stack_a->index >= var.chunk)
			rotate(&stack_a, 'a');
		push(&stack_a, &stack_b, 'b');
		if (stack_b->next && stack_b->index >= var.midchunk)
		{
			if (stack_a && stack_a->index >= var.chunk)
				rr(&stack_a, &stack_b);
			else
				rotate(&stack_b, 'b');
		}
		if (++var.i >= var.chunk)
		{
			var.chunk += var.origin_chunk;
			var.midchunk += var.origin_chunk;
		}
	}
	sort_chunk(stack_a, stack_b);
}
