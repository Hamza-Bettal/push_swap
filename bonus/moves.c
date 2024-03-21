/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 23:38:04 by hbettal           #+#    #+#             */
/*   Updated: 2024/03/20 03:10:25 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate(t_list **stack)
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
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	swap(t_list **stack)
{
	t_list	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = (*stack);
	(*stack) = tmp;
}

void	reverse_rotate(t_list **stack)
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
}

void	push(t_list **from, t_list **to)
{
	t_list	*tmp;

	if (!(*from))
		return ;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
}
