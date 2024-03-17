/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 23:38:04 by hbettal           #+#    #+#             */
/*   Updated: 2024/03/17 21:30:36 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack, char type)
{
	t_list	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	(*stack) = (*stack)->next;
	tmp->next->next = NULL;
	if (type == 'a')
		write(1, "ra\n", 3);
	else if (type == 'b')
		write(1, "rb\n", 3);
	else if (type == 'm')
		write(1, "rr\n", 3);
}

void	swap(t_list **stack, char type)
{
	t_list	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	(*stack) = tmp;
	if (type == 'a')
		write(1, "sa\n", 3);
	else if (type == 'b')
		write(1, "sb\n", 3);
}

void	reverse_rotate(t_list **stack, char type)
{
	t_list	*tmp;
	t_list	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = (*stack);
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	last->next = *stack;
	tmp->next = NULL;
	*stack = last;
	if (type == 'a')
		write(1, "rra\n", 4);
	else if (type == 'b')
		write(1, "rrb\n", 4);
}

void	push(t_list **from, t_list **to, char type)
{
	t_list	*tmp;

	if (!(*from))
		return ;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
	if (type == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}
