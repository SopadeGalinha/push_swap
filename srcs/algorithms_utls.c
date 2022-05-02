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

// PUSH ALL NUMBERS OF B TO A
void ft_all_b_to_a(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_b) >= 1)
		pa(stack_a, stack_b);
}

// FIND THE NODE BEFORE THE LAST ONE
t_list	*ft_lst_beforelast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

//SORT WITH THE NUMBERS
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

// Calculate the distance between the head of the node and the node searched
int		ft_distance(t_list **head, void *content)
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
