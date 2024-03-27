/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snegi <snegi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:53:21 by snegi             #+#    #+#             */
/*   Updated: 2024/02/14 10:53:23 by snegi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sort.h"

void	sa(t_list **stackA)
{
	t_list	*head;
	t_list	*next;
	int		temp;
	int		index;

	head = *stackA;
	next = head->next;
	temp = head->value;
	index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = temp;
	next->index = index;
	write (1, "sa\n", 3);
}

void	ra(t_list **stackA)
{
	t_list	*head;
	t_list	*last;

	head = *stackA;
	last = lstlast(head);
	*stackA = head->next;
	head->next = NULL;
	last->next = head;
	write(1, "ra\n", 3);
}

void	rra(t_list **stackA)
{
	t_list	*head;
	t_list	*last;

	head = *stackA;
	last = lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	last->next = *stackA;
	*stackA = last;
	write(1, "rra\n", 4);
}

void	pa(t_list **stack_to, t_list **stack_from)
{
	t_list	*temp;
	t_list	*head_to;
	t_list	*head_from;

	head_to = *stack_to;
	head_from = *stack_from;
	temp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = temp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		temp->next = head_to;
		*stack_to = temp;
	}
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_from, t_list **stack_to)
{
	t_list	*temp;
	t_list	*head_to;
	t_list	*head_from;

	head_to = *stack_to;
	head_from = *stack_from;
	temp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = temp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		temp->next = head_to;
		*stack_to = temp;
	}
	write(1, "pb\n", 3);
}
