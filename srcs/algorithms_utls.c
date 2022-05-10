/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_utls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <jhgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:26:58 by jhgoncal          #+#    #+#             */
/*   Updated: 2022/05/02 15:26:58 by jhgoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// PUSH ALL NUMBERS OF B TO A AND ORGANIZE
void ft_all_b_to_a(t_list **stack_a, t_list **stack_b)
{
	if (*stack_b == NULL)
		return ;
	while (*stack_b)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a);
		else if ((*stack_b)->content > (*stack_a)->content)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else if ((*stack_a)->content < (*stack_b)->content)
		{
			pb(stack_a, stack_b);
		}
		else
		pa(stack_a, stack_b);
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

//FIND THE SMALLEST NODE
t_list	*ft_smallest_node(t_list *lst)
{
	t_list	*smallest;
	t_list	*node;

	node = lst;
	smallest = lst;
	while (node->next)
	{
		node = node->next;
		if (smallest->content > node->content)
			smallest = node;
	}
	return (smallest);
}

//FIND THE BIGGERST NODE
t_list	*ft_biggerst_node(t_list *lst)
{
	t_list	*biggerst;
	t_list	*node;

	node = lst;
	biggerst = node;
	while (node->next)
	{
		node = node->next;
		if (node->content > biggerst->content)
			biggerst = node;
	}
	return (biggerst);
}

//PRINT THE CONTENT OF THE LIST (Integers)
void	ft_printlist(t_list *head)
{
	t_list *temporary;
	
	temporary = head;
	while (temporary != NULL)
	{
		printf("%ld -", (long int)temporary->content);
		temporary = temporary->next;
	}
	printf("\n");
}