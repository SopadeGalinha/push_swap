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

void	ft_sort_five(t_list **stack_a, t_list stack_b)
{
	
}