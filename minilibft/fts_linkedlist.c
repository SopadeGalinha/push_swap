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

//ADD THE NODE AT THE END OF THE LIST
// if the list is empty the node becomes the first node of the list
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temporary;

	temporary = *lst;
	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		new->next = *lst;
		*lst = new;
		return ;
	}
	while (temporary->next)
		temporary = temporary->next;
	temporary->next = new;
}

//CREATE A NEW NODE
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

//FIND THE LAST NODE
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

//RETURN THE SIZE OF THE LIST
int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!(lst))
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
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
