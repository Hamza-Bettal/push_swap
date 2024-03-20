/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:53:51 by hbettal           #+#    #+#             */
/*   Updated: 2024/03/18 22:51:55 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_of_three(t_list *stack)
{
	if (stack == higher_num(stack))
		rotate(&stack, 'a');
	else if (stack->next == higher_num(stack))
		reverse_rotate(&stack, 'a');
	if (stack->num > stack->next->num)
		swap(&stack, 'a');
	ft_lstclear(&stack);
}

void	sort_of_four(t_list *stack_a, t_list *stack_b)
{
	while (stack_a != lower_num(stack_a))
		reverse_rotate(&stack_a, 'a');
	push(&stack_a, &stack_b, 'b');
	sort_of_three(stack_a);
	push(&stack_b, &stack_a, 'a');
}

void	sort_of_five(t_list *stack_a, t_list *stack_b)
{
	int		size;

	size = ft_lstsize(stack_a);
	while (stack_a != lower_num(stack_a))
	{
		if (stack_a->next == lower_num(stack_a))
			rotate(&stack_a, 'a');
		else
			reverse_rotate(&stack_a, 'a');
	}
	push(&stack_a, &stack_b, 'b');
	sort_of_four(stack_a, stack_b);
	push(&stack_b, &stack_a, 'a');
}

void	ft_start(t_list *stack_a, t_list *stack_b)
{
	int	mode;

	mode = ft_lstsize(stack_a);
	if (mode <= 3)
		sort_of_three(stack_a);
	else if (mode == 4)
		sort_of_four(stack_a, stack_b);
	else if (mode == 5)
		sort_of_five(stack_a, stack_b);
	else if (mode > 5 && mode < 200)
		chunk(stack_a, stack_b, 5);
	else
		chunk(stack_a, stack_b, 9);
}

void	sort_check(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp;

	tmp = stack_a;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (ft_start(stack_a, stack_b));
		tmp = tmp->next;
	}
}
