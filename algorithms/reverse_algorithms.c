/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <jhgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 00:37:53 by jhgoncal          #+#    #+#             */
/*   Updated: 2022/05/21 00:37:53 by jhgoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//SORT THREE NUMBERS IN REVERSE ORDER
void	ft_reverse_sort_three(t_list **stack_b)
{
	if (!ft_reverse_sorted(*stack_b))
		return ;
	if ((*stack_b)->content == ft_biggerst_node(*stack_b)->content)
	{
		rrb(stack_b);
		sb(stack_b);
	}
	else if (ft_lstlast(*stack_b)->content == ft_biggerst_node(*stack_b)->content)
	{
		if ((*stack_b)->content == ft_smallest_node(*stack_b)->content)
		{
			sb(stack_b);
			rrb(stack_b);
		}
		else
			rrb(stack_b);
	}
	else
	{
		if ((*stack_b)->content == ft_smallest_node(*stack_b)->content)
			rb(stack_b);
		else
			sb(stack_b);
	}
}

//SORT FOUR NUMBERS IN REVERSE ORDER
void	ft_reverse_sort_four(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_b) == 3)
		ft_reverse_sort_three(stack_b);
	while (ft_reverse_sorted(*stack_b))
	{
		if ((*stack_b)->content == ft_biggerst_node(*stack_b)->content)
		{
			pa(stack_a, stack_b);
			ft_reverse_sort_three(stack_b);
			pb(stack_a, stack_b);
		}
		else if (ft_biggerst_node(*stack_b)->content == (*stack_b)->next->content)
			sb(stack_b);
		else
			rrb(stack_b);
	}
}

void	ft_reverse_sort_five(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_b) <= 4)
		ft_reverse_sort_four(stack_a, stack_b);
	while (ft_reverse_sorted(*stack_b))
	{
		if (ft_lstsize(*stack_b) == 4)
		{
			ft_reverse_sort_four(stack_a, stack_b);
			pb(stack_a, stack_b);
		}
		else if ((*stack_b)->content == ft_biggerst_node(*stack_b)->content)
			pa(stack_a, stack_b);
		else if (ft_biggerst_node(*stack_b)->content == (*stack_b)->next->content)
			sb(stack_b);
		else if (ft_lstlast(*stack_b)->content == ft_biggerst_node(*stack_b)->content
			|| ft_lst_beforelast(*stack_b)->content == ft_biggerst_node(*stack_b)->content)
				rrb(stack_b);
		else if ((*stack_b)->next->content < ft_lstlast(*stack_b)->content)
			rb(stack_b);
		else
		 rrb(stack_b);
	}
}
//CHECK IF THE LIST IS REVERSE SORTED
int	ft_reverse_sorted(t_list *lst)
{
	t_list	*temporary;
	
	temporary = lst;
	while (temporary->next != NULL)
	{
		if (temporary->content < temporary->next->content)
			break ;
		temporary = temporary->next;
	}
	if (temporary->next == NULL)
		return (0);
	return (1);
}
