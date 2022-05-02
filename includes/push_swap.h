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

//ERRORS CHECKERS.
int		ft_isdigit(int c);
int		ft_is_digit(char *str);
int		ft_is_sorted(t_list *lst);
int		ft_isduplicate(t_list **lst, t_list *node);

//MINILIBFT FUNCTIONS
long int	ft_atoi_l(const char *str);
t_list		*ft_lstnew(void *content);
char		**ft_split(char const *s, char c);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
t_list	*ft_smallest_node(t_list *lst);
t_list	*ft_biggerst_node(t_list *lst);

// Nothing yet
void	printlist(t_list *head);
int	ft_count_sorted(t_list **stack);
void threepb(t_list **stack_a, t_list **stack_b);
int	ft_reverse_sorted(t_list *lst);
int	ft_count_reverse_sorted(t_list **stack);
t_list	*ft_lst_beforelast(t_list *lst);
void	printlist(t_list *head);


//ALGORITHMS
void	ft_sort_three(t_list **stack_a);
void	ft_sort_four(t_list **stack_a, t_list **stack_b);

//ALGORITHMS UTLS
void ft_all_b_to_a(t_list **stack_a, t_list **stack_b);
t_list	*ft_lst_beforelast(t_list *lst);
int		ft_distance(t_list **head, void *content);

#endif