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

/*
** Init A with the list.
** Init B as empty.
** Check if the data is sorted.
** The first argument must be the head of the list
** the program must work with only two arguments. Ex:
$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list	*ft_check_and_init(char **av, int i);
/* This function will check errors and 
** initialize Stack A.
  ERRORS:
** The arguments are not only numbers;
** Argument bigger than MAX_INT; 
** There are duplicates.
** The list it's sorted
*/

//BACKUP FUNCTIONS
t_list		*ft_lstnew(void *content);
long int	ft_atoi_l(const char *str);
char		**ft_split(char const *s, char c);
void		ft_lstadd_back(t_list **lst, t_list *new);

// JUST TO VISUALIZE WHAT I AM DOING.
void	printlist(t_list *head);
int		ft_lstsize(t_list *lst);

//ERRORS CHECKERS.
int		ft_isdigit(int c);
int		ft_is_digit(char *str);
int		ft_is_sorted(t_list *lst);
int		ft_isduplicate(t_list **lst, t_list *node);


//IN PROGRESS
// int	ft_is_argument(const char *str);
t_list	*ft_lstdelfront(t_list *head);
void	shiftup(t_list **stack);


//PUSH && SWAP FUNCTIONS
void	swap(t_list **stack);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);

void	push(t_list **stack_src, t_list **stack_dst);
void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);


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
	// pb(&stack_a, &stack_b);
	// pa(&stack_a, &stack_b);
	// sa(&stack_a);
	shiftup(&stack_a);


	printf("Stack A: ");
	printlist(stack_a);
	// printf("Stack B: ");
	// printlist(stack_b);
}
//SWAP FUNCTION
void	swap(t_list **stack)
{
	t_list	*swap;
	t_list	*tmp;

	tmp = *stack;
	swap =(*stack)->next;
	(*stack)->next = swap->next;
	*stack = swap;
	(*stack)->next = tmp;
}

//Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one or no elements.
void	sa(t_list **stack_a)
{
	if (!stack_a || !*stack_a || ft_lstsize(*stack_a) < 2)
		return ;
	swap(stack_a);
	write(1, "sa\n", 3);
}

//SB: Swap the first 2 elements at the top of stack b.
//Do nothing if there is only one or no elements
void	sb(t_list **stack_b)
{
	if (!stack_b || !*stack_b || ft_lstsize(*stack_b) < 2)
		return ;
	swap(stack_b);
	write(1, "sb\n", 3);
	
}

//SS: sa and sb at the same time.
void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write (1, "ss\n", 3);
}


//PUSH FUNCTION
void push(t_list **stack_src, t_list **stack_dst)
{
	t_list *temporary;
	temporary = *stack_src;
	*stack_src = (*stack_src)->next;
	temporary->next = *stack_dst;
	*stack_dst = temporary;
}

//PA: Take the first element at the top of b and put it at the top of a
void	pa(t_list **stack_a, t_list **stack_b)
{
	if (!stack_b)
		return ;
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

//PB: Take the first element at the top of a and put it at the top of b
void	pb(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a)
		return ;
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}


t_list	*ft_lstlast(t_list *lst);

//SHIFT UP FUNCTION
void	shiftup(t_list **stack)
{
	t_list	*tail;
	t_list	*head;

	tail = ft_lstlast(*stack);
	head = *stack;
	*stack = (*stack)->next;
	tail->next = head;
	head->next = NULL;

	printf("H: %ld\n", (long int)head->content); 
	printf("T: %ld\n", (long int)tail->content); 
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}




//ALREADY DONE//

t_list	*ft_check_and_init(char **av, int i)
{
	t_list		*stack_a;
	t_list		*node;
	long int	_atoi;

	_atoi = 0;
	stack_a = NULL;
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

int	ft_is_sorted(t_list *lst)
{
	t_list	*temporary;
	
	temporary = lst;
	while (temporary->next != NULL)
	{
		if (temporary->content > temporary->next->content)
			break ;
		temporary = temporary->next;
	}
	if (temporary->next == NULL)
		return (0);
	return (1);
}

int	ft_isduplicate(t_list **lst, t_list *node)
{
	t_list *temporary;

	temporary = *lst;
	if (*lst == NULL)
		return (0);
	while (temporary->next != NULL)
	{
		if (temporary->content == node->content)
			return (1);
		temporary = temporary->next;
	}
	return (0);
}

int	ft_is_digit(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	count_words(char const *s, char c)
{
	int	c_words;
	int	trigger;

	c_words = 0;
	trigger = 0;
	while (*s)
	{
		if (*s != c && trigger == 0)
		{
			c_words++;
			trigger = 1;
		}
		else if (*s == c)
			trigger = 0;
		s++;
	}
	return (c_words);
}

static char	*split_word(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static char	**splitting(char **split, char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		start;

	i = 0;
	j = 0;
	start = -1;
	while (i <= strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == strlen(s)) && start >= 0)
		{
			split[j++] = split_word(s, start, i);
			start = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (0);
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (0);
	return (splitting(split, s, c));
}

long int	ft_atoi_l(const char *str)
{
	long int	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}

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

t_list *ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
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
