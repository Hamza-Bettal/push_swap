/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:02:46 by hbettal           #+#    #+#             */
/*   Updated: 2024/03/09 21:32:41 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void f()
{
	system("leaks a.out");
}
int main(int ac, char **av)
{
	t_list *s;
	// atexit(f);
	s = NULL;
	if (ac > 1)
	{
		args_check(ac, av, &s);
		printf("done\n");
		while (s)
		{
			printf("%d\n", s->num);
			s = s->next;
		}
		return (0);
	}
	return (write(2, "error\n", 6), 1);
}