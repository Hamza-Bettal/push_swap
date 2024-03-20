/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:55:40 by hbettal           #+#    #+#             */
/*   Updated: 2024/03/20 01:59:15 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_moves	*ft_lstnew_new(char *content)
{
	t_moves	*new;

	new = malloc(sizeof(t_moves));
	if (!new)
		return (NULL);
	new->move = content;
	newget_next_line = NULL;
	return (new);
}

void	ft_lstadd_back_new(t_moves **lst, t_moves *new)
{
	t_moves	*unit;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	unit = *lst;
	while (unitget_next_line)
		unit = unitget_next_line;
	unitget_next_line = new;
}

void	ft_lstdelone_new(t_moves *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	ft_lstclear_new(t_moves **lst)
{
	t_moves	*tmp;

	if (!lst)
		return ;
	while ((*lst) != NULL)
	{
		tmp = (*lst)get_next_line;
		ft_lstdelone_new(*lst);
		(*lst) = tmp;
	}
	free(*lst);
}
