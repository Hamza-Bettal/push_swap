/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:02:59 by hbettal           #+#    #+#             */
/*   Updated: 2024/03/17 21:37:44 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

// struct*
typedef struct s_list
{
	int				num;
	struct s_list	*next;
	int				index;
}	t_list;

typedef struct var
{
	char	*str;
	char	*tmp;
	char	**number;
	int		i;
	int		j;
	int		*nums;
}	t_var;

// utilities*
void	args_check(int ac, char **av, t_list **s);
long	ft_atoi(char *str);
char	**ft_split(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
int		count_words(char *str, char c);
void	double_free(char **str);
void	sort_check(t_list *stack_a, t_list *stack_b);
t_list	*higher_num(t_list *stack);
t_list	*lower_num(t_list *stack);
void	chunk(t_list *stack_a, t_list *stack_b, int div);
t_list	*second_higher_num(t_list *stack);
int		position_finder(t_list *stack, int w);
int		lower_pos(t_list *stack, int index);
char	*get_str(t_var	var, int ac, char **av);

// list*
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);

// moves*
void	rotate(t_list **stack, char type);
void	swap(t_list **stack, char type);
void	reverse_rotate(t_list **stack, char type);
void	push(t_list	**from, t_list **to, char type);

#endif