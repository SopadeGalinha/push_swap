/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_linkedlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <jhgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:37:45 by jhgoncal          #+#    #+#             */
/*   Updated: 2022/04/27 12:37:45 by jhgoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

