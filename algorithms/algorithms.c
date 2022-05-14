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

// Calculate the distance between the head of the node and the node searched
int		ft_lstdistance(t_list **head, void *content)
{
	t_list *temporary;
	int		d;

	d = 0;
	temporary = *head;
	while (temporary != NULL)
	{
		d++;
		if (temporary->content == (void *)content)
			return (d);
		temporary = temporary->next;
	}
	return (d);
}

// SORT WITH THREE NUMBERS
void	ft_sort_three(t_list **stack_a)
{
	t_list	*node;

	node = *stack_a;
	if (!ft_is_sorted(*stack_a))
		return ;
	if (node->content > node->next->content &&
		node->next->content > ft_lstlast(*stack_a)->content)
		{
			sa(stack_a);
			rra(stack_a);
		}
	else if (node->content > ft_lstlast(*stack_a)->content &&
		node->content < node->next->content)
			rra(stack_a);
	else if (node->content > ft_lstlast(*stack_a)->content &&
		ft_lstlast(*stack_a)->content > node->next->content)
			ra(stack_a);
	else if (node->next->content < node->content && node->content < ft_lstlast(*stack_a)->content)
		sa(stack_a);
	else
	{
		sa(stack_a);
		ra(stack_a);
	}
}

// SORT WITH FOUR NUMBERS
void	ft_sort_four(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 3)
		ft_sort_three(stack_a);
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

// SORT TILL SEVEN NUMBERS
void	ft_sort_seven(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = ft_lstsize(*stack_a);
	while (ft_is_sorted(*stack_a))
	{
		if (ft_lstsize(*stack_a) == 3 || ft_lstsize(*stack_a) == 4)
			ft_sort_four(stack_a, stack_b);
		if (ft_lstsize(*stack_a) == 4 || !ft_is_sorted(*stack_a))
		{
			ft_sort_four(stack_a, stack_b);
			while(ft_lstsize(*stack_a) != i)
				pa(stack_a, stack_b);
			continue ;
		}
		else if (ft_smallest_node(*stack_a)->content == (*stack_a)->content)
			pb(stack_a, stack_b);
		else if((*stack_a)->next->content == ft_smallest_node(*stack_a)->content)
			sa(stack_a);
		else if (ft_lstdistance(stack_a, ft_smallest_node(*stack_a)->content)  == (ft_lstsize(*stack_a) - 3)
			|| ft_lstdistance(stack_a, ft_smallest_node(*stack_a)->content)  == (ft_lstsize(*stack_a) - 2)
				|| ft_lst_beforelast(*stack_a)->content == ft_smallest_node(*stack_a)->content
					|| ft_lstlast(*stack_a)->content == ft_smallest_node(*stack_a)->content)
						rra(stack_a);
		else if((*stack_a)->content < ft_lstlast(*stack_a)->content)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

//SORT ALL NUMBERS
void	ft_sort_up(t_list **stack_a, t_list **stack_b);

/*----------------------------------------------------------------*/


void	ft_with_a(t_list ** stack_a, t_list **stack_b)
{
		if (ft_lstsize(*stack_a) == 7)
			ft_sort_seven(stack_a, stack_b);
		else if ((*stack_a)->content == ft_smallest_node(*stack_a)->content)
			pb(stack_a, stack_b);
		else if(ft_lst_beforelast(*stack_a)->content == ft_smallest_node(*stack_a)->content)
				rra(stack_a);
		else if ((*stack_a)->content > ft_lstlast(*stack_a)->content)
			rra(stack_a);
		else if ((*stack_a)->content > (*stack_a)->next->content)
			ra(stack_a);
		else if (ft_lstlast(*stack_a)->content == ft_biggerst_node(*stack_a)->content)
			sa(stack_a);
		else
			pb(stack_a, stack_b);
}

void	ft_with_b(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 7)
		ft_sort_seven(stack_a, stack_b);
	if (ft_lstsize(*stack_b) > 1 && ft_reverse_sorted(*stack_b))
	{
		if (ft_lst_beforelast(*stack_b)->content > (*stack_b)->content
			|| ft_lstlast(*stack_b)->content > (*stack_b)->content)
			{
				if(ft_lst_beforelast(*stack_a)->content == ft_smallest_node(*stack_a)->content)
					rrr(stack_a, stack_b);
				else if ((*stack_a)->content > ft_lstlast(*stack_a)->content)
					rrr(stack_a, stack_b);
				else
					rrb(stack_b);
			}
		else if ((*stack_b)->content < ft_lstlast(*stack_b)->content)
			rb(stack_b);
		else if ((*stack_b)->content < (*stack_b)->next->content)
			sb(stack_b);
	}
}

void	ft_sort_up(t_list **stack_a, t_list **stack_b)
{
	while(ft_is_sorted(*stack_a))
	{
		ft_with_a(stack_a, stack_b);
		ft_with_b(stack_a, stack_b);
	}
	ft_all_b_to_a(stack_a, stack_b);
}

void	ft_sort_numbers(t_list **stack_a, t_list ** stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a);
	else if (ft_lstsize(*stack_a) <= 7)
		ft_sort_seven(stack_a, stack_b);
	else
		ft_sort_up(stack_a, stack_b);
}
