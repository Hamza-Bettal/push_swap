/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:06:24 by hbettal           #+#    #+#             */
/*   Updated: 2024/03/09 21:46:03 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*fill_stack(int ac, int *nums)
{
	int i;
	t_list *stack;
	t_list *tmp;
	
	i = 0;
	while (ac > i++)
	{
		ft_lstadd_back(&stack ,ft_lstnew(nums[i]));
		printf("%d\n", nums[i]);
	}
	tmp = stack;
	return (tmp);
}

void double_check(int ac, char **av, t_list **s)
{
	t_var	var;
	
	var.i = 0;
	var.str = NULL;
	while (++var.i < ac)
	{
		var.tmp = var.str;
		var.str = ft_strjoin(var.tmp, av[var.i]);
		free(var.tmp);
	}
	var.number = ft_split(var.str, ' ');
	var.nums = malloc(count_words(var.str, ' ') * sizeof(int));
	var.i = -1;
	while (var.number[++var.i] )
		var.nums[var.i] = (int)ft_atoi(var.number[var.i]);
	var.i = -1;
	while (++var.i < count_words(var.str, ' '))
	{
		var.j = var.i;
		while (++var.j < count_words(var.str, ' '))
			if (var.nums[var.i] == var.nums[var.j])
				(write(2, "error\n", 6), exit(1));
	}
	*s = fill_stack(ac, var.nums);
	(double_free(var.number), free(var.str), free(var.nums));
}

void args_check(int ac, char **av, t_list **s)
{
	char	**numbers;
	int		i;
	int		j;
	
	i = 1;
	while (i < ac)
	{
		j = 0;
		numbers = ft_split(av[i], ' ');
		while (numbers[j])
		{
			if (ft_atoi(numbers[j]) > 2147483647 || ft_atoi(numbers[j]) < -214748648)
				(write(2, "error\n", 6), exit(1));
			free(numbers[j]);
			j++;
		}
		free(numbers);
		i++;
	}
	double_check(ac, av, s);
}
