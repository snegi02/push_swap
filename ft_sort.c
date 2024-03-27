/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snegi <snegi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:52:25 by snegi             #+#    #+#             */
/*   Updated: 2024/02/14 10:52:28 by snegi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"

void	sort_3(t_list **stackA)
{
	t_list	*head;
	int		third;

	head = *stackA;
	while (stack_checksort(stackA) == 1)
	{
		third = head->next->next->value;
		if (head->value > head->next->value && third > head->value)
			sa(stackA);
		else if (head->value > third && third > head->next->value)
			ra(stackA);
		else if (head->value < head->next->value && head->value > third)
			rra(stackA);
		else if (head->value > head->next->value && head->next->value > third)
		{
			ra(stackA);
			sa(stackA);
		}
		else
		{
			rra(stackA);
			sa(stackA);
		}
	}
}

void	sort_4(t_list **stackA, t_list **stackB)
{
	int	size_b;

	while (stack_checksort(stackA) == 1)
	{
		little_sort(stackA);
		if (stack_checksort(stackA) == 1)
		{
			pb(stackA, stackB);
			size_b = lstsize(*stackB);
			if (size_b == 2 && (*stackB)->index < (*stackB)->next->index)
				sb(stackB);
			sort_3(stackA);
			pa(stackA, stackB);
		}
	}
}

void	sort_5(t_list **stackA, t_list **stackB)
{
	int	size_b;

	while (stack_checksort(stackA) == 1)
	{
		little_sort(stackA);
		if (stack_checksort(stackA) == 1)
		{
			pb(stackA, stackB);
			size_b = lstsize(*stackB);
			if (size_b == 2 && (*stackB)->index < (*stackB)->next->index)
				sb(stackB);
			sort_4(stackA, stackB);
			pa(stackA, stackB);
		}
	}
}

void	sort_6(t_list **stackA, t_list **stackB)
{
	while (stack_checksort(stackA) == 1)
	{
		little_sort(stackA);
		if (stack_checksort(stackA) == 1)
		{
			pb(stackA, stackB);
			sort_5(stackA, stackB);
			pa(stackA, stackB); 
		}
	}
}

void	sort(t_list **stackA, t_list **stackB, int len)
{
	if (len == 2)
		sa(stackA);
	else if (len == 3)
		sort_3(stackA);
	else if (len == 4)
		sort_4(stackA, stackB);
	else if (len == 5)
		sort_5(stackA, stackB);
	else if (len == 6)
		sort_6(stackA, stackB);
	else
		radix_sort(stackA, stackB, len);
	free_stack(stackA);
}
