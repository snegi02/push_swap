/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snegi <snegi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:53:55 by snegi             #+#    #+#             */
/*   Updated: 2024/02/14 10:53:57 by snegi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"

static int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_list **stackA, t_list **stackB, int len)
{
	t_list	*head;
	int		max_bit;
	int		i;
	int		j;

	i = 0;
	max_bit = get_max_bits(stackA);
	while (i < max_bit)
	{
		j = 0;
		while (j < len)
		{
			head = *stackA;
			if (((head->index >> i) & 1) == 1)
				ra(stackA);
			else
				pb(stackA, stackB);
			j++;
		}
		while (lstsize(*stackB) != 0)
			pa(stackA, stackB);
		i++;
	}
}
