/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 23:38:04 by hbettal           #+#    #+#             */
/*   Updated: 2024/03/11 00:27:59 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack)
{
	int nbr;
	t_list	*tmp;
	
	tmp = *stack;
	nbr = tmp->num;
	while (tmp->next)
	{
		tmp->num = tmp->next->num;
		tmp = tmp->next;
	}
	tmp->num = nbr;
	printf("done 1\n");
}

void	sa(t_list **stack)
{
	t_list *tmp;
	int nbr;

	tmp = *stack;
	nbr = (*stack)->num;
	(*stack)->num = tmp->next->num;
	tmp->num = nbr;
	printf("done 2\n");
}
