/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:06:24 by hbettal           #+#    #+#             */
/*   Updated: 2024/03/20 23:36:14 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_assist(t_list *iter, int min, int index)
{
	while (iter)
	{
		if (iter->num < min)
			index++;
		iter = iter->next;
	}
	return (index);
}

void	get_index(t_list **stack)
{
	t_list	*tmp;
	t_list	*iter;
	int		index;
	int		min;

	tmp = *stack;
	while (tmp)
	{
		min = INT_MAX;
		iter = *stack;
		while (iter)
		{
			if (iter->num >= tmp->num && iter->num < min)
				min = iter->num;
			iter = iter->next;
		}
		index = 0;
		iter = *stack;
		index = index_assist(iter, min, index);
		tmp->index = index;
		tmp = tmp->next;
	}
}

t_list	*fill_stack(int j, int *nums)
{
	int		i;
	t_list	*stack;

	stack = NULL;
	i = -1;
	while (j > ++i)
		ft_lstadd_back(&stack, ft_lstnew(nums[i]));
	get_index(&stack);
	return (stack);
}

void	double_check(int ac, char **av, t_list **s)
{
	t_var	var;

	var.i = 0;
	var.str = NULL;
	var.str = get_str(var, ac, av);
	var.number = ft_split(var.str, ' ');
	var.nums = malloc(count_words(var.str, ' ') * sizeof(int));
	if (!var.nums)
		exit (1);
	var.i = -1;
	while (var.number[++var.i])
		var.nums[var.i] = (int)ft_atoi(var.number[var.i]);
	var.i = -1;
	while (++var.i < count_words(var.str, ' '))
	{
		var.j = var.i;
		while (++var.j < count_words(var.str, ' '))
			if (var.nums[var.i] == var.nums[var.j])
				(write(2, "Error\n", 6), exit(1));
	}
	*s = fill_stack(count_words(var.str, ' '), var.nums);
	(double_free(var.number), free(var.str), free(var.nums));
}

void	args_check(int ac, char **av, t_list **s)
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
			if (ft_atoi(numbers[j]) > INT_MAX || ft_atoi(numbers[j]) < INT_MIN)
				(write(2, "Error\n", 6), exit(1));
			free(numbers[j]);
			j++;
		}
		free(numbers);
		i++;
	}
	double_check(ac, av, s);
}
