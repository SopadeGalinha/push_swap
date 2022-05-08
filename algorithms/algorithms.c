/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <jhgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:42:19 by jhgoncal          #+#    #+#             */
/*   Updated: 2022/04/28 13:42:19 by jhgoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// SORT WITH FOUR NUMBERS
void	ft_sort_four(t_list **stack_a, t_list **stack_b)
{
	while (ft_is_sorted(*stack_a))
	{
		if ((*stack_a)->content == ft_smallest_node(*stack_a)->content)
		{
			pb(stack_a, stack_b);
			ft_sort_three(stack_a);
			pa(stack_a, stack_b);
		}
		else if (ft_biggerst_node(*stack_a)->content == (*stack_a)->content)
			ra(stack_a);
		else if (ft_smallest_node(*stack_a)->content == ft_lstlast(*stack_a)->content)
			rra(stack_a);
		else if ((*stack_a)->next->content == ft_smallest_node(*stack_a)->content)
			sa(stack_a);
		else
		{
			rra(stack_a);
			rra(stack_a);
		}
	}
}

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

void ft_simplesort_b(t_list **stack_b)
{
	if ((*stack_b)->content < (*stack_b)->next->content)
		sb(stack_b);
	 else
	 	return ;
}

void	ft_small_to_b_beggining(t_list **stack_a, t_list **stack_b)
{
	t_list	*small_node;
	
	small_node = ft_smallest_node(*stack_a);
	while (ft_lstfind(stack_a, small_node->content) != NULL)
	{
		if ((*stack_a)->content == ft_smallest_node(*stack_a)->content)
			pb(stack_a, stack_b);
		else if(ft_lst_beforelast(*stack_a)->content == ft_smallest_node(*stack_a)->content)
			rra(stack_a);
		else if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a);
		else if ((*stack_a)->content > ft_lstlast(*stack_a)->content)
			rra(stack_a);
		else
			pb(stack_a, stack_b);
		if (ft_lstsize(*stack_b) > 1 && ft_reverse_sorted(*stack_b))
		{
			if (ft_lstsize(*stack_b) == 3)
				ft_reverse_sort_three(stack_b);
			if ((*stack_b)->content < ft_lstlast(*stack_b)->content)
				rb(stack_b);
			ft_simplesort_b(stack_b);
		}
	}
}

// SORT UP SIX NUMBERS
void	ft_sort_six(t_list **stack_a, t_list ** stack_b)
{
	if (ft_lstsize(*stack_a) == 3)
		ft_sort_three(stack_a);	
	else
		ft_small_to_b_beggining(stack_a, stack_b);
	while (ft_is_sorted(*stack_a))
	{
		if (ft_lstsize(*stack_a) == 4)
			ft_sort_four(stack_a, stack_b);
		else if (ft_lstsize(*stack_a) == 3)
			ft_sort_three(stack_a);
		else
			ft_small_to_b_beggining(stack_a, stack_b);
	}
		ft_all_b_to_a(stack_a, stack_b);
}