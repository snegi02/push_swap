/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snegi <snegi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:55:59 by snegi             #+#    #+#             */
/*   Updated: 2024/02/14 14:56:26 by snegi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"

int	lenght(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	same_num(int a, int b, int *array)
{
	if (a == b)
	{
		free(array);
		return (0);
	}
	return (1);
}

void	little_sort(t_list **stackA)
{
	int	i;

	i = 1;
	while (i >= 1)
	{
		if ((*stackA)->index > (*stackA)->next->index)
			sa(stackA);
		else if ((*lstlast(*stackA)).index < (*stackA)->index)
			rra(stackA);
		else if ((*lstlast(*stackA)).index < (*stackA)->index)
			ra(stackA);
		else 
			i--;
	}
}

void	sb(t_list **stackB)
{
	t_list	*head;
	t_list	*next;
	int		temp;
	int		index;

	head = *stackB;
	next = head->next;
	temp = head->value;
	index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = temp;
	next->index = index;
	write (1, "sb\n", 3);
}
