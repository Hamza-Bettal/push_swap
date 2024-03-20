/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:51:30 by hbettal           #+#    #+#             */
/*   Updated: 2024/03/20 00:45:59 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define BUFFER_SIZE 100

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

// struct*
typedef struct s_list
{
	int				num;
	struct s_list	*next;
}	t_list;

typedef struct s_moves
{
	char			*move;
	struct s_moves	*next;
}	t_moves;

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
char    *ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
size_t		ft_strlen(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char    **ft_split(char *s, char c);
long		ft_atoi(char *s);
void	args_check(int ac, char **av, t_list **s);
char	*get_next_line(int fd);
char	*get_str(t_var	var, int ac, char **av);
int		count_words(char *str, char c);
void	double_free(char **str);
char	*get_strjoin(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// moves*
void	rotate(t_list **stack);
void	swap(t_list **stack);
void	reverse_rotate(t_list **stack);
void	push(t_list	**from, t_list **to);
void	rr(t_list **stack_a, t_list **stack_b);
void    user_move(t_list *a, t_list *b, t_moves *move);

// list*
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
t_moves	*ft_lstnew_new(char *content);
void	ft_lstclear_new(t_moves **lst);
void	ft_lstdelone_new(t_moves *lst);
void	ft_lstadd_back_new(t_moves **lst, t_moves *new);

#endif