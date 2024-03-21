/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_do.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:36:17 by hbettal           #+#    #+#             */
/*   Updated: 2024/03/21 00:25:16 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	do_rotate(t_list **a, t_list **b, char *line)
{
	if (!ft_strncmp(line, "ra\n", 3))
		rotate(a);
	else if (!ft_strncmp(line, "rb\n", 3))
		rotate(b);
	else if (!ft_strncmp(line, "rra\n", 4))
		reverse_rotate(a);
	else if (!ft_strncmp(line, "rrb\n", 4))
		reverse_rotate(b);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(a, b);
	else if (!ft_strncmp(line, "rrr\n", 4))
		(reverse_rotate(a), reverse_rotate(b));
	else
		return (1);
	return (0);
}

void	do_move(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!ft_strncmp(line, "sa\n", 3))
			swap(a);
		else if (!ft_strncmp(line, "sb\n", 3))
			swap(b);
		else if (!ft_strncmp(line, "pa\n", 3))
			push(b, a);
		else if (!ft_strncmp(line, "pb\n", 3))
			push(a, b);
		else if (!ft_strncmp(line, "ss\n", 3))
			(swap(a), swap(b));
		else if (do_rotate(a, b, line))
			(write(2, "Error\n", 6), free(line), exit(1));
		free(line);
		line = get_next_line(0);
	}
}
