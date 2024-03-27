/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snegi <snegi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:53:41 by snegi             #+#    #+#             */
/*   Updated: 2024/02/14 10:53:44 by snegi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sort.h"

int	checksorted(int *array, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (array[i] > array[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

int	stack_checksort(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (1);
		head = head->next;
	}
	return (0);
}

static t_list	*next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;

	min = NULL;
	head = *stack;
	while (head)
	{
		if ((head->index == -1) && (min == NULL || (head->value < min->value)))
			min = head;
		head = head->next;
	}
	return (min);
}

void	stack_build(int *array, int len)
{
	t_list	*new;
	t_list	*stackb;
	t_list	*stacka;
	int		i;

	i = 0;
	stacka = NULL;
	stackb = NULL;
	while (i < len)
	{
		new = lstnew(array[i++]);
		lstadd_back(&stacka, new);
	}
	free(array);
	i = 0;
	new = next_min(&stacka);
	while (new)
	{
		new->index = i++;
		new = next_min(&stacka);
	}
	sort(&stacka, &stackb, len);
}
