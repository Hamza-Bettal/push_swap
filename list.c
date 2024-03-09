/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:24:23 by hbettal           #+#    #+#             */
/*   Updated: 2024/03/09 18:54:45 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));

	if (!new)
		return (NULL);
	new->num = content;
	new->next = NULL;
	return (new);
}
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*unit;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	unit = *lst;
	while (unit->next)
		unit = unit->next;
	unit->next = new;
}