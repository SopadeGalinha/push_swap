/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhgoncal <jhgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:28:09 by jhgoncal          #+#    #+#             */
/*   Updated: 2022/04/16 12:28:09 by jhgoncal         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_check_and_init(char **av, int i);
/* This function will check errors and 
** initialize Stack A.
  ERRORS:
** The arguments are not only numbers;
** Argument bigger than MAX_INT; 
** There are duplicates.
** The list it's sorted
*/

// JUST TO VISUALIZE WHAT I AM DOING.
void	printlist(t_list *head);
int		ft_lstsize(t_list *lst);

int main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	i = -1;
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		i = 0;
	stack_a = ft_check_and_init(av, i);

	printf("Stack A: ");
	printlist(stack_a);
	ft_sort_six(&stack_a, &stack_b);
	printf("\nStack A: ");
	printlist(stack_a);
	if (stack_b)
	{
		printf("\nStack B: ");
		printlist(stack_b);
	}

}

t_list	*ft_check_and_init(char **av, int i)
{
	t_list		*stack_a;
	t_list		*node;
	long int	_atoi;

	_atoi = 0;
	node = NULL;
	while (av[++i])
	{
		_atoi = ft_atoi_l(av[i]);
		if (_atoi > 2147483647)
			exit (write(1, "ErrorMaxInt", 11));
		if (!ft_is_digit(av[i]))
			exit (write(1, "ErrorNotDigit", 13));
		node = ft_lstnew((long int *)_atoi);
		ft_lstadd_back(&stack_a, node);
		if (ft_isduplicate(&stack_a, node))
			exit (write(1,"ErrorDuplicate", 8));
	}
	if (!ft_is_sorted(stack_a))
		exit (write(1, "ErrorSorted", 11));
	node = stack_a;
	return (stack_a);
}

void	printlist(t_list *head)
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