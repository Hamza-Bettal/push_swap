/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:02:59 by hbettal           #+#    #+#             */
/*   Updated: 2024/03/09 21:32:08 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int     num;
	struct	s_list *next;
}   t_list;

// utilities*

void	args_check(int ac, char **av, t_list **s);
long     ft_atoi(char *str);
char	**ft_split(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
int     count_words(char *s, int c);
void	double_free(char **str);
t_list	*fill_stack(int ac, int *nums);

// list*

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);

typedef struct var
{
	char	*str;
	char	*tmp;
	char	**number;
	int		i;
	int		j;
	int		*nums;
}	t_var;

#endif