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

void	ft_sort_three(t_list **stack_a)
{
	t_list	*node;

	node = *stack_a;
	// 3 2 1
	if (node->content > node->next->content &&
		node->next->content > ft_lstlast(*stack_a)->content)
		{
			sa(stack_a);
			rra(stack_a);
		}
	// 2 3 1
	else if (node->content > ft_lstlast(*stack_a)->content &&
		node->content < node->next->content)
			rra(stack_a);
	// 3 1 2
	else if (node->content > ft_lstlast(*stack_a)->content &&
		ft_lstlast(*stack_a)->content > node->next->content)
			ra(stack_a);
	//2 1 3
	else if (node->next->content < node->content && node->content < ft_lstlast(*stack_a)->content)
		sa(stack_a);
	// 1 3 2
	else
	{
		sa(stack_a);
		ra(stack_a);
	}
	if (ft_is_sorted(*stack_a))
		write(1, "Not Sorted\n", 11);
}

void threepb(t_list **stack_a, t_list **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
}

void ft_all_b_to_a(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_b) >= 1)
		pa(stack_a, stack_b);
}


void	ft_sort_six(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	node = *stack_a;
	while (ft_lstsize(*stack_a) != 3)
	{
		if (ft_count_sorted(stack_a) == 3)
		{
			threepb(stack_a, stack_b);
			break ;
		}
		if (node->content == ft_smallest_node(*stack_a)->content)
			pb(stack_a, stack_b);
	}
	while (1)
	{
		if (ft_lstsize(*stack_b) > 2 &&
			reverse_sorted(*stack_b) && ft_is_sorted(*stack_a)
			{
				threepb(stack_a, stack_b);
				break ;
			}
	}
}

/* void	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	t_list *node;

	node = *stack_a;
	while (*stack_a && ft_is_sorted(*stack_a))
	{
		if (ft_lstlast(*stack_a)->content == ft_smallest_node(*stack_a)->content)
		{
			rra(stack_a);
			node = *stack_a;
			if (node->content > node->next->content)
				sa(stack_a);
			else
				pb(stack_a, stack_b);
		}
		if (ft_lstlast(*stack_a)->content == ft_biggerst_node(*stack_a)->content)
		{
			rra(stack_a);
			sa(stack_a);
		}
		sa(stack_a);
		if (ft_reverse_sorted(*stack_b))
		{
			while (ft_lstsize(*stack_b) > 0)
				pa(stack_a, stack_b);

		}
	}
	printf("Sorted: %d", ft_count_sorted(stack_a));
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if (ft_count_sorted(stack_a) == 3)
	{
		rra(stack_a);
		rra(stack_a);
		sa(stack_a);
		ra(stack_a);
		ra(stack_a);
	}

	if (*stack_b)
	{
		printf("Stack B: ");
		printlist(*stack_b);
	}
		
}
 */