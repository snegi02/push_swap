/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snegi <snegi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:52:56 by snegi             #+#    #+#             */
/*   Updated: 2024/02/14 10:52:59 by snegi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sort.h"

t_list	*lstnew(int value)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

void	lstadd_front(t_list **stackA, t_list *new)
{
	new->next = *stackA;
	*stackA = new;
}

t_list	*lstlast(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	lstadd_back(t_list **stackA, t_list *new)
{
	t_list	*last;

	if (*stackA)
	{
		last = lstlast(*stackA);
		last->next = new;
		new->next = NULL;
	}
	else
	{
		*stackA = new;
		(*stackA)->next = NULL;
	}
}

int	lstsize(t_list *head)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = head;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
