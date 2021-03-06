/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <jhgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:22:54 by jhgoncal          #+#    #+#             */
/*   Updated: 2022/04/27 11:22:54 by jhgoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*________________________________HEADERS__________________________________*/

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

/*_________________________________STRUCT___________________________________*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
/*__________________________MANDATORY_FUNCTIONS_____________________________*/

//PUSH
void	push(t_list **stack_src, t_list **stack_dst);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

//SWAP
void	swap(t_list **stack);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);

//ROTATE
void	rotate(t_list **stack);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);

//REVERSE_ROTATE
void	reverse_rotate(t_list **stack);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

/*_______________________________FUNCTIONS__________________________________*/

//MINILIBFT FUNCTIONS
int			ft_is_digit(char *str);
long int	ft_atoi_l(const char *str);
char		**ft_split(char const *s, char c);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(void *content);
t_list		*ft_lst_beforelast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);

//ALGORITHMS
void	ft_sort_three(t_list **stack_a);
void	ft_sort_four(t_list **stack_a, t_list **stack_b);
void	ft_sort_seven(t_list **stack_a, t_list **stack_b);
void	ft_sort_up(t_list **stack_a, t_list **stack_b);
void	ft_sort_numbers(t_list **stack_a, t_list ** stack_b);

//ALGORITHMS_UTLS
void	ft_printlist(t_list *head);//TEMPORARY
t_list	*ft_smallest_node(t_list *lst);
t_list	*ft_biggerst_node(t_list *lst);
int		ft_lstdistance(t_list **head, void *content);
void ft_all_b_to_a(t_list **stack_a, t_list **stack_b);

//ALGORITHMS_REVERSE
int		ft_reverse_sorted(t_list *lst);
void	ft_reverse_sort_three(t_list **stack_b);
void	ft_reverse_sort_four(t_list **stack_a, t_list **stack_b);
void	ft_reverse_sort_five(t_list **stack_a, t_list **stack_b);


//CHECKERS
t_list	*ft_check_and_init(char **av, int i);
int	ft_isduplicate(t_list **lst, t_list *node);
int	ft_is_sorted(t_list *lst);

#endif