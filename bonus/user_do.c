/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_do.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:36:17 by hbettal           #+#    #+#             */
/*   Updated: 2024/03/20 01:01:29 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	do_rotate(t_list *a, t_list *b, t_moves *move)
{
	if (!ft_strncmp(move->move, "ra\n", 3))
		rotate(&a);	
	else if (!ft_strncmp(move->move, "rb\n", 3))
		rotate(&b);
	else if (!ft_strncmp(move->move, "rra\n", 4))
		reverse_rotate(&a);
	else if (!ft_strncmp(move->move, "rrb\n", 4))
		reverse_rotate(&b);
	else if (!ft_strncmp(move->move, "rr\n", 3))
		rr(&a, &b);
    else if (!ft_strncmp(move->move, "rrr\n", 4))
        (reverse_rotate(&a), reverse_rotate(&b));
    else
        return (1);
    return (0);
}

void	do_move(t_list *a, t_list *b, t_moves *move)
{
	while (move)
	{
		if (!ft_strncmp(move->move, "sa\n", 3))
			swap(&a);
		else if (!ft_strncmp(move->move, "sb\n", 3))
			swap(&b);
		else if (!ft_strncmp(move->move, "pa\n", 3))
			push(&b, &a);
		else if (!ft_strncmp(move->move, "pb\n", 3))
			push(&a, &b);
        else if (!ft_strncmp(move->move, "ss\n", 3))
            (swap(&a), swap(&b));
        else if (do_rotate(a, b, move))
            (write(2, "Error\n", 6), exit(1));
		move = move->next;
	}
}

void    user_move(t_list *a, t_list *b, t_moves *move)
{
	char	*line;

	move = NULL;
	line = get_next_line(0);
	while (line)
	{
		ft_lstadd_back_new(&move, ft_lstnew_new(line));
		line = get_next_line(0);
	}
	do_move(a, b, move);
}
