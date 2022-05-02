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
		else if (ft_smallest_node(*stack_a)->content == ft_lstlast(*stack_a)->content)
			rra(stack_a);
		else if (ft_biggerst_node(*stack_a)->content == (*stack_a)->content)
			ra(stack_a);
		else if ((*stack_a)->next->content == ft_smallest_node(*stack_a)->content)
			sa(stack_a);
		else
		{
			rra(stack_a);
			rra(stack_a);
		}
	}
}

// SORT THE STACK WITH 5 NUMBERS
void	ft_sort_five(t_list **stack_a, t_list ** stack_b)
{
	while (ft_is_sorted(*stack_a))
	{
		if (ft_smallest_node(*stack_a)->content == (*stack_a)->content)
		{
			pb(stack_a, stack_b);
			ft_sort_four(stack_a, stack_b);
		}
		break ;
	}
}
// 		else if (ft_count_sorted(stack_a) == 2)
// 		{
// 			if (ft_smallest_node(*stack_a)->content == (*stack_a)->content)
// 			{
// 				pb(stack_a, stack_b);
// 				ft_sort_three(stack_a);
// 			}
			
// 	}
// }

// 	while (ft_is_sorted(*stack_a))
// 	{
// 		while ((*stack_a)->content != ft_smallest_node(*stack_a)->content)
// 		{
// 			if ((*stack_a)->content > (*stack_a)->next->content)
// 				sa(stack_a);
// 			rra(stack_a);
// 		}
// 		if (ft_smallest_node(*stack_a)->content == (*stack_a)->content)
// 			pb(stack_a, stack_b);
// 		if (ft_lstsize(*stack_a) == 3)
// 			break;
// 	}
// 	ft_sort_three(stack_a);
// 	if (stack_b)
// 		ft_all_b_to_a(stack_a, stack_b);
// }
// /*
// void	ft_sort_five(t_list **stack_a, t_list **stack_b)
// {
// 	printf("Sorted = %d", ft_count_sorted(stack_a));
// 	while (!ft_is_sorted(*stack_a))
// 	{
// 		if (ft_count_sorted(stack_a) == 2)
// 		{
// 			if (ft_smallest_node(*stack_a)->content == (*stack_a)->content)
// 			{
// 				pb(stack_a, stack_b);
// 				pb(stack_a, stack_b);
// 				ft_sort_three(stack_a);
// 				ft_all_b_to_a(stack_a, stack_b);
// 			}
// 			else
// 			{
				
// 			}
// 		}
// 	}
// 	if (ft_count_sorted(stack_a) == 4)
// 	{
// 		if (ft_smallest_node(*stack_a)->content == (*stack_a)->content)
// 		{
// 			rra(stack_a);
// 			rra(stack_a);
// 			sa(stack_a);
// 			ra(stack_a);
// 			ra(stack_a);
// 		}
// 		else if (ft_smallest_node(*stack_a)->content == ft_lstlast(*stack_a)->content)
// 		{
// 			rra(stack_a);
// 		}
// 		else
// 		{
// 			rra(stack_a);
// 			rra(stack_a);
// 			sa(stack_a);
// 			ra(stack_a);
// 		}
// 	}
// }